/* ������	�����ж� */
#include <stdio.h>	//�����ļ�ͷ  ������������ȳ��ò���

void test(void)	//����
{
	printf("�����ڲ���");
}

void d_3(void)
{
	//c�еĹ�ϵ�����
	//	<	<=	==	!=	>=	>
	//���в�Ϊ0������תΪbool��Ϊtrue
}

void d_3_1_2(void)
{
	//if �ж�
	int num=0;
	printf("������һ����");
	scanf("%d",&num);
	if(num>0){
		printf("������");
	}else if(num==0){
		printf("0");
	}else{
		printf("������");
	}
	getchar();
}

void d_3_1_6(void)	//�����ַ� if��Ƕ��
{
	char letter=0;
	printf("������һ���ַ�");
	scanf("%c",&letter);
	if(letter>'A'){
		if(letter<'Z'){
			letter=letter-'A'+'a';
			printf("ת��Ϊ%c",letter);
		}else{
			printf("����������");
		}
	}else{
		printf("���벻�Ϸ�");
	}
	getchar();
}

void d_3_1_7(void)
{
	//�߼������
	//	&&	||	��
	//	��	��	��
	char letter=0;
	printf("\n������һ���ַ��ҽ�����תΪСд");
	scanf("%c",&letter);
	if(letter>'A'&&letter<'Z'){
		letter=letter-'A'+'a';
		printf("תΪСдΪ%d",letter);
	}else if(letter<'a'||letter>'z'){
		printf("��������ַ������˶�����");
	}else{
		printf("%c�������һ��Сд",letter);
	}
	scanf("%c");
	getchar();
}

void d_3_1_8(void)	//���������
{
	//һ����ԭ��3.5 ����50����7.5��  ����20������8��  ����10������9��

	const float book_M=3.5F;
	const float count50=0.25;
	const float count20=0.2;
	const float count10=0.1;
	int count=0;
	float sum=0.0F;
	printf("\n������Ҫ������ٱ�");
	scanf("%d",&count);
	sum=book_M*count*(1-(count>=50?count50:(count>=20?count20:(count>=10?count10:0))));
	printf("\n����Ҫ֧��%fԪ",sum);
	getchar();
}

void d_3_1_9(void)	//����������ȼ�
{
	//	���	�����	˵��		ƥ�����
	//	1		����	����		����
	//			[]		�����±�	
	//			.		����ѡ���Ա
	//			->		ָ��ѡ���Ա
	//	2		+-		һԪ+��-	�ҵ���
	//			++ --	�����ݼ�	
	//			��~		�߼��ǰ�λ��
	//			*		ȡ�����ã�����������
	//			&		Ѱַ
	//			Sizeof	���ʽ�����͵��ֽ���
	//			(type)	ǿ������ת��
	//	3		*/%		�˳�ȡģ	����
	//	4		+-		�Ӽ�		����
	//	5		<< >>	��λ������	����
	//	6		< <= > >=	�Ƚ�	����
	//	7		== !=	�Ȳ���		����
	//	8		&		��λ��		����
	//	9		^		��λ���	����
	//	10		|		��λ��		����
	//	11		&&		�߼���		����
	//	12		||		�߼���		����
	//	13		?:		���������	�ҵ���
	//	14		=		��ֵ		�ҵ���
	//			+= -=	
	//			/= *=
	//			%=
	//			<<= >>=	��λ�����Ƹ�ֵ
	//			&= |=	��λ���ֵ
	//			^=		��λ���ֵ
	//	15		,		����		����

	//25�꣬��ѧרҵ������Ү³��ѧ
	//		��ѧרҵ,Ү³��ѧ
	//28���£�����רҵ��������ѧ
	//25�꣬�ǻ�ѧרҵ��Ү³��ѧ
	int age=0;//����
	int ZhuanYe=0;//רҵ
	int DaXue=0;//��ѧ
	bool isCanUse=false;
	printf("\n����������");
	scanf("%d",&age);
	printf("\n������רҵ��1.��ѧרҵ	2.����רҵ	3.����");
	scanf("%d",&ZhuanYe);
	printf("\n�������ѧ��1.Ү³��ѧ	2.������ѧ	3.����");
	scanf("%d",&DaXue);

	if(age>25&&ZhuanYe==1&&DaXue!=1){
		isCanUse=true;
	}
	if(ZhuanYe==1&&DaXue==1){
		isCanUse=true;
	}
	if(age<28&&ZhuanYe==2&&DaXue==2){
		isCanUse=true;
	}
	if(age>25&&ZhuanYe!=1&&DaXue==1){
		isCanUse=true;
	}
	if(isCanUse){
		printf("������Ҫ������������");
	}else{
		printf("�ܿ�ϧ~�������Կ�");
	}
	getchar();
}

void d_3_2(void)	//����ѡ������
{

}

void d_3_2_1(void)	//else-if
{
	int count=0;
	printf("��������ķ���");
	scanf("%d",&count);
	if(count>90){
		printf("����");
	}else if(count>80){
		printf("����");
	}else if(count>60){
		printf("����");
	}else{
		printf("����");
	}
	getchar();
}

void d_3_2_2(void)	//switch���
{
	//<ctype.h>ͷ�ļ��еļ�������ַ�
	//islower()	�Ƿ�Сд
	//isupper	�Ƿ��д
	//isalnum	�Ƿ���ĸ��ʮ��������
	//iscntrl	�����ַ�
	//isprint	�ɴ�ӡ�ַ�	�����ո�
	//isgraph	�ɴ�ӡ�ַ�	�������ո�
	//isdigit	ʮ��������
	//isxdigit	ʮ����������
	//isblank	��׼�հ��ַ����ո񣬡�\t����
	//isspace	��λ�ַ����ո�\n \t \v \r \f��
	//ispunct	isprint��isgraph����false�Ŀɴ�ӡ�ַ�
	//isalpha	�Ƿ���ĸ
	//tolower	תΪСд
	//toupper	תΪ��д

	//test:�������������е�һ��
	int num=0;
	printf("������һ������");
	scanf("%d",&num);
	switch(num){
	case 1:printf("���˵�1");break;
	case 2:printf("���˵�2");break;
	case 3:printf("���˵�3");break;
	default:printf("̫���̫С");break;
	}
	getchar();
}

void d_3_2_3(void)	//goto
{
	//�������Ӳ��ת
	start:
	printf("1ѭ��2����");
	int num=0;
	scanf("%d",&num);
	if(num==1){
		goto start;
	}
	getchar();
}

void d_3_3(void)	//��λ�����
{
	//	&	��λ��		��ͬλ����1 ���λ��1 ������λΪ0
	//	|	��λ��		��һ��������1  ���λΪ1 ������λΪ0
	//	^	��λ���	��ͬλ��ͬ ���λΪ1 ����Ϊ0
	//	~	��λ��		��ת1->0  0->1
	//	<<	��λ����	���Ҳ��0	
	//	>>	��λ����	�������ŵ�����0 �з��ŵ�����λ��ɢ��ȫ��Ϊ1 ����Ϊ0

	//��Щ�����ֻ��������������	~��һԪ�����	ֻ����һ�������� �������Ƕ�Ԫ

}

void d_3_3_2(void)	//��λ�������ʹ��
{
	//��һ��ABC��תΪCBA ʮ��λ��
	unsigned int num1=0xABC;
	unsigned int mesh=0xF;
	unsigned int num2=0x0;
	printf("%x\t->\t",num1);

	num2|=num1&mesh;
	num1>>=4;
	num2<<=4;
	num2|=num1&mesh;
	num1>>=4;
	num2<<=4;
	num2|=num1&mesh;

	printf("%x",num2);
	getchar();

}

void d_3_4()	//��Ƴ���
{
	start:
	//���һ�������
	double num1=0.0;
	double num2=0.0;
	char operation=0;
	printf("������Ҫ�ǵ���ĵ�ʽ\n");
	scanf("%lf %c %lf",&num1,&operation,&num2);
	switch(operation){
	case '+':
		printf("=%lf\n",num1+num2);
		break;
	case '-':
		printf("=%lf\n",num1-num2);break;
	case '*':
		printf("=%lf\n",num1*num2);break;
	case '/':
		printf("=%lf\n",num1/num2);break;
	case '%':
		printf("=%lf\n",(long)num1%(long)num2);break;
	default:
		printf("��֪��");
		break;
	}
	char isReturn=0;
	getchar();
	printf("����һ��?\ty/n");
	scanf("%c",&isReturn);
	if(isReturn=='y'){
		goto start;
	}
}

void d_3_6(void)	//������ϰ
{
	//T1 ѡ��	���϶�ת���϶Ȼ��϶�ת���϶�  ������ֵ  ���ת�����
	int operation=0;
	printf("1.���϶�ת���϶�\n2.���϶�ת���϶�\nѡ��\n");
	scanf("%d",&operation);
	printf("\n������Ҫת����ֵ\n");
	float num1F=0.0F;
	scanf("%f",&num1F);
	switch(operation){
	case 1:
		printf("Լ%f���϶�",num1F*1.8+32);
		break;
	case 2:
		printf("Լ%f���϶�",(num1F-32)*5/9);break;
	default:break;
	}
	getchar();
	getchar();

	//T2 ��������ôת�� Ӣ��ûѧ��
	//T3	������� ����30���� ����50�˵�����
	printf("\n������Ҫ����ĸ��������ۣ�5Ԫ��\n");
	int num1=0;
	scanf("%d",&num1);
	int sum=5*num1*(1-(num1>=50?0.15:(num1>=30?0.1:0)));
	printf("\n����Ҫ֧��%dԪ",sum);
	getchar();
	getchar();
	//T4 �����µļ������޸�Ϊ��ѭ������ģ�goto��
	//Դ���������
}

void main(){
	d_3_6();
}