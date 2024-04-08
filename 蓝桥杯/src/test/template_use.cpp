#include "template_use.h"
#include<iostream>
#include<vector>
using namespace std;
template<>
bool compare<const char*>(const char* a, const char* b)
{
	cout << "template compare" << endl;
	return a > b;
}

template<typename T>
bool compare(T a, T b)//一个模板函数
{
	cout << "template <T>" << endl;
	return a > b;
}