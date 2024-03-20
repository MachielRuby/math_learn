#include<iostream>
using namespace std;
#include<vector>
//#include<queue>
#include "priority_queue.h"
#include<functional>
using Gan_priority_queue::priority_queue;
void testPriorityQueue()
{
	vector<int>v{ 3,2,8,4,3,4,6,1,3 };
	priority_queue<int>q1;
	for (auto& e : v)
	{
		q1.push(e);
	}
	cout << q1.top() << endl;
	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
	cout << q2.top() << endl;

}


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year),
		_month(month),
		_day(day)
	{

	}

	bool operator<(const Date& d)const
	{
		return _year < d._year;
	}
	bool operator>(const Date& d)const
	{
		return _year > d._year;
	}

	friend ostream& operator<<(ostream& _cout, const Date& d)
	{
		_cout << d._year;
		return _cout;
	}

private:
	int _year;
	int _month;
	int _day;
};

void test01()
{
	priority_queue<Date>d1;
	d1.push(Date(2021));
	d1.push(Date(2022));
	cout << d1.top() << endl;
	priority_queue < Date, vector<Date>, greater<Date>>q2;
	q2.push(Date(2021));
	q2.push(Date(2022));
	cout << q2.top() << endl;
}
int main()
{
	//testPriorityQueue();
	test01();
	return 0;
}