declare global {
	interface Hooks {
		['battleground:start']: { readonly bg: Acore.Battleground; };
		['battleground:end']: {
			readonly bg: Acore.Battleground;
			readonly winnerTeamId: TeamId;
		};
		['battleground:create']: { readonly bg: Acore.Battleground; };
		['battleground:destroy']: { readonly bg: Acore.Battleground; };
		['battleground:end-reward']: {
			readonly bg: Acore.Battleground;
			readonly player: Acore.Player;
			readonly winnerTeamId: TeamId;
		};
		['battleground:update']: {
			readonly bg: Acore.Battleground;
			readonly diff: Temporal.Duration;
		};
		['battleground:add-player']: {
			readonly bg: Acore.Battleground;
			readonly player: Acore.Player;
		};
		['battleground:before-add-player']: {
			readonly bg: Acore.Battleground;
			readonly player: Acore.Player;
		};
		['battleground:remove-player-at-leave']: {
			readonly bg: Acore.Battleground;
			readonly player: Acore.Player;
		};
	}
}
export {};
