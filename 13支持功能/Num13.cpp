/* ֧�ֹ��� */
#include <stdio.h>

void test()
{
	printf("�����ڲ���");
	getchar();
}

void d_13_1()	//Ԥ����
{
	// #include <stdio.h>
}

void d_13_2()	//�����Լ���ͷ�ļ�
{
	//ͨ���Զ����ͷ�ļ��в�������ִ�д���
	//ֻ�� ����ԭ��/struct���Ͷ���/���Ŷ���/extern/typedefs
}

void d_13_1_3()	//������Դ�ļ�
{
	//��������һ���ʵ����ļ��нṹ
	//��������IDE�������ļ�����ͬһ���ļ�����
}

void d_13_1_4()	//�ⲿ����
{
	//extern ����������Ϊ�ⲿ����
	//�����е�ȫ�ֱ�������һ���ļ��Ŀ�ͷ�������е�extern��������һ��ͷ�ļ���
	//ʹ��include��������ͷ�ļ�
}

void d_13_1_5()	//��̬����
{
	//static void add(int num1,int num2)
	//����ֻ���ڶ�������.c�ļ��е���
}

void d_13_1_6()	//�滻����Դ����
{
	//#define PI 3.1415926
	//������������鳤�ȵ�ʱ��Ҳ����ʹ��const�������define
	//const size_t MAXLEN=256;
}

void d_13_2_0()	//��
{
	//���һ�°�
	//#define Print(My_var) printf_s("%d",My_var);
}

void d_13_2_1()	//�������뺯���ĺ�
{
	//������û����滻
	//#define product(m,n) m*n
	//product(0,1+1)-> 0*1+1
	//����ת��Ϊproduct(m,n) (m)*(n)
}

void d_13_2_2()	//�ַ�����Ϊ�����
{
	//����ʹ�þ��Ե���
	//#define show(var) printf_s(#var"=%d\n",var)
	//show(number);
	//printf_s("number""=%d\n",number);
}

void d_13_2_3()	//�ں�չ��ʽ�н��������Ԫ
{
	//define join(a,b) a##b
	//##�����ָ�����
	//strnlen_s(join(var,123),sizeof(join(var,123)));
	//strnlen_s(var123,sizeof(var123));
	//��������ϱ�������
}

void d_13_3()	//�����ϵ�Ԥ������ָ��
{
	//���������з� ����
	//#define min(x,y) \ 
	//					((x)<(y)?(x):(y))				
}

void d_13_3_2()	//��������
{
#if define a
	//�������a���� �ͻ����
#endif

#if !definde a
	//���������a���� �ͻ����
#endif
}

void d_13_3_3()	//���Զ������
{
#if define a && define b
	//�������a��b
#endif
}

void d_13_3_4()	//ȡ������ı�ʶ��
{
#undef block
}

#define CUP Intel_i7
void d_13_3_5()	//���Ա�ʶ����ָ��ֵ��ָ��
{
	char *data="";
#if CPU==Intel_i7
	data="��������i7������";
#endif

#if CPU==Intel_i5
	data="��������i5������";
#endif
#if CPU==Intel_i3
	data="��������i3������";
#endif
	printf("%s",data==""?"��":data);
	getchar();
}

void d_13_3_6()	//����ѡ��
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
void ad_13_3_7()	//��׼Ԥ�����
{
	//__func__	��ô����б�ʾ������ĺ�����
	printf("%s\n",__FUNCTIONW__);//vs2013 ����ȫ֧��c99 ����ʹ��__func__
	printf("%s\t%s\n",__DATE__,__TIME__);//ʱ��
	FILE* pfile=NULL;
	char* fileName="D:\\MyDemo\\T13_3_7.txt";
	if(fopen_s(&pfile,fileName,"w"))
	{
		printf("�ļ���%s\n%s���ִ���",__FILE__,__LINE__);//__file__����ǰ�ļ�����תΪ�ַ�����ʽ��__line__��Ӧ��ǰ�к�
	}

	getchar();
}

void d_13_4_1()	//���ʷ���
{
	//���ɵĵ�����
	//1.׷�ٳ�����
	//2.���öϵ�
	//3.���ùۿ�����
	//4.������Ԫ��
}
void d_13_4_2()	//���Խ׶ε�Ԥ������
{
	//����#if #elif #endif
	//�����ж����
}

#include <assert.h>
void d_13_4_3()	//����
{
	//������һ��������Ϣ������������ʱ�������Ϣ
	//���������Ժ������ڶ���
	//assert()//�����ڶ���
	//����assert.hͷ�ļ� assert(bool) �ɰ�������ж����
	//���ж����Ϊfalseʱ��ֹ����
	//����#undef NDEBUG �ر����ж��Թ��ܣ��������assert.hͷ�ļ�����ǰ��

	//�����ڶ���
	//static_assert(bool,string);true����������string

	int b=5;
	for (int i = 0; i < 10; i++)
	{
		printf("i=%d\tb=%d\n",i,b);
		assert(i<b);
	}
	getchar();
}

void d_13_5_t()	//���ں�ʱ�亯��
{
	//time.hͷ�ļ�
}

#include <time.h>
#include <math.h>
#include <ctype.h>
void d_13_5_1()	//��ȡʱ��ֵ
{
	//clock_t clock() clock_t ��time.h�ж������������
	//CLOCKS_PER_SEC һ���ڵ�ʱ��������
	//time_t time(time_t *timer); //19700101 00:00:00  ��λ��
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
		printf("�Ƿ�Ҫ������(y/n)\n");
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
void d_13_5_2()	//��ȡ����
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
		printf("ת��ʧ��");
	}
	//localtime(const time_t* timer)��localtime_s(const time_t* timer,struct tm* tm)
	//tm �ṹ˵��
	//tm_sec			0-60��
	//tm_min			0-60��
	//tm_hour			0-23Сʱ
	//tm_mday			0-31��
	//tm_mon			0-11��
	//tm_year			��ǰ-1900
	//tm_wday			����0-6
	//tm_yday			��0-365
	//tm_isdst			�ڰ��죿����
	const char *days[]={"������","����һ","���ڶ�","������","������","������","������"};
	struct tm time_data;
	if(!localtime_s(&time_data,&timer))
	{
		printf("%s\n",days[time_data.tm_wday]);
	}

	getchar();
}

void d_13_5_3()	//ȷ��ĳһ��ʱ���ڼ�
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
		printf("ת��ʧ��");
	}
	getchar();
}

#define COMPARE(x,y) ((x)<(y)?-1:(x)==(y)?0:1)
void d_13_7_1()	//ϰ��1
{
	printf("%d",COMPARE(11,2));
	getchar();
}

void main()
{
	d_13_7_1();
}