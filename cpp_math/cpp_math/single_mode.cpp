#include <iostream>
using namespace std;
//class Singleton {
//private:
//	static Singleton* instance; // 私有静态成员变量，用于保存唯一实例
//	Singleton() {} // 私有构造函数
//
//public:
//	// 静态方法，用于获取唯一实例
//	static Singleton* getInstance() {
//		// 如果实例还没有被创建，则创建一个新实例并返回
//		if (instance == nullptr) {
//			instance = new Singleton();
//		}
//		return instance;
//	}
//
//	// 示例方法
//	void someMethod() {
//		std::cout << "Hello, I am a Singleton instance!" << std::endl;
//	}
//};
//
//// 静态成员变量初始化
//Singleton* Singleton::instance = nullptr;
//
//int main() {
//	// 获取单例实例
//	Singleton* singletonInstance1 = Singleton::getInstance();
//	Singleton* singletonInstance2 = Singleton::getInstance();
//
//	// 执行单例实例的方法
//	singletonInstance1->someMethod();
//	singletonInstance2->someMethod();
//
//	// 检查两个实例是否相同
//	if (singletonInstance1 == singletonInstance2) {
//		std::cout << "Both instances are the same." << std::endl;
//	}
//	else {
//		std::cout << "Both instances are different." << std::endl;
//	}
//
//	return 0;
//}

//仿函数
/*
#include <iostream>

// 定义一个简单的仿函数
class AddFunctor {
public:
	// 重载 () 运算符，使得对象可以被调用
	int operator()(int a, int b) const {
		return a + b;
	}
};

int main() {
	// 创建一个仿函数对象
	AddFunctor add;

	// 调用仿函数对象，类似于调用函数
	int result = add(3, 4);

	std::cout << "Result of adding 3 and 4 using functor: " << result << std::endl;

	return 0;
}

*/


//void test01()
//{
//	char a = 'a';
//	double d = static_cast<double>(a);
//}
//class Maker
//{
//
//};
//void func(int a, int b)
//{
//	Maker m;
//	throw m;
//	if (b == 0) throw 10;
//	cout << a / b << endl;
//	throw("shabi");
//}
//
//void test02()
//{
//	int a, b;
//	cin >> a >> b;
//	try
//	{
//		func(a, b);
//	}
//	catch (int)
//	{
//		cout << "接受一个int类型的异常" << endl;
//	}
//	catch (Maker)
//	{
//		cout << "抓到一个Maker" << endl;
//	}
//
//}


class Maker
{
public:
	void printMaker()
	{
		cout << "除数不能为0" << endl;
	}
};

int func(int a, int b)
{
	if (b == 0)
	{
		Maker m;
		throw m;

	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;

	try
	{
		func(a, b);

	}
	catch (int)
	{
		cout << "接收一个int类型的异常" << endl;
	}
	catch (Maker maker)
	{
		cout << "接收一个Maker类型的异常" << endl;
		maker.printMaker();
	}

}
int main()
{
	test();
	return 0;
}