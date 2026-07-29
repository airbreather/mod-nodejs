declare global {
	const enum GuildDefaultRanks {
		// These ranks can be modified, but they cannot be deleted
		GR_GUILDMASTER = 0,
		GR_OFFICER = 1,
		GR_VETERAN = 2,
		GR_MEMBER = 3,
		GR_INITIATE = 4
		// When promoting member server does: rank--
		// When demoting member server does: rank++
	}
}
export {};
