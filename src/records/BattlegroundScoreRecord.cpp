#include <string>
#include <v8-local-handle.h>

#include "BattlegroundAB.h"
#include "BattlegroundAV.h"
#include "BattlegroundEY.h"
#include "BattlegroundIC.h"
#include "BattlegroundSA.h"
#include "BattlegroundScore.h"
#include "BattlegroundWS.h" // filename is WS, but everything else is WG
#include "CtoJ.h"
#include "NodeJPropHelpers.h"
#include "ObjectGuid.h"

template<>
[[nodiscard]] v8::Local<v8::Value> jval<BattlegroundScore const *>(BattlegroundScore const * score) {
	auto const result = jobj(
		jprop("playerGuid", score->GetPlayerGuid()),
		jprop("killingBlows", score->GetKillingBlows()),
		jprop("damageDone", score->GetDamageDone()),
		jprop("healingDone", score->GetHealingDone()),
		jprop("deaths", score->GetDeaths()),
		jprop("honorableKills", score->GetHonorableKills()),
		jprop("bonusHonor", score->GetBonusHonor())
	);

	if (auto const score_ab = dynamic_cast<BattlegroundABScore const *>(score)) {
		jobj_set(result,
			jprop("type", "AB"),
			jprop("basesAssaulted", score_ab->GetBasesAssaulted()),
			jprop("basesDefended", score_ab->GetBasesDefended())
		);
	} else if (auto const score_av = dynamic_cast<BattlegroundAVScore const *>(score)) {
		jobj_set(result,
			jprop("type", "AV"),
			jprop("graveyardsAssaulted", score_av->GetGraveyardsAssaulted()),
			jprop("graveyardsDefended", score_av->GetGraveyardsDefended()),
			jprop("towersAssaulted", score_av->GetTowersAssaulted()),
			jprop("towersDefended", score_av->GetTowersDefended()),
			jprop("minesCaptured", score_av->GetMinesCaptured())
		);
	} else if (auto const score_ey = dynamic_cast<BattlegroundEYScore const *>(score)) {
		jobj_set(result,
			jprop("type", "EY"),
			jprop("flagCaptures", score_ey->GetFlagCaptures())
		);
	} else if (auto const score_ic = dynamic_cast<BattlegroundICScore const *>(score)) {
		jobj_set(result,
			jprop("type", "IC"),
			jprop("basesAssaulted", score_ic->GetBasesAssaulted()),
			jprop("basesDefended", score_ic->GetBasesDefended())
		);
	} else if (auto const score_sa = dynamic_cast<BattlegroundSAScore const *>(score)) {
		jobj_set(result,
			jprop("type", "SA"),
			jprop("basesAssaulted", score_sa->GetDemolishersDestroyed()),
			jprop("basesDefended", score_sa->GetGatesDestroyed())
		);
	} else if (auto const score_wg = dynamic_cast<BattlegroundWGScore const *>(score)) {
		jobj_set(result,
			jprop("type", "WG"),
			jprop("basesAssaulted", score_wg->GetFlagCaptures()),
			jprop("basesDefended", score_wg->GetFlagReturns())
		);
	}

	return result;
}

template<>
[[nodiscard]] v8::Local<v8::Value> jval<BattlegroundScore *>(BattlegroundScore * score) {
	return jval<BattlegroundScore const *>(score);
}
