declare global {
	interface Hooks {
		['battleground:start']: { bg: Acore.Battleground; };
		['battleground:end']: {
			bg: Acore.Battleground;
			winnerTeam: TeamId;
		};
		['battleground:create']: { bg: Acore.Battleground; };
		['battleground:destroy']: { bg: Acore.Battleground; };
		['battleground:end-reward']: {
			bg: Acore.Battleground;
			player: Acore.Player;
			winnerTeamId: TeamId;
		};
		['battleground:update']: {
			bg: Acore.Battleground;
			diff: Temporal.Duration;
		};
		['battleground:add-player']: {
			bg: Acore.Battleground;
			player: Acore.Player;
		};
		['battleground:before-add-player']: {
			bg: Acore.Battleground;
			player: Acore.Player;
		};
		['battleground:remove-player-at-leave']: {
			bg: Acore.Battleground;
			player: Acore.Player;
		};
	}
}
export {};
