/* ָ�� */
#include <stdio.h>
#include <stddef.h>		//ͨ������������޷�ʶ��NULL��ʱ��  ���ô��ļ�ͷ�Ϳ�����

void test()	//�����ڲ���
{
	printf("����");
	getchar();
}

void d_7_1_2()	//����ָ��
{
	int number = 5;
	int *p_number = &number;	//ע���ʼ��ָ���ʱ��һ��Ҫ��ʼ��  ������Σ��

	printf("int����number�ĵ�ַ��%p\t intָ��*p_number�ĵ�ַ��%p\n", &number, &p_number);
	printf("int����number��ֵ��%d\t intָ��*p_number��ֵ��%p\n", number, p_number);

	getchar();
}

void d_7_1_3()	//ʹ��ָ��
{
	int number = 5;
	printf("Դ����Ϊ��%d", number);
	int *p_number = &number;
	*p_number += 10;
	printf("�޸�ָ�����ݺ�Ϊ��%d", number);
	getchar();
}

void d_7_1_3_2()	//ʹ��ָ���������
{
	int number = 0;
	int * p_number = &number;
	scanf_s("%d", p_number);
	printf("%d", number);
	getchar();
	getchar();
}

void d_7_1_4()	//ָ�볣����ʹ��
{
	int value = 5;
	const int *p_value = &value;
	//*p_value += 10;		//�޸�ָ�볣����Ӧֵ��ʱ�� ���޷��޸ĵ�
	printf("%d\n", *p_value);

	int number = 30;
	p_value = &number;		//ָ�볣����ֵ���Ա��ı�
	printf("%p\n", p_value);
	getchar();
}

void d_7_1_5()	//����ָ��
{
	int value = 5;
	int number = 10;
	int *const p_value = &value;//����ָ��	ע�ⶨ�巽ʽ  *const ������
	printf("%p\n", p_value);
	//p_value = &number;		//����ָ���޷��޸�ָ����ָ�ĵ�ַ
	printf("%p", p_value);
	getchar();
}

void d_7_1_6()	//����
{
	//ͨ���ø�ʽΪ  p+������
}

void d_7_2()	//������ָ��
{
	char data[50] = "this is my demo";
	printf("����data[0]����Ӧ�ĵ�ַ��%p\n", &data[0]);
	char *p_data = data;
	printf("����data����Ӧ�ĵ�ַ��%p", p_data);
	getchar();
}

void d_7_2_2()	//��
{
	int number = 6;
	char data[50] = "this is my demo";
	char *p_data = data;
	p_data += number;	//��ַ+6
	printf("%c", *p_data);//����ĵ�ַ�ϵ�Ԫ��
	getchar();
}

void d_7_3()	//��ά����
{
	int data[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	printf("����data�ĵ�ַ��%p\n", data);
	printf("����data[0]�ĵ�ַ��%p\n", data[0]);
	printf("����data[0][0]�ĵ�ַ��%p\n", &data[0][0]);

	//˵�� ��ά����ĵ�ַ�ǵ�һ��Ԫ�صĵ�ַ  �� һά������һ����
	getchar();
}

void d_7_3_t_2()	//��ά������
{
	int data[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	for (int i = 0;i<9;i++){
		printf("\n%d",*(*data+i));//��Ϊ����һά����Ҳ�ǵ�ַ  ����ȡ�����ݵ�ַ��Ӧ��ֵ  ȡ��Ԫ�ص�ַ   
	}
	getchar();
}

void d_7_3_1()	//��ά�����ָ��
{
	int data[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	int *p_data = *data;//��ȡһά���ݵ�ַ
	for (int i = 0;i<9;i++){
		printf("%d\n",*(p_data+i));
	}
	getchar();
}

void main()
{
	d_7_3_1();
}