#include<iostream>
using namespace std;


//int func(int a, int b)
//{
//	if (b == 0)
//	{
//		//Maker m;
//		//throw m;//抛出一个Maker类型的异常
//		//throw 20.22;//抛出一个double类型的异常
//		//throw 'c';
//		throw 20.0f;
//
//	}
//
//	return a / b;
//}
//void test()
//{
//	int a = 10;
//	int b = 0;
//
//	try
//	{
//		func(a, b);
//
//	}
//	catch (int)
//	{
//		cout << "接收一个int类型的异常" << endl;
//	}
//	catch (double s)
//	{
//		cout << "接收一个double类型的异常" << endl;
//	}
//	catch (char)
//	{
//		cout << "接收一个char类型的异常" << endl;
//	}
//	catch (...)//接收其他类型的异常
//	{
//		cout << "接收一个其他类型的异常" << endl;
//	}
//
//
//}
//class Maker
//{
//public:
//	Maker()
//	{
//		cout << "Maker的构造" << endl;
//	}
//	Maker(const Maker& m)
//	{
//		cout << "Maker的拷贝构造" << endl;
//	}
//	~Maker()
//	{
//		cout << "Maker的析构" << endl;
//	}
//};
//
//void func()
//{
//	//在抛出异常的函数中，如果抛出异常之后，但函数没有结束，这时，栈上申请的对象都会被释放
//	//这就叫栈解旋
//	Maker m;
//	throw m;//这个m是Maker m拷贝一份的
//
//	cout << "func函数结束" << endl;
//}
//
//void test()
//{
//	try
//	{
//		func();
//		cout << "func()代码后" << endl;
//	}
//	catch (Maker)
//	{
//		cout << "接收一个Maker类型的异常" << endl;
//	}
//
//
//}
//
//class Maker
//{
//public:
//	Maker()
//	{
//		cout << "Maker的构造" << endl;
//	}
//	Maker(const Maker& m)
//	{
//		cout << "Maker的拷贝构造" << endl;
//	}
//	~Maker()
//	{
//		cout << "Maker的析构" << endl;
//	}
//};
////产生三个对象
//void func1()
//{
//	Maker m;//第一个对象，在异常接收前被释放
//	throw m;//第二个对象，是第一个对象拷贝过来的
//}
//
//void test01()
//{
//	try
//	{
//		func1();
//	}
//	catch (Maker m1)//第三个对象，是第二个对象拷贝过来的
//	{
//		cout << "接收一个Maker类型的异常" << endl;
//		//第二个和第三个对象在catch结束时释放
//
//	}
//}
//
//void func3()
//{
//	throw Maker();//匿名对象
//
//}
//
//void test03()
//{
//	try
//	{
//		func3();
//	}
//	catch (Maker& m1)
//	{
//		cout << "接收一个Maker类型的异常" << endl;
//
//
//	}
//
//}
//int main()
//{
//	test03();
//	return 0;
//}

class Maker
{
public:
	Maker(int age)
	{
		if (age < 0 || age>150)
		{
			throw out_of_range("年龄不在范围内");

		}
		else
		{
			this->age = age;
		}
	}
public:
	int age;
};

void test()
{
	try
	{
		Maker m(200);
	}
	catch (out_of_range& ex)
	{
		cout << ex.what() << endl;
	}

}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}
