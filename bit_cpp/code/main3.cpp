#include<iostream>
using namespace std;

#if 0
class Date
{
public:

	// 最实用
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d) // 传地址，不然会递归拷贝
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}



	//private:
	int _year;
	int _month;
	int _day;
};


bool operator==(const Date& d1, const Date& d2)
{
	return d1._year == d2._year;
}

bool operator>(const Date& d1, const Date& d2)
{
	return d1._year > d2._year;
}
// 自定义类型需要重载函数进行调用运算符
int main()
{
	Date d(2022, 1, 1);
	Date d1(d);

	d == d1; // -> operator==(d1,d)
	d1 > d;
	return 0;
}
#endif


class Date
{
public:

	int getMonthDay(int year, int month)
	{
		int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthDays[month];
	}
	// 普通构造函数
	Date(int year = 0, int month = 1, int day = 1) :
		_year(year),
		_month(month),
		_day(day)
	{
		if (_year < 0)_year = 0;
		if (_month < 0 || _month>12)_month = 0;
		if (getMonthDay(_year, _month) < _day) _day = 0;
	}
	Date(const Date& d)
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}

	}

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}

	bool operator<(const Date& d) const
	{
		return this->_year < d._year;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	bool operator>(const Date& d)  // d是常量函数，所以调用的需要加上const
	{
		return d < *this;
	}
	Date& operator+(int day)
	{
		this->_day += day;
		while (this->_day > getMonthDay(_year, this->_month))
		{
			_day -= getMonthDay(_year, _month);
			_month += 1;
			if (_month % 13 == 0)
			{
				_month = 1;
				_year += 1;
			}
		}
		return *this;
	}

	Date& operator-(int day)
	{

		while (this->_day < day)
		{
			this->_day += getMonthDay(_year, _month);
			_month -= 1;
			if (_month % 13 == 0)
			{
				_month = 12;
				_year -= 1;
			}
		}
		this->_day -= day;
		return *this;
	}


	~Date()
	{
		cout << "调用析构函数" << endl;
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
// 高内聚 低耦合  部分的员工之间高内聚，部门与部分低耦合
int main()
{
	Date d1(2001, 1, 1);
	d1.Print();

	d1 = d1 + 365;
	d1.Print();
	d1 = d1 - 368 - 31;
	d1.Print();
	return 0;
}