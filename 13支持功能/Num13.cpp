/* 支持功能 */
#include <stdio.h>

void test()
{
	printf("仅用于测试");
	getchar();
}

void d_13_1()	//预处理
{
	// #include <stdio.h>
}

void d_13_2()	//定义自己的头文件
{
	//通常自定义的头文件中不包含可执行代码
	//只有 函数原型/struct类型定义/符号定义/extern/typedefs
}

void d_13_1_3()	//管理多个源文件
{
	//尽量创建一个适当的文件夹结构
	//而不是让IDE把所有文件放在同一个文件夹中
}

void d_13_1_4()	//外部变量
{
	//extern 将变量声明为外部变量
	//将所有的全局变量放在一个文件的开头，将所有的extern语句放在另一个头文件中
	//使用include语句包含该头文件
}

void d_13_1_5()	//静态函数
{
	//static void add(int num1,int num2)
	//函数只能在定义它的.c文件中调用
}

void d_13_1_6()	//替换程序源代码
{
	//#define PI 3.1415926
	//当定义变量数组长度的时候也可以使用const类型替代define
	//const size_t MAXLEN=256;
}

void d_13_2_0()	//宏
{
	//体会一下吧
	//#define Print(My_var) printf_s("%d",My_var);
}

void d_13_2_1()	//看起来想函数的宏
{
	//宏的作用还是替换
	//#define product(m,n) m*n
	//product(0,1+1)-> 0*1+1
	//可以转变为product(m,n) (m)*(n)
}

void d_13_2_2()	//字符串作为宏参数
{
	//这样使用就略叼啦
	//#define show(var) printf_s(#var"=%d\n",var)
	//show(number);
	//printf_s("number""=%d\n",number);
}

void d_13_2_3()	//在宏展开式中结合两个变元
{
	//define join(a,b) a##b
	//##用来分个参数
	//strnlen_s(join(var,123),sizeof(join(var,123)));
	//strnlen_s(var123,sizeof(var123));
	//常用于组合变量名称
}

void d_13_3()	//多行上的预处理器指令
{
	//多行用续行符 ‘’
	//#define min(x,y) \ 
	//					((x)<(y)?(x):(y))				
}

void d_13_3_2()	//条件编译
{
#if define a
	//如果存在a变量 就会进来
#endif

#if !definde a
	//如果不存在a变量 就会进来
#endif
}

void d_13_3_3()	//测试多个条件
{
#if define a && define b
	//如果存在a和b
#endif
}

void d_13_3_4()	//取消定义的标识符
{
#undef block
}

#define CUP Intel_i7
void d_13_3_5()	//测试标识符的指定值的指令
{
	char *data="";
#if CPU==Intel_i7
	data="处理器：i7处理器";
#endif

#if CPU==Intel_i5
	data="处理器：i5处理器";
#endif
#if CPU==Intel_i3
	data="处理器：i3处理器";
#endif
	printf("%s",data==""?"空":data);
	getchar();
}

void d_13_3_6()	//多项选择
{
#if CUP==Intel_i7
	printf("I7");
#elif CUP==Intel_i5
	printf("I5");
#elif CUP==Intel_i3
	printf("I3");
#endif
	getchar();
}

#include <stdio.h>
void ad_13_3_7()	//标准预处理宏
{
	//__func__	获得代码中表示函数体的函数名
	printf("%s\n",__FUNCTIONW__);//vs2013 不完全支持c99 不能使用__func__
	printf("%s\t%s\n",__DATE__,__TIME__);//时间
	FILE* pfile=NULL;
	char* fileName="D:\\MyDemo\\T13_3_7.txt";
	if(fopen_s(&pfile,fileName,"w"))
	{
		printf("文件：%s\n%s出现错误",__FILE__,__LINE__);//__file__将当前文件名称转为字符串形式，__line__对应当前行号
	}

	getchar();
}

void d_13_4_1()	//调适方法
{
	//集成的调试器
	//1.追踪程序流
	//2.设置断点
	//3.设置观看窗口
	//4.检查程序元素
}
void d_13_4_2()	//调试阶段的预处理器
{
	//利用#if #elif #endif
	//进行判断输出
}

#include <assert.h>
void d_13_4_3()	//断言
{
	//断言是一条错误消息，在满足条件时输出该消息
	//编译器断言和运行期断言
	//assert()//运行期断言
	//属于assert.h头文件 assert(bool) 可包含如何判断语句
	//当判断语句为false时终止程序
	//利用#undef NDEBUG 关闭所有断言功能（必须放在assert.h头文件引用前）

	//编译期断言
	//static_assert(bool,string);true出发并返回string

	int b=5;
	for (int i = 0; i < 10; i++)
	{
		printf("i=%d\tb=%d\n",i,b);
		assert(i<b);
	}
	getchar();
}

void d_13_5_t()	//日期和时间函数
{
	//time.h头文件
}

#include <time.h>
#include <math.h>
#include <ctype.h>
void d_13_5_1()	//获取时间值
{
	//clock_t clock() clock_t 在time.h中定义的整数类型
	//CLOCKS_PER_SEC 一秒内的时钟周期数
	//time_t time(time_t *timer); //19700101 00:00:00  单位秒
	clock_t start=0,end=0;
	double cpu_time=0.0;
	start=clock();
	time_t time_start=time(NULL);
	char IsGoOn='n';
	long long time_num=0;

	while(true)
	{
		for(int i=0;i<10000;i++)
		{
			sqrt(3.1415926);
		}
		printf("是否要继续？(y/n)\n");
		fflush(stdin);
		scanf_s("%c",&IsGoOn,sizeof(char));
		if(toupper(IsGoOn)=='N')
		{
			break;
		}
	}

	time_t time_end=time(NULL);
	end=clock();
	cpu_time=(-start+end)/CLOCKS_PER_SEC;
	printf("%lf\n",cpu_time);
	printf("%lf\n",difftime(time_end,time_start));

	fflush(stdin);

	getchar();
}

#include <stdlib.h>
void d_13_5_2()	//获取日期
{
	//char *ctime(const time_t* timer);	"Mon Aug 25 10:22:23 2016\n\0"
	//errno_t ctime_s(char* str,rsize_t size,const time_t *timer);
	time_t timer=time(NULL);
	char *str=(char*)calloc(100,sizeof(char));
	if(!ctime_s(str,100*sizeof(char),&timer))
	{
		printf("%s",str);
	}else
	{
		printf("转换失败");
	}
	//localtime(const time_t* timer)和localtime_s(const time_t* timer,struct tm* tm)
	//tm 结构说明
	//tm_sec			0-60秒
	//tm_min			0-60分
	//tm_hour			0-23小时
	//tm_mday			0-31天
	//tm_mon			0-11月
	//tm_year			当前-1900
	//tm_wday			星期0-6
	//tm_yday			年0-365
	//tm_isdst			黑白天？？？
	const char *days[]={"星期日","星期一","星期二","星期三","星期四","星期五","星期六"};
	struct tm time_data;
	if(!localtime_s(&time_data,&timer))
	{
		printf("%s\n",days[time_data.tm_wday]);
	}

	getchar();
}

void d_13_5_3()	//确定某一天时星期几
{
	//time_t mktime(struct tm* ptime);
	struct tm data={0};
	data.tm_mday=27;
	data.tm_mon=11;
	data.tm_year=2016-1900;
	time_t getData=mktime(&data);
	char *str=(char*)calloc(100,sizeof(char));
	if(!ctime_s(str,100*sizeof(char),&getData))
	{
		printf("%s",str);
	}else
	{
		printf("转换失败");
	}
	getchar();
}

#define COMPARE(x,y) ((x)<(y)?-1:(x)==(y)?0:1)
void d_13_7_1()	//习题1
{
	printf("%d",COMPARE(11,2));
	getchar();
}

void main()
{
	d_13_7_1();
}