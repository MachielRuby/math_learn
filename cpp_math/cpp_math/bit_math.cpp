#include<iostream>
using namespace std;

/*
位运算常用两种运算
求n的k位数字:n>>k&1
返回n的最后一位1:lowbit(n) = n& -n;

*/
/*
1001
0111

0001

1000
1000

1000
*/
// lowbit函数用于返回一个整数x的二进制表示中最低位的1所代表的值
int lowbit(int x)
{
	return x & -x;
}
int main()
{
	int n;
	cin >> n; // 读取输入的整数n
	while (n--) // 循环读取n个整数
	{
		int x;
		cin >> x; // 读取一个整数x
		int res = 0;
		// 当x不为0时，不断将x减去其最低位的1，并记录次数
		while (x)
			x -= lowbit(x), res++;
		// 输出每个整数x的最低位1的个数
		cout << res << endl;
	}
	return 0;
}
