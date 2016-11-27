/* 第九章 再谈函数 */

#include <stdio.h>
#include <stdarg.h>		//用于可变参数函数
#include <stdlib.h>

void test()
{
	printf("仅用于测试");
	getchar();
}

void d_9_1_1()	//函数指针
{
	int				(*pfunction) (int);	//函数指针的定义,她更类似于变量
	//	返回值类型		指针名称	参数类型
}

int sum(int a,int b);//函数原型
int product(int a,int b);
int difference(int a,int b);
int any_function(int (*pf_fun) (int,int),int a,int b);

void d_9_1_2()	//函数指针的调用
{
	int (*pf_fun) (int,int);//函数指针
	pf_fun=sum;
	printf("1+1=%d\n",pf_fun(1,1));
	pf_fun=product;
	printf("1*1=%d\n",pf_fun(1,1));
	pf_fun=difference;
	printf("1-1=%d\n",pf_fun(1,1));
	getchar();
}

void d_9_1_3()	//函数指针数组
{
	int (*pf_fun[3]) (int,int);
	pf_fun[0]=sum;
	pf_fun[1]=product;
	pf_fun[2]=difference;
	printf("1+1=%d\n",pf_fun[0](1,1));
	printf("1*1=%d\n",pf_fun[1](1,1));
	printf("1-1=%d\n",pf_fun[2](1,1));
	getchar();

}

void d_9_1_4()	//function pointer for parameter (用于参数的函数指针)
{
	int (*pf_fun) (int ,int);
	pf_fun=sum;
	printf("1+1=%d\n",any_function(pf_fun,1,1));
	pf_fun=product;
	printf("1*1=%d\n",any_function(pf_fun,1,1));
	pf_fun=difference;
	printf("1-1=%d\n",any_function(pf_fun,1,1));
	getchar();
}

int any_function(int (*pf_fun) (int,int),int a,int b)
{
	return pf_fun(a,b);
}

int sum(int a,int b)
{
	return a+b;
}
int product(int a,int b)
{
	return a*b;
}
int difference(int a,int b)
{
	return a-b;
}

void d_2_t1();
void d_2_t2();

void d_9_2()	//函数中的变量
{
	for(int i=0;i<5;i++)
	{
		d_2_t1();
		d_2_t2();	//使用了静态变量
	}
	getchar();
}

void d_2_t1()
{
	int count=0;
	printf("test1:%d\n",count);
	count++;
}
void d_2_t2()
{
	//静态变量不会随着方法结束而释放内存
	//直到程序结束后才会释放掉
	static int count=0;		//使用关键字static
	printf("test2:%d\n",count);
	count++;
}


int count_2_2=0;	//global variable
void d_2_2_t1()
{
	printf("test1:%d\n",count_2_2);
	count_2_2++;
}
void d_2_2_t2()
{
	//静态变量不会随着方法结束而释放内存
	//直到程序结束后才会释放掉
	static int count_2_2=0;		//使用关键字static 
	printf("test2:%d\n",count_2_2);
	count_2_2++;
}


void d_9_2_2()	//global variable 全局变量
{
	for(int i=0;i<5;i++){
		d_2_2_t1();
		d_2_2_t2();
	}
	getchar();
}


int numbers=1;
void d_9_3_t(int number);

void d_9_3()	//递归
{
	//利用递归获得一个数的阶乘
	//阶乘 1到这个数之间所有数的乘机（包含此数）
	int number=0;
	printf("请输入要计算阶乘的数字\n");
	scanf_s("%d",&number);
	d_9_3_t(number);
	printf("该数字的阶乘：%d",numbers);
	getchar();
}

void d_9_3_t(int number)
{
	static int count=1;
	numbers*=count;
	if(count<number){
		count++;
		d_9_3_t(number);	//调用自己
	}
}

double average(double v1,double v2,...);

void d_9_4()	//可变参数个数方法定义
{
	printf("average=%.2lf",average(1.1,2.2,3.3,4.0,5.5,0.0));
	getchar();
}

void d_9_4_1()	//变元数组的复制
{
	va_list parg;
	va_list copy_parg;
	//va_copy(copy_parg,parg);//拷贝原地址到新地址
}

double average(double v1,double v2,...)
{
	double sum=v1+v2;		//变元总和
	double value=0.0;		//。。。中变元值
	int count=2;			//变元个数

	va_list parg;			//变元列表指针
	va_start(parg,v2);		//列表起始位置
	while((value=va_arg(parg,double))!=0.0)	//循环获取下一个变元值	注意这里最后一个参数必须时0.0
	{
		sum+=value;
		++count;
	}
	va_end(parg);			//变元列表结束
	return sum/count;
}

void d_9_5()	//main函数
{
	//main函数时程序的入口
	//可带有两个参数或者无参数两种
	//有参数的时候
	//参数一：int类型 最大为3 最小为1
	//参数二:三个地址分别指向程序名称，二三都是命令行变元且都为char*类型
}

void d_9_6()	//结束程序
{
	//在stdlib.h头文件中
	abort();	//清空输出缓冲区，关闭打开的流
	exit(EXIT_SUCCESS);	//正常关闭程序，清空缓冲区，使用完流后关闭流，放回主机控制权
	atexit(d_9_5);//关闭时调用函数	参数函数名
	//_Exit(1);	//正常关闭程序 不调用任何已注册的函数
	/*quick_exit(d_9_5);
	at_quick_exit(d_9_5);*/
}

void d_9_7_1()	//性能
{

}

void d_9_9()	//设计
{

}

double power(double x,int n);//x的n次方

void d_9_10()	//练习
{
t1:
	double num=power(5.0,2);
	printf("5的2次方：%.2lf",num);

	getchar();
}
double power(double x,int n)
{
	static int count=1;
	static double num =1;
	num*=x;
	if(count<n)
	{
		count++;
		power(x,n);
	}
	return num;
}

double subtract_t_2(double a,double b);	//a-b+c-d+... 奇数加  偶数减
double array_op(double array[],size_t size,double (*pfun) (double,double));
void d_9_10_2()
{
	//基本上其他都是循环调用就好  只有减法稍有改变
	double (*pfun)(double,double);
	pfun=subtract_t_2;
	size_t size=5;
	double array[]={1.0,2.0,3.0,4.0,5.0};
	printf("%.2lf",array_op(array,size,pfun));
	getchar();
}
double array_op(double array[],size_t size,double (*pfun) (double,double))
{
	double sum=0;
	for(int i=0;i<size;i++)
	{
		sum=pfun(sum,array[i]);
	}
	return sum;
}
double subtract_t_2(double a,double b)
{
	static int count=0;
	count++;
	if(count%2)
	{
		return a-b;
	}else{
		return a+b;
	}
}

#include <string.h>

char* MoreToOne_str(char *List[],size_t count);

void d_9_10_3()	//习题三
{
	//TODO：代码未完
	int count=5;
	char **str_list=(char**)calloc(count,sizeof(char*));
	char *str=(char*)calloc(100,sizeof(char));
	int str_count=0;

	while(true)
	{
		if(!fgets(str,100,stdin))
		{
			printf("输入有误");
			free(str_list);
			**str_list=NULL;
		}
		if(!strcmp(str,"exit\n"))
		{
			break;
		}
		if(str_count==count)
		{
			++count;
			char **temp=(char**)realloc(str_list,count*sizeof(char*));
			str_list=temp;
		}
		str_list[str_count]=(char*)calloc(100,sizeof(char));
		strcpy_s(str_list[str_count],100*sizeof(char),str);
		str_count++;
	}

	for(int i=0;i<count;i++)
	{
		printf("%s",str_list[i]);
	}
	getchar();
}
char* MoreToOne_str(char *List[],size_t count)
{
	char *str=NULL;
	for(int i=0;i<count;i++)
	{
		strcat_s(str,sizeof(str),List[i]);
	}
}

void main()
{
	d_9_10_3();
}