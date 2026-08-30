declare global {
	interface BattlegroundScoreBase {
		playerGuid: bigint;
		killingBlows: number;
		damageDone: number;
		healingDone: number;
		deaths: number;
		honorableKills: number;
		bonusHonor: number;
	}

	interface BattlegroundScoreAB extends BattlegroundScoreBase {
		type: 'AB';
		basesAssaulted: number;
		basesDefended: number;
	}

	interface BattlegroundScoreAV extends BattlegroundScoreBase {
		type: 'AV';
		graveyardsAssaulted: number;
		graveyardsDefended: number;
		towersAssaulted: number;
		towersDefended: number;
		minesCaptured: number;
	}

	interface BattlegroundScoreEY extends BattlegroundScoreBase {
		type: 'EY';
		flagCaptures: number;
	}

	interface BattlegroundScoreIC extends BattlegroundScoreBase {
		type: 'IC';
		basesAssaulted: number;
		basesDefended: number;
	}

	interface BattlegroundScoreSA extends BattlegroundScoreBase {
		type: 'SA';
		demolishersDestroyed: number;
		gatesDestroyed: number;
	}

	interface BattlegroundScoreWG extends BattlegroundScoreBase {
		type: 'WG';
		flagCaptures: number;
		flagReturns: number;
	}

	type BattlegroundScore =
		| BattlegroundScoreAB
		| BattlegroundScoreAV
		| BattlegroundScoreEY
		| BattlegroundScoreIC
		| BattlegroundScoreSA
		| BattlegroundScoreWG;
}
export {};
