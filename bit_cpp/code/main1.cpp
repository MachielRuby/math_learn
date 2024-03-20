#include<iostream>
using namespace std;
//工程项目中常用
using std::cout;
using std::endl;

//缺省参数
void Func(int a = 0)
{
	cout << a << endl;
}

// 半缺省
void Func1(int a, int b, int c = 10);
//void Func1(int a = 6, int b, int c = 10); err 必须右往左缺省

// 函数重载 参数个数 类型
/*
void foo(int x, int y = 10);
void foo(int x, int y);
在这种情况下，编译器会认为这是两个完全相同的函数声明，
因为它们的参数列表是相同的。这样定义是不合法的，
编译器会报错。】

void func()
int func()
只是返回值不同，顺序不同,不能构成重载
什么是函数重载？
为什么c语言不支持?
编译器内部会重新给函数命名，c++的命名方式与c语言不同，函数名修饰有所区别，故有所区别。
预处理 ： 头文件展开、宏替换、条件编译、去掉注释
编译： 检查语法，生成汇编代码
汇编：  汇编代码转成二进制的机器码
链接：  将两个目标文件链接到一起
*/

extern "C" int add(int left, int  right);
// 告诉编译器采用c的方式链接

//int main()
//{
//	//引用
//	int a = 1;
//	int& ra = a; //ra 是a的引用,是a的别名
//	int& b = a;
//	int& c = b;
//
//	int d = 2;
//	c = d; // 分析这里是把d值赋值给c
//
//	const int d = 0;
//	//int& b = d;  err d只读，b可读可写，所以不能。反过来可以，权限不能有小变大，只能大变小 个人理解。
//
//	const int* cp1 = &a;
//	//int *p1 = cp1;//不能属于权限的放大
//
//	int* p2 = &c;
//	const int* cp2 = p2;//可以，权限的2缩小
//	return 0;
//}

int Add1(int a, int b)
{
	int c = a + b;
	return c;
}
int& Add2(int a, int b)
{
	int c = a + b;
	return c;
}


int main()
{
	const int& ret = Add1(1, 2);
	Add1(3, 4);
	cout << Add1(1, 2) << endl;

	const int& ret1 = Add2(1, 2); //引用不是狠安全
	Add2(3, 4);
	cout << ret1 << endl;
	// 出了作用域，引用返回还在就可以
	//指针都是四个字节32位平台下

	//inline空间换时间的做法

	int c = 10;
	auto d = c;
	cout << typeid(d).name() << endl;
	int* p = nullptr; //推荐
	return 0;
}