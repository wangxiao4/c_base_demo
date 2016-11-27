/* 第八章 程序的结构 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void test()	//仅用于测试
{
	printf("仅用于测试");
	getchar();
}

void d_8_1()	//了解作用域
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

void d_8_1_2()	//深入了解作用域
{
	//死循环了
	int data1=0;
	do{
		int data1=0;
		printf("data1=%d",data1);
		data1++;
	}while(data1<5);
	getchar();
}

int d_8_2_2(int a,int b)	//使用参数以及return
{
	return a+b;
}

void d_8_3()	//按值传递机制
{
	//当函数接收到变元的时候，应该知道变元是相对原始数据的副本
	//所以在函数内修改变元对原始数据并不会影响
	//修改原始数据的唯一方式是传递原始数据的指针
}

void d_8_4()	//函数原型
{
	//函数原型是对函数定义的编译初始化
	//防止编译的时候出现未定函数这种错误
	//返回值参数与函数定义相同
}

void d_8_5()	//指针用作参数与返回值
{
	//当指针用作参数的时候可以对源数据进行修改
}


#define COUNT 5

void getInput(char **,size_t *);
void getSort(char **,size_t *);
void printData( char *const*,const size_t *);

void d_8_5_1()	//常量指针参数
{
	//利用指针参数进行排序
	size_t count=COUNT;
	size_t *pcount=&count;
	char **returnData=(char**)calloc(count,sizeof(char*));

	//获取键盘输入并保存到数据中
	getInput(returnData,pcount);
	printf("\n");
	getSort(returnData,pcount);
	printData(returnData,pcount);
	getchar();
}


//输出信息
void printData(char *const* returnData,const size_t *count)
{
	int vcount=*count;
	for(int i=0;i<vcount;i++){
		printf("%s",returnData[i]);
	}
}

//获取排序
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

//获取键盘输入并保存到数据中
void getInput(char **returnData,size_t *count)
{
	char *value=(char*)calloc(100,sizeof(char));
	size_t str_len=0;
	char **pData=NULL;
	size_t str_count=0;
	char *ptr=NULL;
	printf("请输入想要排序的字符串\n");
	while(true)
	{
		ptr=fgets(value,100,stdin);
		if(!ptr)
		{
			printf("获取或转化数据时失败");
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
void d_8_5_2()	//返回指针的风险
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
	//当不想修改传入的变量内容的时候
	//要么使用静态
	//要么重新定义引用
	int new_pay=0;
	new_pay=*pay+1000;
	return &new_pay;
}
void d_8_5_2_2()	//返回指针的风险
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

void d_8_7()	//习题
{
	goto t3;
t1:
	float *data=(float*)calloc(COUNT,sizeof(float));
	int count=COUNT;
	int *pCount=&count;
	//获取输入
	getInput_7(data,pCount);
	//打印输入
	printData_7(data,pCount);
	printf("\n");
	//获取平均值
	getAverage(data,pCount); 
t2:
	printf("请输入一个数字\n");
	int number_2=0;
	scanf_s("%d",&number_2);
	char *str_number=intToString(number_2);
	printf("%s",str_number);

t3:
	printf("请输入一个数字\n");
	int number_3=0;
	scanf_s("%d",&number_3);
	printf("请输入一个数字\n");
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
	itoa(number,str_number,10);//此函数与ANSI标准是不兼容
	return str_number;
}

char * intToString_3(int number,int width)
{
	char *str_number=(char*)calloc(100,sizeof(char));
	//char str_number[100];
	itoa(number,str_number,10);//此函数与ANSI标准是不兼容
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

	printf("%d个浮点数的总和为：%f\t平均值为：%f",*count,sum,average);
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
	printf("请输入要计算的浮点数\n");
	while(true)
	{
		if(!fgets(number,100,stdin))
		{
			printf("传入的数值不正确");
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