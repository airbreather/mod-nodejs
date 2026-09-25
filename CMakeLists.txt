if ((NOT NODEJS_INCLUDE_DIR) OR (NOT NODEJS_LIB))
  include(FetchContent)
  message(STATUS "mod-nodejs: using libnode v26.9.0 from the GitHub release")
  if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    FetchContent_Declare(
            nodejs_linux

            URL                        https://github.com/airbreather/mod-nodejs/releases/download/v26.9.0/libnode-linux-v26.9.0.tar.zst
            URL_HASH                   SHA256=e4056017551c9075e103ebef92eb391b89561e478ef287343a4b1ba72d22b964
            DOWNLOAD_EXTRACT_TIMESTAMP true
    )

    FetchContent_MakeAvailable(nodejs_linux)

    CU_SET_GLOBAL(NODEJS_INCLUDE_DIR "${nodejs_linux_SOURCE_DIR}/include/node")
    CU_SET_GLOBAL(NODEJS_LIB "${nodejs_linux_SOURCE_DIR}/lib/libnode.so.147")
  elseif(WIN32)
    FetchContent_Declare(
            nodejs_win

            URL                        https://github.com/airbreather/mod-nodejs/releases/download/v26.9.0/libnode-windows-v26.9.0.7z
            URL_HASH                   SHA256=4c0dab0523f09a6c9eaedb217eb5bbc8efeaf79a837e02e37edbb1e7c9de26d3
            DOWNLOAD_EXTRACT_TIMESTAMP true
    )

    FetchContent_MakeAvailable(nodejs_win)

    CU_SET_GLOBAL(NODEJS_INCLUDE_DIR "${nodejs_win_SOURCE_DIR}/include/node")
    # Debug and Release builds link to different versions of the CRT.
    CU_SET_GLOBAL(NODEJS_LIB "$<$<CONFIG:Debug>:${nodejs_win_SOURCE_DIR}/bin/Debug/libnode.lib>$<$<CONFIG:Release,RelWithDebInfo,MinSizeRel>:${nodejs_win_SOURCE_DIR}/bin/Release/libnode.lib>")
  else()
    message(FATAL_ERROR("Linux and Windows have pre-built files available. Others (we are '${CMAKE_SYSTEM_NAME}') must figure out their own NODEJS_INCLUDE_DIR and NODEJS_LIB values. PRs to show what I should for other systems are welcome!"))
  endif()
endif()

# Windows: the matching .dll must be copied into bin/<Config> by hand like the
# others that the setup instructions tell users to deal with.
if (NOT WIN32)
    install(
            FILES
            ${NODEJS_LIB}
            DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
    )
endif()

list(APPEND ${PRIVATE_SOURCES} (
        src/records/BattlegroundScoreRecord.cpp
        src/records/ChaseAngleRecord.cpp
        src/records/ChaseRangeRecord.cpp
        src/records/CreatureModelRecord.cpp
        src/records/CreatureMovementDataRecord.cpp
        src/records/GroupMemberRecord.cpp
        src/records/GroupQueueInfoRecord.cpp
        src/records/ImmunityInfoRecord.cpp
        src/records/LootItemRecord.cpp
        src/records/ObjectGuidRecord.cpp
        src/records/PetInfoRecord.cpp
        src/records/PetSpellRecord.cpp
        src/records/PositionRecord.cpp
        src/records/SpellModifierRecord.cpp

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
        src/templates/AreaDamageDataTemplate.cpp
        src/templates/AuctionHouseTemplate.cpp
        src/templates/AuctionTemplate.cpp
        src/templates/AuraApplicationTemplate.cpp
        src/templates/AuraEffectTemplate.cpp
        src/templates/AuraGeneratorDataTemplate.cpp
        src/templates/AuraTemplate.cpp
        src/templates/BarberChairDataTemplate.cpp
        src/templates/BattlegroundTemplate.cpp
        src/templates/ButtonDataTemplate.cpp
        src/templates/ByteBufferTemplate.cpp
        src/templates/CameraDataTemplate.cpp
        src/templates/CapturePointDataTemplate.cpp
        src/templates/CastSpellBuilderTemplate.cpp
        src/templates/ChannelTemplate.cpp
        src/templates/ChairDataTemplate.cpp
        src/templates/CharTitlesEntryTemplate.cpp
        src/templates/ChatCommandBuilderBuilderBoxTemplate.cpp
        src/templates/ChatHandlerTemplate.cpp
        src/templates/ChestDataTemplate.cpp
        src/templates/ConfigTemplate.cpp
        src/templates/ConditionTemplate.cpp
        src/templates/ConditionSourceInfoTemplate.cpp
        src/templates/CorpseTemplate.cpp
        src/templates/CreatureTemplate.cpp
        src/templates/CreatureTemplateTemplate.cpp
        src/templates/DestructibleBuildingDataTemplate.cpp
        src/templates/DoorDataTemplate.cpp
        src/templates/DungeonDifficultyDataTemplate.cpp
        src/templates/DynamicObjectTemplate.cpp
        src/templates/FactionEntryTemplate.cpp
        src/templates/FishingHoleDataTemplate.cpp
        src/templates/FlagDropDataTemplate.cpp
        src/templates/FlagStandDataTemplate.cpp
        src/templates/GameObjectTemplate.cpp
        src/templates/GameObjectTemplateTemplate.cpp
        src/templates/GemPropertiesEntryTemplate.cpp
        src/templates/GenericDataTemplate.cpp
        src/templates/GlyphPropertiesEntryTemplate.cpp
        src/templates/GmTicketTemplate.cpp
        src/templates/GroupTemplate.cpp
        src/templates/GooberDataTemplate.cpp
        src/templates/GuardianTemplate.cpp
        src/templates/GuardPostDataTemplate.cpp
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
        src/templates/MeetingStoneDataTemplate.cpp
        src/templates/MiniGameDataTemplate.cpp
        src/templates/MinionTemplate.cpp
        src/templates/MoTransportDataTemplate.cpp
        src/templates/MySQLConnectionInfoTemplate.cpp
        src/templates/ObjectMgrTemplate.cpp
        src/templates/PetTemplate.cpp
        src/templates/PlayerTemplate.cpp
        src/templates/PvPDifficultyEntryTemplate.cpp
        src/templates/QueryResultFieldTemplate.cpp
        src/templates/QueryResultSetTemplate.cpp
        src/templates/QuestGiverDataTemplate.cpp
        src/templates/QuestTemplate.cpp
        src/templates/RollTemplate.cpp
        src/templates/SpawnCreatureBuilderTemplate.cpp
        src/templates/SpawnGameObjectBuilderTemplate.cpp
        src/templates/SpellcasterDataTemplate.cpp
        src/templates/SpellCastTimesEntryTemplate.cpp
        src/templates/SpellCategoryEntryTemplate.cpp
        src/templates/SpellChainNodeTemplate.cpp
        src/templates/SpellDurationEntryTemplate.cpp
        src/templates/SpellEffectInfoTemplate.cpp
        src/templates/SpellFocusDataTemplate.cpp
        src/templates/SpellImplicitTargetInfoTemplate.cpp
        src/templates/SpellInfoTemplate.cpp
        src/templates/SpellRadiusEntryTemplate.cpp
        src/templates/SpellRangeEntryTemplate.cpp
        src/templates/SpellTemplate.cpp
        src/templates/SummoningRitualDataTemplate.cpp
        src/templates/SummonPropertiesEntryTemplate.cpp
        src/templates/TempSummonTemplate.cpp
        src/templates/TextDataTemplate.cpp
        src/templates/ThreatReferenceTemplate.cpp
        src/templates/TransportDataTemplate.cpp
        src/templates/TransportTemplate.cpp
        src/templates/TrapDataTemplate.cpp
        src/templates/TrapDoorDataTemplate.cpp
        src/templates/UnitTemplate.cpp
        src/templates/VehicleEntryTemplate.cpp
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
        src/JBox.cpp
        src/JtoC.cpp
        src/NodeCommon.cpp
        src/NodeJPropHelpers.cpp
        src/NodeJs.cpp
        src/NodePostToEventLoopMaster.cpp
        src/NodePropertySystem.cpp
        src/NodeWrappedObject.cpp
        src/PropertyImplementations.cpp
        src/SpawnCreatureBuilder.cpp
        src/SpawnGameObjectBuilder.cpp
        src/UnixTimestamp.cpp
))
