if ((NOT NODEJS_INCLUDE_DIR) OR (NOT NODEJS_LIB))
  include(FetchContent)
  if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Using Node.js v26.8.1 from this project's GitHub release (Linux)")

    FetchContent_Declare(
            nodejs_linux

            URL                        https://github.com/airbreather/mod-nodejs/releases/download/libnode-linux-v26.8.1/nodejs-v26.8.1.tar.zst
            URL_HASH                   SHA256=7fac51e9d04916f7599f48bbb83c28785ad1095519f363c05256f32ca202c780
            DOWNLOAD_EXTRACT_TIMESTAMP true
    )

    FetchContent_MakeAvailable(nodejs_linux)

    CU_SET_GLOBAL(NODEJS_INCLUDE_DIR "${nodejs_linux_SOURCE_DIR}/include/node")
    CU_SET_GLOBAL(NODEJS_LIB "${nodejs_linux_SOURCE_DIR}/lib/libnode.so.147")
  elseif(WIN32)
    message(STATUS "Using Node.js v26.8.1 from this project's GitHub release (Windows)")

    FetchContent_Declare(
            nodejs_win

            URL                        https://github.com/airbreather/mod-nodejs/releases/download/libnode-windows-v26.8.1/nodejs-v26.8.1.7z
            URL_HASH                   SHA256=bb2146445abfd5746d8b7a3009583d84faabda8925ecd2828cdf5c7d8ccb91c9
            DOWNLOAD_EXTRACT_TIMESTAMP true
    )

    FetchContent_MakeAvailable(nodejs_win)

    if (NOT ZLIB_IMPORT)
        set(ZLIB_IMPORT "${nodejs_win_SOURCE_DIR}/zlib.lib")
        file(
                DOWNLOAD               https://github.com/airbreather/mod-nodejs/releases/download/libnode-windows-v26.8.1/zlib.lib
                ${ZLIB_IMPORT}
                EXPECTED_HASH          SHA256=6784de83aa9020df38748712b1548c612ee8a046288910afb43e433febc9961b
        )
    endif()

    CU_SET_GLOBAL(NODEJS_INCLUDE_DIR "${nodejs_win_SOURCE_DIR}/include/node")
    CU_SET_GLOBAL(NODEJS_LIB "${nodejs_win_SOURCE_DIR}/bin/libnode.lib")

    # Copy libnode.dll next to the built executables (Windows convention:
    # DLLs live in the same directory as the .exe). The core's non-vendored
    # deps don't, but this is a solvable problem given we need the DLL anyway.
    add_custom_command(TARGET worldserver POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${nodejs_win_SOURCE_DIR}/bin/libnode.dll"
        "$<TARGET_FILE_DIR:worldserver>"
      COMMENT "Copying libnode.dll to bin/"
    )
  else()
    message(FATAL_ERROR("Linux and Windows have pre-built files available. Others (we are '${CMAKE_SYSTEM_NAME}') must figure out their own NODEJS_INCLUDE_DIR and NODEJS_LIB values. PRs to show what I should for other systems are welcome!"))
  endif()
endif()

install(
        FILES
        "${NODEJS_LIB}"
        DESTINATION "${CMAKE_INSTALL_PREFIX}/bin"
)

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
        src/templates/AuctionHouseTemplate.cpp
        src/templates/AuctionTemplate.cpp
        src/templates/AuraApplicationTemplate.cpp
        src/templates/AuraEffectTemplate.cpp
        src/templates/AuraTemplate.cpp
        src/templates/BattlegroundTemplate.cpp
        src/templates/ByteBufferTemplate.cpp
        src/templates/CastSpellBuilderTemplate.cpp
        src/templates/ChannelTemplate.cpp
        src/templates/CharTitlesEntryTemplate.cpp
        src/templates/ChatCommandBuilderBuilderBoxTemplate.cpp
        src/templates/ChatHandlerTemplate.cpp
        src/templates/ConfigTemplate.cpp
        src/templates/ConditionTemplate.cpp
        src/templates/ConditionSourceInfoTemplate.cpp
        src/templates/CorpseTemplate.cpp
        src/templates/CreatureTemplate.cpp
        src/templates/CreatureTemplateTemplate.cpp
        src/templates/DynamicObjectTemplate.cpp
        src/templates/FactionEntryTemplate.cpp
        src/templates/GameObjectTemplate.cpp
        src/templates/GemPropertiesEntryTemplate.cpp
        src/templates/GlyphPropertiesEntryTemplate.cpp
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
        src/templates/PvPDifficultyEntryTemplate.cpp
        src/templates/QueryResultFieldTemplate.cpp
        src/templates/QueryResultSetTemplate.cpp
        src/templates/QuestTemplate.cpp
        src/templates/RollTemplate.cpp
        src/templates/SpellCastTimesEntryTemplate.cpp
        src/templates/SpellCategoryEntryTemplate.cpp
        src/templates/SpellChainNodeTemplate.cpp
        src/templates/SpellDurationEntryTemplate.cpp
        src/templates/SpellEffectInfoTemplate.cpp
        src/templates/SpellImplicitTargetInfoTemplate.cpp
        src/templates/SpellInfoTemplate.cpp
        src/templates/SpellRadiusEntryTemplate.cpp
        src/templates/SpellRangeEntryTemplate.cpp
        src/templates/SpellTemplate.cpp
        src/templates/SummonPropertiesEntryTemplate.cpp
        src/templates/TempSummonTemplate.cpp
        src/templates/ThreatReferenceTemplate.cpp
        src/templates/TrainerSpellListMessageTemplate.cpp
        src/templates/TrainerSpellListTemplate.cpp
        src/templates/TrainerSpellTemplate.cpp
        src/templates/TransportTemplate.cpp
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
