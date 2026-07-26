#include <optional>
#include <v8-local-handle.h>
#include <v8-template.h>

#include "ByteBuffer.h"
#include "CtoJ.h"
#include "JtoC.h"
#include "NodePropertySystem.h"
#include "WorldPacket.h"

JVAL_CVAL_TMPLS_RW(WorldPacket)

template<>
v8::Local<v8::FunctionTemplate> jcreate_template<WorldPacket *>() {
	TypedTemplate<WorldPacket *> const ft = jctor([](std::optional<uint16_t> opcode, std::optional<size_t> res) {
		if (!opcode) {
			return new WorldPacket();
		}
		return new WorldPacket(*opcode, res.value_or(200));
	});

	ft->SetClassName(jstr_intern("WorldPacket"));
	ft.safe_inherit<ByteBuffer *>();

	reg_prop_ro(ft, "opcode", [](WorldPacket * pkt) {
		return pkt->GetOpcode();
	});

	reg_prop(ft, "opcode",
		[](WorldPacket * pkt) { return pkt->GetOpcode(); },
		[](WorldPacket * pkt, uint16_t const val) { pkt->SetOpcode(val); }
	);
	return ft;
}
