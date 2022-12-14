#define _CRT_SECURE_NO_WARNINGS 1
// 笔试题1：
//#include <stdio.h>
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	// (&a + 1)原本的类型是数组指针 int(*)[5],强制转换成int*类型
//	printf("%d,%d", *(a + 1), *(ptr - 1));// 2,5
//	return 0;
//}


// 笔试题2：
//#include <stdio.h>
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
//// 假设p 的值为0x100000。 如下表表达式的值分别为多少？
//// X86环境下：
//// 已知，结构体Test类型的变量大小是20个字节
//// 练习的是指针类型+-整数的问题(加指针类型的大小)
//// %p 打印地址
//int main()
//{
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);// p是结构体指针，大小20字节，+1后为0x100014(十六进制)
//	printf("%p\n", (unsigned long)p + 0x1);// 强制转换为无符号长整型，不是指针，+1为0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);// 强制转换为整型指针类型，+1后为0x100004
//	return 0;
//}


// 笔试题3:
//#include <stdio.h>
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);// &a+1数组后的地址，强制转换成int*类型
//	int* ptr2 = (int*)((int)a + 1);// a是首元素地址，强制转换成int类型，+1就是移动一个字节
//	// 00000000 00000000 00000000 00000000
//	// 十六进制就变成了 0x 00 00 00 00
//	// 在vs中是小端存储(低位存到低地址)
//	// 数组a在内存中存放为 |01 00 00 00 | 02 00 00 00 | 03 00 00 00 | 04 00 00 00|
//	// (int*)((int)a + 1) 强制转换成int*类型，在解引用时访问4个字节，所以取出的内容是
//	// 01 |00 00 00  02|00 00 00  03 00 00 00  04 00 00 00    |00 00 00 02|这一部分
//	// 以十六进制格式打印转换为 0x 02 00 00 00 打印结果就是 2000000
//	printf("%x,%x", ptr1[-1], *ptr2);// 4,2000000
//	return 0;
//}


// 笔试题4:
//#include <stdio.h>
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };// 这是逗号表达式，实际初始化{1,3,5}
//	// 二维数组初始化要int a[3][2] = { {0,1}, {2,3}, {4,5} };
//	// 实际初始化后的数组为：
//	//                     1 3
//	//                     5 0
//	//                     0 0
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//	return 0;
//}


// 笔试题5:
//#include <stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	// 指针-指针得到元素个数
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//                     -4的补码直接打印        -4
//	// 小地址-大地址 = 负数
//	return 0;
//}


// 笔试题6:
//#include <stdio.h>
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));// 10,5
//	return 0;
//}


// 笔试题7:
//#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);// at
//	return 0;
//}


// 笔试题8:
#include <stdio.h>
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);// POINT
	printf("%s\n", *-- * ++cpp + 3);// ER
	printf("%s\n", *cpp[-2] + 3);// ST
	printf("%s\n", cpp[-1][-1] + 1);// EW
	return 0;
}