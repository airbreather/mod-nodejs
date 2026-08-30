declare global {
	type ObjectGuidDecoded = [type: HighGuid, entry: number, counter: number];
	type ObjectGuid = bigint | ObjectGuidDecoded;
}
export {};
