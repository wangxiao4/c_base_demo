/* �����ļ� */
#include <stdio.h>
#include <stdlib.h>


void test()
{
	printf("�����ڲ���");
	getchar();
}

void d_12_1()	//�ļ��ĸ���
{
	//�ļ�������һϵ���ֽ�
}

void d_12_1_1()	//�ļ��е�λ��
{
	//�ļ��п�ͷ�ͽ�β
	//����һ����ǰλ��
	//����ָ����ǰλ���뿪ͷ��ƫ����
	//�����ƶ��뵱ǰλ�õ�����ƫ����
}

void d_12_1_2()	//�ļ���
{
	//���ݿ������ı����߶�������ʽд���ļ���
	//��ȡ��ʱ�����ֽڣ����Գ������ֱ������ļ�����ʲô���������
}

void d_12_2()	//�ļ�����
{
	//FILE �ļ�ָ������ ����stdio.h
}

void d_12_2_1()	//���ļ�
{
	FILE *pfile=NULL;
	char *fileName="d:\\MyDemo\\myFile.txt";
	if(!fopen_s(&pfile,fileName,"w"))
	{
		printf("�������ļ�%s\n",fileName);
	}
	fileName="d:\\Code\\C\\B\\myFile.txt";	//��·�������ڵ�ʱ��  w����ʧ��
	if(!fopen_s(&pfile,fileName,"w"))
	{
		printf("�������ļ�%s\n",fileName);
	}else
	{
		printf("�����ļ�%sʧ��",fileName);
	}

	//����  a  ׷��  �Լ�  r  ��ȡ����

	getchar();
}

void d_12_2_2()	//�����ļ�����
{
	//_IOFBFʹ�ļ�ȫ������
	//_IOLBF����һ��
	//_IONBF�����棨���ֽ�Ϊ��λ��
	FILE *pflie=NULL;
	char *fileName="d:\\MyDemo\\myFile.txt";
	if(!fopen_s(&pflie,fileName,"a")){
		size_t bufsize=1024;
		if(setvbuf(pflie,NULL,_IOFBF,bufsize))
		{
			printf("����%s���ݳɹ�\n",fileName);
		}else
		{
			printf("�����ļ�ʧ��");
		}
	}else{
		printf("���ļ�ʧ��");
	}
	getchar();
}

void d_12_2_3()	//�ļ���������ɾ��
{
	//			ԭʼ����				�޸ĺ������
	if(rename("d:\\MyDemo\\myFile.txt","d:\\MyDemo\\myFile_copy.txt"))
	{
		//�ɹ�����0
		printf("�޸ĳɹ�");
	}
	remove("d:\\MyDemo\\myFile.txt");	//ɾ���ļ�
}

void d_12_2_4()	//�ر��ļ�
{
	FILE *pflie=NULL;
	char *fileName="d:\\MyDemo\\myFile.txt";
	if(!fopen_s(&pflie,fileName,"a")){
		if(!fclose(pflie))	//����ɹ��ر�  ����0 ���򷵻�EOF
		{
			printf("�ɹ��ر�");
			pflie=NULL;
		}else{
			printf("�ر�ʧ��");
		}
	}
	getchar();
}

void d_12_3()	//д���ı��ļ�
{
	FILE *pflie=NULL;
	char *fileName="d:\\MyDemo\\myFile.txt";//ȷ�����д�·��
	if(!fopen_s(&pflie,fileName,"w"))
	{
		if(fputs("this is a test",pflie)!=EOF){//д��char[]  ����fputc
			printf("д��ɹ�");
		}else{
			printf("д��ʧ��");
		}
		fclose(pflie);
		pflie=NULL;
	}else{
		printf("���ļ�ʧ��");
	}
	getchar();
}

void d_12_4()	//��ȡ�ı��ļ�
{
	FILE *pfile=NULL;
	char *fileName="d:\\MyDemo\\myFile.txt";
	char *putDemo=(char*)calloc(100,sizeof(char));
	char *getDemo=(char*)calloc(100,sizeof(char));
	if(!fopen_s(&pfile,fileName,"w"))
	{
		printf("������Ҫд�������\n");
		if(fgets(putDemo,100*sizeof(char),stdin)){
			if(fputs(putDemo,pfile)!=EOF)
			{
				fclose(pfile);
				pfile=NULL;
				printf("д�����\n");
			}else
			{
				printf("д���ļ�ʧ��\n");
			}
		}else
		{
			printf("¼��ʧ��\n");
		}
	}else{
		printf("���ļ�%sʧ��\n",fileName);
	}
	if(!fopen_s(&pfile,fileName,"r"))	//ע���ȡ�á�r��
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
		printf("���ļ�%sʧ��\n",fileName);
	}
	getchar();
}
#include <string.h>
#define MaxCount 1
void d_12_5()	//��ȡ�ı��е��ַ���
{
	//��fgets ָ������ԴΪFILE*�Ϳ����� ��ϸ��12.4����
	FILE *pfile=NULL;		//�ļ�����ַ
	char *fileName="d:\\MyDemo\\myFile.txt";	//�ļ���
	char **strings=(char**)calloc(MaxCount,sizeof(char*));	//������ַ���
	size_t str_Max_count=MaxCount;
	size_t str_count=0;
	printf("exit �˳�¼��\n");
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
				printf("���ļ�д��%sʱ����\n",strings[i]);
			}
		}
		fclose(pfile);
		pfile=NULL;
	}else
	{
		printf("¼��ʱ���ļ�ʧ��");
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
		printf("��ȡʱ���ļ�ʧ��");
	}
	free(str);
	str=NULL;

	fflush(stdin);
	getchar();
}

void d_12_6()	//��ʽ���ļ����������
{
	//��Щʱ����Ҫ�������������������char�������ݴ���
}

void d_12_6_1()	//��ʽ���ļ����
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
			printf("д��������\n");
		}
		fclose(pfile);
		pfile=NULL;
	}
}

void d_12_6_2()	//��ʽ���ļ�����
{
	FILE* pfile=NULL;
	char* fileName="d:\\MyDemo\\myFile.txt";
	double PI=3.1415926;

	if(fopen_s(&pfile,fileName,"w")!=EOF)
	{
		if(0>fprintf(pfile,"PI=%6lf",PI))
		{
			printf("д���ļ�ʧ��\n");
		}
		fclose(pfile);
		pfile=NULL;
	}else
	{
		printf("�ļ�д��ʧ��\n");
	}

	if(fopen_s(&pfile,fileName,"r")!=EOF)
	{
		fscanf_s(pfile,"PI=%6lf",&PI);
		printf("��ȡPI=%6lf",PI);
		fclose(pfile);
		pfile=NULL;
	}
	getchar();
}

void d_12_7()	//������
{
	FILE* pfile=NULL;
	char* fileName="d:\\MyDeo\\myFile.txt";

	if(fopen_s(&pfile,fileName,"r"))
	{
		//������ļ�ʱ��������
		fprintf(stderr,"���ļ�%s��ʱ����ֵ�����",fileName);
	}
	getchar();
}

void d_12_8()	//��̸�ı��ļ�����ģʽ
{
	//ģʽ			˵��
	//r				���ļ�����ȡ
	//r+			��д
	//w				д�룬����������
	//wx			�ǹ���д��
	//w+			w���������Ӹ���
	//w+x			�ǹ���д�����
	//a				׷�ӵ�ĩβ
	//a+			���²�׷�ӵ�ĩβ
}

void d_12_9()	//freopen_s
{
	FILE* pfile=NULL;
	char* fileName="d:\\MyDemo\\myFile.txt";
	if(freopen_s(&pfile,fileName,"w+",stdout))//����׼�����¸���һ���ļ�
	{
		printf("�ض��������ʧ��");
	}else{
		printf("Ŀǰ���������ת���ı���");
	}
	getchar();
}

void d_12_10()	//�������ļ�
{
	//�������ļ�����Ҫ�����ı����������
	//�������ļ�û�о�����ʧ
	//�������ļ�û������ת��
	//�������ļ��鿴�������鷳
}

void d_12_10_1()	//���ı�
{
	//����ģʽ��b
	//ģʽ			˵��
	//r				���ļ�����ȡ
	//r+			��д
	//w				д�룬����������
	//wx			�ǹ���д��
	//w+			w���������Ӹ���
	//w+x			�ǹ���д�����
	//a				׷�ӵ�ĩβ
	//a+			���²�׷�ӵ�ĩβ
}

void d_12_10_2()	//д��������ļ�
{
	FILE* pfile=NULL;
	char* fileName="d:\\MyDemo\\myFile.bin";
	if(fopen_s(&pfile,fileName,"w+"))
	{
		printf("���ļ�ʧ��\n");
	}else
	{
		long data[]={2L,3L,4L};
		size_t num_items=sizeof(data)/sizeof(long);
		//ʹ��fwrite()����д�����������
		//������1.����ָ��	2.���������ֽ���	3.���ݸ���	4.�ļ���ָ��
		size_t wcount=fwrite(data,sizeof(long),num_items,pfile);
		fclose(pfile);
		pfile=NULL;
		printf("д������Ƴɹ�");
	}
	getchar();
}



void d_12_10_3()	//��ȡ�������ļ�
{
	FILE* pfile=NULL;
	char* fileName="d:\\MyDemo\\myFile.bin";
	if(fopen_s(&pfile,fileName,"r+"))
	{
		printf("���ļ�ʧ��\n");
	}else
	{
		long data[3];
		size_t num_items=sizeof(data)/sizeof(long);
		//ʹ��fwrite()����д�����������
		//������1.����ָ��	2.���������ֽ���	3.���ݸ���	4.�ļ���ָ��
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

void d_12_11()	//���ļ����ƶ�
{
	//���ļ��а����������ݵ�ʱ������Ҫ���ʵ��м������ʱ����Ҫ�ƶ���ǰָ�뵽�ļ��м䲿��
}

void d_12_11_1()	//�ļ���λ����
{
	//��windowsϵͳ�в����ı��ļ���ʱ��Ҫע����Щ������ַ���(\n \0 ����)
}

void d_12_11_2()	//�ҳ��������ļ��е�λ��
{
	//long ftell(FILE* pfile)	���ص�ǰλ�ã������ļ���ͷ��
	//long fgetpos(FILE* pfile,fpos_t*)	����0(��ȷ)���0(����)
	fpos_t here;//�м� ʹ��fpos_t ��������ָ�� ��Ϊ����������κ��ڴ����洢λ������
}

void d_12_11_3()	//���ļ�������λ��
{
	//int fseek(FILE* pfile,long offset,int origin) �˺�����ftell����
	//�������ļ���ָ�룬ƫ�������ο��㣨SEEK_SET,SEEK_CUR,SEEK_END��
	//int fsetpos(FILE* pfile,const fpos_t *position)	��fgetpos()����
	//�������ļ���ָ�룬fpos_tָ�루ֻ��ʹ��fgetpos����ֵ��
}

void d_12_12()	//ʹ����ʱ�ļ�
{
	//��Ҫһ���ļ��洢�м����������˳���ɾ����
}
void d_12_12_1()	//������ʱ�ļ�
{
	//FILE* tmpfile(void);	//����ʧ�ܵĻ��᷵��NULL���������ļ�
	//error_t tmpfile_s(FILE* restrict *restrict pfile);

	FILE* pfile=0;
	if(tmpfile_s(&pfile))
		printf("����ʧ��");
}

void d_12_12_2()	//����Ψһ���ļ���
{
	FILE* pfile=NULL;
	char* fileName=tmpnam(NULL);	//���Ǵ�������ָ����ʱ�ļ�������
	if(!fileName){
		printf("������ʱ�ļ�ʧ��");
	}

	if(!fopen_s(&pfile,fileName,"wb+"))
	{
		printf("����ʱ�ļ�ʧ��");
	}else
	{
		printf("������ʱ�ļ�%s",fileName);
	}
	getchar();

	//tmpnam_s ��tmpnam����չ�汾
	//tmpnam_s(fileName,sizeof(fileName)) //�����Լ�ɾ�����ļ�
}

void d_12_13()	//���¶������ļ�
{
	//rb+
	//wb+
	//ab+
	//¼�����������䱣�浽�������ļ���
	char name[20];
	unsigned int age;
	FILE *pfile=NULL;
	char *fileName="d:\\MyDemo\\d_12_13.bin";

	if(fopen_s(&pfile,fileName,"wb+"))
	{
		printf("���ļ�ʧ��\n");
		getchar();
		exit(1);
	}
	while(true)
	{
		printf("����������(exit�˳�)\n");
		scanf_s("%s",name,sizeof(name));
		if(!strcmp("exit",name))
		{
			break;
		}
		printf("\n����������\n");
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
		printf("���ļ�ʧ��");
		getchar();
		exit(1);
	}else{
		size_t nameLen=0;
		unsigned int age_r=0;
		while(fread(&nameLen,sizeof(nameLen),1,pfile)==1){
			fread(name,sizeof(char),nameLen,pfile);
			name[nameLen]='\0';
			fread(&age_r,sizeof(age_r),1,pfile);
			printf("%s������:%d\n",name,age_r);
		}
	}
	printf("��������˳�");
	fflush(stdin);
	getchar();
}

typedef struct Record Record;
struct Record{
	char name[20];
	int age;
};

const char *fileName_13="D:\\MyDemo\\file_13.bin";

void d_12_13_1() //�޸��ı�������
{

}
#include <ctype.h>
void d_12_15()	//�������
{
	//�ļ��鿴��  һ����ʾʮ������	һ����ʾ�ַ�
	//1.ȷ��Ҫ�鿴���ļ�
	char *fileName=(char*)calloc(100,sizeof(char));
	scanf_s("%s",fileName,100*sizeof(char));
	char buffer[20];
	size_t count=0;
	//2.���ļ�
	FILE* pfile=NULL;
	if(fileName){
		if(fopen_s(&pfile,fileName,"rb"))
		{
			printf("�ļ���ʧ��\n");
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

void d_12_17_1()	//ϰ��һ
{
	char *data=(char*)calloc(1000,sizeof(char));
	FILE* pfile=NULL;
	char* fileName="d:\\MyDemo\\d_17_1.txt";
	if(fopen_s(&pfile,fileName,"w"))
	{
		printf("�ļ���ʧ��");
		getchar();
		exit(1);
	}
	printf("��¼���ַ���(exit����¼��)\n");
	while(true){

		fgets(data,1000*sizeof(char),stdin);
		if(!strcmp("exit\n",data)){
			break;
		}
		if(fputs(data,pfile)==EOF)
		{
			printf("д��ʧ��");
		}
	}
	fflush(stdin);
	getchar();
}

void d_12_17_3()	//ϰ����
{
	char* fileName="d:\\MyDemo\\17_3.txt";
	FILE* pfile=NULL;

	if(fopen_s(&pfile,fileName,"r")){
		pfile=NULL;
		if(fopen_s(&pfile,fileName,"w"))
		{
			printf("���������ļ�ʧ��");
			getchar();
			exit(1);
		}
	}else
	{
		fclose(pfile);
		pfile=NULL;
		if(fopen_s(&pfile,fileName,"a"))
		{
			printf("���ļ�ʧ��");
			getchar();
			exit(1);
		}
	}

	char name[20];
	int age=0;
	while(true)
	{
		printf("����������(exit�˳�¼��)\n");
		scanf_s("%s",name,sizeof(name));
		if(!strcmp(name,"exit"))
		{
			break;
		}
		printf("����������\n");
		scanf_s("%d",&age,sizeof(age));
		if(0>fprintf(pfile,"name=%s,age=%d\n",name,age))
		{
			printf("д�����ݳ�������\n");
			getchar();
			exit(1);
		}
	}
	fclose(pfile);
	pfile=NULL;
	if(fopen_s(&pfile,fileName,"r"))
	{
		printf("���ļ�ʧ��");
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
	printf("����������˳�");
	fflush(stdin);
	getchar();
}

void main()
{
	d_12_17_3();
}