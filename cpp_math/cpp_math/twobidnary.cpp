#include<iostream>
using namespace std;
/*
输入两个n,m 分别代表数组长度和次数
然后输入一个数组
然后输入查询数字
注意数组是有序的
结束会打印查询数字的区域范围

5 2
1 2 3 4 4
1
0 0
4
3 4

*/
//const int N = 100000;
//int n, m;
//int q[N];
//
//
//int main()
//{
//	scanf_s("%d %d", &n, &m);
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &q[i]);
//	}
//
//	while (m--)
//	{
//		int x;
//		scanf_s("%d", &x);
//		int l = 0, r = n - 1;
//		while (l < r)
//		{
//			int mid = l + r >> 1;
//			if (q[mid] >= x)r = mid;
//			else l = mid + 1;
//		}
//
//		if (q[l] != x) cout << "-1 -1 " << endl;
//		else
//		{
//			cout << l << " ";
//
//			int l = 0, r = n - 1;
//			while (l < r)
//			{
//				int mid = l + r + 1 >> 1;
//				if (q[mid] <= x)l = mid;
//				else r = mid - 1;
//			}
//			cout << l << endl;
//		}
//	}
//	return 0;
//}

// 正的浮点数求平方根

int main()
{
	double x;
	cin >> x;
	double l = 0, r = x;
	while (r - l > 1e-6)
	{
		double mid = (l + r) / 2;
		if (mid * mid >= x)r = mid;
		else l = mid;

	}

	printf("%lf\n", l);
	return 0;
}