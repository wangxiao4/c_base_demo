/* ��ʮ�� ������� ��һ�·ǳ�û����˼*/
#include <stdio.h>
#include <stdlib.h>

void test()
{
	printf("�����ڲ���");
	getchar();
}

void d_10_1()
{
	//������������ַ������ļ�������������
}

void d_10_2()
{
	//��stdio.hͷ�ļ��� ����������׼��
	//stdin		stdout					stderr
	//����		���������������		�������ϵĴ������
	//ʹ�ò���ϵͳ������Խ�stdin��stdout�ض����ļ���
}

void d_10_3()	//��������
{
	//stdin�ļ���������������ʽ
	//scanf_s(scanf�İ�ȫ�汾)		getchar()
}

void d_10_3_1()	//��ʽ����������
{
	double var;
	char str[]="%lf";	//double����
	scanf_s(str,&var);	//��������int����ֵ
}

void d_10_3_2()		//�����ʽ�����ַ���
{
	//scanf_s �������������Ŀհ��ַ�  ֱ�Ӷ�ȡ��һ���ǿհ��ַ�����ʹ��%C %[] %n���⣩
	//scanf_s ���Էָ���ֵ�Ķ���
	//һ���ʽ	
	//%			*						field_width			
	//			��ѡ��������һ��ֵ��	�����ַ�������ѡ��	
	//�������η�			conversion_character
	//h hh l L ll j z t
}
void d_10_3_3()	//�����ʽ�ַ����е��ַ�
{
	int i=0;
	int j=0;
	int z=0;
	int value_count=0;
	printf("�밴���¸�ʽ���룺\n i=1 j=2 3\n");
	value_count=scanf_s("i=%d j=%d %d",&i,&j,&z);
	printf("����%d�����鱻¼��\n",value_count);
	printf("i=%d j=%d %d",i,j,z);
	fflush(stdin);
	getchar();
}

void d_10_3_4()	//���븡�����ĸ��ֱ仯
{
	printf("�����븡������ʽ���£�\n3.14.314E1.0314E+2\n");
	float f1=0;
	float f2=0;
	float f3=0;

	scanf_s("%f%f%f",&f1,&f2,&f3);
	printf("f1=%f\nf2=%f\nf3=%f",f1,f2,f3);
	fflush(stdin);
	getchar();

}
void d_10_3_5()	//��ȡʮ�����ƺͰ˽���
{
	//����ֻ�ǽ���ע���ʽ
	int i=0;
	int j=0;
	int z=0;
	scanf_s("%d %x %o",&i,&j,&z);
	printf("ȫ��תΪ10�������\ni=%d\tj=%d\tz=%d",i,j,z);
	fflush(stdin);
	getchar();
}
void d_10_3_6()	//ʹ��scanf��ȡ�ַ�
{
	char name_f='a';
	char name[50]={' '};
	char age[4]={' '};
	printf("�����������ֵ��׸���ĸ\n");
	scanf_s("%c",&name_f);
	printf("��������������\n");
	scanf_s("%s",name,sizeof(name));
	if(name_f==name[0])
	{
		printf("��������������\n");
		scanf_s("%[0123456789]",age);
	}else{
		printf("��������ĸ�����ֲ���");
	}
	fflush(stdin);
	printf("name=%s\tage=%s",name,age);
	getchar();
}
void d_10_3_7()	//�Ӽ����������ַ���
{
	char *name=(char*)calloc(100,sizeof(char));
	printf("��������������\n");
	gets_s(name,100*sizeof(char));
	printf("name=%s",name);
	fflush(stdin);
	getchar();

}

void d_10_4()	//��Ļ���
{
	printf("������");
	printf_s("��Ļ���");	//��Ҫ��ֹ%n������д���ڴ�
}

void d_10_4_3()	//�������
{
	int a=3; long long lb=1235ll;
	printf("a=%d\tlb=%lld",a,lb);
	getchar();
}

void d_10_4_3_2()	//��һ���ݵı仯
{
	int a=678;
	printf("ʮ���ƣ�%d\t ʮ�����ƣ�%x\t �˽��ƣ�%o",a,a,a);
	getchar();
}

void d_10_4_4()	//������
{
	float fa=3.14;
	printf("������:%f",fa);
	getchar();
}

#include <limits.h>

void d_10_4_5()	//����ַ�
{
	for(int i=0;i<=CHAR_MAX;i++)
	{
		printf("\t%c",i);
	}
	getchar();
}

void d_10_5()	//�����������
{
	puts("this is my demo");//ֻ��ʹ�ó���
	getchar();
}

void d_10_5_1()	//��Ļ�ķǸ�ʽ�����
{
	char name[50]="my name is \n wang xiao si ";
	printf("%s",name);
	int i=0;
	printf("\n");
	while(name[i]!='\0')
	{
		if(name[i]!='\n')
		{
			putchar(name[i]);
		}
		i++;
	}
	getchar();
}
void d_10_5_2()	//����ĸ�ʽ�����
{
	char data[50];
	int count=4;

	int size_data=_snprintf_s(data,sizeof(data),"һֻ����%d���ȣ������ټ�һ��",count);
	if(size_data>0)
	{
		printf("%s",data);
	}else{
		printf("��ʽ�����ݳ���");
	}
	getchar();
}

void d_10_7()	//ϰ��
{
t2:
	int a,b,c,d;
	scanf_s("%*[ ,$]%d,%*[ ,$]%d,%*[ ,$]%d,%*[ ,$]%d",a,b,c,d);//vs2013����
	printf("�����ܺ�Ϊ��%d",a+b+c+d);
	getchar();

}

void main()
{
	d_10_7();
}
