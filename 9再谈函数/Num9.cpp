/* �ھ��� ��̸���� */

#include <stdio.h>
#include <stdarg.h>		//���ڿɱ��������
#include <stdlib.h>

void test()
{
	printf("�����ڲ���");
	getchar();
}

void d_9_1_1()	//����ָ��
{
	int				(*pfunction) (int);	//����ָ��Ķ���,���������ڱ���
	//	����ֵ����		ָ������	��������
}

int sum(int a,int b);//����ԭ��
int product(int a,int b);
int difference(int a,int b);
int any_function(int (*pf_fun) (int,int),int a,int b);

void d_9_1_2()	//����ָ��ĵ���
{
	int (*pf_fun) (int,int);//����ָ��
	pf_fun=sum;
	printf("1+1=%d\n",pf_fun(1,1));
	pf_fun=product;
	printf("1*1=%d\n",pf_fun(1,1));
	pf_fun=difference;
	printf("1-1=%d\n",pf_fun(1,1));
	getchar();
}

void d_9_1_3()	//����ָ������
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

void d_9_1_4()	//function pointer for parameter (���ڲ����ĺ���ָ��)
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

void d_9_2()	//�����еı���
{
	for(int i=0;i<5;i++)
	{
		d_2_t1();
		d_2_t2();	//ʹ���˾�̬����
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
	//��̬�����������ŷ����������ͷ��ڴ�
	//ֱ�����������Ż��ͷŵ�
	static int count=0;		//ʹ�ùؼ���static
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
	//��̬�����������ŷ����������ͷ��ڴ�
	//ֱ�����������Ż��ͷŵ�
	static int count_2_2=0;		//ʹ�ùؼ���static 
	printf("test2:%d\n",count_2_2);
	count_2_2++;
}


void d_9_2_2()	//global variable ȫ�ֱ���
{
	for(int i=0;i<5;i++){
		d_2_2_t1();
		d_2_2_t2();
	}
	getchar();
}


int numbers=1;
void d_9_3_t(int number);

void d_9_3()	//�ݹ�
{
	//���õݹ���һ�����Ľ׳�
	//�׳� 1�������֮���������ĳ˻�������������
	int number=0;
	printf("������Ҫ����׳˵�����\n");
	scanf_s("%d",&number);
	d_9_3_t(number);
	printf("�����ֵĽ׳ˣ�%d",numbers);
	getchar();
}

void d_9_3_t(int number)
{
	static int count=1;
	numbers*=count;
	if(count<number){
		count++;
		d_9_3_t(number);	//�����Լ�
	}
}

double average(double v1,double v2,...);

void d_9_4()	//�ɱ����������������
{
	printf("average=%.2lf",average(1.1,2.2,3.3,4.0,5.5,0.0));
	getchar();
}

void d_9_4_1()	//��Ԫ����ĸ���
{
	va_list parg;
	va_list copy_parg;
	//va_copy(copy_parg,parg);//����ԭ��ַ���µ�ַ
}

double average(double v1,double v2,...)
{
	double sum=v1+v2;		//��Ԫ�ܺ�
	double value=0.0;		//�������б�Ԫֵ
	int count=2;			//��Ԫ����

	va_list parg;			//��Ԫ�б�ָ��
	va_start(parg,v2);		//�б���ʼλ��
	while((value=va_arg(parg,double))!=0.0)	//ѭ����ȡ��һ����Ԫֵ	ע���������һ����������ʱ0.0
	{
		sum+=value;
		++count;
	}
	va_end(parg);			//��Ԫ�б����
	return sum/count;
}

void d_9_5()	//main����
{
	//main����ʱ��������
	//�ɴ����������������޲�������
	//�в�����ʱ��
	//����һ��int���� ���Ϊ3 ��СΪ1
	//������:������ַ�ֱ�ָ��������ƣ��������������б�Ԫ�Ҷ�Ϊchar*����
}

void d_9_6()	//��������
{
	//��stdlib.hͷ�ļ���
	abort();	//���������������رմ򿪵���
	exit(EXIT_SUCCESS);	//�����رճ�����ջ�������ʹ��������ر������Ż���������Ȩ
	atexit(d_9_5);//�ر�ʱ���ú���	����������
	//_Exit(1);	//�����رճ��� �������κ���ע��ĺ���
	/*quick_exit(d_9_5);
	at_quick_exit(d_9_5);*/
}

void d_9_7_1()	//����
{

}

void d_9_9()	//���
{

}

double power(double x,int n);//x��n�η�

void d_9_10()	//��ϰ
{
t1:
	double num=power(5.0,2);
	printf("5��2�η���%.2lf",num);

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

double subtract_t_2(double a,double b);	//a-b+c-d+... ������  ż����
double array_op(double array[],size_t size,double (*pfun) (double,double));
void d_9_10_2()
{
	//��������������ѭ�����þͺ�  ֻ�м������иı�
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

void d_9_10_3()	//ϰ����
{
	//TODO������δ��
	int count=5;
	char **str_list=(char**)calloc(count,sizeof(char*));
	char *str=(char*)calloc(100,sizeof(char));
	int str_count=0;

	while(true)
	{
		if(!fgets(str,100,stdin))
		{
			printf("��������");
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