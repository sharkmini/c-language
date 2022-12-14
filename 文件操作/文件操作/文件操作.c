#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
// 打开文件
// FILE* fopen(const char* filename, const char* mode);// mode 打开方式
// 关闭文件
// int fclose(FILE* stream); // 文件流
//int main()
//{
//	// 打开文件
//	FILE* pf = fopen("test.txt", "w");// 相对路径
//	// FILE* pf = fopen("d:\\code\\test.txt", "w");// 绝对路径
//
//	// 没有找到会返回空指针，判断是否为空指针，如果是空指针就报错。
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	// 写文件  fputc - 单个字符输出（写到文件中）
//  // int fputc ( int character, FILE * stream );
//	fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	// 打开文件
//	FILE* pf = fopen("test.txt", "w");
//
//	// 判断
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	// 写文件
//	int i = 0;
//	for (i = 0; i < 26; i++)
//	{
//		fputc('a' + i, pf);
//	}
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;// 释放
//	return 0;
//}

//int main()
//{
//	// 打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 读文件
//  // int fgetc ( FILE * stream );
//	/*int i = 0;
//	for (i = 0; i < 26; i++)
//	{
//		int ch = fgetc(pf);
//		printf("%c ", ch);
//	}*/
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c ", ch);
//	}
//
//	// 关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

// 按照顺序写文本行
//int main()
//{
//	// 打开文件
//	FILE* pf = fopen("test.txt", "w");
// 
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
// 
//	// 写文件 - 一行一行写
//  // int fputs ( const char * str, FILE * stream );
//	fputs("hello\n", pf);
//	fputs("world\n", pf);
// 
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

// 按照顺序读文本行
//int main()
//{
//	// 打开文件
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 写文件 - 一行一行读，存到数组中
//  // char * fgets ( char * str, int num, FILE * stream );
//	char arr[20] = "###############";
//	fgets(arr,20,pf);
//	printf("%s", arr);
//	
//	fgets(arr,20,pf);
//	printf("%s", arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

// 写一个结构体的数据
//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S s = { "张三",20,95.5f };
//	FILE* pf = fopen("test.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 写文件
//  // int fprintf ( FILE * stream, const char * format, ... );
//	fprintf(pf, "%s %d %.2lf", s.name, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//读取一个结构体数据
//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct S s = {0};
//	//把s中的数据写到文件中
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 读文件
//  // int fscanf ( FILE * stream, const char * format, ... );
//	fscanf(pf, "%s %d %f", s.name, &(s.age), &(s.score));
//
//	printf("%s %d %f\n", s.name, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}


//scanf(...)
//fscanf(stdin,...)

//printf
//fprintf(stdout, ...)

//int main()
//{
//	int ch = fgetc(stdin);
//	fputc(ch, stdout);
//
//	return 0;
//}

//二进制的形式：写一个结构体的数据

//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct S s = { "zhangsan", 20, 95.5f };
//	//把s中的数据写到文件中
//	FILE*pf = fopen("test.txt", "wb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 二进制的写文件
//	// size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
//	fwrite(&s, sizeof(s), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//二进制的读文件
//struct S
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct S s = {0};
//	// 把s中的数据写到文件中
//	FILE* pf = fopen("test.txt", "rb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 二进制的读文件
//	// size_t fread(void* ptr, size_t size, size_t count, FILE * stream);
//	fread(&s, sizeof(s), 1, pf);
//
//	printf("%s %d %.2f\n", s.name, s.age, s.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include <stdio.h>
//
//struct S
//{
//	char name[10];
//	int age;
//	float score;
//};
//
//
//
//int main()
//{
//	char buf[100] = {0};
//	struct S tmp = { 0 };
//
//	struct S s = { "zhangsan", 20, 95.5f };
//	//能够把这个结构体的数据，转换成字符串
//	//"zhangsan 20 95.5"
//	sprintf(buf, "%s %d %f", s.name, s.age, s.score);//以字符串的形式打印
//	printf("%s\n", buf);
//
//	//将buf中的字符串，还原成一个结构体数据
//	sscanf(buf, "%s %d %f", tmp.name, &(tmp.age), &(tmp.score));
//	printf("%s %d %f\n", tmp.name, tmp.age, tmp.score);//以结构的形式打印
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    FILE* pFile;
//    pFile = fopen("example.txt", "wb");
//    fputs("This is an apple.", pFile);
//    fseek(pFile, 9, SEEK_SET);
//    fputs(" sam", pFile);
//    fclose(pFile);
//    return 0;
//}

#include <stdio.h>
int main()
{
    int a = 10000;
    FILE* pf = fopen("test.txt", "wb");
    fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
    fclose(pf);
    pf = NULL;
    return 0;
}