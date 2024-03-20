#include "func.h"
void F1()
{
	cout << "F1()" << endl;
}
// 不适用 不方便 显示实例化
template<class T>
void F2(const T& x)
{
	cout << "void F2(const T&x)" << endl;
}

