#include<iostream>
using namespace std;


//
//class Date
//{
//public:
//	explicit Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print() const// ->void Print(const Date*this);
//	{
//		cout << this->_year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//Date d1 = { 1,2,3 }; 加上explicit就限制了不准隐式转换
//	//d1.Print();
//	return 0;
//}


class Count
{
public:
	Count()
	{
		n++;
	}
	Count(const Count& d)
	{
		n++;
	}
	static int getn()
	{
		return n;
	}
private:
	static int n;
	int n1;
};
int Count::n = 0;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			Count d1;
		}
	}
	cout << Count::getn() << endl;
	return 0;
}