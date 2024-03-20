#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<deque>

void test01()
{
	string s1;
	string s2(10, 's');
	string s3(s2);
	string s4("hello");
}

void printDeque(const deque<int>& deq)
{
	for (auto e : deq)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test02()
{
	//deque<int>::iterator it;
	//it++;

	int arr[] = { 1,3,5,7,8 };
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(int));
	printDeque(d1);
}
int main()
{
	test02();
	return 0;
}