/* �ڶ��´��� */

#include <stdio.h>
#include <limits.h>	//ͷ�ļ��а����������͵ļ���ֵ
#include <float.h>	//floatͷ�ļ��а���float���������͵ķ��� ��������
#include <stddef.h>	//����Ŀ�����ڻ�ȡsizeofֵ size_t

void index(void)	//ֻ���ڲ���
{
	printf("����ר��");
	getchar();
}

void d_2_2(void)	//ʲô�Ǳ���
{
	printf("�ҵĹ����� ��10000\n");
	getchar();
}

void d_2_3(void)	//�洢�����ı���
{
	int salary;		//����һ�������ͱ���salary��нˮ��
	salary=10000;	//������ı�����ֵ
	printf("�ҵĹ����ǣ� %d \n",salary);	//%d ת��˵����
	getchar();
}

void d_2_3_1(void)	//������ʹ��	
{
	int total_pets;
	int cats;
	int dogs;
	int ponies;
	int others;

	cats=2;
	dogs=1;
	ponies=1;
	others=46;

	total_pets=cats+dogs+ponies+others;
	printf("we hava %d pets in total\n",total_pets);
	getchar();
}

void d_2_3_2(void)	//�����ĳ�ʼ��
{
	int cats;		//��ʼ��������ַ
	cats=2;			//����ַ��ֵ
}

//�������ڴ�
void d_2_4(void)
{
	//�з���������
	signed char num1=1234;	//1�ֽ�
	short num2=2;	//2�ֽ�
	int num3=3;			//4�ֽ�
	long num4=4;	//4�ֽ�
	long long num5=5;	//8�ֽ�

	//�޷���������
	unsigned char num2_1=1;
	unsigned short int num2_2=2;
	unsigned int num2_3=3;
	unsigned long num2_4=4;
	unsigned long long num2_5=5;
}

void d_2_5(void)
{
	//������
	//�������Ͳ��ܾ�ȷ�ı��10�����е�һЩ���� ��1/3 ���ڸ������洢��ʽλ������
	//�洢��ʽ 
	//float �� 4�ֽڹ�32λ
	//��Ϊ����λ ��0 ��1
	//8λָ��λ
	//23λС��λ

	//����		�ֽ���	ȡֵ��Χ
	//float			4	+-3.4E+-38(��ȷ��6��7λС��)
	//double		8	+-1.7E+-308(��ȷ��15λС��)
	//long double	12	+-1.19E+-4932(��ȷ��18λС��)

	//
}

void d_2_6(void)
{
	//������������
	float pai=3.14F;
	double biggest=123E30;
	long double bigbigget=123E30L;
}

void d_2_6_1()//��10�ֳ�4�ȷ�
{
	float num1=10.0F;
	float num2=4.0F;
	float num3=num1/num2;
	printf("��10�ֳ�4�ȷ�ÿһ��Ϊ %f",num3);	//%f������ʾ������ %.number f ���Կ������С����λ��
	getchar();
}
void d_2_6_other()
{
	//%-/+[width][.number][modifier]f ���Կ���������ֶο��
	//-/+:��������뻹���Ҷ��룬��f����dʹ��
	//width������ռ����ʾ��ȣ�һ������Ϊһ����λ������f����dʹ��
	//.number��С������λ��
	//������������long double ��ʱ��modifierΪL �������ʡ��
	float num1=3.14159267F;
	printf("Ҫ��ʾ��С��:%-15.4f����ǰ�����",num1);
	getchar();
}

void d_2_7()//����һ��Բ�����ܳ������
{
	float R=0.0F;
	float PI=3.14F;
	float area=0.0F;
	float circumference=0.0F;

	printf("������Բ���İ뾶��");
	scanf("%f",&R);		//��׼�⺯�� ��ȡ����  &��Ѱַ�����  �����븳ֵ����
	circumference=2*PI*R;
	area=PI*R*R;

	printf("����Բ�����ܳ�ԼΪ%5.5f\r\n����Բ�������ԼΪ%5.5f",circumference,area);
	getchar();

}

void d_2_7_other(){
	//����%
	//��ʽ˵�����Ŀ���
	//��ȡshort		%hd
	//��ȡint		%d
	//��ȡlong		%ld		Сд��L
	//��ȡfloat		%f��%e
	//��ȡdouble	%lf��%le

	//���������	%d
	//����ַ���	%s
	//���������	%ld
	//���ʮ�����޷���	%u
	//���������	%f
	//������ַ�	%c
	//���ָ��		%p
	//���ָ���͸�����%e
	//ʮ������		%x
	//�˽���		%0
	//�Զ�ƥ��		%g
}

//d_2_8	������������
#define PI 3.1415926F	//���峣����ʱ������ȫ����д
void d_2_8()
{
	float R=0.0F;
	float ZhouChang=0.0F;
	float area=0.0F;
	printf("������Բ���İ뾶");
	scanf("%f",&R);
	ZhouChang=2*PI*R;
	area=PI*R*R;
	printf("����Բ�����ܳ�Ϊ%f\n",ZhouChang);
	printf("����Բ�������Ϊ%f",area);
	getchar();
}

void d_2_8_Demo_2()
{
	float R=0.0F;
	float ZhouChang=0.0F;
	float area=0.0F;
	const float Pi=3.1415926F;		//������const�ؼ��ֱ�ʶ�ñ�����һ���̻�����
	//Pi=3.3F;		�Թ̻����������޸Ļᱨ��
	printf("������Բ���İ뾶");
	scanf("%f",&R);
	ZhouChang=2*PI*R;
	area=PI*R*R;
	printf("����Բ�����ܳ�Ϊ%f\n",ZhouChang);
	printf("����Բ�������Ϊ%f",area);
	getchar();
}

void d_2_8_1()//����ֵ
{
	//��limits.hͷ�ļ��ж�������������͵ļ���ֵ
	//ͨ����ʽΪ	����_MIN �� ����_MAX
	//��������
	//char			CHAR_MIN	CHAR_MAX
	//short			SHORT_MIN	SHORT_MAX
	//int			INT_MIN		INT_MAX
	//long			LONG_MIN	LONG_MAX
	//long long		LLONG_MIN	LLONG_MAX

	//�����޷����������߶�Ϊ0 (unsigned)

	//float			FLT_MIN		FLT_MAX
	//double		DBL_MIN		DBL_MAX
	//long double	LDBL_MIN	LDBL_MAX

	//ע��FLT_DIG	DBL_DIG	LDBL_DIG	�ɻ�ö�����β�����Ա�ʾ��С��λ��

	printf("char ���͵���Сֵ%-10d���ֵ%-10d\n",CHAR_MIN,CHAR_MAX);
	printf("unsigned char���͵���Сֵ0\t���ֵ%-10d\n",UCHAR_MAX);
	printf("short ���͵���Сֵ%-10d���ֵ%-10d\n",SHRT_MIN,SHRT_MAX);
	printf("unsigned short ���͵���Сֵ0\t���ֵ%-10d\n",USHRT_MAX);
	printf("int ���͵���Сֵ%-10d���ֵ%-10d\n",INT_MIN,INT_MAX);
	printf("unsigned int���͵���Сֵ0\t���ֵ%-10d\n",UINT_MAX);
	printf("long ���͵���Сֵ%-10d���ֵ%-10d\n",LONG_MIN,LONG_MAX);
	printf("unsigned long���͵���Сֵ0\t���ֵ%-10d\n",ULONG_MAX);
	printf("long long ���͵���Сֵ%-10d���ֵ%-10d\n",LLONG_MIN,LLONG_MAX);
	printf("unsigned long long���͵���Сֵ0\t���ֵ%-10d\n",ULLONG_MAX);

	printf("float ���͵���Сֵ%-10.3ef\n���ֵ%-10.3ef\n",FLT_MIN,FLT_MAX);
	printf("double ���͵���Сֵ%-10.3ef\n���ֵ%-10.3ef\n",DBL_MIN,DBL_MAX);
	printf("long double ���͵���Сֵ%-10.3eLf\n���ֵ%-10.3eLf\n",LDBL_MIN,LDBL_MAX);

	printf("float ����С�����λ�����Ϊ%u\n",FLT_DIG);
	printf("double ����С�����λ�����Ϊ%u\n",DBL_DIG);
	printf("long double ����С�����λ�����Ϊ%u\n",LDBL_DIG);

	getchar();
}

void d_2_8_2()	//sizeof �����
{
	//sizeof ͨ���õ�һ��int���͵�ֻ���ڱ�ʾ��������ռ���ֽ���
	//���ڲ�ͬ��C����sizeof���ܶ�Ӧ�ⲻͬ��������������stddef.h�ļ�ͷ
	printf("char ����ռ��%4u���ֽ�\n",sizeof(char));
	printf("short ����ռ��%4u���ֽ�\n",sizeof(short));
	printf("int ����ռ��%4u���ֽ�\n",sizeof(int));
	printf("long ����ռ��%4u���ֽ�\n",sizeof(long));
	printf("longlong ����ռ��%4u���ֽ�\n",sizeof(long long));
	printf("float ����ռ��%4u���ֽ�\n",sizeof(float));
	printf("double ����ռ��%4u���ֽ�\n",sizeof(double));
	printf("long double ����ռ��%4u���ֽ�\n",sizeof(long double));
	getchar();
}

void d_2_9(void)	//ѡ����ȷ������
{
	//��������Բ�ͬ�������ò�ͬ�����ͣ�ȷ��ֵ���������͵�ȡֵ��Χ��
}

void d_2_10(void)	//����ת��
{
	short snum1=1;
	short snum2=3;
	double dnum3=(double)snum1/snum2;
	printf("dnum3:%f",dnum3);
	getchar();
}

void d_2_10_other()	//��ʽ����ת���Ĺ���
{
	//����ӵ͵���
	//char short int long longlong float double long double

	//��ֵ�����е���ʽ����ת��
	int num1=0;
	float fnum2=2.5F;
	num1=fnum2;		//����num1��int�������Ի��Զ���ȡ��С�������ֵ
	printf("%d",num1);
	getchar();
}

void d_2_11_1(void)
{
	char character=74;
	char letter='C';
	letter+=3;
	printf("%d\n%c",character,letter);
	getchar();
}

void d_2_11_3(void)
{
	enum Weekday{zhouyi=1,zhouer=2,zhousan=3,
		zhousi=4,zhouwu=5,zhouliu=6,zhouri=7
	}
	today=zhouwu,tomrrow=zhouliu;//�൱��ֱ��ʹ����ö��

	enum Weekday day=zhouwu;//�������

	printf("������%d,%d",today,day);

	//δ����ö��  ����ֻ���Ѿ�����ı�������ʹ��
	enum {red,orang,yellow,green,blue,indigo} shirt_color;
	shirt_color=red;

	getchar();
}

void d_2_11_4(void)	//�洢��������
{
	//_Bool��gcc�����Ĳ������� bool��g++����
	//_Bool=0/1		��Ӧ false true
	//�����ڷ����ⲿ����define������������벻ͨ�������
	//#define bool _Bool
	//#define true 1
	//#define false 0
}

void d_2_12(void)
{
	//��ֵ������op=��ʽ  ����+=  -=
	//����
	//	+	-	*	/	%
	//	<<	>>	&	^	|
}

#include <math.h>

void d_2_13(void)	//��ѧ����
{
	//��math.hͷ�ļ��� ���к���������һ��double���͵�ֵ

	//��ֵ����
	//floor(x)	���ز�����x���������
	//ceil(x)	���ز�С��x����С����
	//fabs(x)	����x�ľ���ֵ
	//log(x)	����x����Ȼ��������EΪ�ף�
	//log10(x)	����x����Ȼ��������10Ϊ�ף�
	//exp(x)	����e��x�η���ֵ
	//sqrt(x)	����x��ƽ����
	//pow(x,y)	����x��y�η�

	float num1=0.1F;
	printf("ͨ��floor�������ز�����%f���������%f\n",num1,floor(num1));
	printf("ͨ��ceil�������ز�С��%f����С����%f\n",num1,floor(num1));
	printf("ͨ��fabs()����%f�ľ���ֵ%f\n",num1,fabs(num1));
	printf("ͨ��log(x)����%f����EΪ�׵���Ȼ����%f\n",num1,log(num1));
	printf("ͨ��log10(x)����%f����10Ϊ�׵���Ȼ����%f\n",num1,log10(num1));
	printf("ͨ��exp(x)����e��%f�η�%f\n",num1,exp(num1));
	printf("ͨ��sqrt(x)����%f��ƽ����%f\n",num1,sqrt(num1));
	printf("ͨ��pow(x,y)����%f��y�η�%f\n",num1,pow(num1,2));

	//���Ǻ���
	//sin(x)	cos(x)	tan(x)
	getchar();
}

void d_2_14(void)//�������ĸ߶�����
{
	
	//����Ϊ ��1�߶�<��2�߶ȣ���1�����ľ����Զ ����12����ͷ��һ��ֱ���ϣ���ȴ�����ƽ

	float p1height;			//��1�ĸ߶�
	float p2height;			//��2�ĸ߶�
	float p1_p2_width;		//��12֮��ľ���
	float p1_tree_width;	//��1�����ľ���
	float treeHieght;		//���ĸ߶�

	printf("\n��������1�ĸ߶ȣ�");
	scanf("%f",&p1height);
	printf("\n��������2�ĸ߶ȣ�");
	scanf("%f",&p2height);
	printf("\n����������֮��ľ��룺");
	scanf("%f",&p1_p2_width);
	printf("\n��������1�����ľ��룺");
	scanf("%f",&p1_tree_width);

	//�����ǹ�ʽ�ɵ�
	//(p2height-p1height)/p1_p2_width = (treeheight-p1height)/p1_tree_width
	//����treeheight=(p2height-p1height)/p1_p2_width*p1_tree_width+p1height

	treeHieght=(p2height-p1height)/p1_p2_width*p1_tree_width+p1height;
	printf("\n��������ó����ĸ߶ȴ�ԼΪ��%f",treeHieght);
	scanf("%f");
	getchar();
}

void d_2_16(void)	//��ϰ��
{

	//T2.1
	printf("\nT2.1");
	int num1=0;
	printf("\n������һ����ֵ��Ӣ�磩");
	scanf("%d",&num1);
	float num2=0.0F;
	float num3=0.0F;
	num2=num1/12.0F;
	num3=num2/3;
	printf("��������ó���%dӢ���ת��Ϊ\n %.2fӢ��\n %.2f��",num1,num2,num3);
	getchar();
	//T2.2
	printf("\nT2.2");
	float width_f_YCH=0.0F;
	float height_f_YC=0.0F;
	float area_M=0.0F;
	printf("\n�����볤�ȣ���λӢ�ߣ���");
	scanf("%f",&width_f_YCH);
	printf("\n�������ȣ���λӢ�磩��");
	scanf("%f",&height_f_YC);

	area_M=width_f_YCH/3*height_f_YC/36;
	printf("\n�������㷿�����Ϊ%fƽ����",area_M);

	//T2.3
	int count1=0;
	int count2=0;
	float book1=3.5F;
	float book2=5.5F;
	printf("\n��������������������1��");
	scanf("%d",&count1);
	printf("\n��������������������2��");
	scanf("%d",&count2);

	float sum=(count1*book1)+(count2*book2);
	printf("\n��乲֧����Y%f",sum);

	//T2.4
	float Mnum=0.0F;
	float Hcount=0.0F;
	printf("\n���빤��");
	scanf("%f",&Mnum);
	printf("\n���빤��ʱ��");
	scanf("%f",&Hcount);
	float num_H=Mnum/(Hcount*30);
	printf("��ÿ�칤��%.0f��Сʱ������Ϊ��׬%.0f���Ǯ��ƽ��������ÿСʱ��%f��ô��",Hcount,Mnum,num_H);
	
	scanf("%c");
}

int main(void)
{
	d_2_16();
	getchar();
}

