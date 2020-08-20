#ifndef  _USER_HEAP_
#define  _USER_HEAP_

#include <stdint.h>

typedef int32_t CPU_INT32U;
typedef int8_t CPU_INT08U;

#define portBYTE_ALIGNMENT					8 //8字节对齐
#define portBYTE_ALIGNMENT_MASK 			( 0x0007 )

#define heapMINIMUM_BLOCK_SIZE				( ( CPU_INT32U ) ( xHeapStructSize << 1 ) )

#define heapBITS_PER_BYTE					( ( CPU_INT32U ) 8 )

//typedef unsigned int                    	size_t;

#define RT_TINY_SIZE

#ifndef NULL
#define NULL                                 0 
#endif

typedef struct A_BLOCK_LINK
{
	struct A_BLOCK_LINK *pxNextFreeBlock;	/*<< The next free block in the list. */
	CPU_INT32U xBlockSize;					/*<< The size of the free block. */
} BlockLink_t;

typedef struct
{
	CPU_INT32U HeapStartAddr;
	CPU_INT32U TOTAL_HEAP_SIZE;
	CPU_INT32U xFreeBytesRemaining;				//目前堆剩余多少字节
	CPU_INT32U xMinimumEverFreeBytesRemaining; 	//在堆的使用历史中剩余最少时的字节数
	CPU_INT32U xBlockAllocatedBit;
	BlockLink_t xStart;
	BlockLink_t *pxEnd;
} Heap_t;

void *pvPortMalloc(Heap_t *hd, CPU_INT32U xWantedSize );
void vPortFree(Heap_t *hd, void *pv );	
void *vPortRealloc(Heap_t *hd, void *pv , CPU_INT32U xWantedSize );
void system_heap_init(Heap_t *hd,CPU_INT32U SA,CPU_INT32U EA);
		
#endif
