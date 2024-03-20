#include<iostream>
using namespace std;

//#define N 100
// 非类型参数
template<class T, int N>
class Array
{

private:
	T _a[N];
};


//template<class T, string double  N>
//浮点数、类对象以及字符串不能作为非类型模板参数


//特化
template<class T>
bool IsEqual(T& left, T& right)
{
	return left == right;
}
template<>
bool IsEqual<const char* const>(const char* const& left, const char* const& right)
{
	if (strcmp(left, right) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//偏特化
//template<class T1,class T2>
//template<class T1,int>
///分离编译 
/*普通函数可以，类模板不行*/

int main()
{
	Array<int, 100>a1;
	Array<int, 1000>a2;
	return 0;
}