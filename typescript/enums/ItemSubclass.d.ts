declare global {
	type ItemSubclass =
		| ItemSubclassArmor
		| ItemSubclassConsumable
		| ItemSubclassContainer
		| ItemSubclassGem
		| ItemSubclassGeneric
		| ItemSubclassGlyph
		| ItemSubclassJunk
		| ItemSubclassKey
		| ItemSubclassMoney
		| ItemSubclassPermanent
		| ItemSubclassProjectile
		| ItemSubclassQuest
		| ItemSubclassQuiver
		| ItemSubclassReagent
		| ItemSubclassRecipe
		| ItemSubclassTradeGoods
		| ItemSubclassWeapon
		;
	// mod-nodejs invention
	type ItemSubclassMask =
		| ItemSubclassMaskArmor
		| ItemSubclassMaskConsumable
		| ItemSubclassMaskContainer
		| ItemSubclassMaskGem
		| ItemSubclassMaskGeneric
		| ItemSubclassMaskGlyph
		| ItemSubclassMaskJunk
		| ItemSubclassMaskKey
		| ItemSubclassMaskMoney
		| ItemSubclassMaskPermanent
		| ItemSubclassMaskProjectile
		| ItemSubclassMaskQuest
		| ItemSubclassMaskQuiver
		| ItemSubclassMaskReagent
		| ItemSubclassMaskRecipe
		| ItemSubclassMaskTradeGoods
		| ItemSubclassMaskWeapon
		;
}
export {};
