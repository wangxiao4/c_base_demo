/* 处理文件 */
#include <stdio.h>
#include <stdlib.h>


void test()
{
	printf("仅用于测试");
	getchar();
}

void d_12_1()	//文件的概念
{
	//文件本身是一系列字节
}

void d_12_1_1()	//文件中的位置
{
	//文件有开头和结尾
	//还有一个当前位置
	//可以指定当前位置与开头的偏移量
	//可以制定与当前位置的正负偏移量
}

void d_12_1_2()	//文件流
{
	//数据可以以文本或者二进制形式写入文件中
	//读取的时候都是字节，所以程序必须直到这个文件包含什么种类的数据
}

void d_12_2()	//文件访问
{
	//FILE 文件指针类型 属于stdio.h
}

void d_12_2_1()	//打开文件
{
	FILE *pfile=NULL;
	char *fileName="d:\\MyDemo\\myFile.txt";
	if(!fopen_s(&pfile,fileName,"w"))
	{
		printf("创建了文件%s\n",fileName);
	}
	fileName="d:\\Code\\C\\B\\myFile.txt";	//当路径不存在的时候  w创建失败
	if(!fopen_s(&pfile,fileName,"w"))
	{
		printf("创建了文件%s\n",fileName);
	}else
	{
		printf("创建文件%s失败",fileName);
	}

	//还有  a  追加  以及  r  读取操作

	getchar();
}

void d_12_2_2()	//缓存文件操作
{
	//_IOFBF使文件全部缓存
	//_IOLBF缓存一行
	//_IONBF不缓存（以字节为单位）
	FILE *pflie=NULL;
	char *fileName="d:\\MyDemo\\myFile.txt";
	if(!fopen_s(&pflie,fileName,"a")){
		size_t bufsize=1024;
		if(setvbuf(pflie,NULL,_IOFBF,bufsize))
		{
			printf("缓存%s数据成功\n",fileName);
		}else
		{
			printf("缓存文件失败");
		}
	}else{
		printf("打开文件失败");
	}
	getchar();
}

void d_12_2_3()	//文件重命名与删除
{
	//			原始名字				修改后的名字
	if(rename("d:\\MyDemo\\myFile.txt","d:\\MyDemo\\myFile_copy.txt"))
	{
		//成功返回0
		printf("修改成功");
	}
	remove("d:\\MyDemo\\myFile.txt");	//删除文件
}

void d_12_2_4()	//关闭文件
{
	FILE *pflie=NULL;
	char *fileName="d:\\MyDemo\\myFile.txt";
	if(!fopen_s(&pflie,fileName,"a")){
		if(!fclose(pflie))	//如果成功关闭  返回0 否则返回EOF
		{
			printf("成功关闭");
			pflie=NULL;
		}else{
			printf("关闭失败");
		}
	}
	getchar();
}

void d_12_3()	//写入文本文件
{
	FILE *pflie=NULL;
	char *fileName="d:\\MyDemo\\myFile.txt";//确保含有此路径
	if(!fopen_s(&pflie,fileName,"w"))
	{
		if(fputs("this is a test",pflie)!=EOF){//写入char[]  还有fputc
			printf("写入成功");
		}else{
			printf("写入失败");
		}
		fclose(pflie);
		pflie=NULL;
	}else{
		printf("打开文件失败");
	}
	getchar();
}

void d_12_4()	//读取文本文件
{
	FILE *pfile=NULL;
	char *fileName="d:\\MyDemo\\myFile.txt";
	char *putDemo=(char*)calloc(100,sizeof(char));
	char *getDemo=(char*)calloc(100,sizeof(char));
	if(!fopen_s(&pfile,fileName,"w"))
	{
		printf("请输入要写入的内容\n");
		if(fgets(putDemo,100*sizeof(char),stdin)){
			if(fputs(putDemo,pfile)!=EOF)
			{
				fclose(pfile);
				pfile=NULL;
				printf("写入完成\n");
			}else
			{
				printf("写入文件失败\n");
			}
		}else
		{
			printf("录入失败\n");
		}
	}else{
		printf("打开文件%s失败\n",fileName);
	}
	if(!fopen_s(&pfile,fileName,"r"))	//注意读取用“r”
	{
		if(fgets(getDemo,100*sizeof(char),pfile))
		{
			printf("%s\n",getDemo);
		}else{
			printf("%s\n",getDemo);
		}
		fclose(pfile);
		pfile=NULL;
	}else{
		printf("打开文件%s失败\n",fileName);
	}
	getchar();
}
#include <string.h>
#define MaxCount 1
void d_12_5()	//读取文本中的字符串
{
	//用fgets 指定数据源为FILE*就可以了 详细看12.4代码
	FILE *pfile=NULL;		//文件流地址
	char *fileName="d:\\MyDemo\\myFile.txt";	//文件名
	char **strings=(char**)calloc(MaxCount,sizeof(char*));	//输入的字符串
	size_t str_Max_count=MaxCount;
	size_t str_count=0;
	printf("exit 退出录入\n");
	while(true)
	{
		char *str=(char *)calloc(100,sizeof(char));
		if(fgets(str,100*sizeof(char),stdin)){
			if(!strcmp(str,"exit\n")){
				break;
			}
			if(str_count==str_Max_count){
				str_Max_count++;
				char **strs_temp=(char**)realloc(strings,str_Max_count*100*sizeof(char));
				strings=strs_temp;
			}
			strings[str_count]=(char*)calloc(100,sizeof(char));
			strings[str_count]=str;
		}
		str_count++;
	}

	if(!fopen_s(&pfile,fileName,"w"))
	{
		for(int i=0;i<str_count;i++)
		{
			if(fputs(strings[i],pfile)==EOF)
			{
				printf("向文件写入%s时出错\n",strings[i]);
			}
		}
		fclose(pfile);
		pfile=NULL;
	}else
	{
		printf("录入时打开文件失败");
	}

	char *str=(char *)calloc(100,sizeof(char));
	if(!fopen_s(&pfile,fileName,"r"))
	{
		while(fgets(str,100*sizeof(char),pfile)){
			printf("%s",str);
		}
		fclose(pfile);
		pfile=NULL;
	}else
	{
		printf("读取时打开文件失败");
	}
	free(str);
	str=NULL;

	fflush(stdin);
	getchar();
}

void d_12_6()	//格式化文件的输入输出
{
	//有些时候需要将数字数组或者其他非char类型数据存入
}

void d_12_6_1()	//格式化文件输出
{
	FILE* pfile=NULL;
	int num1=1;
	float num_f1=0.002F;
	double num_f2=0.00003;
	char *fileName="d:\\MyDemo\\myFile.txt";
	if(fopen_s(&pfile,fileName,"w")!=EOF)
	{
		if(0>fprintf_s(pfile,"num1=%d\tnum_f1=%f\tnum_f2=%lf",num1,num_f1,num_f2))
		{
			printf("写入有问题\n");
		}
		fclose(pfile);
		pfile=NULL;
	}
}

void d_12_6_2()	//格式化文件输入
{
	FILE* pfile=NULL;
	char* fileName="d:\\MyDemo\\myFile.txt";
	double PI=3.1415926;

	if(fopen_s(&pfile,fileName,"w")!=EOF)
	{
		if(0>fprintf(pfile,"PI=%6lf",PI))
		{
			printf("写入文件失败\n");
		}
		fclose(pfile);
		pfile=NULL;
	}else
	{
		printf("文件写入失败\n");
	}

	if(fopen_s(&pfile,fileName,"r")!=EOF)
	{
		fscanf_s(pfile,"PI=%6lf",&PI);
		printf("读取PI=%6lf",PI);
		fclose(pfile);
		pfile=NULL;
	}
	getchar();
}

void d_12_7()	//错误处理
{
	FILE* pfile=NULL;
	char* fileName="d:\\MyDeo\\myFile.txt";

	if(fopen_s(&pfile,fileName,"r"))
	{
		//如果打开文件时出现问题
		fprintf(stderr,"打开文件%s的时候出现点问题",fileName);
	}
	getchar();
}

void d_12_8()	//再谈文本文件操作模式
{
	//模式			说明
	//r				打开文件并读取
	//r+			读写
	//w				写入，创建，覆盖
	//wx			非共享写入
	//w+			w基础上增加更新
	//w+x			非共享写入更新
	//a				追加到末尾
	//a+			更新并追加到末尾
}

void d_12_9()	//freopen_s
{
	FILE* pfile=NULL;
	char* fileName="d:\\MyDemo\\myFile.txt";
	if(freopen_s(&pfile,fileName,"w+",stdout))//将标准流重新赋予一个文件
	{
		printf("重定向输出流失败");
	}else{
		printf("目前输出操作会转到文本中");
	}
	getchar();
}

void d_12_10()	//二进制文件
{
	//二进制文件操作要不比文本操作更简洁
	//二进制文件没有精度损失
	//二进制文件没有类型转换
	//二进制文件查看起来更麻烦
}

void d_12_10_1()	//打开文本
{
	//所有模式加b
	//模式			说明
	//r				打开文件并读取
	//r+			读写
	//w				写入，创建，覆盖
	//wx			非共享写入
	//w+			w基础上增加更新
	//w+x			非共享写入更新
	//a				追加到末尾
	//a+			更新并追加到末尾
}

void d_12_10_2()	//写入二进制文件
{
	FILE* pfile=NULL;
	char* fileName="d:\\MyDemo\\myFile.bin";
	if(fopen_s(&pfile,fileName,"w+"))
	{
		printf("打开文件失败\n");
	}else
	{
		long data[]={2L,3L,4L};
		size_t num_items=sizeof(data)/sizeof(long);
		//使用fwrite()函数写入二进制数据
		//参数：1.数据指针	2.数据类型字节数	3.数据个数	4.文件流指针
		size_t wcount=fwrite(data,sizeof(long),num_items,pfile);
		fclose(pfile);
		pfile=NULL;
		printf("写入二进制成功");
	}
	getchar();
}



void d_12_10_3()	//读取二进制文件
{
	FILE* pfile=NULL;
	char* fileName="d:\\MyDemo\\myFile.bin";
	if(fopen_s(&pfile,fileName,"r+"))
	{
		printf("打开文件失败\n");
	}else
	{
		long data[3];
		size_t num_items=sizeof(data)/sizeof(long);
		//使用fwrite()函数写入二进制数据
		//参数：1.数据指针	2.数据类型字节数	3.数据个数	4.文件流指针
		size_t wcount=0;
		while(!feof(pfile)){
			wcount=fread(data,sizeof(long),num_items,pfile);
		}
		fclose(pfile);
		pfile=NULL;
		for(int i=0;i<wcount;i++)
		{
			printf("%ld\t",data[i]);
		}
	}
	getchar();
}

void d_12_11()	//在文件中移动
{
	//当文件中包含过多数据的时候，我们要访问到中间的数据时就需要移动当前指针到文件中间部分
}

void d_12_11_1()	//文件定位操作
{
	//在windows系统中操作文本文件的时候要注意那些特殊的字符，(\n \0 ……)
}

void d_12_11_2()	//找出我们在文件中的位置
{
	//long ftell(FILE* pfile)	返回当前位置（距离文件开头）
	//long fgetpos(FILE* pfile,fpos_t*)	返回0(正确)或非0(错误)
	fpos_t here;//切记 使用fpos_t 而不适用指针 因为它不会分配任何内存来存储位置数据
}

void d_12_11_3()	//在文件中设置位置
{
	//int fseek(FILE* pfile,long offset,int origin) 此函数与ftell互补
	//参数：文件流指针，偏移量，参考点（SEEK_SET,SEEK_CUR,SEEK_END）
	//int fsetpos(FILE* pfile,const fpos_t *position)	与fgetpos()互补
	//参数：文件流指针，fpos_t指针（只能使用fgetpos返回值）
}

void d_12_12()	//使用临时文件
{
	//需要一个文件存储中间结果，程序退出后删除它
}
void d_12_12_1()	//创建临时文件
{
	//FILE* tmpfile(void);	//创建失败的化会返回NULL；二进制文件
	//error_t tmpfile_s(FILE* restrict *restrict pfile);

	FILE* pfile=0;
	if(tmpfile_s(&pfile))
		printf("创建失败");
}

void d_12_12_2()	//创建唯一的文件名
{
	FILE* pfile=NULL;
	char* fileName=tmpnam(NULL);	//可是传入名称指定临时文件的名称
	if(!fileName){
		printf("创建临时文件失败");
	}

	if(!fopen_s(&pfile,fileName,"wb+"))
	{
		printf("打开临时文件失败");
	}else
	{
		printf("创建临时文件%s",fileName);
	}
	getchar();

	//tmpnam_s 是tmpnam的扩展版本
	//tmpnam_s(fileName,sizeof(fileName)) //必须自己删除此文件
}

void d_12_13()	//更新二进制文件
{
	//rb+
	//wb+
	//ab+
	//录入人名与年龄保存到二进制文件中
	char name[20];
	unsigned int age;
	FILE *pfile=NULL;
	char *fileName="d:\\MyDemo\\d_12_13.bin";

	if(fopen_s(&pfile,fileName,"wb+"))
	{
		printf("打开文件失败\n");
		getchar();
		exit(1);
	}
	while(true)
	{
		printf("请输入姓名(exit退出)\n");
		scanf_s("%s",name,sizeof(name));
		if(!strcmp("exit",name))
		{
			break;
		}
		printf("\n请输入年龄\n");
		scanf_s("%d",&age,sizeof(age));

		size_t nameLen=strnlen_s(name,sizeof(name));
		fwrite(&nameLen,sizeof(nameLen),1,pfile);
		fwrite(name,sizeof(char),nameLen,pfile);
		fwrite(&age,sizeof(age),1,pfile);
	}

	if(pfile)
	{
		fclose(pfile);
		pfile=NULL;
	}
	if(fopen_s(&pfile,fileName,"rb")){
		printf("打开文件失败");
		getchar();
		exit(1);
	}else{
		size_t nameLen=0;
		unsigned int age_r=0;
		while(fread(&nameLen,sizeof(nameLen),1,pfile)==1){
			fread(name,sizeof(char),nameLen,pfile);
			name[nameLen]='\0';
			fread(&age_r,sizeof(age_r),1,pfile);
			printf("%s的年龄:%d\n",name,age_r);
		}
	}
	printf("按任意键退出");
	fflush(stdin);
	getchar();
}

typedef struct Record Record;
struct Record{
	char name[20];
	int age;
};

const char *fileName_13="D:\\MyDemo\\file_13.bin";

void d_12_13_1() //修改文本的内容
{

}
#include <ctype.h>
void d_12_15()	//程序设计
{
	//文件查看器  一列显示十六进制	一列显示字符
	//1.确认要查看的文件
	char *fileName=(char*)calloc(100,sizeof(char));
	scanf_s("%s",fileName,100*sizeof(char));
	char buffer[20];
	size_t count=0;
	//2.打开文件
	FILE* pfile=NULL;
	if(fileName){
		if(fopen_s(&pfile,fileName,"rb"))
		{
			printf("文件打开失败\n");
			getchar();
			exit(1);
		}
		setvbuf(pfile,NULL,_IOFBF,BUFSIZ);
		while(!feof(pfile))
		{
			count =fread(buffer,1,sizeof(buffer),pfile);
			for(int i=0;i<sizeof(buffer);i++)
			{
				if(i<count)
				{
					printf("%02x ",buffer[i]);
				}else
				{
					printf(" ");
				}
			}
			printf("|");
			for(int i=0;i<sizeof(buffer);i++)
			{
				if(i<count){
					printf("%c",isprint(buffer[i])?buffer[i]:'.');
				}else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	if(pfile)
	{
		fclose(pfile);
		pfile=NULL;
	}
	fflush(stdin);
	getchar();
}

void d_12_17_1()	//习题一
{
	char *data=(char*)calloc(1000,sizeof(char));
	FILE* pfile=NULL;
	char* fileName="d:\\MyDemo\\d_17_1.txt";
	if(fopen_s(&pfile,fileName,"w"))
	{
		printf("文件打开失败");
		getchar();
		exit(1);
	}
	printf("请录入字符串(exit结束录入)\n");
	while(true){

		fgets(data,1000*sizeof(char),stdin);
		if(!strcmp("exit\n",data)){
			break;
		}
		if(fputs(data,pfile)==EOF)
		{
			printf("写入失败");
		}
	}
	fflush(stdin);
	getchar();
}

void d_12_17_3()	//习题三
{
	char* fileName="d:\\MyDemo\\17_3.txt";
	FILE* pfile=NULL;

	if(fopen_s(&pfile,fileName,"r")){
		pfile=NULL;
		if(fopen_s(&pfile,fileName,"w"))
		{
			printf("创建并打开文件失败");
			getchar();
			exit(1);
		}
	}else
	{
		fclose(pfile);
		pfile=NULL;
		if(fopen_s(&pfile,fileName,"a"))
		{
			printf("打开文件失败");
			getchar();
			exit(1);
		}
	}

	char name[20];
	int age=0;
	while(true)
	{
		printf("请输入姓名(exit退出录入)\n");
		scanf_s("%s",name,sizeof(name));
		if(!strcmp(name,"exit"))
		{
			break;
		}
		printf("请输入年龄\n");
		scanf_s("%d",&age,sizeof(age));
		if(0>fprintf(pfile,"name=%s,age=%d\n",name,age))
		{
			printf("写入数据出现问题\n");
			getchar();
			exit(1);
		}
	}
	fclose(pfile);
	pfile=NULL;
	if(fopen_s(&pfile,fileName,"r"))
	{
		printf("打开文件失败");
		getchar();
		exit(1);
	}
	while(!fscanf_s(pfile,"name=%s,age=%d\n",name,age))
	{
		printf("name=%s,age=%d\n",name,age);
	}
	if(pfile)
	{
		fclose(pfile);
		pfile=NULL;
	}
	printf("输入任意键退出");
	fflush(stdin);
	getchar();
}

void main()
{
	d_12_17_3();
}