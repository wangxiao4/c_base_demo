/* ��ʮһ��	�ṹ������ */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void test()
{
	printf("�����ڲ���");
	getchar();
}

void d_11_1()	//ʹ��struct
{
	//����ʹ��struct�������ݽṹ
}
struct Horse{
	int age;
	int height;
}silver;

struct Horse1
{
	int age;
	int height;
	char name[20];
	char father[20];
}dobbin={
	26,170,"xiaosi","father"
};

void d_11_1_1()	//����ṹ���ͺͽṹ����
{
	//���Զ���ʱ��ָ������������ʹ�õ�ʱ���ٴ�����
}

struct Horse1 dobbin2={
	26,170,"xiaosi","father"
};

//typedef struct Horse Horse;	//���Խ���䶨����Դ�ļ��Ŀ�ͷ  �����������õ�ʱ�����ü�struct
//
//Horse trigger={
//				26,170,"xiaosi","father"
//			};

typedef struct Bug Bug;
struct Bug{
	int age;
	int width;
	char name[20];
	char father[20];
};

void d_11_2()	//ʹ�ýṹ
{
	Bug bug;
	printf("��������ӵ�����\n");
	scanf_s("%s",&bug.name,sizeof(bug.name));
	printf("\n��������ӵ�����\n");
	scanf_s("%d",&bug.age,sizeof(bug.age));
	printf("\n��������ӵĴ�С\n");
	scanf_s("%d",&bug.width,sizeof(bug.width));
	printf("\n��������ӵĸ���\n");
	scanf_s("%s",&bug.father,sizeof(bug.father));

	fflush(stdin);

	printf("%s�ĳ���%s������%d�꣬%d��ô��",bug.father,bug.name,bug.age,bug.width);
	getchar();
}

struct{		//δ�����Ľṹ
	int age;
}shenmegui;

void d_11_1_3()	//δ�����Ľṹ
{
	//δ����Ľṹ�ص�
	//ֻ���ڶ���ṹ��ʱ��ͬʱ����������޷��½�����ʵ��
}


typedef struct Bug1_4 Bug1_4;
struct Bug1_4{
	int age;
	int width;
	char name[20];
	char father[20];
};
void d_11_1_4()
{
	Bug1_4 bugs[50];
	unsigned int bug_count=0;
	for(int i=0;i<sizeof(bugs)/sizeof(Bug1_4);i++)
	{
		printf("��������ӵ�����\n");
		scanf_s("%s",&bugs[i].name,sizeof(bugs[i].name));
		printf("\n��������ӵ�����\n");
		scanf_s("%d",&bugs[i].age,sizeof(bugs[i].age));
		printf("\n��������ӵĴ�С\n");
		scanf_s("%d",&bugs[i].width,sizeof(bugs[i].width));
		printf("\n��������ӵĸ���\n");
		scanf_s("%s",&bugs[i].father,sizeof(bugs[i].father));
		printf("\n�Ƿ����?y/n\n");
		bug_count++;
		fflush(stdin);
		char isGoOn;
		scanf_s("%c",&isGoOn,sizeof(isGoOn));
		if(tolower(isGoOn)=='n')
		{
			break;
		}
	}

	for(int i=0;i<bug_count;i++)
	{
		printf("\n%s�ĳ���%s������%d�꣬%d��ô��",bugs[i].father,bugs[i].name,bugs[i].age,bugs[i].width);
	}

	/*for each (Bug1_4 var in bugs)
	{
	printf("\n%s�ĳ���%s������%d�꣬%d��ô��",var.father,var.name,var.age,var.width);
	}*/
	fflush(stdin);
	getchar();
}

void d_11_1_5()	//���ʽ�еĽṹ��Ա
{
	//����ֱ��ʹ�� bugs[1]=bugs[2];
}

void d_11_1_6()	//�ṹָ��
{
	//�ṹָ��Ķ���
	Bug1_4 bug={1,1,"xiao1","xiaosi"};
	Bug1_4 *p_bug=&bug;
	printf("\n%s�ĳ���%s������%d�꣬%d��ô��",p_bug->father,p_bug->name,p_bug->age,p_bug->width);
	//���ʽṹ���Ե�ʱ��Ҳ����ʹ�ã�*bug��.name
	//.�����ȼ������*������Ҫ������
	getchar();
}

void d_11_1_7()	//��̬�����ڴ�
{
	size_t MaxCount=5;
	size_t NowCount=0;
	Bug *bugs=NULL;
	bugs=(Bug*)malloc(MaxCount*sizeof(Bug));
	while(true)
	{
		if(NowCount==MaxCount)
		{
			MaxCount+=MaxCount/4;
			Bug *temp=(Bug*)realloc(bugs,MaxCount*sizeof(Bug));
			bugs=temp;
		}
		Bug bug;
		printf("��������ӵ�����\n");
		scanf_s("%s",&bug.name,sizeof(bug.name));
		printf("\n��������ӵ�����\n");
		scanf_s("%d",&bug.age,sizeof(bug.age));
		printf("\n��������ӵĴ�С\n");
		scanf_s("%d",&bug.width,sizeof(bug.width));
		printf("\n��������ӵĸ���\n");
		scanf_s("%s",&bug.father,sizeof(bug.father));
		printf("\n�Ƿ����?y/n\n");
		fflush(stdin);

		bugs[NowCount]=bug;

		char isGoOn;
		scanf_s("%c",&isGoOn,sizeof(isGoOn));
		if(tolower(isGoOn)=='n')
		{
			break;
		}

		NowCount++;
	}
	for(int i=0;i<=NowCount;i++)
	{
		printf("\n%s�ĳ���%s������%d�꣬%d��ô��",bugs[i].father,bugs[i].name,bugs[i].age,bugs[i].width);
	}
	fflush(stdin);
	getchar();
}

void d_11_1_7_d_2()	//���е�д�������
{
	Bug *bugs[50];	//ָ�������ָ��  
	size_t bug_count=0;

	for(;bug_count<sizeof(bugs)/sizeof(Bug*);)
	{
		bugs[bug_count]=(Bug*)malloc(sizeof(Bug));
		printf("��������ӵ�����\n");
		scanf_s("%s",&bugs[bug_count]->name,sizeof(bugs[bug_count]->name));
		printf("\n��������ӵ�����\n");
		scanf_s("%d",&bugs[bug_count]->age,sizeof(bugs[bug_count]->age));
		printf("\n��������ӵĴ�С\n");
		scanf_s("%d",&bugs[bug_count]->width,sizeof(bugs[bug_count]->width));
		printf("\n��������ӵĸ���\n");
		scanf_s("%s",&bugs[bug_count]->father,sizeof(bugs[bug_count]->father));
		printf("\n�Ƿ����?y/n\n");
		bug_count++;
		fflush(stdin);
		char isGoOn;
		scanf_s("%c",&isGoOn,sizeof(isGoOn));
		if(tolower(isGoOn)=='n')
		{
			break;
		}
	}
	for(int i=0;i<bug_count;i++)
	{
		printf("\n%s�ĳ���%s������%d�꣬%d��ô��",bugs[i]->father,bugs[i]->name,bugs[i]->age,bugs[i]->width);
	}
	fflush(stdin);
	getchar();
}

void d_11_2_0()	//��̸�ṹ��Ա
{
	//�ṹ�����Կɰ���
	//�����ṹ(���15��)
	//ָ��
	//�ṹָ��
	getchar();
}

typedef struct Bug2_1 Bug2_1;
typedef struct Date2_1 Date2_1;
struct Date2_1
{
	int year;
	int month;
	int day;
};
struct Bug2_1
{
	Date2_1 dob;
	char *name;
};


void d_11_2_1()	//�ṹ�еĽṹ
{
	Bug2_1 bug;
	bug.dob.year=1991;
	bug.dob.month=4;
	bug.dob.day=4;
	bug.name=(char*)malloc(20*sizeof(char));
	bug.name="С4";
	printf("��һֻ���ֽ�%s��С���ӣ�����������%d��%d��%d��\n",bug.name,bug.dob.year,bug.dob.month,bug.dob.day);
	getchar();
}

struct Bug_2_2{
	char* name;
	unsigned int age;
};
void d_11_2_2()	//�����ṹ�еĽṹ
{
	//�ڽṹ�ڲ�����Ľṹ�޷����ṹ�ⲿ����ʹ��
}

typedef struct Bug_2_3 Bug_2_3;
struct Bug_2_3{
	char name[20];
	Bug_2_3* next;
};

void d_11_2_3()	//���ṹָ�������ṹ��Ա
{
	const size_t MaxCount=10;	//�ݲ���������
	Bug_2_3* bugList[MaxCount];
	size_t bugCount=0;
	Bug_2_3* p_FirstBug=NULL;
	for(;bugCount<MaxCount;)
	{
		bugList[bugCount]=(Bug_2_3*)malloc(sizeof(Bug_2_3));
		Bug_2_3* bug=(Bug_2_3*)malloc(sizeof(Bug_2_3));
		if(bugCount>0){
			bugList[bugCount-1]->next=bug;
		}
		char isGoOn=' ';
		printf("��������ӵ�����\n");
		scanf_s("%s",&bug->name,sizeof(bug->name));
		bug->next=NULL;
		bugList[bugCount]=bug;
		fflush(stdin);
		printf("�Ƿ�Ҫ������(y/n)\n");
		scanf_s("%c",&isGoOn,sizeof(isGoOn));
		if(isGoOn=='n')
			break;

		bugCount++;
	}
	/*for(int i=0;i<=bugCount;i++)
	{
	printf("����%s����һ����%s\n",bugList[i]->name,(*(bugList[i]->next)).name);
	}*/
	p_FirstBug=bugList[0];
	while(p_FirstBug!=NULL)	//��������
	{
		printf("����%s\n",p_FirstBug->name);
		p_FirstBug=p_FirstBug->next;
	}

	fflush(stdin);
	getchar();
}

typedef struct Bug_2_4 Bug_2_4;
struct Bug_2_4{
	Bug_2_4* Previous;
	char name[20];
	Bug_2_4* Next;
};

void d_11_2_4()	//˫������
{
	Bug_2_4* Previous=NULL;
	Bug_2_4* Next=NULL;
	const size_t MaxCount=10;
	Bug_2_4 *Firs_Bug=NULL;
	char isGoOn=' ';
	for(int i=0;i<MaxCount;i++)
	{
		Bug_2_4* bug=(Bug_2_4*)malloc(sizeof(Bug_2_4));
		bug->Previous=Previous;
		if(i>0)
			Previous->Next=bug;
		else
			Firs_Bug=bug;
		printf("��������ӵ�����\n");
		scanf_s("%s",&bug->name,sizeof(bug->name));
		fflush(stdin);
		bug->Next=NULL;
		printf("�Ƿ����¼��?(y/n)\n");
		scanf_s("%c",&isGoOn,sizeof(isGoOn));
		if(isGoOn=='n')
			break;

		Previous=bug;
	}


	while(Firs_Bug!=NULL)
	{
		printf("����%s->����%s->����%s\n"
			,Firs_Bug->Previous!=NULL?Firs_Bug->Previous->name:"ͷ"
			,Firs_Bug->name,Firs_Bug->Next!=NULL?Firs_Bug->Next->name:"β"
			);
		Firs_Bug=Firs_Bug->Next;
	}
	fflush(stdin);
	getchar();
}

struct //����λ�ֶ� ���ֶ�Ϊ��ռ7λ
{
	unsigned int flag1:1;
	unsigned int flag2:1;
	unsigned int flag3:2;
	unsigned int flag4:3;
}indeicators;

struct	//���ֶ�Ϊ��ռ��4�ֽ�  1+1+2+3+25=32 32/8=4���ֽڣ�
{
	unsigned int flag1:1;
	unsigned int flag2:1;
	unsigned int flag3:2;
	unsigned int flag4:3;
	unsigned int :25;

}indeicators2;

struct
{
	char name[20];	//λ�ֶοɺ�����������
	unsigned int flag1:1;
	unsigned int flag2:1;
	unsigned int flag3:2;
	unsigned int flag4:3;
}indeicators3;

void d_11_2_5()	//�ṹ�е�λ�ֶ�
{
	//λ�ֶγ����ڱ����ʡ�ڴ�������
	//���������������ṹ��
	//������������ã����ȱ���ڴ棬���Գ���һ��
}

void d_11_3()	//�ṹ�뺯��
{
	//�ṹ��c������һ��ǿ�������
}

typedef struct Bug_3 Bug_3;
struct Bug_3
{
	char name[50];
};

void t_11_3_1(Bug_3 bug);

void d_11_3_1()	//��Ϊ��Ԫ��������
{
	Bug_3 bug={"xiao4"};
	t_11_3_1(bug);
	getchar();
}

void t_11_3_1(Bug_3 bug)
{
	printf(bug.name);
}

void t_11_3_2(Bug_3 * bug);

void d_11_3_2()	//�ṹָ����Ϊ������Ԫ
{
	Bug_3 bug={"xiao4"};
	Bug_3 *p_bug=&bug;
	t_11_3_2(p_bug);
	getchar();
}
void t_11_3_2(Bug_3 * bug)
{
	printf(bug->name);
}

Bug_3 CreateBug();
Bug_3* GetBug_p();
void d_11_3_3()	//��Ϊ��������ֵ�Ľṹ
{
	Bug_3 bug=CreateBug();//���ؽṹ
	Bug_3 * p_Bug=GetBug_p();	//���ؽṹָ��
	printf("%s",p_Bug->name);
	printf("\n%s",bug.name);
	getchar();
}

Bug_3 CreateBug(){
	Bug_3 bug={"xiao4"};
	return bug;
}

Bug_3* GetBug_p()
{
	Bug_3 bug1={"xiaosi"};
	Bug_3 * p_bug=&bug1;
	return p_bug;
}

typedef struct Node Node;
struct Node		//�ڵ�ṹ
{
	long item;
	unsigned int count;
	Node* n_Left;
	Node* n_Right;
};

Node* CreateNode(long value)	//�����½ڵ�
{
	Node* node=(Node*)malloc(sizeof(Node));
	node->item=value;
	node->count=1;
	node->n_Left=node->n_Right=NULL;
	return node;
}

Node* AddNode(long value,Node* pNode)
{
	if(!pNode){
		return CreateNode(value);
	}

	if(value==pNode->item)
	{
		++pNode->count;
		return pNode;
	}
	if(value<pNode->item)
	{
		if(!pNode->n_Left)
		{
			Node* node =CreateNode(value);
			pNode->n_Left=node;
			return node;
		}else
		{
			return AddNode(value,pNode->n_Left);
		}
	}else
	{
		if(!pNode->n_Right)
		{
			Node* node=CreateNode(value);
			pNode->n_Right=node;
			return node;
		}else
		{
			return AddNode(value,pNode->n_Right);
		}
	}
}

void Print_Nodes(Node* node);	//����ڵ�
void Print_Nodes(Node* node)
{
	if(node->n_Left)
	{
		Print_Nodes(node->n_Left);
	}
	printf("count:%d\t value:%ld\n",node->count,node->item);
	if(node->n_Right)
	{
		Print_Nodes(node->n_Right);
	}
}

void d_11_3_4()	//������
{
	int num=0;
	Node* root=NULL;
	char isGoOn='n';
	while(true)
	{
		printf("����������\n");
		scanf_s("%ld",&num,sizeof(long));
		if(!root)
			root=CreateNode(num);
		else
			AddNode(num,root);
		fflush(stdin);
		printf("�Ƿ�Ҫ����?(y/n)\n");
		scanf_s("%c",&isGoOn,sizeof(char));
		if(isGoOn=='n')
			break;
	}

	Print_Nodes(root);
	fflush(stdin);
	getchar();
}

typedef union UDate UDate;	//����(����)
typedef struct NumDate NumDate;//���ڣ��ṹ��
struct NumDate{
	int year;
	int month;
	int day;
};

union UDate{
	char date_str[20];
	NumDate numDate;
};
void d_11_4()	//�����ڴ�  union(����)
{
	//���Խ��������������һ������֮��
	//��ͬ��������ò�ͬ�ı���
	//���ϵĴ�С�����������������Ĵ�С
	NumDate numDate={2016,11,17};
	UDate date={"2016��11��17��"};
	printf("%s\t����UDate��ռ�ڴ棺%u\n",date.date_str,sizeof(date));
	date.numDate=numDate;
	printf("%d��%d��%d��\t����UDate��ռ�ڴ棺%u\n",date.numDate.year,date.numDate.month,date.numDate.day,sizeof(date));
	getchar();
}

#define PAGE_HEIGHT 41
#define PAGE_WIDTH 75
typedef unsigned int uint;
typedef struct Bar Bar;
struct Bar{
	double value;
	Bar* Next;
};
void PrintfData(char* title,Bar* bar);	//������״ͼ
void FreeData(Bar* First_bar);//�ͷ��ڴ�


void d_11_5()	//���
{
	//����·�ƽ���¶ȵ���״ͼ
	Bar* bar=(Bar*)malloc(sizeof(Bar));
	Bar* First_bar=NULL;
	//1.��ȡ����
	printf("���������\n");
	char title[50];		//����
	fgets(title,sizeof(title),stdin);
	fflush(stdin);
	double value=0;	//ƽ������
	for(int i=0;i<12;i++)
	{
		printf("������%d�µ�ƽ������\n",i+1);
		scanf_s("%lf",&value,sizeof(value));

		Bar* temp=(Bar*)malloc(sizeof(Bar));
		temp->Next=NULL;
		temp->value=value;
		if(!First_bar)
		{
			First_bar=(Bar*)malloc(sizeof(Bar));
			First_bar=temp;
		}else
		{
			bar->Next=temp;
		}
		bar=temp;
	}

	//2.��������
	PrintfData(title,First_bar);
	//3.�ͷ�����
	FreeData(First_bar);

	fflush(stdin);
	getchar();
}
void PrintfData(char* title,Bar* bar)
{
	printf("^%s",title);
	for(int i=0;i<PAGE_HEIGHT;i++)
	{
		if(i==21){
			for(int j=0;j<PAGE_WIDTH-1;j++){
				printf("-");
			}
			printf(">\n");
		}
		else
		{
			printf("|");
			Bar* num= (Bar*)malloc(sizeof(Bar));
			num=bar;

			while(num){
				if((num->value>20-i&&21-i>0&&num->value>0)||(21-i<0&&num->value<21-i&&num->value<0))
				{
					printf("  ****");
				}else{
					printf("      ");
				}
				num=num->Next;
			}
			printf("\n");
		}
	}
}

void FreeData(Bar* First_bar)
{
	Bar* temp=NULL;
	while(temp){
		temp=First_bar->Next;
		free(First_bar);
		First_bar=temp;
	}
}


typedef struct Length Length;
struct Length
{
	int width_M;
	int width_CM;
	int width_MM;
};
Length* add(const Length* l1,const Length* l2);
void show(const Length length);
void d_11_7_1()	//ϰ��һ
{
	Length Length1;
	Length1.width_CM=1;
	Length1.width_M=1;
	Length1.width_MM=1;
	Length Length2;
	Length2.width_CM=2;
	Length2.width_M=2;
	Length2.width_MM=2;

	show(*(add(&Length1,&Length2)));
	getchar();
}
Length* add(const Length* l1,const Length* l2)
{
	Length Length;
	Length.width_CM=l1->width_CM+l2->width_CM;
	Length.width_M=l1->width_M+l2->width_M;
	Length.width_MM=l1->width_MM+l2->width_MM;

	return &Length;
}
void show(const Length length)
{
	printf("M:%d\tCM:%d\tMM:%d\n",length.width_M,length.width_CM,length.width_MM);
}

typedef struct People People;
struct People //��
{
	char *Name;
	char *Tel;
};
#include <string.h>
void d_11_7_2()//ϰ���
{
	People peoples[50];//����һ��������50�˵��ڴ�
	char *filter_char=",\n";
	char IsGoOn='n';
	char operation[50];
	size_t peopleCount=0;


	//1.ѭ��¼������
	while(true){
		size_t people_name_count=0;
		size_t people_tel_count=0;

		char *Got_data=NULL;//���ڱ���ԭʼ����
		char *p_temp=NULL;//���ڴ洢��ֺ������
		char *names=(char*)malloc(100*sizeof(char));
		char *tels=(char*)malloc(1000*sizeof(char));

		fflush(stdin);
		//1.1¼������
		printf("��������ϰ������,�����ϵ������\',\'����\n");
		if(fgets(names,100*sizeof(char),stdin))
		{
			p_temp=strtok_s(names,filter_char,&Got_data);
			while(p_temp)
			{
				if(p_temp)
				{
					People* people=(People*)malloc(sizeof(People));
					people->Name=p_temp;
					people->Tel="";
					peoples[peopleCount+people_name_count]=*people;
					//peoples[peopleCount+people_name_count].Name=*p_temp;
					people_name_count++;
					p_temp=strtok_s(NULL,filter_char,&Got_data);
				}
			}
		}
		fflush(stdin);
		//1.2¼����ϰ��ʽ
		printf("��������ϰ�˵绰,�����ϵ�˵绰����\',\'����\n");
		if(fgets(tels,1000*sizeof(char),stdin))
		{
			Got_data=NULL;//���ڱ���ԭʼ����
			p_temp=NULL;//���ڴ洢��ֺ������

			p_temp=strtok_s(tels,filter_char,&Got_data);
			while(p_temp)
			{
				if(p_temp)
				{
					if(people_tel_count<=people_name_count){
						peoples[peopleCount+people_tel_count].Tel=p_temp;
						people_tel_count++;
						p_temp=strtok_s(NULL,filter_char,&Got_data);
					}else{
						p_temp=NULL;
					}
				}
			}
		}

		peopleCount+=people_name_count;
		/*
		free(Got_data);
		free(p_temp);*/
		//1.3�Ƿ����
		printf("�Ƿ�Ҫ����¼��?(y/n)\n");
		scanf_s("%c",&IsGoOn,sizeof(IsGoOn));
		if(IsGoOn!='y')
			break;

	}
	//2.��ѯ
	while(true)
	{

		//�Ƿ�����鿴
		printf("������Ҫ��ѯ����ϰ�ˣ�all��ѯȫ��,exit�Ƴ���\n");
		scanf_s("%s",&operation,sizeof(operation));
		if(!strcmp("exit",operation))
		{
			break;
		}
		else 
		{
			bool isAll=false;
			if(!strcmp("all",operation))
				isAll=true;
			for(int i=0;i<peopleCount;i++)
			{
				if(!strcmp(operation,peoples[i].Name)||isAll){
					printf("%s:%s\n",peoples[i].Name,peoples[i].Tel);
				}
			}
		}
	}
	fflush(stdin);
	printf("��������˳�\t����v����~�ݰ��");
	getchar();
}

typedef struct People_3 People_3;
struct People_3 //��
{
	char *Name;
	char *Tel;
	People_3 *Next;
};
void d_11_7_3()	//ϰ����
{
	People_3 *p_First_People=NULL;	//���ڴ洢��һ����ϵ�˵ĵ�ַ
	size_t people_Count=0;	//��¼��ϵ�˸���
	People_3 *p_Temp_People=NULL;	//��ϵ�˱���
	char IsGoOn='n';
	char *Filter_char=",\n\0";

	//1 ¼����ϰ��
	while(true)
	{
		char *names=(char*)calloc(100,sizeof(char));//����
		char *tel=(char*)calloc(1000,sizeof(char));//��ϵ�绰
		People_3 *p_previous=NULL;	//��һ�� ������next��ֵʹ��
		People_3 *p_whileStart_people=NULL;//����ѭ���������ϵ��
		size_t people_count_inWhile=0;//����ѭ����¼������
		size_t tel_count_inWhile=0;//����ѭ����¼��绰��

		//ѭ��¼����ϵ������
		fflush(stdin);
		printf("��������ϵ�����ƣ���������\',\'����\n");
		if(fgets(names,100*sizeof(char),stdin))
		{
			char *p_names=NULL;
			char *p_temp_names=NULL;
			p_temp_names=strtok_s(names,Filter_char,&p_names);
			while(p_temp_names)
			{
				if(p_temp_names)
				{
					People_3 *people=(People_3*)malloc(sizeof(People_3)); 
					people->Name=p_temp_names;
					people->Next=NULL;
					people->Tel=NULL;

					if(!people_count_inWhile)
					{
						p_whileStart_people=people;
						if(!p_First_People)
						{
							p_First_People=people;
						}else
						{
							p_Temp_People->Next=people;
						}
					}else{
						p_previous->Next=people;
					}
					people_count_inWhile++;
					p_Temp_People=p_previous=people;
					p_temp_names=strtok_s(NULL,Filter_char,&p_names);
				}
			}
		}else
		{
			printf("�����������\n");
			goto isgoon;
		}

inputTel:
		//¼����ϰ�绰
		fflush(stdin);
		printf("��������ϰ�˵绰���������\',\'����\n");
		if(fgets(tel,1000*sizeof(char),stdin))
		{
			char *p_tel=NULL;
			char *p_temp_names=NULL;
			People_3 *people=p_whileStart_people; 
			p_temp_names=strtok_s(tel,Filter_char,&p_tel);
			while(p_temp_names)
			{
				if(p_temp_names&&tel_count_inWhile<=people_count_inWhile)
				{
					people->Tel=p_temp_names;
					if(people->Next)
					{
						people=people->Next;
					}
					tel_count_inWhile++;
					p_temp_names=strtok_s(NULL,Filter_char,&p_tel);
				}else{
					break;
				}
			}
		}else
		{
			printf("��ϵ�绰��������\n");
			goto inputTel;
		}

isgoon:
		//ѭ���ж��Ƿ����
		printf("�Ƿ�Ҫ����������ϵ����Ϣ��(y/n)\n");
		fflush(stdin);
		scanf_s("%c",&IsGoOn,stdin);
		if(IsGoOn=='n')
		{
			break;
		}
	}

	//2��ѯ��ϵ��

	bool isChange=true;
	while(isChange){
		People_3 *test_people=p_First_People;
		People_3 *test_prevous_people=NULL;
		isChange=false;
		int count=0;
		while(test_people)
		{
			if(test_people->Next!=NULL&&strcmp(test_people->Name,test_people->Next->Name)>0)
			{
				if(count==0){
					p_First_People=test_people->Next;
				}
				//����λ��
				//1.��һ�����ݵ�ָ��ָ��ǰ���ݵ���һ������
				//2.��ǰ����ָ��ָ����һ������һ��
				//3.��һ����Nextָ��ָ��ǰ
				People_3 *temp=test_people->Next;
				if(test_prevous_people){
					test_prevous_people->Next=temp;
				}
				test_prevous_people=temp;

				test_people->Next=test_people->Next->Next;
				temp->Next=test_people;

				isChange=true;
			}else{
				test_prevous_people=test_people;
				test_people=test_people->Next;
			}
			count++;
		}
	}

	//2.��ѯ
	char operation[100];
	while(true)
	{
		//�Ƿ�����鿴
		printf("������Ҫ��ѯ����ϵ�ˣ�all��ѯȫ��,exit�Ƴ���\n");
		scanf_s("%s",&operation,100*sizeof(char));
		if(!strcmp("exit",operation))
		{
			break;
		}
		else 
		{
			bool isAll=false;
			if(!strcmp("all",operation))
				isAll=true;
			People_3 *startPoeple=p_First_People;
			while(startPoeple)
			{
				if(!strcmp(operation,startPoeple->Name)||isAll){
					printf("%s:%s\n",startPoeple->Name,startPoeple->Tel);
				}
				startPoeple=startPoeple->Next;
			}
		}
	}
	fflush(stdin);
	printf("����\n");
	getchar();

}

void main()
{
	d_11_7_3();
}