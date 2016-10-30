#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void test(void)	//测试
{
	printf("仅用于测试");
	getchar();
}

void d_4_1(void)	//for
{
	//输出一个正方形
	printf("\n*******");
	for(int i=0;i<7;i++){
		printf("\n*     *");
	}
	printf("\n*******");
	getchar();
}

void d_4_6(void)	//再论for
{
	//输入一个值  得出这个数的阶乘
	printf("请输入一个数\n");
	int num1=0;
	scanf("%d",&num1);
	int num2=1;
	if(num1>1){
		for(int i=1;i<=num1;i++){
			num2*=i;
		}
	}else if(num1==0){
		num2=1;
	}else{
		num2=0;
	}
	printf("%d的阶乘是%d",num1,num2);
	getchar();
	getchar();
}

void d_4_6_4(void)	//终止循环 跳出循环	随机变量
{
	//输入预设值
	srand(time(NULL));//利用时间函数设置种子
	int num1=0;
	num1=rand();	//伪随机函数，需要种子 种子相同则生成的随机数相同	<stdlib.h>
	int num2=0;
	for(;;){
		printf("输入一个数字\n");
		scanf("%d",&num2);
		if(num2>num1){
			printf("\n有点大\n");
		}else if(num2==num1){
			printf("\n你猜对了\n");
			break;
		}else{
			printf("\n有点小\n");
		}
	}
	getchar();
	getchar();
}

void d_4_7()	//while
{
	//求数字的综合
	int num1=0;
	printf("\n请输入要汇总的数字\n");
	scanf("%d",&num1);
	int sum=0;
	int i=1;
	while(i<=num1){
		sum+=i;
		i++;
	}
	printf("%d的汇总和为%d",num1,sum);
	getchar();
	getchar();
}

void d_4_8(void)	//循环嵌套
{
	//杨辉三角
	printf("请输入行数\n");
	int rows=0;
	scanf("%d",&rows);
	for(int i=0;i<rows;i++){
		for(int j=rows-i;j>0;j--){
			printf(" ");
		}
		for(int z=i*2-1;z>0;z--){
			printf("*");
		}
		printf("\n");
	}
	for(int i=rows;i>0;i--){
		for(int j=rows-i;j>0;j--){
			printf(" ");
		}
		for(int z=i*2-1;z>0;z--){
			printf("*");
		}
		printf("\n");
	}
	getchar();
	getchar();
}

void d_4_10()	//	do-while
{
	//至少执行一次
	int i=0;
	do{
		printf("%d",i);
		i++;
	}while(i<10);
	getchar();
}
void d_4_11()	//continue	跳过本次循环
{
	int i=0;
	printf("输出10以内的奇数\n");
	do{
		i++;
		if(i%2==0){
			continue;
		}
		printf("%d\t",i);

	}while(i<10);
	getchar();
}

void d_4_12()	//程序设计
{
	//一个记忆小游戏 屏幕上随机显示一串数字 一秒后隐藏并输入你的记忆值  循环累加难度
	char another_game='Y';
	const unsigned int DELAY=1;
	bool correct=true;
	unsigned int tries=0;
	unsigned int digits=0;
	time_t seed=0;
	unsigned int number=0;
	time_t wait_start=0;
	clock_t start_time=0;
	unsigned int score=0;
	unsigned int total_digits=0;
	unsigned int game_time=0;
	printf("玩这个小游戏");
	printf("\n看屏幕上的整数值");
	printf("\n整数值将在 %u 秒内消失",DELAY);
	printf("\n按回车开始游戏");
	scanf("%c",&another_game);

	do{
		correct=true;
		tries=0;
		digits=2;
		start_time=clock();

		while(correct){
			++tries;
			wait_start=clock();
			srand(time(&seed));

			for(unsigned int i=1;i<=digits;++i)
			{
				printf("%d",rand()%10);
			}
			for(;clock()-wait_start<DELAY*CLOCKS_PER_SEC;);
			printf("\n");
			for(unsigned int i=1;i<=digits;i++)
				printf(" ");
			if(tries==1)
				printf("\n 请输入数字，别忘记空格\n");
			else
				printf("\r");
			srand(seed);
			for(unsigned int i=1;i<=digits;++i)
			{
				scanf("%u",&number);
				if(number!=rand()%10){
					correct=false;
					break;
				}
			}
			if(correct && ((tries%3)==0)){
				++digits;
			}
			printf("%s\n",correct?"对":"错");
		}
		printf("要继续吗（Y/N）？");
		scanf("%c",&another_game);
	}while(toupper(another_game)=='Y');
}

void d_4_14()	//习题
{
	int num=0;
	int rows=1;
	char ch1=0;
	printf("请输入要查看的题号，共五题");
	scanf("%d",&num);
	switch(num){
	case 1:
		printf("\n九九乘法表 请输入行数\n");
		scanf("%d",&rows);
		for(int i=1;i<=rows;i++){
			for(int j=1;j<=i;j++){
				printf("%d*%d=%d\t",i,j,i*j);
			}
			printf("\n");
		}
		break;
	case 2:
		printf("\n输出char(0-127) 数字 ，字符\n");
		for(int i=0;i<=127;i++){
			ch1=i;
			printf("%d\t%c\n",ch1,isgraph(ch1)>0?ch1:'?');
		}
		break;
	case 3:
		printf("繁琐");
		break;
	default:break;
	}
	getchar();
	getchar();
}

void main(){
	d_4_14();
}