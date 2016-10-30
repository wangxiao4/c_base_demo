/* 第二章代码 */

#include <stdio.h>
#include <limits.h>	//头文件中包含所有类型的极限值
#include <float.h>	//float头文件中包含float浮点数类型的符号 包括极限
#include <stddef.h>	//本项目中用于获取sizeof值 size_t

void index(void)	//只用于测试
{
	printf("测试专用");
	getchar();
}

void d_2_2(void)	//什么是变量
{
	printf("我的工资是 ￥10000\n");
	getchar();
}

void d_2_3(void)	//存储整数的变量
{
	int salary;		//定义一个整数型变量salary（薪水）
	salary=10000;	//给定义的变量赋值
	printf("我的工资是￥ %d \n",salary);	//%d 转换说明符
	getchar();
}

void d_2_3_1(void)	//变量的使用	
{
	int total_pets;
	int cats;
	int dogs;
	int ponies;
	int others;

	cats=2;
	dogs=1;
	ponies=1;
	others=46;

	total_pets=cats+dogs+ponies+others;
	printf("we hava %d pets in total\n",total_pets);
	getchar();
}

void d_2_3_2(void)	//变量的初始化
{
	int cats;		//初始化变量地址
	cats=2;			//给地址赋值
}

//变量与内存
void d_2_4(void)
{
	//有符号整数型
	signed char num1=1234;	//1字节
	short num2=2;	//2字节
	int num3=3;			//4字节
	long num4=4;	//4字节
	long long num5=5;	//8字节

	//无符号整数型
	unsigned char num2_1=1;
	unsigned short int num2_2=2;
	unsigned int num2_3=3;
	unsigned long num2_4=4;
	unsigned long long num2_5=5;
}

void d_2_5(void)
{
	//浮点数
	//浮点类型不能精确的表达10进制中的一些数字 如1/3 由于浮点数存储方式位数限制
	//存储方式 
	//float ： 4字节共32位
	//以为符号位 正0 负1
	//8位指数位
	//23位小数位

	//类型		字节数	取值范围
	//float			4	+-3.4E+-38(精确到6到7位小数)
	//double		8	+-1.7E+-308(精确到15位小数)
	//long double	12	+-1.19E+-4932(精确到18位小数)

	//
}

void d_2_6(void)
{
	//浮点数的声明
	float pai=3.14F;
	double biggest=123E30;
	long double bigbigget=123E30L;
}

void d_2_6_1()//将10分成4等分
{
	float num1=10.0F;
	float num2=4.0F;
	float num3=num1/num2;
	printf("将10分成4等分每一份为 %f",num3);	//%f可以显示浮点数 %.number f 可以控制输出小数的位数
	getchar();
}
void d_2_6_other()
{
	//%-/+[width][.number][modifier]f 可以控制输出的字段宽度
	//-/+:代表左对齐还是右对齐，将f换成d使用
	//width：数据占用显示宽度（一个数字为一个单位），将f换成d使用
	//.number：小数点后的位数
	//当数据类型是long double 的时候modifier为L 其他情况省略
	float num1=3.14159267F;
	printf("要显示的小数:%-15.4f就是前面这个",num1);
	getchar();
}

void d_2_7()//计算一个圆桌的周长和面积
{
	float R=0.0F;
	float PI=3.14F;
	float area=0.0F;
	float circumference=0.0F;

	printf("请输入圆桌的半径：");
	scanf("%f",&R);		//标准库函数 获取输入  &是寻址运算符  类似与赋值运算
	circumference=2*PI*R;
	area=PI*R*R;

	printf("所以圆桌的周长约为%5.5f\r\n所以圆桌的面积约为%5.5f",circumference,area);
	getchar();

}

void d_2_7_other(){
	//关于%
	//格式说明符的开端
	//读取short		%hd
	//读取int		%d
	//读取long		%ld		小写的L
	//读取float		%f或%e
	//读取double	%lf或%le

	//输出整数型	%d
	//输出字符串	%s
	//输出长整型	%ld
	//输出十进制无符号	%u
	//输出浮点数	%f
	//输出单字符	%c
	//输出指针		%p
	//输出指数型浮点数%e
	//十六进制		%x
	//八进制		%0
	//自动匹配		%g
}

//d_2_8	定义命名常量
#define PI 3.1415926F	//定义常量的时候常量名全部大写
void d_2_8()
{
	float R=0.0F;
	float ZhouChang=0.0F;
	float area=0.0F;
	printf("请输入圆桌的半径");
	scanf("%f",&R);
	ZhouChang=2*PI*R;
	area=PI*R*R;
	printf("所以圆桌的周长为%f\n",ZhouChang);
	printf("所以圆桌的面积为%f",area);
	getchar();
}

void d_2_8_Demo_2()
{
	float R=0.0F;
	float ZhouChang=0.0F;
	float area=0.0F;
	const float Pi=3.1415926F;		//可以用const关键字标识该变量是一个固化常量
	//Pi=3.3F;		对固化常量进行修改会报错
	printf("请输入圆桌的半径");
	scanf("%f",&R);
	ZhouChang=2*PI*R;
	area=PI*R*R;
	printf("所以圆桌的周长为%f\n",ZhouChang);
	printf("所以圆桌的面积为%f",area);
	getchar();
}

void d_2_8_1()//极限值
{
	//在limits.h头文件中定义好了所有类型的极限值
	//通常格式为	类型_MIN 和 类型_MAX
	//整数类型
	//char			CHAR_MIN	CHAR_MAX
	//short			SHORT_MIN	SHORT_MAX
	//int			INT_MIN		INT_MAX
	//long			LONG_MIN	LONG_MAX
	//long long		LLONG_MIN	LLONG_MAX

	//所有无符号整数下线都为0 (unsigned)

	//float			FLT_MIN		FLT_MAX
	//double		DBL_MIN		DBL_MAX
	//long double	LDBL_MIN	LDBL_MAX

	//注：FLT_DIG	DBL_DIG	LDBL_DIG	可获得二进制尾数可以表示的小数位数

	printf("char 类型的最小值%-10d最大值%-10d\n",CHAR_MIN,CHAR_MAX);
	printf("unsigned char类型的最小值0\t最大值%-10d\n",UCHAR_MAX);
	printf("short 类型的最小值%-10d最大值%-10d\n",SHRT_MIN,SHRT_MAX);
	printf("unsigned short 类型的最小值0\t最大值%-10d\n",USHRT_MAX);
	printf("int 类型的最小值%-10d最大值%-10d\n",INT_MIN,INT_MAX);
	printf("unsigned int类型的最小值0\t最大值%-10d\n",UINT_MAX);
	printf("long 类型的最小值%-10d最大值%-10d\n",LONG_MIN,LONG_MAX);
	printf("unsigned long类型的最小值0\t最大值%-10d\n",ULONG_MAX);
	printf("long long 类型的最小值%-10d最大值%-10d\n",LLONG_MIN,LLONG_MAX);
	printf("unsigned long long类型的最小值0\t最大值%-10d\n",ULLONG_MAX);

	printf("float 类型的最小值%-10.3ef\n最大值%-10.3ef\n",FLT_MIN,FLT_MAX);
	printf("double 类型的最小值%-10.3ef\n最大值%-10.3ef\n",DBL_MIN,DBL_MAX);
	printf("long double 类型的最小值%-10.3eLf\n最大值%-10.3eLf\n",LDBL_MIN,LDBL_MAX);

	printf("float 类型小数点后位数最多为%u\n",FLT_DIG);
	printf("double 类型小数点后位数最多为%u\n",DBL_DIG);
	printf("long double 类型小数点后位数最多为%u\n",LDBL_DIG);

	getchar();
}

void d_2_8_2()	//sizeof 运算符
{
	//sizeof 通常得到一个int类型的只用于表示该类型所占的字节数
	//由于不同的C库中sizeof可能对应这不同的类型所以引用stddef.h文件头
	printf("char 类型占有%4u个字节\n",sizeof(char));
	printf("short 类型占有%4u个字节\n",sizeof(short));
	printf("int 类型占有%4u个字节\n",sizeof(int));
	printf("long 类型占有%4u个字节\n",sizeof(long));
	printf("longlong 类型占有%4u个字节\n",sizeof(long long));
	printf("float 类型占有%4u个字节\n",sizeof(float));
	printf("double 类型占有%4u个字节\n",sizeof(double));
	printf("long double 类型占有%4u个字节\n",sizeof(long double));
	getchar();
}

void d_2_9(void)	//选择正确的类型
{
	//根据情况对不同的数据用不同的类型，确保值可以在类型的取值范围内
}

void d_2_10(void)	//类型转换
{
	short snum1=1;
	short snum2=3;
	double dnum3=(double)snum1/snum2;
	printf("dnum3:%f",dnum3);
	getchar();
}

void d_2_10_other()	//隐式类型转化的规则
{
	//级别从低到高
	//char short int long longlong float double long double

	//赋值运算中的隐式类型转换
	int num1=0;
	float fnum2=2.5F;
	num1=fnum2;		//由于num1是int类型所以会自动截取掉小数后面的值
	printf("%d",num1);
	getchar();
}

void d_2_11_1(void)
{
	char character=74;
	char letter='C';
	letter+=3;
	printf("%d\n%c",character,letter);
	getchar();
}

void d_2_11_3(void)
{
	enum Weekday{zhouyi=1,zhouer=2,zhousan=3,
		zhousi=4,zhouwu=5,zhouliu=6,zhouri=7
	}
	today=zhouwu,tomrrow=zhouliu;//相当于直接使用了枚举

	enum Weekday day=zhouwu;//常规调用

	printf("今天是%d,%d",today,day);

	//未命名枚举  这种只有已经定义的变量可以使用
	enum {red,orang,yellow,green,blue,indigo} shirt_color;
	shirt_color=red;

	getchar();
}

void d_2_11_4(void)	//存储布尔变量
{
	//_Bool是gcc环境的布尔类型 bool是g++环境
	//_Bool=0/1		对应 false true
	//可以在方法外部定义define常量来处理编译不通过的情况
	//#define bool _Bool
	//#define true 1
	//#define false 0
}

void d_2_12(void)
{
	//赋值操作的op=形式  就是+=  -=
	//常见
	//	+	-	*	/	%
	//	<<	>>	&	^	|
}

#include <math.h>

void d_2_13(void)	//数学函数
{
	//在math.h头文件中 所有函数都返回一个double类型的值

	//数值计算
	//floor(x)	返回不大于x的最大整数
	//ceil(x)	返回不小于x的最小整数
	//fabs(x)	返回x的绝对值
	//log(x)	返回x的自然对数（以E为底）
	//log10(x)	返回x的自然对数（以10为底）
	//exp(x)	返回e的x次方的值
	//sqrt(x)	返回x的平方根
	//pow(x,y)	返回x的y次方

	float num1=0.1F;
	printf("通过floor函数返回不大于%f的最大整数%f\n",num1,floor(num1));
	printf("通过ceil函数返回不小于%f的最小整数%f\n",num1,floor(num1));
	printf("通过fabs()返回%f的绝对值%f\n",num1,fabs(num1));
	printf("通过log(x)返回%f的以E为底的自然对数%f\n",num1,log(num1));
	printf("通过log10(x)返回%f的以10为底的自然对数%f\n",num1,log10(num1));
	printf("通过exp(x)返回e的%f次方%f\n",num1,exp(num1));
	printf("通过sqrt(x)返回%f的平方根%f\n",num1,sqrt(num1));
	printf("通过pow(x,y)返回%f的y次方%f\n",num1,pow(num1,2));

	//三角函数
	//sin(x)	cos(x)	tan(x)
	getchar();
}

void d_2_14(void)//测量树的高度问题
{
	
	//命题为 人1高度<人2高度，人1与树的距离更远 ，人12树的头在一跳直线上，并却地面很平

	float p1height;			//人1的高度
	float p2height;			//人2的高度
	float p1_p2_width;		//人12之间的距离
	float p1_tree_width;	//人1与树的距离
	float treeHieght;		//数的高度

	printf("\n请输入人1的高度：");
	scanf("%f",&p1height);
	printf("\n请输入人2的高度：");
	scanf("%f",&p2height);
	printf("\n请输入两人之间的距离：");
	scanf("%f",&p1_p2_width);
	printf("\n请输入人1与树的距离：");
	scanf("%f",&p1_tree_width);

	//由三角公式可的
	//(p2height-p1height)/p1_p2_width = (treeheight-p1height)/p1_tree_width
	//所以treeheight=(p2height-p1height)/p1_p2_width*p1_tree_width+p1height

	treeHieght=(p2height-p1height)/p1_p2_width*p1_tree_width+p1height;
	printf("\n经过计算得出树的高度大约为：%f",treeHieght);
	scanf("%f");
	getchar();
}

void d_2_16(void)	//练习题
{

	//T2.1
	printf("\nT2.1");
	int num1=0;
	printf("\n请输入一个数值（英寸）");
	scanf("%d",&num1);
	float num2=0.0F;
	float num3=0.0F;
	num2=num1/12.0F;
	num3=num2/3;
	printf("经过计算得出可%d英寸可转换为\n %.2f英尺\n %.2f码",num1,num2,num3);
	getchar();
	//T2.2
	printf("\nT2.2");
	float width_f_YCH=0.0F;
	float height_f_YC=0.0F;
	float area_M=0.0F;
	printf("\n请输入长度（单位英尺）：");
	scanf("%f",&width_f_YCH);
	printf("\n请输入宽度（单位英寸）：");
	scanf("%f",&height_f_YC);

	area_M=width_f_YCH/3*height_f_YC/36;
	printf("\n经过计算房间面积为%f平方码",area_M);

	//T2.3
	int count1=0;
	int count2=0;
	float book1=3.5F;
	float book2=5.5F;
	printf("\n请输入欲购买数量（书1）");
	scanf("%d",&count1);
	printf("\n请输入欲购买数量（书2）");
	scanf("%d",&count2);

	float sum=(count1*book1)+(count2*book2);
	printf("\n语句共支付：Y%f",sum);

	//T2.4
	float Mnum=0.0F;
	float Hcount=0.0F;
	printf("\n输入工资");
	scanf("%f",&Mnum);
	printf("\n输入工作时长");
	scanf("%f",&Hcount);
	float num_H=Mnum/(Hcount*30);
	printf("你每天工作%.0f个小时，就是为了赚%.0f多块钱，平均算下来每小时就%f这么点",Hcount,Mnum,num_H);
	
	scanf("%c");
}

int main(void)
{
	d_2_16();
	getchar();
}

