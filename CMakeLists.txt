if ((NOT NODEJS_INCLUDE_DIR) OR (NOT NODEJS_LIB))
  if (NOT WIN32)
    # I don't know of anywhere to find this pre-built the way we need it to be.
    message(FATAL_ERROR "Must pass -DNODEJS_INCLUDE_DIR and -DNODEJS_LIB flags when building with mod_nodejs.")
  endif()

  message(STATUS "Using Node.js v26.7.0 from nodejs.org")

  include(FetchContent)
  FetchContent_Declare(
          nodejs_win32

          URL                        https://nodejs.org/dist/v26.7.0/node-v26.7.0-win-x64.7z
          URL_HASH                   SHA256=073be1a597ff9f0130b067fb35eb84225d3970fdd7a84ee898f4b6270aadec0f
          DOWNLOAD_EXTRACT_TIMESTAMP true
  )

  FetchContent_Declare(
          nodejs_headers

          URL                        https://nodejs.org/dist/v26.7.0/node-v26.7.0-headers.tar.xz
          URL_HASH                   SHA256=453153ebefe7999965211df9ad3029f99a3c57b89eded9862e17be7ee0aaf1ba
          DOWNLOAD_EXTRACT_TIMESTAMP true
  )

  FetchContent_MakeAvailable(nodejs_win32 nodejs_headers)

  set(NODEJS_INCLUDE_DIR "${nodejs_headers_SOURCE_DIR}/include/node")
  set(NODEJS_LIB "${nodejs_win32_SOURCE_DIR}/nodejs.lib")
  file(
          DOWNLOAD
          https://nodejs.org/dist/v26.7.0/win-x64/node.lib
          "${NODEJS_LIB}"
          EXPECTED_HASH SHA256=56f06350037085fce04930befd98327afc86ee46f52af6f6f8a68a03630e8380
  )
endif()

message(STATUS "Node.js include path: ${NODEJS_INCLUDE_DIR}")
message(STATUS "Node.js library: ${NODEJS_LIB}")

if(WIN32)
  # Win32 Node.js builds statically link zlib, so that should take precedence.
  set(ZLIB_EXTERNAL_INCLUDE_DIR "${NODEJS_INCLUDE_DIR}" CACHE PATH "Path to zlib headers.")
endif()

list(APPEND ${PRIVATE_SOURCES} (
        src/records/AchievementEntryRecord.cpp
        src/records/BattlegroundScoreRecord.cpp
        src/records/CharTitlesEntryRecord.cpp
        src/records/ChaseAngleRecord.cpp
        src/records/ChaseRangeRecord.cpp
        src/records/CreatureModelRecord.cpp
        src/records/CreatureMovementDataRecord.cpp
        src/records/FactionEntryRecord.cpp
        src/records/GemPropertiesEntryRecord.cpp
        src/records/GlyphPropertiesEntryRecord.cpp
        src/records/GroupMemberRecord.cpp
        src/records/GroupQueueInfoRecord.cpp
        src/records/ImmunityInfoRecord.cpp
        src/records/ItemDamageRecord.cpp
        src/records/ItemSocketRecord.cpp
        src/records/ItemSpellRecord.cpp
        src/records/ItemStatRecord.cpp
        src/records/LootItemRecord.cpp
        src/records/ObjectGuidRecord.cpp
        src/records/PetInfoRecord.cpp
        src/records/PetSpellRecord.cpp
        src/records/PositionRecord.cpp
        src/records/PvPDifficultyEntryRecord.cpp
        src/records/SpellCastTimesEntryRecord.cpp
        src/records/SpellCategoryEntryRecord.cpp
        src/records/SpellDurationEntryRecord.cpp
        src/records/SpellModifierRecord.cpp
        src/records/SpellRadiusEntryRecord.cpp
        src/records/SpellRangeEntryRecord.cpp
        src/records/SummonPropertiesEntryRecord.cpp
        src/records/VehicleEntryRecord.cpp

        src/scripts/AccountScript.cpp
        src/scripts/AllBattlegroundScript.cpp
        src/scripts/AllCreatureScript.cpp
        src/scripts/AllGameObjectScript.cpp
        src/scripts/AllItemScript.cpp
        src/scripts/AllMapScript.cpp
        src/scripts/AllSpellScript.cpp
        src/scripts/AuctionHouseScript.cpp
        src/scripts/CommandScript.cpp
        src/scripts/GroupScript.cpp
        src/scripts/GuildScript.cpp
        src/scripts/LootScript.cpp
        src/scripts/MiscScript.cpp
        src/scripts/PetScript.cpp
        src/scripts/PlayerScript.cpp
        src/scripts/TicketScript.cpp
        src/scripts/UnitScript.cpp
        src/scripts/VehicleScript.cpp
        src/scripts/WorldObjectScript.cpp
        src/scripts/WorldScript.cpp

        src/templates/_GlobalFunctions.cpp
        src/templates/_InteropTemplates.cpp
        src/templates/ACObjectTemplate.cpp
        src/templates/AuctionHouseTemplate.cpp
        src/templates/AuctionTemplate.cpp
        src/templates/AuraApplicationTemplate.cpp
        src/templates/AuraEffectTemplate.cpp
        src/templates/AuraTemplate.cpp
        src/templates/BattlegroundTemplate.cpp
        src/templates/ByteBufferTemplate.cpp
        src/templates/CastSpellBuilderTemplate.cpp
        src/templates/ChatCommandBuilderBuilderBoxTemplate.cpp
        src/templates/ChatHandlerTemplate.cpp
        src/templates/ConfigTemplate.cpp
        src/templates/ConditionTemplate.cpp
        src/templates/ConditionSourceInfoTemplate.cpp
        src/templates/CorpseTemplate.cpp
        src/templates/CreatureTemplate.cpp
        src/templates/CreatureTemplateTemplate.cpp
        src/templates/DynamicObjectTemplate.cpp
        src/templates/GameObjectTemplate.cpp
        src/templates/GmTicketTemplate.cpp
        src/templates/GroupTemplate.cpp
        src/templates/GuardianTemplate.cpp
        src/templates/GuildMemberTemplate.cpp
        src/templates/GuildTemplate.cpp
        src/templates/ItemTemplate.cpp
        src/templates/ItemTemplateTemplate.cpp
        src/templates/LootStoreTemplate.cpp
        src/templates/LootTemplate.cpp
        src/templates/LootTemplateTemplate.cpp
        src/templates/MailDraftTemplate.cpp
        src/templates/MailSenderTemplate.cpp
        src/templates/MapTemplate.cpp
        src/templates/MinionTemplate.cpp
        src/templates/PetTemplate.cpp
        src/templates/PlayerTemplate.cpp
        src/templates/QueryResultFieldTemplate.cpp
        src/templates/QueryResultSetTemplate.cpp
        src/templates/QuestTemplate.cpp
        src/templates/RollTemplate.cpp
        src/templates/SpellChainNodeTemplate.cpp
        src/templates/SpellEffectInfoTemplate.cpp
        src/templates/SpellImplicitTargetInfoTemplate.cpp
        src/templates/SpellInfoTemplate.cpp
        src/templates/SpellTemplate.cpp
        src/templates/TempSummonTemplate.cpp
        src/templates/ThreatReferenceTemplate.cpp
        src/templates/TransportTemplate.cpp
        src/templates/UnitTemplate.cpp
        src/templates/VehicleTemplate.cpp
        src/templates/WorldObjectTemplate.cpp
        src/templates/WorldPacketTemplate.cpp

        src/CastSpellBuilder.cpp
        src/ChatCommandBuilderBuilder.cpp
        src/CtoJ.cpp
        src/Db.cpp
        src/DurationWrapper.cpp
        src/JtoC.cpp
        src/NodeCommon.cpp
        src/NodeJPropHelpers.cpp
        src/NodeJs.cpp
        src/NodePostToEventLoopMaster.cpp
        src/NodePropertySystem.cpp
        src/NodeWrappedObject.cpp
        src/PropertyImplementations.cpp
        src/UnixTimestamp.cpp
))
