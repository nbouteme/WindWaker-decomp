#include <dolphin/ar.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace ar {
	// TODO: mem allocator in 32 bits area

	u32 ARInit(u32* stack_idx_array, u32 num_entries) {
		puts("Initing AR");
		return 1;
	}

	u32 ARGetSize(void) {
		return 16 * 1024 * 1024;
	}

	void ARQInit() {
		puts("Initing ARQ");
	}

	u64 ARAlloc(u32 length) {
		return (u64)malloc(length);
	}

	void ARQPostRequest(ARQRequest* task,
						u32 owner,
						u32 type,
						u32 priority,
						u64 source,
						u64 dest,
						u64 length,
						ARQCallback callback) {
		memcpy((void*)task->dest, (void*)task->source, length);
		task->callback((void*)task);
	}
}