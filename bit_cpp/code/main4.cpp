#include<iostream>
using namespace std;


class Date
{
	friend void f(Date& d);//友元函数
public:
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	// 必须friend不然汇报错误
	/*friend ostream& operator<<(ostream& out, const Date& d)
	{
		out << d._year << "-" << d._month << "-" << d._day;
		return out;
	}*/
	ostream& operator<<(ostream& out)
	{
		out << _year;
		return out;
	}
	friend istream& operator>>(istream& in, Date& d)
	{
		in >> d._year >> d._month >> d._day;
		return in;
	}
private:
	int _year = 0;
	int _month = 1;
	int _day = 1;
};

void f(Date& d)
{
	d._year = 10;
	cout << d._year << endl;
}

int main()
{
	Date d1;
	d1 << cout;
	return 0;
}