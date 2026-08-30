if (WIN32)
  message(FATAL_ERROR "Giving up for now trying to figure out how to get this to work natively on Windows. You might just have to use Docker or WSL. See the Git history for what I've tried.")
endif()

if ((NOT NODEJS_INCLUDE_DIR) OR (NOT NODEJS_LIB))
  if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Using Node.js v26.7.0 from this project's GitHub release")

    include(FetchContent)
    FetchContent_Declare(
            nodejs_linux

            URL                        https://github.com/airbreather/mod-nodejs/releases/download/libnode-linux-v26.7.0/nodejs-v26.7.0.tar.zst
            URL_HASH                   SHA256=9ddb6a049a90a25983cd59a9efb26fde6dea717775764964182f8336d9309e8d
            DOWNLOAD_EXTRACT_TIMESTAMP true
    )

    FetchContent_MakeAvailable(nodejs_linux)

    CU_SET_GLOBAL(NODEJS_INCLUDE_DIR "${nodejs_linux_SOURCE_DIR}/include/node")
    CU_SET_GLOBAL(NODEJS_LIB "${nodejs_linux_SOURCE_DIR}/lib/libnode.so.147")
  else()
    message(FATAL_ERROR("Linux has pre-built files available. Others (we are '${CMAKE_SYSTEM_NAME}') must figure out their own NODEJS_INCLUDE_DIR and NODEJS_LIB values. PRs to show what I should for other systems are welcome!"))
  endif()
endif()

install(
        FILES
        "${NODEJS_LIB}"
        DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
)

list(APPEND ${PRIVATE_SOURCES} (
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
        src/templates/AchievementEntryTemplate.cpp
        src/templates/ACObjectTemplate.cpp
        src/templates/AuctionHouseTemplate.cpp
        src/templates/AuctionTemplate.cpp
        src/templates/AuraApplicationTemplate.cpp
        src/templates/AuraEffectTemplate.cpp
        src/templates/AuraTemplate.cpp
        src/templates/BattlegroundTemplate.cpp
        src/templates/ByteBufferTemplate.cpp
        src/templates/CastSpellBuilderTemplate.cpp
        src/templates/ChannelTemplate.cpp
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
        src/templates/MySQLConnectionInfoTemplate.cpp
        src/templates/ObjectMgrTemplate.cpp
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
        src/templates/TrainerSpellListMessageTemplate.cpp
        src/templates/TrainerSpellListTemplate.cpp
        src/templates/TrainerSpellTemplate.cpp
        src/templates/TransportTemplate.cpp
        src/templates/UnitTemplate.cpp
        src/templates/VehicleTemplate.cpp
        src/templates/VendorItemDataTemplate.cpp
        src/templates/VendorItemTemplate.cpp
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
