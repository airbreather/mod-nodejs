declare global {
	namespace Acore {
		class Item extends ACObject {
			readonly isBoundAccountWide: boolean;
			readonly isBoundByEnchant: boolean;
			readonly isLocked: boolean;
			readonly isBag: boolean;
			readonly isCurrencyToken: boolean;
			readonly isNotEmptyBag: boolean;
			readonly isBroken: boolean;
			readonly isInTrade: boolean;
			readonly isInBag: boolean;
			readonly isEquipped: boolean;
			readonly isPotion: boolean;
			readonly isWeaponVellum: boolean;
			readonly isArmorVellum: boolean;
			readonly isConjuredConsumable: boolean;
			readonly isRefundExpired: boolean;
			readonly maxStackCount: number;
			readonly slot: number;
			readonly bagSlot: number;
			readonly template: ItemTemplateNarrowable;
			readonly bagSize: number;
			ownerGuid: ObjectGuid;
			count: number;
			isSoulBound: boolean;

			hasQuest(questId: number): boolean;
			getEnchantmentId(slot: EnchantmentSlot): number;
			canBeTraded(mail?: boolean, trade?: boolean): boolean;
			isBindedNotWith(player: Player): boolean;
			getItemLinkText(locale?: LocaleConstant): string;
			setEnchantment(slot: EnchantmentSlot, enchantmentId: number, duration: number, charges: number, caster?: ObjectGuid): boolean;
			clearEnchantment(slot: EnchantmentSlot): boolean;
			setRandomProperties(prop: number): void;
			setRandomSuffix(suffix: number): void;
			save(): void;
		}
	}
}
export {};
