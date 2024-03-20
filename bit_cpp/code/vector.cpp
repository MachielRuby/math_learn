#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

//加入算法的回调函数
void Print(int val)
{
	cout << val << " ";
}
void test01()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	for (auto e : v)
	{
		cout << e << " ";
	}

	vector<int>::iterator begin = v.begin();
	vector<int>::iterator end = v.end();
	cout << endl;
	for_each(begin, end, Print);

	vector<vector<int>> v1;
}

int main()
{
	test01();
	return 0;
}