#include<iostream>
using namespace std;

class A
{
public:
	A(int a) :_a(a)
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

int main()
{
	// new malloc new开了空间+构造函数初始化 失败抛出异常
	// delete free  delete删除空间+析构函数调用 失败返回0
	//int* p = new int[3];
	A* p1 = (A*)malloc(sizeof(A));
	A* p3 = (A*)operator new (sizeof(A));
	new(p3)A(10);// new（空间指针）类型（参数）
	p3->~A();
	operator delete(p3);
	// operator new 和 malloc的区别
	size_t size = 80;
	void* p4 = malloc(size * 1024 * 1024 * 1024);
	cout << p4 << endl; //失败返回0

	try {
		void* p5 = operator new(size * 1024 * 1024 * 1024);

		cout << p5 << endl;
	}
	catch (const exception& e) { // 声明捕获异常的类型为 const 引用
		cout << e.what() << endl; // 使用异常的成员函数 what() 获取异常信息
	}

	return 0;
}