#include "lib_std.h"
#include <string.h>

int My_Mem_Init(Heap_t *hd,char *Heap,int HeapSize)
{
	if(Heap == NULL)return -1;
	memset(hd,0,sizeof(Heap_t));
    system_heap_init(hd,(CPU_INT32U)Heap,(CPU_INT32U)Heap+HeapSize);
    return 0;
}

void *My_malloc(Heap_t *hd,CPU_INT32U length )
{
    void *pv;	
    pv = pvPortMalloc(hd,length);
    return pv;
}

void My_free(Heap_t *hd, void *pv )
{
    vPortFree(hd,pv);
    return;
}


void *My_realloc(Heap_t *hd,void *rmem, CPU_INT32U newsize)
{
    void *pv;
    pv = vPortRealloc(hd,rmem,newsize);
    return pv;
}
