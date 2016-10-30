/* 该代码为第一章习题 */
#include <stdio.h> //预处理引用 printf函数属于该函数集

int main(void)	//定义主函数
{
	//1.1 用两个 printf函数 输出地址和名字
	printf("习题1.1\n");
	printf("\t姓名：张彩慧");
	printf("\t地址：上海");
	printf("\n\n");
	printf("习题1.2\n");
	printf("\t姓名：张彩慧\n\t地址：上海");
	printf("\n\n");
	printf("习题1.3\n");
	printf("\"It's freezing in here,\"he said coldly");
	getchar();
	return 0;
}