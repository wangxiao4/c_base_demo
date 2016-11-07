/* 字符串与文本的应用 */
#include <stdio.h>
#include <string.h>
#include <malloc.h>	//动态函数分配函数
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

void test(void)	//仅用于测试
{
	for (int i = 0; i < 1000; i++){	//半径500
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
	printf("这个月有29天");
	else if (y == 2)
	printf("这个月有28天");
	else if (x % 4 != 0 && (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12))
	printf("这个月有31天");
	else
	printf("这个月有30 天");*/
}

int a = 0;

void d_6_1(void)
{
	//通常用char数组来存储字符串
	//字符串以\0空白符作为结束
	//所有的字符串的长度都要比原长度多1，因为\0站用一位
	printf("我会走上巅峰\0前提是不断前进");
	getchar();
}

void d_6_2(void)	//存储字符串变量
{
	char *data = "my test word is number";
	int count = 0;
	while (data[count] != '\0'){
		count++;
	}
	printf("测试字符串共有%d个字符", count);
	getchar();
}

void d_6_2_2(void)	//测试字符串个数以及每个字符串的长度
{
	char data[][50] = { "hello dude", "sometime i don't know that how to speak english", "but i want to try" };
	unsigned int count = sizeof(data) / sizeof(data[0]);
	printf("测试语句共有%u条", count);
	for (unsigned i = 0; i < count; i++){
		unsigned int number = 0;
		while (data[i][number] != '\0'){
			number++;
		}
		printf("\n测试语句的第%u条语句共包含%u个字符", i + 1, number);
	}
	getchar();
}

void d_6_3_1()	//检测对C11的支持
{
	//貌似vs2013不完全支持c11
	printf("检测是否支持C11\n");
#if defined __STDC_LIB_EXT1__
	printf("支持C11");
#else
	printf("不支持C11");
#endif
	getchar();
}

void d_6_3_2(void)	//获取字符长度
{
	char data[][50] = { "hello dude", "sometime i don't know that how to speak english", "but i want to try" };
	unsigned int count = sizeof(data) / sizeof(data[0]);
	printf("测试语句共有%u条", count);
	for (unsigned i = 0; i < count; i++){
		unsigned int number = 0;
		number = strnlen_s(data[i], sizeof(data[i]));
		printf("\n测试语句的第%u条语句共包含%u个字符", i + 1, number);
	}
	getchar();
}

void d_6_3_3()	//复制字符串
{
	char data1[] = "我是一个程序员，更是一个有血有肉有感情的人";
	const int lenght = strnlen_s(data1, sizeof(data1));
	char data2[50] = {};
	strncpy_s(data2, data1, (size_t)sizeof(data2));//strcat_s三个参数:目标字符串(固定的),源字符串，目标字符串长度
	//strcpy(data1,data2);	//同样可以达到复制  不安全  没有溢出检查
	printf(data2);
	getchar();
}

void d_6_3_4()	//字符串的连接
{
	char data1[50] = "Hello";
	char data2[] = "world";
	int returnError_code = strcat_s(data1, sizeof(data1), data2);//三个参数：目标字符串（长度一定要够），目标字符串可用长度，要连接的字符串
	if (returnError_code){
		printf("连接字符串出现了问题 code:%d", returnError_code);
	}
	else{
		printf("%s", data1);
	}
	getchar();
}

void d_6_3_4_2()	//拼接字符串
{
	char data1[] = "Hi~";
	char data2[][50] = { "Tim", "Join", "Bone" };
	unsigned int sizeCount = 0;
	int data2_char_count = sizeof(data2) / sizeof(data2[0]);
	for (int i = 0; i < data2_char_count; i++)
		sizeCount += sizeof(data2[i]);	//增加数组中所有字符串的长度
	sizeCount += sizeof(data1)+1;//计算连接后长度
	char *data3 = (char*)malloc(165);
	memset(data3, 0, sizeof(data3));
	strcat_s(data3, sizeCount, data1);
	for (int i = 0; i < data2_char_count; i++)
		strcat_s(data3, sizeCount, data2[i]);

	printf("%s", data3);

	delete[] data3;
	getchar();
}

void d_6_3_5()	//比较字符串
{
	char data1[50] = "";
	char data2[50] = "";
	printf("请输入字符1\n");
	scanf_s("%s", data1, sizeof(data1));
	printf("请输入字符2\n");
	scanf_s("%s", data2, sizeof(data1));
	if (strcmp(data1, data2) > 0){
		printf("输入的字符不一样");
	}
	else{
		printf("输入的字符一样");
	}
	getchar();
	getchar();
}

void d_6_3_6(void)	//搜索字符
{
	char data1[50];
	printf("请输入字符串\n");
	scanf_s("%s", &data1, sizeof(data1));
	char chr;
	printf("\n请输入要查询的字符\n");
	getchar();
	scanf_s("%c", &chr, sizeof(chr));

	char *Got_chr = NULL;
	Got_chr = strchr(data1, chr);
	if (Got_chr){
		printf("%s中包含%c", data1, chr);
	}
	else{
		printf("%s中不包含%c", data1, chr);
	}
	getchar();
	getchar();
}

void d_6_3_6_2()	//查询字符串
{
	char data1[50];
	printf("请输入字符串\n");
	scanf_s("%s", &data1, sizeof(data1));
	char chr[50];
	printf("\n请输入要查询的字符\n");
	getchar();
	scanf_s("%s", &chr, sizeof(chr));

	char* Got_chr = NULL;
	Got_chr = strstr(data1, chr);
	if (Got_chr){
		printf("%s中包含%s,位置：%d", data1, chr, Got_chr - data1 + 1);
	}
	else{
		printf("%s中不包含%c", data1, chr);
	}
	getchar();
	getchar();
}

void d_6_3_7()	//分割字符串
{
	char data1[100];//用于存储源字符串
	char data2[1000] = "";//用于存储分割后的字符串
	size_t str_len = sizeof(data2);
	size_t data1_len = sizeof(data1);
	char *filter_char = " \",.~!? \n";
	bool CanRun = true;
	printf("请输入源字符串\n");
	while (true){
		if (!gets_s(data1, data1_len)){	//也可以使用fgets(地址，最大长度，输入源（键盘->stdin）)
			printf("输入有误");
			CanRun = false;
		}
		if (!strnlen_s(data1, data1_len)){
			break;
		}
		if (strcat_s(data2, str_len, data1)){
			printf("拼接出了问题");
			CanRun = false;
		}
	}
	char* token = NULL;	//用于保存原地址
	char * next_token = NULL;//用于保存分割后地址
	if (CanRun){
		char * next_token = strtok_s(data2, filter_char, &token);//获取第一个复合要求的地址

		while (next_token != NULL){//循环获取后面复合的地址
			if (next_token != NULL){
				printf("%s\t", next_token);//输出复合要求的地址
				next_token = strtok_s(NULL, filter_char, &token);//执行
			}
		}
	}

	getchar();
}

void d_6_3_8(void)	//读取换行符
{
	char data[100];
	size_t data1_len = sizeof(data);
	printf("请输入字符串");
	while (true){
		if (!fgets(data, sizeof(data), stdin)){	//此函数可以获取换行符
			break;
		}
		if (data[0] == '\n'){
			break;
		}
	}
	printf("%s", data);
	getchar();
}

void d_6_4()	//分析转化字符串
{
	//判断共输入了多少字符，多少数字，多少标点符号
	//	函数		内容
	//	islower		小写字母
	//	isupper		大写字母
	//	isalpha		是否字母
	//	isalnum		是否数字或字母
	//	iscntrl		控制字符
	//	isprint		是否可打印
	//	isgraph		是否可打印不含空格
	//	isdigit		是否10进制数字
	//	isxdigit	是否16进制数字
	//	isblank		空格，\t
	//	isspace		空白字符（空格，\n,\t,\v,\r,\f）
	//	ispunct		isprint和isalnum返回false的可打印字符

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

void d_6_4_1(void)	//转换大小写
{
	char data[50] = "";
	if (fgets(data, sizeof(data), stdin)){
		for (int i = 0; (data[i] = (char)tolower(data[i])) != '\0'; i++);
		printf("\n转小写：%s", data);
		for (int i = 0; (data[i] = (char)toupper(data[i])) != '\0'; i++);
		printf("\n转大写：%s", data);
	}
	getchar();
}

void d_6_4_2()	//将字符串转换成数值
{
	//每一个函数都需要一个指针参数
	//	atof	生成double类型值 “无穷大”表示字符串INF或INFINITY 所有字母全大写或小写 not a number指NAN
	//	atoi	生成int
	//	atol	生成long
	//	atoll	生成long long
	//会忽略一些前导空白（isspace返回true的字符）
	char data[] = " 98.4";
	double value = atof(data);	//类似C# tryParse 无法转换的时候返回其他值  
	printf("%lf\t", value);
	//需要两个参数
	//	strtod	转为double
	//	strtof	转为float
	//	strtold	long double
	double value2 = 0;
	char str[] = "3.5 2.5 1.26";
	char *pstr = str;
	char *ptr = NULL;
	while (true)
	{
		value2 = strtod(pstr, &ptr);//可同时转换多个 参数后面可接类型参数（int型）0代表10进制 16代表16进制 2代表2进制
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

void d_6_5()	//设计
{
	//从键盘输入中获取一段文本，计算每个单词出现的频谱（不区分大小写）

	char data_row[50] = "";	//用于存储输入单行的文本
	char data[500] = "";	//用于存储全部行文本
	char *words[1000];		//存储所有的单词
	bool canRun = true;		//是否可以正常运行

	//循环读取文本
	while (true){
		if (!fgets(data_row, sizeof(data), stdin)){
			printf("输入有误，虽然键盘输入很少出现这种情况，但是文本情况会多一些");
			canRun = false;
			break;
		}
		if (data_row[0] == '\n'){
			break;	//如果输入结束 则跳出循环
		}
		if (strncat_s(data, data_row, sizeof(data))){
			printf("拼接字符串除了问题");
			canRun = false;
			break;
		}
	}

	//获取所有word
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