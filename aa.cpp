#include "stdio.h"
main(void){
	float a;
	printf( "数据排列\n\n");
	printf("请输入相关的数据：");
	scanf("%f",&a);
	printf("输出的数据：%-80.5s\n",a);
} 
