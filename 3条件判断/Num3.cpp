/* 第三章	条件判断 */
#include <stdio.h>	//基本文件头  包含输入输出等常用操作

void test(void)	//测试
{
	printf("仅用于测试");
}

void d_3(void)
{
	//c中的关系运算符
	//	<	<=	==	!=	>=	>
	//所有不为0的数字转为bool都为true
}

void d_3_1_2(void)
{
	//if 判断
	int num=0;
	printf("请输入一数字");
	scanf("%d",&num);
	if(num>0){
		printf("正整数");
	}else if(num==0){
		printf("0");
	}else{
		printf("负整数");
	}
	getchar();
}

void d_3_1_6(void)	//测试字符 if的嵌套
{
	char letter=0;
	printf("请输入一个字符");
	scanf("%c",&letter);
	if(letter>'A'){
		if(letter<'Z'){
			letter=letter-'A'+'a';
			printf("转换为%c",letter);
		}else{
			printf("超出定义域");
		}
	}else{
		printf("输入不合法");
	}
	getchar();
}

void d_3_1_7(void)
{
	//逻辑运算符
	//	&&	||	！
	//	并	或	非
	char letter=0;
	printf("\n请输入一个字符我将帮你转为小写");
	scanf("%c",&letter);
	if(letter>'A'&&letter<'Z'){
		letter=letter-'A'+'a';
		printf("转为小写为%d",letter);
	}else if(letter<'a'||letter>'z'){
		printf("您输入的字符超过了定义域");
	}else{
		printf("%c本身就是一个小写",letter);
	}
	scanf("%c");
	getchar();
}

void d_3_1_8(void)	//条件运算符
{
	//一本书原价3.5 购买50以上7.5折  购买20本以上8折  购买10本以上9折

	const float book_M=3.5F;
	const float count50=0.25;
	const float count20=0.2;
	const float count10=0.1;
	int count=0;
	float sum=0.0F;
	printf("\n请输入要购买多少本");
	scanf("%d",&count);
	sum=book_M*count*(1-(count>=50?count50:(count>=20?count20:(count>=10?count10:0))));
	printf("\n共需要支付%f元",sum);
	getchar();
}

void d_3_1_9(void)	//运算符的优先级
{
	//	序号	运算符	说明		匹配规则
	//	1		（）	括号		左右
	//			[]		数组下标	
	//			.		对象选择成员
	//			->		指针选择成员
	//	2		+-		一元+和-	右到左
	//			++ --	递增递减	
	//			！~		逻辑非按位补
	//			*		取消引用（间接运算符）
	//			&		寻址
	//			Sizeof	表达式或类型的字节数
	//			(type)	强制类型转换
	//	3		*/%		乘除取模	左右
	//	4		+-		加减		左右
	//	5		<< >>	按位左右移	左右
	//	6		< <= > >=	比较	左右
	//	7		== !=	等不等		左右
	//	8		&		按位与		左右
	//	9		^		按位异或	左右
	//	10		|		按位或		左右
	//	11		&&		逻辑与		左右
	//	12		||		逻辑或		左右
	//	13		?:		条件运算符	右到左
	//	14		=		赋值		右到左
	//			+= -=	
	//			/= *=
	//			%=
	//			<<= >>=	按位左右移赋值
	//			&= |=	按位与或赋值
	//			^=		按位异或赋值
	//	15		,		逗号		左右

	//25岁，化学专业，不是耶鲁大学
	//		化学专业,耶鲁大学
	//28以下，经济专业，哈弗大学
	//25岁，非化学专业，耶鲁大学
	int age=0;//年龄
	int ZhuanYe=0;//专业
	int DaXue=0;//大学
	bool isCanUse=false;
	printf("\n请输入年龄");
	scanf("%d",&age);
	printf("\n请输入专业：1.化学专业	2.经济专业	3.其他");
	scanf("%d",&ZhuanYe);
	printf("\n请输入大学：1.耶鲁大学	2.哈弗大学	3.其他");
	scanf("%d",&DaXue);

	if(age>25&&ZhuanYe==1&&DaXue!=1){
		isCanUse=true;
	}
	if(ZhuanYe==1&&DaXue==1){
		isCanUse=true;
	}
	if(age<28&&ZhuanYe==2&&DaXue==2){
		isCanUse=true;
	}
	if(age>25&&ZhuanYe!=1&&DaXue==1){
		isCanUse=true;
	}
	if(isCanUse){
		printf("您符合要求，请速来面试");
	}else{
		printf("很可惜~与您不对口");
	}
	getchar();
}

void d_3_2(void)	//多先选择问题
{

}

void d_3_2_1(void)	//else-if
{
	int count=0;
	printf("请输入你的分数");
	scanf("%d",&count);
	if(count>90){
		printf("优秀");
	}else if(count>80){
		printf("良好");
	}else if(count>60){
		printf("及格");
	}else{
		printf("补考");
	}
	getchar();
}

void d_3_2_2(void)	//switch语句
{
	//<ctype.h>头文件中的及格测试字符
	//islower()	是否小写
	//isupper	是否大写
	//isalnum	是否字母或十进制数字
	//iscntrl	控制字符
	//isprint	可打印字符	包含空格
	//isgraph	可打印字符	不包含空格
	//isdigit	十进制数字
	//isxdigit	十六进制数字
	//isblank	标准空白字符（空格，‘\t’）
	//isspace	空位字符（空格\n \t \v \r \f）
	//ispunct	isprint和isgraph返回false的可打印字符
	//isalpha	是否字母
	//tolower	转为小写
	//toupper	转为大写

	//test:输入三个数字中的一个
	int num=0;
	printf("请输入一个数字");
	scanf("%d",&num);
	switch(num){
	case 1:printf("幸运的1");break;
	case 2:printf("幸运的2");break;
	case 3:printf("幸运的3");break;
	default:printf("太大或太小");break;
	}
	getchar();
}

void d_3_2_3(void)	//goto
{
	//用于语句硬跳转
	start:
	printf("1循环2结束");
	int num=0;
	scanf("%d",&num);
	if(num==1){
		goto start;
	}
	getchar();
}

void d_3_3(void)	//按位运算符
{
	//	&	按位与		相同位都是1 结果位是1 否则结果位为0
	//	|	按位或		有一个或两个1  结果位为1 否则结果位为0
	//	^	按位异或	相同位不同 结果位为1 否则为0
	//	~	按位非		反转1->0  0->1
	//	<<	按位左移	在右侧加0	
	//	>>	按位右移	不带符号的左侧加0 有符号当符号位扩散则全部为1 否则为0

	//这些运算符只能用于整数类型	~是一元运算符	只处理一个操作数 其他都是二元

}

void d_3_3_2(void)	//按位运算符的使用
{
	//将一个ABC反转为CBA 十六位的
	unsigned int num1=0xABC;
	unsigned int mesh=0xF;
	unsigned int num2=0x0;
	printf("%x\t->\t",num1);

	num2|=num1&mesh;
	num1>>=4;
	num2<<=4;
	num2|=num1&mesh;
	num1>>=4;
	num2<<=4;
	num2|=num1&mesh;

	printf("%x",num2);
	getchar();

}

void d_3_4()	//设计程序
{
	start:
	//设计一款计算器
	double num1=0.0;
	double num2=0.0;
	char operation=0;
	printf("请输入要记得算的等式\n");
	scanf("%lf %c %lf",&num1,&operation,&num2);
	switch(operation){
	case '+':
		printf("=%lf\n",num1+num2);
		break;
	case '-':
		printf("=%lf\n",num1-num2);break;
	case '*':
		printf("=%lf\n",num1*num2);break;
	case '/':
		printf("=%lf\n",num1/num2);break;
	case '%':
		printf("=%lf\n",(long)num1%(long)num2);break;
	default:
		printf("不知道");
		break;
	}
	char isReturn=0;
	getchar();
	printf("再来一遍?\ty/n");
	scanf("%c",&isReturn);
	if(isReturn=='y'){
		goto start;
	}
}

void d_3_6(void)	//本章练习
{
	//T1 选择	摄氏度转华氏度或华氏度转摄氏度  输入数值  输出转化结果
	int operation=0;
	printf("1.摄氏度转华氏度\n2.华氏度转摄氏度\n选择？\n");
	scanf("%d",&operation);
	printf("\n请输入要转换的值\n");
	float num1F=0.0F;
	scanf("%f",&num1F);
	switch(operation){
	case 1:
		printf("约%f华氏度",num1F*1.8+32);
		break;
	case 2:
		printf("约%f摄氏度",(num1F-32)*5/9);break;
	default:break;
	}
	getchar();
	getchar();

	//T2 不明白怎么转换 英语没学好
	//T3	输入个数 超过30九折 超过50八点五折
	printf("\n请输入要购买的个数（单价：5元）\n");
	int num1=0;
	scanf("%d",&num1);
	int sum=5*num1*(1-(num1>=50?0.15:(num1>=30?0.1:0)));
	printf("\n共需要支付%d元",sum);
	getchar();
	getchar();
	//T4 将本章的计算器修改为可循环计算的（goto）
	//源代码已完成
}

void main(){
	d_3_6();
}