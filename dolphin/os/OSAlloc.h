#pragma once

namespace os {

	typedef int OSHeapHandle;
	typedef void (*OSAllocVisitor)(
		void* obj,
		u32 size);

	void* OSInitAlloc(
		void* arenaStart,
		void* arenaEnd,
		int maxHeaps);

	OSHeapHandle OSCreateHeap(
		void* start,
		void* end);
	void OSDestroyHeap(
		OSHeapHandle heap);
	void OSAddToHeap(
		OSHeapHandle heap,
		void* start,
		void* end);

	OSHeapHandle OSSetCurrentHeap(
		OSHeapHandle heap);

	void* OSAllocFromHeap(
		OSHeapHandle heap,
		u32 size);
	void* OSAllocFixed(
		void** rstart,
		void** rend);
	void OSFreeToHeap(
		OSHeapHandle heap,
		void* ptr);

	long OSCheckHeap(
		OSHeapHandle heap);
	void OSDumpHeap(
		OSHeapHandle heap);
	u32 OSReferentSize(
		void* ptr);

	void OSVisitAllocated(
		OSAllocVisitor visitor);

	extern volatile OSHeapHandle __OSCurrHeap;

/*---------------------------------------------------------------------------*
  Name:         OSAlloc

  Description:  Allocates /size/ bytes from current heap

  Arguments:    size        size of object to be allocated.

  Returns:      a null pointer or a pointer to the allocated space aligned
                with 32 bytes boundaries
 *---------------------------------------------------------------------------*/
#define OSAlloc(size) OSAllocFromHeap(__OSCurrHeap, (size))

/*---------------------------------------------------------------------------*
  Name:         OSFree

  Description:  Deallocates /ptr/ to current heap.

  Arguments:    ptr         non-NULL pointer to object previously allocated
                            by OSAlloc() or OSAllocFromHeap().

  Returns:      None.
 *---------------------------------------------------------------------------*/
#define OSFree(ptr) OSFreeToHeap(__OSCurrHeap, (ptr))
}