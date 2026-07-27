declare global {
	namespace Acore {
		class MailSender {
			constructor(messageType: MailMessageType, sender: number, stationery?: MailStationery);

			readonly messageType: MailMessageType;
			// creature's entry,
			// game object's entry,
			// player's ObjectGuid's counter,
			// {@link AuctionHouseId}, or
			// calendar entry's id (truncated to 32 bits for some reason)
			readonly senderId: number;
			readonly stationery: MailStationery;

			static forCreature(entry: number, stationery?: MailStationery): MailSender;
			static forPlayer(guid: ObjectGuid, stationery?: MailStationery): MailSender;
			static forGameObject(entry: number, stationery?: MailStationery): MailSender;
			static forAuctionHouse(id: AuctionHouseId, stationery?: MailStationery): MailSender;
			static forCalendarEvent(entry: number, stationery?: MailStationery): MailSender;
		}
	}
}
export {};
