/* 第十章 输入输出 这一章非常没有意思*/
#include <stdio.h>
#include <stdlib.h>

void test()
{
	printf("仅用于测试");
	getchar();
}

void d_10_1()
{
	//输入输出流：字符流，文件流，二进制流
}

void d_10_2()
{
	//在stdio.h头文件中 包含三个标准流
	//stdin		stdout					stderr
	//键盘		命令行上正常输出		命令行上的错误输出
	//使用操作系统命令可以将stdin和stdout重定向到文件上
}

void d_10_3()	//键盘输入
{
	//stdin的键盘输入有两种形式
	//scanf_s(scanf的安全版本)		getchar()
}

void d_10_3_1()	//格式化键盘输入
{
	double var;
	char str[]="%lf";	//double类型
	scanf_s(str,&var);	//函数返回int类型值
}

void d_10_3_2()		//输入格式控制字符串
{
	//scanf_s 函数会忽略输入的空白字符  直接读取下一个非空白字符（除使用%C %[] %n除外）
	//scanf_s 忽略分隔各值的逗号
	//一般格式	
	//%			*						field_width			
	//			可选（忽略下一个值）	读入字符数（可选）	
	//长度修饰符			conversion_character
	//h hh l L ll j z t
}
void d_10_3_3()	//输入格式字符串中的字符
{
	int i=0;
	int j=0;
	int z=0;
	int value_count=0;
	printf("请按以下格式输入：\n i=1 j=2 3\n");
	value_count=scanf_s("i=%d j=%d %d",&i,&j,&z);
	printf("共有%d个数组被录入\n",value_count);
	printf("i=%d j=%d %d",i,j,z);
	fflush(stdin);
	getchar();
}

void d_10_3_4()	//输入浮点数的各种变化
{
	printf("请输入浮点数格式如下：\n3.14.314E1.0314E+2\n");
	float f1=0;
	float f2=0;
	float f3=0;

	scanf_s("%f%f%f",&f1,&f2,&f3);
	printf("f1=%f\nf2=%f\nf3=%f",f1,f2,f3);
	fflush(stdin);
	getchar();

}
void d_10_3_5()	//读取十六进制和八进制
{
	//这里只是接收注意格式
	int i=0;
	int j=0;
	int z=0;
	scanf_s("%d %x %o",&i,&j,&z);
	printf("全部转为10进制输出\ni=%d\tj=%d\tz=%d",i,j,z);
	fflush(stdin);
	getchar();
}
void d_10_3_6()	//使用scanf读取字符
{
	char name_f='a';
	char name[50]={' '};
	char age[4]={' '};
	printf("请输入您名字的首个字母\n");
	scanf_s("%c",&name_f);
	printf("请输入您的名字\n");
	scanf_s("%s",name,sizeof(name));
	if(name_f==name[0])
	{
		printf("请输入您的年龄\n");
		scanf_s("%[0123456789]",age);
	}else{
		printf("名字首字母与名字不符");
	}
	fflush(stdin);
	printf("name=%s\tage=%s",name,age);
	getchar();
}
void d_10_3_7()	//从键盘上输入字符串
{
	char *name=(char*)calloc(100,sizeof(char));
	printf("请输入您的名字\n");
	gets_s(name,100*sizeof(char));
	printf("name=%s",name);
	fflush(stdin);
	getchar();

}

void d_10_4()	//屏幕输出
{
	printf("屏输入");
	printf_s("屏幕输出");	//主要防止%n将数据写入内存
}

void d_10_4_3()	//整数输出
{
	int a=3; long long lb=1235ll;
	printf("a=%d\tlb=%lld",a,lb);
	getchar();
}

void d_10_4_3_2()	//单一数据的变化
{
	int a=678;
	printf("十进制：%d\t 十六进制：%x\t 八进制：%o",a,a,a);
	getchar();
}

void d_10_4_4()	//浮点数
{
	float fa=3.14;
	printf("浮点数:%f",fa);
	getchar();
}

#include <limits.h>

void d_10_4_5()	//输出字符
{
	for(int i=0;i<=CHAR_MAX;i++)
	{
		printf("\t%c",i);
	}
	getchar();
}

void d_10_5()	//其他输出函数
{
	puts("this is my demo");//只能使用常量
	getchar();
}

void d_10_5_1()	//屏幕的非格式化输出
{
	char name[50]="my name is \n wang xiao si ";
	printf("%s",name);
	int i=0;
	printf("\n");
	while(name[i]!='\0')
	{
		if(name[i]!='\n')
		{
			putchar(name[i]);
		}
		i++;
	}
	getchar();
}
void d_10_5_2()	//数组的格式化输出
{
	char data[50];
	int count=4;

	int size_data=_snprintf_s(data,sizeof(data),"一只狗有%d条腿，公狗再加一条",count);
	if(size_data>0)
	{
		printf("%s",data);
	}else{
		printf("格式化数据出错");
	}
	getchar();
}

void d_10_7()	//习题
{
t2:
	int a,b,c,d;
	scanf_s("%*[ ,$]%d,%*[ ,$]%d,%*[ ,$]%d,%*[ ,$]%d",a,b,c,d);//vs2013报错
	printf("数据总和为：%d",a+b+c+d);
	getchar();

}

void main()
{
	d_10_7();
}
