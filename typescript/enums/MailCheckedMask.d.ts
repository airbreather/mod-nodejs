declare global {
	const enum MailCheckedMask {
		MAIL_CHECK_MASK_NONE        = 0x00,
		MAIL_CHECK_MASK_READ        = 0x01,
		MAIL_CHECK_MASK_RETURNED    = 0x02,                     /// This mail was returned. Do not allow returning mail back again.
		MAIL_CHECK_MASK_COPIED      = 0x04,                     /// This mail was copied. Do not allow making a copy of items in mail.
		MAIL_CHECK_MASK_COD_PAYMENT = 0x08,
		MAIL_CHECK_MASK_HAS_BODY    = 0x10,                     /// This mail has body text.
	}
}
export {};
