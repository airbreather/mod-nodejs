declare global {
	namespace Acore {
		class MailDraft {
			constructor(subject: string, text: string);

			addMoney(money: number): MailDraft;
			addCOD(money: number): MailDraft;
			addItem(item: Item): MailDraft;
			createAndAddItem(entry: number, amount?: number): ObjectGuid;
			send(receiver: ObjectGuid, sender: MailSender, checked?: MailCheckedMask, deliverDelay?: number, customExpiration?: number): void;
			sendReturnToSender(senderAccount: number, sender: ObjectGuid, receiver: ObjectGuid): void;
		}
	}
}
export {};
