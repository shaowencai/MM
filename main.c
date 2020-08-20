#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#include "lib_std.h"

int main()
{
	void *ptr[16];
	Heap_t hd;
	int i = 0;
	char buf[1024];
	
	My_Mem_Init(&hd,buf,sizeof(buf));
	
	My_malloc(&hd,1);
	printf("开始内存字节数：%d\r\n",hd.xFreeBytesRemaining);
	
	for(i=0;i<16;i++)
	{
		ptr[i] = My_malloc(&hd,4*(i+1));
	
		printf("%x\r\n",ptr[i]);
		printf("%d\r\n",hd.xFreeBytesRemaining);
	}
	
	printf("1111111111111111111\r\n");
	
	for(i=0;i<16;i++)
	{
		My_free(&hd,ptr[i]);

		printf("%d\r\n",hd.xFreeBytesRemaining);
	}
	
	printf("2222222222222222222\r\n");
	
	ptr[0] = My_malloc(&hd,800);

	printf("%x\r\n",ptr[0]);
	printf("%d\r\n",hd.xFreeBytesRemaining);
	
	ptr[1] = My_malloc(&hd,180);

	printf("%x\r\n",ptr[1]);
	printf("%d\r\n",hd.xFreeBytesRemaining);
	
	My_free(&hd,ptr[0]);
	My_free(&hd,ptr[1]);
	printf("结束内存字节数：%d\r\n",hd.xFreeBytesRemaining);
	return 1;
}
