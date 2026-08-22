#ifndef DEFERRED_FIELD
#include <cstdint>
#define DEFERRED_FIELD(field) uint32_t field##_offset, field##_size
#define DEFERRED_ARGS(struct,field) (struct).field##_offset, (struct).field##_size
#endif
