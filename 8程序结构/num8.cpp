/* �ڰ��� ����Ľṹ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void test()	//�����ڲ���
{
	printf("�����ڲ���");
	getchar();
}

void d_8_1()	//�˽�������
{
	int data1=0;

	do{
		int data2=0;
		printf("data1=%d\tdata2=%d\n",data1,data2);
		data2++;
		data1++;
	}while(data1<5);
	getchar();
}

void d_8_1_2()	//�����˽�������
{
	//��ѭ����
	int data1=0;
	do{
		int data1=0;
		printf("data1=%d",data1);
		data1++;
	}while(data1<5);
	getchar();
}

int d_8_2_2(int a,int b)	//ʹ�ò����Լ�return
{
	return a+b;
}

void d_8_3()	//��ֵ���ݻ���
{
	//���������յ���Ԫ��ʱ��Ӧ��֪����Ԫ�����ԭʼ���ݵĸ���
	//�����ں������޸ı�Ԫ��ԭʼ���ݲ�����Ӱ��
	//�޸�ԭʼ���ݵ�Ψһ��ʽ�Ǵ���ԭʼ���ݵ�ָ��
}

void d_8_4()	//����ԭ��
{
	//����ԭ���ǶԺ�������ı����ʼ��
	//��ֹ�����ʱ�����δ���������ִ���
	//����ֵ�����뺯��������ͬ
}

void d_8_5()	//ָ�����������뷵��ֵ
{
	//��ָ������������ʱ����Զ�Դ���ݽ����޸�
}


#define COUNT 5

void getInput(char **,size_t *);
void getSort(char **,size_t *);
void printData( char *const*,const size_t *);

void d_8_5_1()	//����ָ�����
{
	//����ָ�������������
	size_t count=COUNT;
	size_t *pcount=&count;
	char **returnData=(char**)calloc(count,sizeof(char*));

	//��ȡ�������벢���浽������
	getInput(returnData,pcount);
	printf("\n");
	getSort(returnData,pcount);
	printData(returnData,pcount);
	getchar();
}


//�����Ϣ
void printData(char *const* returnData,const size_t *count)
{
	int vcount=*count;
	for(int i=0;i<vcount;i++){
		printf("%s",returnData[i]);
	}
}

//��ȡ����
void getSort(char **returnData,size_t *count)
{
	bool isChange=true;
	while(isChange)
	{
		isChange=false;
		for(int i=0;i<*count-1;i++)
		{
			if(strcmp(returnData[i],returnData[i+1])>0)
			{
				isChange=true;
				char *temp=returnData[i];
				returnData[i]=returnData[i+1];
				returnData[i+1]=temp;
			}
		}
	}
}

//��ȡ�������벢���浽������
void getInput(char **returnData,size_t *count)
{
	char *value=(char*)calloc(100,sizeof(char));
	size_t str_len=0;
	char **pData=NULL;
	size_t str_count=0;
	char *ptr=NULL;
	printf("��������Ҫ������ַ���\n");
	while(true)
	{
		ptr=fgets(value,100,stdin);
		if(!ptr)
		{
			printf("��ȡ��ת������ʱʧ��");
			free(value);
			*value=NULL;
		}

		if(!strcmp(value,"\n"))
		{
			break;	
		}

		if(str_count==*count){
			*count+=1;
			pData=(char**)realloc(returnData,*count*strnlen_s(value,100));
			returnData=pData;
		}
		str_len=strnlen_s(value,100)+1;
		returnData[str_count]=(char*)malloc(str_len);
		strcpy_s(returnData[str_count],str_len,value);
		str_count++;
	}
}

int* setPay(int *pay);
void d_8_5_2()	//����ָ��ķ���
{
	int my_pay=1000;
	int *pMy_pay=&my_pay;
	int new_pay=*setPay(pMy_pay);
	printf("old:%d,\tnew:%d",my_pay,new_pay);
	getchar();
}

int* setPay(int *pay){
	*pay+=1000;
	return pay;
}
int* setPay2(int *pay)
{
	//�������޸Ĵ���ı������ݵ�ʱ��
	//Ҫôʹ�þ�̬
	//Ҫô���¶�������
	int new_pay=0;
	new_pay=*pay+1000;
	return &new_pay;
}
void d_8_5_2_2()	//����ָ��ķ���
{
	int my_pay=1000;
	int *pMy_pay=&my_pay;
	int new_pay=*setPay2(pMy_pay);
	printf("old:%d,\tnew:%d",my_pay,new_pay);
	getchar();
}

void getInput_7(float*,int*);
void printData_7(float*,int*);
void getAverage(float*,int*);
char * intToString(int number);
char * intToString_3(int number,int width);

void d_8_7()	//ϰ��
{
	goto t3;
t1:
	float *data=(float*)calloc(COUNT,sizeof(float));
	int count=COUNT;
	int *pCount=&count;
	//��ȡ����
	getInput_7(data,pCount);
	//��ӡ����
	printData_7(data,pCount);
	printf("\n");
	//��ȡƽ��ֵ
	getAverage(data,pCount); 
t2:
	printf("������һ������\n");
	int number_2=0;
	scanf_s("%d",&number_2);
	char *str_number=intToString(number_2);
	printf("%s",str_number);

t3:
	printf("������һ������\n");
	int number_3=0;
	scanf_s("%d",&number_3);
	printf("������һ������\n");
	int width_3=0;
	scanf_s("%d",&width_3);
	char *str_number_3=intToString_3(number_3,width_3);
	printf("%s",str_number_3);

	getchar();
	getchar();
}

char * intToString(int number)
{
	char *str_number=(char*)malloc(100*sizeof(char));
	itoa(number,str_number,10);//�˺�����ANSI��׼�ǲ�����
	return str_number;
}

char * intToString_3(int number,int width)
{
	char *str_number=(char*)calloc(100,sizeof(char));
	//char str_number[100];
	itoa(number,str_number,10);//�˺�����ANSI��׼�ǲ�����
	int abWidth=abs(width);
	char *str_width=(char*)calloc((abWidth+1),sizeof(char));
	for(int i=0;i<abWidth;i++){
		str_width[i]='\ ';
	}

	int len1=strnlen_s(str_width,(abWidth)*sizeof(char))+1;
	int len2=strnlen_s(str_number,(100)*sizeof(char))+1;

	char* returnData=(char*)calloc(len2+len1+3,sizeof(char));


	if(width<0){
		strcat(returnData,str_width);
		strcat(returnData,str_number);
	}else{
		strcat(returnData,str_number);
		strcat(returnData,str_width);
	}
	return returnData;
}

void getAverage(float *data,int *count)
{
	float average=0;
	float sum=0;
	for(int i=0;i<*count;i++)
	{
		sum+=data[i];
	}
	average=sum / *count;

	printf("%d�����������ܺ�Ϊ��%f\tƽ��ֵΪ��%f",*count,sum,average);
}

void printData_7(float *data,int *count)
{
	for(int i=0;i<*count;i++)
	{
		printf("\t%f",data[i]);
	}
}

void getInput_7(float *data,int *count)
{
	char *number=(char*)malloc(100*sizeof(char));
	size_t number_count=0;
	printf("������Ҫ����ĸ�����\n");
	while(true)
	{
		if(!fgets(number,100,stdin))
		{
			printf("�������ֵ����ȷ");
		}
		if(!strcmp("exit\n",number))
		{
			break;
		}
		if(number_count==*count){
			*count+=1;
			float *temp=(float*)realloc(data,*count*sizeof(float));
			data=temp;
		}
		data[number_count]=atof(number);
		number_count++;
	}
}

void main()	
{
	/*printf("%d",d_8_2_2(1,1));
	getchar();*/
	d_8_7();
}