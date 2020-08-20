#ifndef __LIB_STD__
#define __LIB_STD__

#include "heap.h"

int My_Mem_Init(Heap_t *hd,char *Heap,int HeapSize);
void *My_malloc(Heap_t *hd, CPU_INT32U length  );
void My_free(Heap_t *hd, void *pv );
void *My_realloc(Heap_t *hd,void *rmem, CPU_INT32U newsize);

#endif

