#define _CRT_SECURE_NO_WARNINGS	//��ʹ��vs2013�汾��ʱ�������scanf��ȫ������ ��Ӵ˳��� �������
#include <stdio.h>
#include <math.h>

void test(void)	//����
{
	printf("�����ڲ���");
	getchar();
}

void d_5_1_3(void)	//ʹ������
{
	int grade[10];
	int sum = 0;
	int num1 = 0;
	printf("������10������\n");
	for (int i = 0; i < 10; i++){
		printf("��%d����\n", i);
		scanf("%d", &num1);
		grade[i] = num1;
		sum += grade[i];
	}
	printf("�ܺ�Ϊ��%d\tƽ��ֵΪ��%d\n", sum, sum / 10);
	printf("�����ֵ�ֱ��ǣ�\n");
	for (unsigned int i = 0; i < 10; i++)
		printf("\t%d", grade[i]);
	getchar();
	getchar();

}

void d_5_2()	//Ѱַ����� &
{
	long num1 = 123;
	double num3 = 4.0;
	printf("һ��long���͵�ֵռ��%u���ֽ�\n", sizeof(num1));
	printf("�����ڴ��ַΪ%p", &num1);
	printf("һ��double���͵�ֵռ��%u���ֽ�\n", sizeof(num3));
	printf("�����ڴ��ַΪ%p", &num3);
	getchar();
}

void d_5_5(void)	//����Ĵ�С
{
	//����  sizeof ������  ���Ի�����鹲ռ�ö����ֽ�
	double nums[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	for (unsigned int i = 0; i < sizeof nums / sizeof(nums[0]); i++)
		printf("%.2f\t", nums[i]);
	getchar();
}

void d_5_8(void)	//�䳤����
{
	int size = 0;
	printf("������Ҫ��������ĳ���\n");
	scanf("%d", &size);
	int *nums = new int[size];
	int sizes = sizeof &nums;
	int count = sizes / sizeof(int);
	for (unsigned int i = 0; i < size; i++)
	{
		printf("\n�������%d��ֵ", i + 1);
		scanf("%d", &nums[i]);
	}
	printf("\n�ɱ䳤����Ԫ�طֱ��ǣ�");
	for (unsigned int i = 0; i < size; i++)
		printf("%d\t", nums[i]);

	getchar();
	getchar();
}

void d_5_9(void)	//���
{
	//�Ź�����Ϸ
	int player = 0;
	int winner = 0;
	int choice = 0;
	unsigned int row = 0;
	unsigned int column = 0;

	char board[3][3] = {
		{ '1', '2', '3' },
		{ '4', '5', '6' },
		{ '7', '8', '9' },
	};

	for (unsigned int i = 0; i < 9 && winner == 0; ++i)
	{
		printf("\n");
		printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
		printf("---|---|---\n");
		printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
		printf("---|---|---\n");
		printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

		player = i % 2 + 1;

		do
		{
			printf("��� %d ��Ҫ������������ %c ��", player, player == 1 ? 'X' : 'O');
			scanf("%d", &choice);

			row = --choice / 3;
			column = choice % 3;
		} while (choice<0 || choice>8 || board[row][column] > '9');
		board[row][column] = player == 1 ? 'X' : 'O';

		if ((board[0][0] == board[1][1] && board[0][0] == board[2][2])
			|| (board[0][0] == board[1][1] && board[0][0] == board[2][2]))
		{
			winner = player;
		}
		else{
			for (unsigned int line = 0; line <= 2; ++line)
			{
				if ((board[line][0] == board[line][1] && board[line][0] == board[line][2])
					|| (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
					winner = player;
			}
		}
	}

	printf("\n");
	printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

	if (winner){
		printf("��� %d ��ʤ", winner);
	}
	else{
		printf("ƽ��");
	}

	getchar();
	getchar();

}

void d_5_11(void)	//��ϰ
{
	int num = 0;
	double *t1_2 = new double[5];
	double *t1_1 = new double[5];
	double t1_3 = 0.0;
	double *data = new double[100];
	float *amounts = new float[5];
	long *dollars = new long[5];
	long *cents = new long[5];
	double sum = 0.0;

	double t_4[11][5];

	printf("������Ҫ�鿴����ţ�������");
	scanf("%d", &num);
	switch (num){
	case 1:
		//�������double ������ �� ������
		for (size_t i = 0; i < 5; i++)
		{
			printf("������� %d ����", i + 1);
			scanf("%lf", &t1_1[i]);
			t1_2[i] = 1.0 / t1_1[i];
			int num = t1_1[i];
			t1_3 += t1_2[i];
		}

		printf("�����ֱ��ǣ�\n");
		for (size_t i = 0; i < 5; i++)
		{
			printf("\t%lf", t1_2[i]);
		}
		printf("\n�����ܺ�Ϊ��%f", t1_3);
		break;
	case 2:
		for (size_t i = 1; i <= 100; i++)
		{
			int num1 = 2 * i;
			data[i - 1] = 1.0l / (num1*(num1 + 1)*(num1 + 2));
		}
		for (int i = 0; i < 100; i++){
			printf("\t%lf", data[i]);
			if ((i + 1) % 2 == 1){
				sum += data[i];
			}
			else{
				sum -= data[i];
			}
		}
		printf("\n�ܺ�Ϊ %lf", sum);
		printf("\n�ܺ�*4+3=%lf", sum * 4 + 3);

		break;
	case 3:
		//��һ���������������
		for (unsigned int i = 0; i < 5; i++){
			printf("������� %d ����", i + 1);
			scanf("%f", &amounts[i]);
			//dollars[i] = (int)amounts[i];
			dollars[i] = (int)(amounts[i] * 100) / 100;
			//cents[i] = (int)((float)(amounts[i] - dollars[i]) * 100.0);
			cents[i] = (int)(amounts[i] * 1000) % 1000 / 10;
		}
		for (unsigned int i = 0; i < 5; i++){
			printf("\n��%d.%d", dollars[i], cents[i]);
		}
		break;
	case 4:
		for (unsigned int i = 0; i < 11; i++){
			t_4[i][0] = 2.0l + (i)*0.1l;
			printf("\n");
			for (unsigned int j = 1; j < 5; j++){

				t_4[i][j] = 1 / pow(t_4[i][0], j + 0.0);
			}

			for (unsigned int j = 0; j < 5; j++){
				printf("%lf\t", t_4[i][j]);
			}
		}
		break;

	default:break;
	}
	getchar();
	getchar();
}

void main()
{
	d_5_11();
}