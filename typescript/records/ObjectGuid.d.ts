declare const __opaque : unique symbol;

declare global {
	type ObjectGuidNative = {
		[__opaque]: 'This type is opaque. Use Acore.decodeGuid() if you need its sub-components.',
	}
	type ObjectGuidDecoded = [type: HighGuid, entry: number, counter: number];
	type ObjectGuid = ObjectGuidNative | ObjectGuidDecoded;
}
export {};
