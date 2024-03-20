#include<iostream>
using namespace std;

class Stack
{
	//成员函数
	//成员变量
	void Push(int x);


private:
	int* _a;
	int _size;
	int _capacity;
};

struct ListNode_c
{
	int val;
	struct ListNode_c* _next;
	struct ListNode_c* _prev;
};

struct ListNode_cpp
{
	int val;
	ListNode_cpp* _next;
	struct ListNode_cpp* _prev;
	// 还可以定义成员函数
};

void Stack::Push(int x)
{

}

// 内存对齐
class A
{
	void push();
private:
	int _a;
	char _c;
};

//int main()
//{
//	Stack s1; //实例化对象
//	cout << sizeof(A) << endl;
//	return 0;
//}

class Time
{
public:
	Time(int hour, int minute, int second)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}
private:
	int _hour;
	int _second;
	int _minute;

};
class Date
{
public:

	Date()
	{

	}
	// 普通构造函数
	Date(int year, int month, int day) :
		_year(year),
		_month(month),
		_day(day)
	{}
	~Date()
	{
		cout << "调用析构函数" << endl;
	}

	void Init(int year, int month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;
	}

	void Print() //void Print(Date *this)
	{
		cout << this->_year << "-" << _month << "-" << _day << endl;
	}
	// 隐含的this指针 在栈上，因为它是一个形参
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Init(2020, 4, 7);
	d1.Print();
	return 0;
}