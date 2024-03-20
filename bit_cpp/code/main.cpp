#include<iostream>
using namespace std;
#include<map>
// c11 新特性
void test1()
{
	cout << R"(\t000w00w)" << endl;// 字面量
	cout << "Wcoa" << endl;
}
void func(int p)
{
	cout << p << endl;
}
void func(int* p)
{
	cout << p << endl;
}
//初始化空指针 建议用nullptr
void test2()
{
	int* prt = NULL;
	int* prt1 = nullptr; //建议使用 限制隐式转换 NULL在c++中和0没什么区别
	func(prt);
	func(prt1);
}

// const constexpr
struct T
{
	int a;
};

//修饰函数  必须有返回值 必须返回常量表达式
constexpr void func1()
{
	//定义必须放在main函数前面，不然是错的，因为开始就调用了
	//整个函数体中，不能出现非常量表达式的语句(using typedef static_assert return)
}
void test03()
{
	// 表达式只读 const
	//表达式常量 constexpr 效率高
	//对于自定义的类型直接使用constexpr不可以
	//constexpr struct Test 无效的
	//{
	//	int id;
	//	int name;
	//}；
	constexpr T t{ 100 }; //11之后可以{}初始化
	//t.a = 10;

}

//定义函数模板
template<typename T> //如果不满足常量表达式函数的要求，constexpr会自动被忽略
constexpr T displat(T t)
{
	return t;
}

//auto 推出变量的类型 迭代器的时候我老用
/*
1、不能作为形参
2、不能用于类内的非静态成员的初始化
3、不能使用auto关键字定义数组
4、无法使用auto推导出模板参数
Test<auto> t1;errno
*/
void test04()
{
	int temp = 250;
	const auto a1 = temp;
	auto a2 = a1; // int 没有引用或者指针
	const auto& a3 = temp; //是引用
	auto& a4 = a3;
}

void test05()
{
	map<int, string> mp;
	mp.insert(make_pair(1, "ace"));
	mp.insert(make_pair(2, "sabo"));
	mp.insert(make_pair(3, "luffy"));
	//map<int, string>::iterator it = mp.begin();
	auto it = mp.begin();
	for (; it != mp.end(); ++it)
	{
		cout << "key: " << it->first << ", value: " << it->second << endl;
	}
}

// decltype(表达式)
void test061()
{
	int a = 10;
	decltype (a) b = 99;
	decltype(a + 5.45) c = 100;

	int x = 99;
	const int& y = x;
	// y: const int &
	//b: const int &
	//decltype(y) b = x; 

	// a:int 
	//decltype(obj.num) a = 0;
	// b:int &
	//decltype((ob32j.num)) b = a;
}

// 返回值类型后置
//R 返回值 T 参数  U 参数
//template<typename R, typename T, typename U>
//R add(T t, U u)
//{
//	return t + u;
//}
//
//void  test06()
//{
//	int x = 520;
//	double y = 13.14;
//	auto ret = add<decltype(x + y), int, double>(x, y);
//	cout << "Ret: " << ret << endl;
//}
// 正确
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u)
{
	return t + u;
}

void test06()
{
	int x = 520;
	double y = 13.14;
	auto ret = add(x, y);
	cout << "Ret: " << ret << endl;
}


// final 修饰虚函数 写道函数的后面
// override可以重写
// 基类
class Base {
public:
	// 虚函数，可以在派生类中重写
	virtual void print() const {
		std::cout << "Base::print() called" << std::endl;
	}

	// 虚函数，被标记为 final，不能在派生类中重写
	virtual void finalize() const final {
		std::cout << "Base::finalize() called" << std::endl;
	}
};

// 派生类
class Derived : public Base {
public:
	// 重写基类的虚函数
	void print() const override {
		std::cout << "Derived::print() called" << std::endl;
	}
	// 虚函数，尝试重写被标记为 final 的函数，会导致编译错误
	/*void finalize() const override {
		std::cout << "Derived::finalize() called" << std::endl;
	}*/
};

void test07() {
	Base baseObj;
	baseObj.print(); // 输出 Base::print() called
	baseObj.finalize(); // 输出 Base::finalize() called

	Derived derivedObj;
	derivedObj.print(); // 输出 Base::print() called，派生类未重写虚函数
	// derivedObj.finalize(); // 尝试调用被标记为 final 的函数，会导致编译错误
}


//函数模板增加参数
//template <typename T=int> 先使用固定的然后自动推导

//定义别名 typedef 创建空间 using

int mytest(int a, string b)
{
	cout << "a : " << a << ", b: " << b << endl;
	return 0;
}

//typedef int(*func) (int, string);
//using func1 = int(*)(int, string);
//
//void test09()
//{
//	func f = mytest;
//	func1 f1 = mytest;
//	f(10, "shabi");
//	f1(19, "wocao");
//}


//委托构造函数 一个类中构造函数调用其他的构造函数
class Person {
private:
	std::string name;
	int age;

public:
	// 委托构造函数1
	Person() : Person("", 0) {}

	// 委托构造函数2
	Person(const std::string& name) : Person(name, 0) {}

	// 主要构造函数
	Person(const std::string& name, int age) : name(name), age(age) {}

	void display() const {
		std::cout << "Name: " << name << ", Age: " << age << std::endl;
	}
};

//初始化统一
void test10()
{
	int array[] = { 1,2,3 };
	struct Person
	{
		int id;
		double salary;

	}zhangsan3{ 1,3000 };
	//静态成员不能在初始化列表直接初始化 c14之后支持
}

// initializer_list模板使用
void func11(initializer_list<int>ls)
{
	auto it = ls.begin();
	for (; it != ls.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (const auto& e : ls) //不能修改引用的值
	{
		cout << *it << " ";

	}
}


//可调用对象包装器、绑定器
/*
1、是一个函数指针
2、是一个具有operator（）成员函数的类对象（仿函数）
3、是一个可被转换为函数指针的对象
4、是一个类成员函数指针或者类成员指针
#include<functional>可以去查查怎么使用
包装普通函数
包装类的静态函数
包装仿函数
*/


int main()
{
	//test07();
	func11({ 3,4,55,34,3,45,5 });
	return 0;
}
