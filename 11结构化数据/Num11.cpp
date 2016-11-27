/* 第十一章	结构化数据 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void test()
{
	printf("仅用于测试");
	getchar();
}

void d_11_1()	//使用struct
{
	//可以使用struct定义数据结构
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

void d_11_1_1()	//定义结构类型和结构变量
{
	//可以定义时不指定变量，后续使用的时候再次引用
}

struct Horse1 dobbin2={
	26,170,"xiaosi","father"
};

//typedef struct Horse Horse;	//可以将语句定义在源文件的开头  这样后续引用的时候则不用加struct
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

void d_11_2()	//使用结构
{
	Bug bug;
	printf("请输入虫子的名字\n");
	scanf_s("%s",&bug.name,sizeof(bug.name));
	printf("\n请输入虫子的年龄\n");
	scanf_s("%d",&bug.age,sizeof(bug.age));
	printf("\n请输入虫子的大小\n");
	scanf_s("%d",&bug.width,sizeof(bug.width));
	printf("\n请输入虫子的父亲\n");
	scanf_s("%s",&bug.father,sizeof(bug.father));

	fflush(stdin);

	printf("%s的虫子%s，今年%d岁，%d那么大",bug.father,bug.name,bug.age,bug.width);
	getchar();
}

struct{		//未命名的结构
	int age;
}shenmegui;

void d_11_1_3()	//未命名的结构
{
	//未定义的结构特点
	//只能在定义结构的时候同时定义变量，无法新建其他实例
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
		printf("请输入虫子的名字\n");
		scanf_s("%s",&bugs[i].name,sizeof(bugs[i].name));
		printf("\n请输入虫子的年龄\n");
		scanf_s("%d",&bugs[i].age,sizeof(bugs[i].age));
		printf("\n请输入虫子的大小\n");
		scanf_s("%d",&bugs[i].width,sizeof(bugs[i].width));
		printf("\n请输入虫子的父亲\n");
		scanf_s("%s",&bugs[i].father,sizeof(bugs[i].father));
		printf("\n是否继续?y/n\n");
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
		printf("\n%s的虫子%s，今年%d岁，%d那么大",bugs[i].father,bugs[i].name,bugs[i].age,bugs[i].width);
	}

	/*for each (Bug1_4 var in bugs)
	{
	printf("\n%s的虫子%s，今年%d岁，%d那么大",var.father,var.name,var.age,var.width);
	}*/
	fflush(stdin);
	getchar();
}

void d_11_1_5()	//表达式中的结构成员
{
	//可以直接使用 bugs[1]=bugs[2];
}

void d_11_1_6()	//结构指针
{
	//结构指针的定义
	Bug1_4 bug={1,1,"xiao1","xiaosi"};
	Bug1_4 *p_bug=&bug;
	printf("\n%s的虫子%s，今年%d岁，%d那么大",p_bug->father,p_bug->name,p_bug->age,p_bug->width);
	//访问结构属性的时候也可以使用（*bug）.name
	//.的优先级别高于*，所以要用括号
	getchar();
}

void d_11_1_7()	//动态分配内存
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
		printf("请输入虫子的名字\n");
		scanf_s("%s",&bug.name,sizeof(bug.name));
		printf("\n请输入虫子的年龄\n");
		scanf_s("%d",&bug.age,sizeof(bug.age));
		printf("\n请输入虫子的大小\n");
		scanf_s("%d",&bug.width,sizeof(bug.width));
		printf("\n请输入虫子的父亲\n");
		scanf_s("%s",&bug.father,sizeof(bug.father));
		printf("\n是否继续?y/n\n");
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
		printf("\n%s的虫子%s，今年%d岁，%d那么大",bugs[i].father,bugs[i].name,bugs[i].age,bugs[i].width);
	}
	fflush(stdin);
	getchar();
}

void d_11_1_7_d_2()	//书中的写法更简介
{
	Bug *bugs[50];	//指向数组的指针  
	size_t bug_count=0;

	for(;bug_count<sizeof(bugs)/sizeof(Bug*);)
	{
		bugs[bug_count]=(Bug*)malloc(sizeof(Bug));
		printf("请输入虫子的名字\n");
		scanf_s("%s",&bugs[bug_count]->name,sizeof(bugs[bug_count]->name));
		printf("\n请输入虫子的年龄\n");
		scanf_s("%d",&bugs[bug_count]->age,sizeof(bugs[bug_count]->age));
		printf("\n请输入虫子的大小\n");
		scanf_s("%d",&bugs[bug_count]->width,sizeof(bugs[bug_count]->width));
		printf("\n请输入虫子的父亲\n");
		scanf_s("%s",&bugs[bug_count]->father,sizeof(bugs[bug_count]->father));
		printf("\n是否继续?y/n\n");
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
		printf("\n%s的虫子%s，今年%d岁，%d那么大",bugs[i]->father,bugs[i]->name,bugs[i]->age,bugs[i]->width);
	}
	fflush(stdin);
	getchar();
}

void d_11_2_0()	//再谈结构成员
{
	//结构中属性可包含
	//其他结构(最多15层)
	//指针
	//结构指针
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


void d_11_2_1()	//结构中的结构
{
	Bug2_1 bug;
	bug.dob.year=1991;
	bug.dob.month=4;
	bug.dob.day=4;
	bug.name=(char*)malloc(20*sizeof(char));
	bug.name="小4";
	printf("有一只名字叫%s的小虫子，他的生日是%d年%d月%d日\n",bug.name,bug.dob.year,bug.dob.month,bug.dob.day);
	getchar();
}

struct Bug_2_2{
	char* name;
	unsigned int age;
};
void d_11_2_2()	//声明结构中的结构
{
	//在结构内部定义的结构无法被结构外部声明使用
}

typedef struct Bug_2_3 Bug_2_3;
struct Bug_2_3{
	char name[20];
	Bug_2_3* next;
};

void d_11_2_3()	//将结构指针用作结构成员
{
	const size_t MaxCount=10;	//暂不考虑扩充
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
		printf("请输入虫子的名字\n");
		scanf_s("%s",&bug->name,sizeof(bug->name));
		bug->next=NULL;
		bugList[bugCount]=bug;
		fflush(stdin);
		printf("是否要继续？(y/n)\n");
		scanf_s("%c",&isGoOn,sizeof(isGoOn));
		if(isGoOn=='n')
			break;

		bugCount++;
	}
	/*for(int i=0;i<=bugCount;i++)
	{
	printf("虫子%s的下一个是%s\n",bugList[i]->name,(*(bugList[i]->next)).name);
	}*/
	p_FirstBug=bugList[0];
	while(p_FirstBug!=NULL)	//单向链表
	{
		printf("虫子%s\n",p_FirstBug->name);
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

void d_11_2_4()	//双向链表
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
		printf("请输入虫子的名称\n");
		scanf_s("%s",&bug->name,sizeof(bug->name));
		fflush(stdin);
		bug->Next=NULL;
		printf("是否继续录入?(y/n)\n");
		scanf_s("%c",&isGoOn,sizeof(isGoOn));
		if(isGoOn=='n')
			break;

		Previous=bug;
	}


	while(Firs_Bug!=NULL)
	{
		printf("虫子%s->虫子%s->虫子%s\n"
			,Firs_Bug->Previous!=NULL?Firs_Bug->Previous->name:"头"
			,Firs_Bug->name,Firs_Bug->Next!=NULL?Firs_Bug->Next->name:"尾"
			);
		Firs_Bug=Firs_Bug->Next;
	}
	fflush(stdin);
	getchar();
}

struct //定义位字段 此字段为共占7位
{
	unsigned int flag1:1;
	unsigned int flag2:1;
	unsigned int flag3:2;
	unsigned int flag4:3;
}indeicators;

struct	//此字段为共占用4字节  1+1+2+3+25=32 32/8=4（字节）
{
	unsigned int flag1:1;
	unsigned int flag2:1;
	unsigned int flag3:2;
	unsigned int flag4:3;
	unsigned int :25;

}indeicators2;

struct
{
	char name[20];	//位字段可含有其他属性
	unsigned int flag1:1;
	unsigned int flag2:1;
	unsigned int flag3:2;
	unsigned int flag4:3;
}indeicators3;

void d_11_2_5()	//结构中的位字段
{
	//位字段常用在必须节省内存的情况下
	//常常定义在匿名结构中
	//这个东西很少用，如果缺乏内存，可以尝试一下
}

void d_11_3()	//结构与函数
{
	//结构是c语言中一个强大的特性
}

typedef struct Bug_3 Bug_3;
struct Bug_3
{
	char name[50];
};

void t_11_3_1(Bug_3 bug);

void d_11_3_1()	//作为变元传给函数
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

void d_11_3_2()	//结构指针作为函数变元
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
void d_11_3_3()	//作为函数返回值的结构
{
	Bug_3 bug=CreateBug();//返回结构
	Bug_3 * p_Bug=GetBug_p();	//返回结构指针
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
struct Node		//节点结构
{
	long item;
	unsigned int count;
	Node* n_Left;
	Node* n_Right;
};

Node* CreateNode(long value)	//创建新节点
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

void Print_Nodes(Node* node);	//输出节点
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

void d_11_3_4()	//二叉树
{
	int num=0;
	Node* root=NULL;
	char isGoOn='n';
	while(true)
	{
		printf("请输入数字\n");
		scanf_s("%ld",&num,sizeof(long));
		if(!root)
			root=CreateNode(num);
		else
			AddNode(num,root);
		fflush(stdin);
		printf("是否要继续?(y/n)\n");
		scanf_s("%c",&isGoOn,sizeof(char));
		if(isGoOn=='n')
			break;
	}

	Print_Nodes(root);
	fflush(stdin);
	getchar();
}

typedef union UDate UDate;	//日期(联合)
typedef struct NumDate NumDate;//日期（结构）
struct NumDate{
	int year;
	int month;
	int day;
};

union UDate{
	char date_str[20];
	NumDate numDate;
};
void d_11_4()	//共享内存  union(联合)
{
	//可以将多个变量定义在一个联合之中
	//不同情况下引用不同的变量
	//联合的大小等于联合中最大变量的大小
	NumDate numDate={2016,11,17};
	UDate date={"2016年11月17日"};
	printf("%s\t联合UDate共占内存：%u\n",date.date_str,sizeof(date));
	date.numDate=numDate;
	printf("%d年%d月%d日\t联合UDate共占内存：%u\n",date.numDate.year,date.numDate.month,date.numDate.day,sizeof(date));
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
void PrintfData(char* title,Bar* bar);	//绘制柱状图
void FreeData(Bar* First_bar);//释放内存


void d_11_5()	//设计
{
	//输出月份平均温度的柱状图
	Bar* bar=(Bar*)malloc(sizeof(Bar));
	Bar* First_bar=NULL;
	//1.获取数据
	printf("请输入标题\n");
	char title[50];		//标题
	fgets(title,sizeof(title),stdin);
	fflush(stdin);
	double value=0;	//平均气温
	for(int i=0;i<12;i++)
	{
		printf("请输入%d月的平均气温\n",i+1);
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

	//2.绘制数据
	PrintfData(title,First_bar);
	//3.释放数据
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
void d_11_7_1()	//习题一
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
struct People //人
{
	char *Name;
	char *Tel;
};
#include <string.h>
void d_11_7_2()//习题二
{
	People peoples[50];//定义一个可容纳50人的内存
	char *filter_char=",\n";
	char IsGoOn='n';
	char operation[50];
	size_t peopleCount=0;


	//1.循环录入数据
	while(true){
		size_t people_name_count=0;
		size_t people_tel_count=0;

		char *Got_data=NULL;//用于保存原始数据
		char *p_temp=NULL;//用于存储拆分后的数据
		char *names=(char*)malloc(100*sizeof(char));
		char *tels=(char*)malloc(1000*sizeof(char));

		fflush(stdin);
		//1.1录入人名
		printf("请输入练习人名称,多个联系人请以\',\'隔开\n");
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
		//1.2录入练习方式
		printf("请输入练习人电话,多个联系人电话请以\',\'隔开\n");
		if(fgets(tels,1000*sizeof(char),stdin))
		{
			Got_data=NULL;//用于保存原始数据
			p_temp=NULL;//用于存储拆分后的数据

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
		//1.3是否继续
		printf("是否要继续录入?(y/n)\n");
		scanf_s("%c",&IsGoOn,sizeof(IsGoOn));
		if(IsGoOn!='y')
			break;

	}
	//2.查询
	while(true)
	{

		//是否继续查看
		printf("请输入要查询的练习人（all查询全部,exit推出）\n");
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
	printf("按任意键退出\t（·v·）~拜拜喽");
	getchar();
}

typedef struct People_3 People_3;
struct People_3 //人
{
	char *Name;
	char *Tel;
	People_3 *Next;
};
void d_11_7_3()	//习题三
{
	People_3 *p_First_People=NULL;	//用于存储第一个联系人的地址
	size_t people_Count=0;	//记录联系人个数
	People_3 *p_Temp_People=NULL;	//联系人变量
	char IsGoOn='n';
	char *Filter_char=",\n\0";

	//1 录入练习人
	while(true)
	{
		char *names=(char*)calloc(100,sizeof(char));//名字
		char *tel=(char*)calloc(1000,sizeof(char));//联系电话
		People_3 *p_previous=NULL;	//上一个 用来对next赋值使用
		People_3 *p_whileStart_people=NULL;//本次循环的起点联系人
		size_t people_count_inWhile=0;//本次循环共录入人数
		size_t tel_count_inWhile=0;//本次循环共录入电话数

		//循环录入联系人名称
		fflush(stdin);
		printf("请输入联系人名称，多人请用\',\'隔开\n");
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
			printf("传入参数有误\n");
			goto isgoon;
		}

inputTel:
		//录入练习电话
		fflush(stdin);
		printf("请输入练习人电话，多个请以\',\'隔开\n");
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
			printf("联系电话输入有误\n");
			goto inputTel;
		}

isgoon:
		//循环判断是否继续
		printf("是否要继续输入联系人信息？(y/n)\n");
		fflush(stdin);
		scanf_s("%c",&IsGoOn,stdin);
		if(IsGoOn=='n')
		{
			break;
		}
	}

	//2查询联系人

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
				//交换位置
				//1.上一个数据的指针指向当前数据的下一个数据
				//2.当前数据指针指向下一个的下一个
				//3.下一个的Next指针指向当前
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

	//2.查询
	char operation[100];
	while(true)
	{
		//是否继续查看
		printf("请输入要查询的联系人（all查询全部,exit推出）\n");
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
	printf("结束\n");
	getchar();

}

void main()
{
	d_11_7_3();
}