/* �ַ������ı���Ӧ�� */
#include <stdio.h>
#include <string.h>
#include <malloc.h>	//��̬�������亯��
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

void test(void)	//�����ڲ���
{
	for (int i = 0; i < 1000; i++){	//�뾶500
		int left_s_count = 0;	//"   *"
		int right_s_count = 0;	//"*   "
		char *left_chars = "";
		char *right_chars = "";
		if (i != 0){

		}
	}
	/*__int64 t,i;
	while (scanf("%i64d",&t)!=EOF){
	i = pow(t,t);
	i = i % 10;
	printf("%i64d\n",i);
	}*/
	/*int x = 0;
	scanf_s("%d",&x);
	printf("%d",x);
	getchar();*/
	/*int x = 0; int y = 0;
	scanf("%d", &x);
	scanf("%d", &y);
	if (x % 4 == 0 && y == 2)
	printf("�������29��");
	else if (y == 2)
	printf("�������28��");
	else if (x % 4 != 0 && (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12))
	printf("�������31��");
	else
	printf("�������30 ��");*/
}

int a = 0;

void d_6_1(void)
{
	//ͨ����char�������洢�ַ���
	//�ַ�����\0�հ׷���Ϊ����
	//���е��ַ����ĳ��ȶ�Ҫ��ԭ���ȶ�1����Ϊ\0վ��һλ
	printf("�һ������۷�\0ǰ���ǲ���ǰ��");
	getchar();
}

void d_6_2(void)	//�洢�ַ�������
{
	char *data = "my test word is number";
	int count = 0;
	while (data[count] != '\0'){
		count++;
	}
	printf("�����ַ�������%d���ַ�", count);
	getchar();
}

void d_6_2_2(void)	//�����ַ��������Լ�ÿ���ַ����ĳ���
{
	char data[][50] = { "hello dude", "sometime i don't know that how to speak english", "but i want to try" };
	unsigned int count = sizeof(data) / sizeof(data[0]);
	printf("������乲��%u��", count);
	for (unsigned i = 0; i < count; i++){
		unsigned int number = 0;
		while (data[i][number] != '\0'){
			number++;
		}
		printf("\n�������ĵ�%u����乲����%u���ַ�", i + 1, number);
	}
	getchar();
}

void d_6_3_1()	//����C11��֧��
{
	//ò��vs2013����ȫ֧��c11
	printf("����Ƿ�֧��C11\n");
#if defined __STDC_LIB_EXT1__
	printf("֧��C11");
#else
	printf("��֧��C11");
#endif
	getchar();
}

void d_6_3_2(void)	//��ȡ�ַ�����
{
	char data[][50] = { "hello dude", "sometime i don't know that how to speak english", "but i want to try" };
	unsigned int count = sizeof(data) / sizeof(data[0]);
	printf("������乲��%u��", count);
	for (unsigned i = 0; i < count; i++){
		unsigned int number = 0;
		number = strnlen_s(data[i], sizeof(data[i]));
		printf("\n�������ĵ�%u����乲����%u���ַ�", i + 1, number);
	}
	getchar();
}

void d_6_3_3()	//�����ַ���
{
	char data1[] = "����һ������Ա������һ����Ѫ�����и������";
	const int lenght = strnlen_s(data1, sizeof(data1));
	char data2[50] = {};
	strncpy_s(data2, data1, (size_t)sizeof(data2));//strcat_s��������:Ŀ���ַ���(�̶���),Դ�ַ�����Ŀ���ַ�������
	//strcpy(data1,data2);	//ͬ�����Դﵽ����  ����ȫ  û��������
	printf(data2);
	getchar();
}

void d_6_3_4()	//�ַ���������
{
	char data1[50] = "Hello";
	char data2[] = "world";
	int returnError_code = strcat_s(data1, sizeof(data1), data2);//����������Ŀ���ַ���������һ��Ҫ������Ŀ���ַ������ó��ȣ�Ҫ���ӵ��ַ���
	if (returnError_code){
		printf("�����ַ������������� code:%d", returnError_code);
	}
	else{
		printf("%s", data1);
	}
	getchar();
}

void d_6_3_4_2()	//ƴ���ַ���
{
	char data1[] = "Hi~";
	char data2[][50] = { "Tim", "Join", "Bone" };
	unsigned int sizeCount = 0;
	int data2_char_count = sizeof(data2) / sizeof(data2[0]);
	for (int i = 0; i < data2_char_count; i++)
		sizeCount += sizeof(data2[i]);	//���������������ַ����ĳ���
	sizeCount += sizeof(data1)+1;//�������Ӻ󳤶�
	char *data3 = (char*)malloc(165);
	memset(data3, 0, sizeof(data3));
	strcat_s(data3, sizeCount, data1);
	for (int i = 0; i < data2_char_count; i++)
		strcat_s(data3, sizeCount, data2[i]);

	printf("%s", data3);

	delete[] data3;
	getchar();
}

void d_6_3_5()	//�Ƚ��ַ���
{
	char data1[50] = "";
	char data2[50] = "";
	printf("�������ַ�1\n");
	scanf_s("%s", data1, sizeof(data1));
	printf("�������ַ�2\n");
	scanf_s("%s", data2, sizeof(data1));
	if (strcmp(data1, data2) > 0){
		printf("������ַ���һ��");
	}
	else{
		printf("������ַ�һ��");
	}
	getchar();
	getchar();
}

void d_6_3_6(void)	//�����ַ�
{
	char data1[50];
	printf("�������ַ���\n");
	scanf_s("%s", &data1, sizeof(data1));
	char chr;
	printf("\n������Ҫ��ѯ���ַ�\n");
	getchar();
	scanf_s("%c", &chr, sizeof(chr));

	char *Got_chr = NULL;
	Got_chr = strchr(data1, chr);
	if (Got_chr){
		printf("%s�а���%c", data1, chr);
	}
	else{
		printf("%s�в�����%c", data1, chr);
	}
	getchar();
	getchar();
}

void d_6_3_6_2()	//��ѯ�ַ���
{
	char data1[50];
	printf("�������ַ���\n");
	scanf_s("%s", &data1, sizeof(data1));
	char chr[50];
	printf("\n������Ҫ��ѯ���ַ�\n");
	getchar();
	scanf_s("%s", &chr, sizeof(chr));

	char* Got_chr = NULL;
	Got_chr = strstr(data1, chr);
	if (Got_chr){
		printf("%s�а���%s,λ�ã�%d", data1, chr, Got_chr - data1 + 1);
	}
	else{
		printf("%s�в�����%c", data1, chr);
	}
	getchar();
	getchar();
}

void d_6_3_7()	//�ָ��ַ���
{
	char data1[100];//���ڴ洢Դ�ַ���
	char data2[1000] = "";//���ڴ洢�ָ����ַ���
	size_t str_len = sizeof(data2);
	size_t data1_len = sizeof(data1);
	char *filter_char = " \",.~!? \n";
	bool CanRun = true;
	printf("������Դ�ַ���\n");
	while (true){
		if (!gets_s(data1, data1_len)){	//Ҳ����ʹ��fgets(��ַ����󳤶ȣ�����Դ������->stdin��)
			printf("��������");
			CanRun = false;
		}
		if (!strnlen_s(data1, data1_len)){
			break;
		}
		if (strcat_s(data2, str_len, data1)){
			printf("ƴ�ӳ�������");
			CanRun = false;
		}
	}
	char* token = NULL;	//���ڱ���ԭ��ַ
	char * next_token = NULL;//���ڱ���ָ���ַ
	if (CanRun){
		char * next_token = strtok_s(data2, filter_char, &token);//��ȡ��һ������Ҫ��ĵ�ַ

		while (next_token != NULL){//ѭ����ȡ���渴�ϵĵ�ַ
			if (next_token != NULL){
				printf("%s\t", next_token);//�������Ҫ��ĵ�ַ
				next_token = strtok_s(NULL, filter_char, &token);//ִ��
			}
		}
	}

	getchar();
}

void d_6_3_8(void)	//��ȡ���з�
{
	char data[100];
	size_t data1_len = sizeof(data);
	printf("�������ַ���");
	while (true){
		if (!fgets(data, sizeof(data), stdin)){	//�˺������Ի�ȡ���з�
			break;
		}
		if (data[0] == '\n'){
			break;
		}
	}
	printf("%s", data);
	getchar();
}

void d_6_4()	//����ת���ַ���
{
	//�жϹ������˶����ַ����������֣����ٱ�����
	//	����		����
	//	islower		Сд��ĸ
	//	isupper		��д��ĸ
	//	isalpha		�Ƿ���ĸ
	//	isalnum		�Ƿ����ֻ���ĸ
	//	iscntrl		�����ַ�
	//	isprint		�Ƿ�ɴ�ӡ
	//	isgraph		�Ƿ�ɴ�ӡ�����ո�
	//	isdigit		�Ƿ�10��������
	//	isxdigit	�Ƿ�16��������
	//	isblank		�ո�\t
	//	isspace		�հ��ַ����ո�\n,\t,\v,\r,\f��
	//	ispunct		isprint��isalnum����false�Ŀɴ�ӡ�ַ�

	int letter_count = 0;
	int number_count = 0;
	int punctuation_count = 0;
	char data[100] = "";
	scanf_s("%s", &data, sizeof(data));
	int i = 0;
	char chr = data[i];
	while (data[i])
	{
		if (isalnum(data[i])){
			if (isalpha(data[i])){
				letter_count++;
			}
			else{
				number_count++;
			}
		}
		else{
			if (ispunct(data[i])){
				punctuation_count++;
			}
		}
		i++;
	}
	printf("letter:%d\tnumber:%d\tpunctuation:%d", letter_count, number_count, punctuation_count);
	getchar();
	getchar();
}

void d_6_4_1(void)	//ת����Сд
{
	char data[50] = "";
	if (fgets(data, sizeof(data), stdin)){
		for (int i = 0; (data[i] = (char)tolower(data[i])) != '\0'; i++);
		printf("\nתСд��%s", data);
		for (int i = 0; (data[i] = (char)toupper(data[i])) != '\0'; i++);
		printf("\nת��д��%s", data);
	}
	getchar();
}

void d_6_4_2()	//���ַ���ת������ֵ
{
	//ÿһ����������Ҫһ��ָ�����
	//	atof	����double����ֵ ������󡱱�ʾ�ַ���INF��INFINITY ������ĸȫ��д��Сд not a numberָNAN
	//	atoi	����int
	//	atol	����long
	//	atoll	����long long
	//�����һЩǰ���հף�isspace����true���ַ���
	char data[] = " 98.4";
	double value = atof(data);	//����C# tryParse �޷�ת����ʱ�򷵻�����ֵ  
	printf("%lf\t", value);
	//��Ҫ��������
	//	strtod	תΪdouble
	//	strtof	תΪfloat
	//	strtold	long double
	double value2 = 0;
	char str[] = "3.5 2.5 1.26";
	char *pstr = str;
	char *ptr = NULL;
	while (true)
	{
		value2 = strtod(pstr, &ptr);//��ͬʱת����� ��������ɽ����Ͳ�����int�ͣ�0����10���� 16����16���� 2����2����
		if (pstr == ptr){
			break;
		}
		else{
			printf("%f\t", value2);
			pstr = ptr;
		}
	}

	getchar();
}

void d_6_5()	//���
{
	//�Ӽ��������л�ȡһ���ı�������ÿ�����ʳ��ֵ�Ƶ�ף������ִ�Сд��

	char data_row[50] = "";	//���ڴ洢���뵥�е��ı�
	char data[500] = "";	//���ڴ洢ȫ�����ı�
	char *words[1000];		//�洢���еĵ���
	bool canRun = true;		//�Ƿ������������

	//ѭ����ȡ�ı�
	while (true){
		if (!fgets(data_row, sizeof(data), stdin)){
			printf("����������Ȼ����������ٳ�����������������ı�������һЩ");
			canRun = false;
			break;
		}
		if (data_row[0] == '\n'){
			break;	//���������� ������ѭ��
		}
		if (strncat_s(data, data_row, sizeof(data))){
			printf("ƴ���ַ�����������");
			canRun = false;
			break;
		}
	}

	//��ȡ����word
	char *Got_chr = NULL;
	char fliter[10] = " \",.\n";
	char *Got_word = strtok_s(data, fliter, &Got_chr);
	int i = 0;
	while (Got_word){
		words[i] = Got_word;
		if (Got_word){
			Got_word = strtok_s(NULL, fliter, &Got_chr);
			i++;
		}
	}

	for (){}

	getchar();
}


void main(){
	d_6_5();
}