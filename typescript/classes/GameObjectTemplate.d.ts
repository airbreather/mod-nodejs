declare global {
	namespace Acore {
		class GameObjectTemplate {
			private constructor();

			static byId(id: number): GameObjectTemplate | undefined;

			readonly entry: number;
			readonly type: GameobjectTypes;
			readonly displayId: number;
			readonly name: string;
			readonly iconName: string;
			readonly castBarCaption: string;
			readonly unk1: string;
			readonly size: number;
			readonly rawData: readonly number[];
			readonly data: object | undefined;
		}

		type GameObjectTemplateNarrowable = GameObjectTemplate & (
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_DOOR, data: DoorData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_BUTTON, data: ButtonData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_QUESTGIVER, data: QuestGiverData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_CHEST, data: ChestData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_BINDER, data: undefined }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_GENERIC, data: GenericData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_TRAP, data: TrapData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_CHAIR, data: ChairData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_SPELL_FOCUS, data: SpellFocusData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_TEXT, data: TextData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_GOOBER, data: GooberData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_TRANSPORT, data: TransportData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_AREADAMAGE, data: AreaDamageData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_CAMERA, data: CameraData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_MAP_OBJECT, data: undefined }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_MO_TRANSPORT, data: MoTransportData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_DUEL_ARBITER, data: undefined }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_FISHINGNODE, data: undefined }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_SUMMONING_RITUAL, data: SummoningRitualData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_MAILBOX, data: undefined }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_DO_NOT_USE, data: undefined }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_GUARDPOST, data: GuardPostData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_SPELLCASTER, data: SpellcasterData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_MEETINGSTONE, data: MeetingStoneData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_FLAGSTAND, data: FlagStandData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_FISHINGHOLE, data: FishingHoleData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_FLAGDROP, data: FlagDropData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_MINI_GAME, data: MiniGameData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_DO_NOT_USE_2, data: undefined }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_CAPTURE_POINT, data: CapturePointData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_AURA_GENERATOR, data: AuraGeneratorData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY, data: DungeonDifficultyData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_BARBER_CHAIR, data: BarberChairData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING, data: DestructibleBuildingData }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_GUILD_BANK, data: undefined }
			| { type: GameobjectTypes.GAMEOBJECT_TYPE_TRAPDOOR, data: TrapDoorData }
		);
	}
}
export {};
