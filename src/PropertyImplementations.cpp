#include <optional>
#include <v8-function.h>
#include <v8-local-handle.h>
#include <v8-object.h>

#include "AuctionHouseMgr.h"
#include "Common.h"
#include "CtoJ.h"
#include "GameObject.h"
#include "GameObjectData.h"
#include "JtoC.h"
#include "LFG.h"
#include "LootMgr.h"
#include "MotionMaster.h"
#include "NodePropertySystem.h"
#include "Object.h"
#include "ObjectGuid.h"
#include "PetDefines.h"
#include "Player.h"
#include "SharedDefines.h"
#include "SpellAuraDefines.h"
#include "SpellDefines.h"
#include "SpellInfo.h"
#include "ThreatManager.h"
#include "Unit.h"
#include "UnitDefines.h"

// passthroughs
template<> v8::Local<v8::Value> jval<v8::Local<v8::Value>>(v8::Local<v8::Value> const v) { return v; }
template<> std::optional<v8::Local<v8::Value>> cval<v8::Local<v8::Value>>(v8::Local<v8::Value> v) { return v; }

#define JVAL_CVAL_PASSTHROUGH(v8_typ) \
	template<> v8::Local<v8::Value> jval<v8::Local<v8::v8_typ>>(v8::Local<v8::v8_typ> const v) { return v; } \
	template<> std::optional<v8::Local<v8::v8_typ>> cval<v8::Local<v8::v8_typ>>(v8::Local<v8::Value> v) { return v->Is##v8_typ() ? std::optional(v.As<v8::v8_typ>()) : std::nullopt; }

JVAL_CVAL_PASSTHROUGH(BigInt)
JVAL_CVAL_PASSTHROUGH(External)
JVAL_CVAL_PASSTHROUGH(Map)
JVAL_CVAL_PASSTHROUGH(Function)
JVAL_CVAL_PASSTHROUGH(Object)
JVAL_CVAL_PASSTHROUGH(Promise)
JVAL_CVAL_PASSTHROUGH(Uint8Array)

#undef JVAL_CVAL_PASSTHROUGH

// enums get real repetitive
template <typename Enum, typename Underlying>
std::optional<Enum> cval_enum(v8::Local<v8::Value> const v) {
	auto const result = cval<Underlying>(v);
	return result
		? std::optional<Enum>{static_cast<Enum>(*result)}
	: std::nullopt;
}

// I/E: (I)mplicit / (E)xplicit (enums with implicit storage use uint32_t)
// O/P/C: (O)nly the jval/cval, forward-declare as (P)lain enum, or forward-declare as enum (C)lass

#define ENUM_JVAL_CVAL_EO(enum_type, underlying_type) \
	template<> v8::Local<v8::Value> jval<enum_type>(enum_type const v) { return jval<underlying_type>(static_cast<underlying_type>(v)); } \
	template<> std::optional<enum_type> cval<enum_type>(v8::Local<v8::Value> const v) { return cval_enum<enum_type, underlying_type>(v); }

#define ENUM_JVAL_CVAL_IO(enum_type) \
	ENUM_JVAL_CVAL_EO(enum_type, uint32_t)

#define ENUM_JVAL_CVAL_EP(enum_type, underlying_type) \
	enum enum_type : underlying_type; \
	ENUM_JVAL_CVAL_EO(enum_type, underlying_type);

#define ENUM_JVAL_CVAL_EC(enum_type, underlying_type) \
	enum class enum_type : underlying_type; \
	ENUM_JVAL_CVAL_EO(enum_type, underlying_type);

#define ENUM_JVAL_CVAL_IP(enum_type) \
	enum enum_type; \
	ENUM_JVAL_CVAL_EO(enum_type, uint32_t);

#define ENUM_JVAL_CVAL_IC(enum_type) \
	enum class enum_type; \
	ENUM_JVAL_CVAL_EO(enum_type, uint32_t);

ENUM_JVAL_CVAL_IP(AccountFlag)
ENUM_JVAL_CVAL_IP(AccountTypes)
ENUM_JVAL_CVAL_IP(AcoreStrings)
ENUM_JVAL_CVAL_EP(ActiveStates, uint8_t)
ENUM_JVAL_CVAL_EP(ArenaTeamInfoType, uint8_t)
ENUM_JVAL_CVAL_IP(AtLoginFlags)
ENUM_JVAL_CVAL_EC(AuctionHouseId, uint8_t)
ENUM_JVAL_CVAL_EP(AuraRemoveMode, uint8_t)
ENUM_JVAL_CVAL_IP(AuraStateType)
ENUM_JVAL_CVAL_IP(AuraType)
ENUM_JVAL_CVAL_EP(BattlegroundBracketId, uint8_t)
ENUM_JVAL_CVAL_EP(BattlegroundDesertionType, uint8_t)
ENUM_JVAL_CVAL_EP(BattlegroundTypeId, uint8_t)
#ifdef MOD_PLAYERBOTS
	ENUM_JVAL_CVAL_EP(ChatMsg, uint32_t)
#else
	ENUM_JVAL_CVAL_IP(ChatMsg)
#endif
ENUM_JVAL_CVAL_EP(ClassContext, uint8_t)
ENUM_JVAL_CVAL_IP(Classes)
ENUM_JVAL_CVAL_EP(CombatRating, uint8_t)
ENUM_JVAL_CVAL_IP(ConditionSourceType)
ENUM_JVAL_CVAL_IP(ConditionTypes)
namespace Acore::ChatCommands { enum class Console : bool; }
ENUM_JVAL_CVAL_EO(Acore::ChatCommands::Console, bool)
ENUM_JVAL_CVAL_EP(CorpseType, int32_t)
ENUM_JVAL_CVAL_EC(CreatureChaseMovementType, uint8_t)
ENUM_JVAL_CVAL_IP(CreatureEliteType)
ENUM_JVAL_CVAL_EC(CreatureFlightMovementType, uint8_t)
ENUM_JVAL_CVAL_EC(CreatureGroundMovementType, uint8_t)
ENUM_JVAL_CVAL_EC(CreatureRandomMovementType, uint8_t)
ENUM_JVAL_CVAL_IP(CurrentSpellTypes)
ENUM_JVAL_CVAL_EP(DamageEffectType, uint8_t)
ENUM_JVAL_CVAL_EC(DatabaseFieldTypes, uint8_t)
ENUM_JVAL_CVAL_EC(Db, uint8_t)
ENUM_JVAL_CVAL_EC(DeathState, uint8_t)
ENUM_JVAL_CVAL_EP(Difficulty, uint8_t)
#ifdef MOD_PLAYERBOTS
ENUM_JVAL_CVAL_EP(DispelType, uint8_t)
#else
ENUM_JVAL_CVAL_IP(DispelType)
#endif
ENUM_JVAL_CVAL_IP(DuelCompleteType)
ENUM_JVAL_CVAL_IP(Emote)
ENUM_JVAL_CVAL_EP(EnchantmentSlot, uint8_t)
ENUM_JVAL_CVAL_IP(EnviromentalDamage)
ENUM_JVAL_CVAL_IP(EquipmentSlots)
ENUM_JVAL_CVAL_IP(Expansions)
ENUM_JVAL_CVAL_EP(GMTicketEscalationStatus, int32_t)
ENUM_JVAL_CVAL_IP(GOState)
ENUM_JVAL_CVAL_IP(GroupJoinBattlegroundResult)
ENUM_JVAL_CVAL_EP(GroupType, int32_t)
ENUM_JVAL_CVAL_IP(HappinessState)
ENUM_JVAL_CVAL_IC(HighGuid)
ENUM_JVAL_CVAL_EP(InventoryResult, uint8_t)
ENUM_JVAL_CVAL_EP(ItemFlags, uint32_t)
ENUM_JVAL_CVAL_EP(ItemFlags2, uint32_t)
ENUM_JVAL_CVAL_EP(ItemFlagsCustom, uint32_t)
ENUM_JVAL_CVAL_IP(ItemModType)
ENUM_JVAL_CVAL_IP(ItemSubclassArmor)
ENUM_JVAL_CVAL_IP(ItemSubclassWeapon)
ENUM_JVAL_CVAL_IP(Language)
ENUM_JVAL_CVAL_IO(lfg::LfgRoles)
ENUM_JVAL_CVAL_IP(LocaleConstant)
ENUM_JVAL_CVAL_EP(LogLevel, uint8_t)
ENUM_JVAL_CVAL_IP(LootState)
ENUM_JVAL_CVAL_IP(LootType)
ENUM_JVAL_CVAL_IP(MailAuctionAnswers)
ENUM_JVAL_CVAL_EP(MailCheckMask, uint8_t)
ENUM_JVAL_CVAL_IP(MailMessageType)
ENUM_JVAL_CVAL_IP(MailStationery)
ENUM_JVAL_CVAL_EP(Mechanics, uint32_t)
ENUM_JVAL_CVAL_IP(MovementGeneratorType)
ENUM_JVAL_CVAL_IP(MovementSlot)
ENUM_JVAL_CVAL_EP(NPCFlags, uint32_t)
ENUM_JVAL_CVAL_EP(PetSaveMode, int8_t)
ENUM_JVAL_CVAL_IP(PetSpellState)
ENUM_JVAL_CVAL_IP(PetSpellType)
ENUM_JVAL_CVAL_EP(PetType, uint8_t)
ENUM_JVAL_CVAL_EP(PlayerFlags, uint32_t)
ENUM_JVAL_CVAL_IP(Powers)
ENUM_JVAL_CVAL_EP(QuestStatus, uint8_t)
ENUM_JVAL_CVAL_EP(ReactStates, uint8_t)
ENUM_JVAL_CVAL_EP(RemoveMethod, uint8_t)
ENUM_JVAL_CVAL_EP(ReputationRank, uint8_t)
ENUM_JVAL_CVAL_IP(ReputationSource)
ENUM_JVAL_CVAL_EP(RollVote, uint8_t)
ENUM_JVAL_CVAL_IP(ServerSideVisibilityType)
ENUM_JVAL_CVAL_IP(SheathState)
ENUM_JVAL_CVAL_EP(ShutdownMask, uint8_t)
ENUM_JVAL_CVAL_IP(SkillType)
ENUM_JVAL_CVAL_IP(SpellCastTargetFlags)
ENUM_JVAL_CVAL_EP(SpellCastResult, uint8_t)
ENUM_JVAL_CVAL_IP(SpellEffectImplicitTargetTypes)
ENUM_JVAL_CVAL_IP(SpellEffects)
ENUM_JVAL_CVAL_EP(SpellEffIndex, uint8_t)
ENUM_JVAL_CVAL_IP(SpellImmuneBlockType)
ENUM_JVAL_CVAL_IP(SpellImmunity)
ENUM_JVAL_CVAL_IP(SpellModOp)
ENUM_JVAL_CVAL_IP(SpellModType)
ENUM_JVAL_CVAL_IP(SpellSchoolMask)
ENUM_JVAL_CVAL_IP(SpellSchools)
ENUM_JVAL_CVAL_IP(SpellSpecificType)
ENUM_JVAL_CVAL_IP(SpellTargetCheckTypes)
ENUM_JVAL_CVAL_IP(SpellTargetDirectionTypes)
ENUM_JVAL_CVAL_IP(SpellTargetObjectTypes)
ENUM_JVAL_CVAL_IP(SpellTargetReferenceTypes)
ENUM_JVAL_CVAL_IP(SpellTargetSelectionCategories)
ENUM_JVAL_CVAL_IP(SpellValueMod)
ENUM_JVAL_CVAL_IP(Stats)
ENUM_JVAL_CVAL_IP(Targets)
ENUM_JVAL_CVAL_EP(TeamId, uint8_t)
ENUM_JVAL_CVAL_IP(TempSummonType)
ENUM_JVAL_CVAL_EO(ThreatReference::OnlineState, int32_t)
ENUM_JVAL_CVAL_EO(ThreatReference::TauntState, uint32_t)
ENUM_JVAL_CVAL_IP(TriggerCastFlags)
ENUM_JVAL_CVAL_EP(WeaponAttackType, uint8_t)
ENUM_JVAL_CVAL_IP(TypeID)
ENUM_JVAL_CVAL_IP(UnitDynFlags)
ENUM_JVAL_CVAL_EP(UnitFlags, uint32_t)
ENUM_JVAL_CVAL_EP(UnitFlags2, uint32_t)
ENUM_JVAL_CVAL_IP(UnitModifierFlatType)
ENUM_JVAL_CVAL_IP(UnitModifierPctType)
ENUM_JVAL_CVAL_IP(UnitMods)
ENUM_JVAL_CVAL_IP(UnitMoveType)
ENUM_JVAL_CVAL_IP(UnitState)

#undef ENUM_JVAL_CVAL_IC
#undef ENUM_JVAL_CVAL_IP
#undef ENUM_JVAL_CVAL_EC
#undef ENUM_JVAL_CVAL_EP
#undef ENUM_JVAL_CVAL_IO
#undef ENUM_JVAL_CVAL_EO
