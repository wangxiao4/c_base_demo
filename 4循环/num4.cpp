#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void test(void)	//����
{
	printf("�����ڲ���");
	getchar();
}

void d_4_1(void)	//for
{
	//���һ��������
	printf("\n*******");
	for(int i=0;i<7;i++){
		printf("\n*     *");
	}
	printf("\n*******");
	getchar();
}

void d_4_6(void)	//����for
{
	//����һ��ֵ  �ó�������Ľ׳�
	printf("������һ����\n");
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
	printf("%d�Ľ׳���%d",num1,num2);
	getchar();
	getchar();
}

void d_4_6_4(void)	//��ֹѭ�� ����ѭ��	�������
{
	//����Ԥ��ֵ
	srand(time(NULL));//����ʱ�亯����������
	int num1=0;
	num1=rand();	//α�����������Ҫ���� ������ͬ�����ɵ��������ͬ	<stdlib.h>
	int num2=0;
	for(;;){
		printf("����һ������\n");
		scanf("%d",&num2);
		if(num2>num1){
			printf("\n�е��\n");
		}else if(num2==num1){
			printf("\n��¶���\n");
			break;
		}else{
			printf("\n�е�С\n");
		}
	}
	getchar();
	getchar();
}

void d_4_7()	//while
{
	//�����ֵ��ۺ�
	int num1=0;
	printf("\n������Ҫ���ܵ�����\n");
	scanf("%d",&num1);
	int sum=0;
	int i=1;
	while(i<=num1){
		sum+=i;
		i++;
	}
	printf("%d�Ļ��ܺ�Ϊ%d",num1,sum);
	getchar();
	getchar();
}

void d_4_8(void)	//ѭ��Ƕ��
{
	//�������
	printf("����������\n");
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
	//����ִ��һ��
	int i=0;
	do{
		printf("%d",i);
		i++;
	}while(i<10);
	getchar();
}
void d_4_11()	//continue	��������ѭ��
{
	int i=0;
	printf("���10���ڵ�����\n");
	do{
		i++;
		if(i%2==0){
			continue;
		}
		printf("%d\t",i);

	}while(i<10);
	getchar();
}

void d_4_12()	//�������
{
	//һ������С��Ϸ ��Ļ�������ʾһ������ һ������ز�������ļ���ֵ  ѭ���ۼ��Ѷ�
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
	printf("�����С��Ϸ");
	printf("\n����Ļ�ϵ�����ֵ");
	printf("\n����ֵ���� %u ������ʧ",DELAY);
	printf("\n���س���ʼ��Ϸ");
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
				printf("\n ���������֣������ǿո�\n");
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
			printf("%s\n",correct?"��":"��");
		}
		printf("Ҫ������Y/N����");
		scanf("%c",&another_game);
	}while(toupper(another_game)=='Y');
}

void d_4_14()	//ϰ��
{
	int num=0;
	int rows=1;
	char ch1=0;
	printf("������Ҫ�鿴����ţ�������");
	scanf("%d",&num);
	switch(num){
	case 1:
		printf("\n�žų˷��� ����������\n");
		scanf("%d",&rows);
		for(int i=1;i<=rows;i++){
			for(int j=1;j<=i;j++){
				printf("%d*%d=%d\t",i,j,i*j);
			}
			printf("\n");
		}
		break;
	case 2:
		printf("\n���char(0-127) ���� ���ַ�\n");
		for(int i=0;i<=127;i++){
			ch1=i;
			printf("%d\t%c\n",ch1,isgraph(ch1)>0?ch1:'?');
		}
		break;
	case 3:
		printf("����");
		break;
	default:break;
	}
	getchar();
	getchar();
}

void main(){
	d_4_14();
}