/* 指针 */
#include <stdio.h>
#include <stddef.h>		//通常如果编译器无法识别NULL的时候  引用此文件头就可以了

void test()	//仅用于测试
{
	printf("测试");
	getchar();
}

void d_7_1_2()	//声明指针
{
	int number = 5;
	int *p_number = &number;	//注意初始化指针的时候一定要初始化  否则会很危险

	printf("int变量number的地址：%p\t int指针*p_number的地址：%p\n", &number, &p_number);
	printf("int变量number的值：%d\t int指针*p_number的值：%p\n", number, p_number);

	getchar();
}

void d_7_1_3()	//使用指针
{
	int number = 5;
	printf("源数据为：%d", number);
	int *p_number = &number;
	*p_number += 10;
	printf("修改指针内容后为：%d", number);
	getchar();
}

void d_7_1_3_2()	//使用指针接收数据
{
	int number = 0;
	int * p_number = &number;
	scanf_s("%d", p_number);
	printf("%d", number);
	getchar();
	getchar();
}

void d_7_1_4()	//指针常量的使用
{
	int value = 5;
	const int *p_value = &value;
	//*p_value += 10;		//修改指针常量对应值的时候 是无法修改的
	printf("%d\n", *p_value);

	int number = 30;
	p_value = &number;		//指针常量的值可以被改变
	printf("%p\n", p_value);
	getchar();
}

void d_7_1_5()	//常量指针
{
	int value = 5;
	int number = 10;
	int *const p_value = &value;//常量指针	注意定义方式  *const 变量名
	printf("%p\n", p_value);
	//p_value = &number;		//常量指针无法修改指针所指的地址
	printf("%p", p_value);
	getchar();
}

void d_7_1_6()	//命名
{
	//通常用格式为  p+变量名
}

void d_7_2()	//数组与指针
{
	char data[50] = "this is my demo";
	printf("数据data[0]所对应的地址：%p\n", &data[0]);
	char *p_data = data;
	printf("数据data所对应的地址：%p", p_data);
	getchar();
}

void d_7_2_2()	//续
{
	int number = 6;
	char data[50] = "this is my demo";
	char *p_data = data;
	p_data += number;	//地址+6
	printf("%c", *p_data);//输出改地址上的元素
	getchar();
}

void d_7_3()	//多维数组
{
	int data[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	printf("数组data的地址：%p\n", data);
	printf("数组data[0]的地址：%p\n", data[0]);
	printf("数组data[0][0]的地址：%p\n", &data[0][0]);

	//说明 多维数组的地址是第一个元素的地址  和 一维数组是一样的
	getchar();
}

void d_7_3_t_2()	//多维数组续
{
	int data[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	for (int i = 0;i<9;i++){
		printf("\n%d",*(*data+i));//因为里层的一维数组也是地址  所以取得数据地址对应的值  取得元素地址   
	}
	getchar();
}

void d_7_3_1()	//多维数组和指针
{
	int data[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	int *p_data = *data;//获取一维数据地址
	for (int i = 0;i<9;i++){
		printf("%d\n",*(p_data+i));
	}
	getchar();
}

void main()
{
	d_7_3_1();
}