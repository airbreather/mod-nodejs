#include "CoreAccessShims.h"

#include "DatabaseEnv.h"
#include "ScriptMgr.h"

// ---------------------------------------------------------------------
// Guild::SetMOTD / Guild::SetInfo
//
// UNLIKE every other shim in this file, these are not "make an existing
// private thing reachable" -- before azerothcore-wotlk#26648, this logic
// only ever ran inline inside Guild::HandleSetMOTD/HandleSetInfo, gated
// behind a WorldSession* and a permission check. There was no private
// method sitting there to steal.
//
// So this is a genuine reimplementation, byte-for-byte identical to what
// PR #26648 adds to Guild.cpp (verified against the real diff), built out
// of pieces stolen via CoreAccessSteal.h:
//   - m_motd, m_info, m_id (protected data members -> stolen directly)
//   - _BroadcastEvent        (protected method     -> stolen directly)
//   - CharacterDatabase, sScriptMgr, GE_MOTD, CHAR_UPD_GUILD_MOTD/INFO
//     (all already public/global, no stealing needed)
//
// RISK, stated plainly: if AzerothCore ever changes what SetMOTD/SetInfo
// do internally (e.g. adds a new side effect, changes the broadcast
// event, adds validation), this copy will silently NOT pick that up,
// because it isn't calling into AC's real implementation -- there isn't
// one to call. This is exactly the "silent drift" risk flagged earlier.
// If azerothcore-wotlk#26648 (or equivalent) merges upstream, delete this
// whole implementation and call guild.SetMOTD(...)/guild.SetInfo(...)
// directly instead.
// ---------------------------------------------------------------------

AC_STEAL_MEMBER(Guild_MOTD, Guild, m_motd, std::string)
AC_STEAL_MEMBER(Guild_Info, Guild, m_info, std::string)
AC_STEAL_MEMBER(Guild_Id, Guild, m_id, uint32)

AC_STEAL_METHOD(Guild_BroadcastEvent, Guild, _BroadcastEvent, void,
                 GuildEvents, ObjectGuid, Optional<std::string_view>, Optional<std::string_view>, Optional<std::string_view>)

void Guild_SetMOTD(Guild& guild, std::string_view motd)
{
    Guild_MOTD(guild) = motd;

    sScriptMgr->OnGuildMOTDChanged(&guild, Guild_MOTD(guild));

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_MOTD);
    stmt->SetData(0, Guild_MOTD(guild));
    stmt->SetData(1, Guild_Id(guild));
    CharacterDatabase.Execute(stmt);

    Guild_BroadcastEvent(guild, GE_MOTD, ObjectGuid::Empty,
                          Optional<std::string_view>(Guild_MOTD(guild)),
                          Optional<std::string_view>(),
                          Optional<std::string_view>());
}

void Guild_SetInfo(Guild& guild, std::string_view info)
{
    Guild_Info(guild) = info;

    sScriptMgr->OnGuildInfoChanged(&guild, Guild_Info(guild));

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_GUILD_INFO);
    stmt->SetData(0, Guild_Info(guild));
    stmt->SetData(1, Guild_Id(guild));
    CharacterDatabase.Execute(stmt);

    // Note: the real PR does NOT broadcast an event for SetInfo, only for
    // SetMOTD -- verified against the actual diff, not assumed.
}
