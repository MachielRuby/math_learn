#include<iostream>
using namespace std;

//const int N = 1000010;
//int n, m;
//int a[N], b[N];
//
//// 实现差分数组的插入操作，对 b 数组进行区间增加操作
//void insert(int l, int r, int c)
//{
//	// 在区间 [l, r] 上增加 c
//	b[l] += c;
//	// 在区间 [r+1, n] 上减去 c，用于后续计算前缀和时进行补偿
//	b[r + 1] -= c;
//}
//
//int main()
//{
//	// 输入数组长度和操作次数
//	scanf_s("%d%d", &n, &m);
//
//	// 输入数组的值
//	for (int i = 1; i <= n; i++)
//		scanf_s("%d", &a[i]);
//
//	// 利用差分数组插入操作，构建差分数组 b，初始情况下 b 数组等于原数组 a
//	for (int i = 1; i <= n; i++)
//		insert(i, i, a[i]);
//
//	// 循环执行 m 次操作
//	while (m--)
//	{
//		int l, r, c;
//		scanf_s("%d%d%d", &l, &r, &c);
//		// 对数组 b 进行区间增加操作
//		insert(l, r, c);
//	}
//
//	// 计算差分数组的前缀和，得到最终结果数组
//	for (int i = 1; i <= n; i++)
//		b[i] += b[i - 1];
//
//	// 输出最终结果数组
//	for (int i = 1; i <= n; i++)
//		cout << b[i];
//
//	return 0;
//}
/*
5 1
1 2 3 4 5
1 2 3
45345
*/

const int N = 1010;
int n, q, m;
int a[N][N], b[N][N];

void insert(int x1, int y1, int x2, int y2, int c)
{
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}

int main()
{
	scanf_s("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			insert(i, j, i, j, a[i][j]);
		}
	}
	while (q--)
	{
		int x1, x2, y1, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			b[i][j] += b[i][j - 1] + b[i - 1][j] - b[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)cout << b[i][j];
		puts(" ");
	}
	return 0;
}
/*
3 3 1
1 2 3
1 2 3
1 2 3
1 1 2 2 5
673
673
123
*/