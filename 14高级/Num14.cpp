/* 第十四章  */

#include <stdio.h>

void test(){
	printf("仅用于测试");
	getchar();
}

void d_14_4()	//用线程变成
{
	//threads.h 头文件提供了一些关于线程的类型与工具
}
#include <ThrdBase.h>
int get_data(void *data);

void d_14_4_1()	//创建线程
{
	//int thrd_create(thrd_t *thr,thrd_start_t func,void *arg);
	//						类型存储线程的标识符
	//								指向函数的指针 int(*)(void*)
	//												调用函数传递的变元地址
}
int get_data(void *data)
{
	return 0;
}

void main()
{
	test();
}
