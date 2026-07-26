declare global {
	const __opaque : unique symbol;

	type ObjectGuidNative = {
		[__opaque]: 'This type is opaque. Use Acore.decodeGuid() if you need its sub-components.',
	}
	type ObjectGuidDecoded = [type: HighGuid, entry: number, counter: number];
	type ObjectGuid = ObjectGuidNative | ObjectGuidDecoded;

	interface Position {
		x: number;
		y: number;
		z: number;
		o: number;
	}

	interface Homebind {
		mapId: number;
		areaId: number;
		x: number;
		y: number;
		z: number;
	}

	interface Box<T> {
		boxed: T;
	}

	interface GlyphPropertiesEntry {
		id: number;
		spellId: number;
		typeFlags: number;
		// spellIconID: number;                                      // GlyphIconId (SpellIcon.dbc)
	}
}
export {};
