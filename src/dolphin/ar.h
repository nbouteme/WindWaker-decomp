#pragma once

#include <doltypes.h>

namespace ar {

	/*---------------------------------------------------------------------------*
 * Definitions
 *---------------------------------------------------------------------------*/

#define AR_STACK_INDEX_ENTRY_SIZE sizeof(u32)

#define ARAM_DIR_MRAM_TO_ARAM 0x00
#define ARAM_DIR_ARAM_TO_MRAM 0x01

#define AR_CLEAR_INTERNAL_ALL 0x00
#define AR_CLEAR_INTERNAL_USER 0x01
#define AR_CLEAR_EXPANSION 0x02

	/*---------------------------------------------------------------------------*
 * Types/Declarations
 *---------------------------------------------------------------------------*/
	typedef void (*ARCallback)(void);

	/*---------------------------------------------------------------------------*
 * Globals
 *---------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------*
 * Function Prototypes
 *---------------------------------------------------------------------------*/

	ARCallback ARRegisterDMACallback(ARCallback callback);
	u32 ARGetDMAStatus(void);
	void ARStartDMA(u32 type, u32 mainmem_addr, u32 aram_addr, u32 length);
	u32 ARInit(u32* stack_index_addr, u32 num_entries);
	u32 ARGetBaseAddress(void);
	BOOL ARCheckInit(void);
	void ARReset(void);
	u64 ARAlloc(u32 length);
	u32 ARFree(u32* length);
	u32 ARGetSize(void);
	u32 ARGetInternalSize(void);
	void ARSetSize(void);
	void ARClear(u32 flag);

	void __ARClearInterrupt(void);
	u16 __ARGetInterruptStatus(void);

	/*---------------------------------------------------------------------------*
 * Macro definitions
 *---------------------------------------------------------------------------*/

#define ARStartDMARead(mmem, aram, len) ARStartDMA(ARAM_DIR_ARAM_TO_MRAM, mmem, aram, len)
#define ARStartDMAWrite(mmem, aram, len) ARStartDMA(ARAM_DIR_MRAM_TO_ARAM, mmem, aram, len)

/*---------------------------------------------------------------------------*
    misc defines
 *---------------------------------------------------------------------------*/
#define ARQ_DMA_ALIGNMENT 32		 // byte alignment for ARAM DMA
#define ARQ_CHUNK_SIZE_DEFAULT 4096	 // default chunk size after init

/*---------------------------------------------------------------------------*
    ARQ type definitions for DMA direction
 *---------------------------------------------------------------------------*/
#define ARQ_TYPE_MRAM_TO_ARAM ARAM_DIR_MRAM_TO_ARAM
#define ARQ_TYPE_ARAM_TO_MRAM ARAM_DIR_ARAM_TO_MRAM

/*---------------------------------------------------------------------------*
    ARQ priority definitions for DMA request
 *---------------------------------------------------------------------------*/
#define ARQ_PRIORITY_LOW 0
#define ARQ_PRIORITY_HIGH 1

	/*---------------------------------------------------------------------------*
    ARQ callback interface
 *---------------------------------------------------------------------------*/
	typedef void (*ARQCallback)(void* pointerToARQRequest);

	/*---------------------------------------------------------------------------*
    ARQRequest definition
 *---------------------------------------------------------------------------*/
	typedef struct ARQRequest {
		struct ARQRequest* next;  // pointer to next in list
		u32 owner;				  // user enumerated owner id
		u32 type;				  // DMA direction
		u32 priority;			  // priority for transaction
		u64 source;				  // address of source TODO: change to 64 bits
		u64 dest;				  // address of destination TODO: change to 64 bits
		u64 length;				  // length in bytes
		ARQCallback callback;	  // user specified callback routine

	} ARQRequest;

	/*---------------------------------------------------------------------------*
    function prototypes
 *---------------------------------------------------------------------------*/
	void ARQInit(void);
	void ARQReset(void);
	void ARQPostRequest(ARQRequest* task,
						u32 owner,
						u32 type,
						u32 priority,
						u64 source, // TODO: change to 64 bytes
						u64 dest, // TODO: change to 64 bytes
						u64 length,
						ARQCallback callback);
	void ARQRemoveRequest(ARQRequest* task);
	void ARQRemoveOwnerRequest(u32 owner);
	void ARQFlushQueue(void);
	void ARQSetChunkSize(u32 size);
	u32 ARQGetChunkSize(void);
	BOOL ARQCheckInit(void);

}