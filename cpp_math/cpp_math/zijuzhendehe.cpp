#include<iostream>
using namespace std;

const int N = 1010;
int n, m, q;
int a[N][N], s[N][N];


int main()
{
	scanf_s("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf_s("%d", &a[i][j]);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}
	//注意从1开始的
	/*
	3 3 1 三行三列 一次测试
	1 2 3
	1 2 3
	1 2 3
	2 2 3 3
	10
	*/
	while (q--)
	{
		int x1, y1, x2, y2;
		scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);
		cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];//算的是部分和
	}
	return 0;
}