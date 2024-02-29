#include<iostream>
using namespace std;

/*
第一行n,m
第二行n个整数
接下来m行每行包含两个整数l和r
计算公式： S[r] - s[l-1]
*/

const int N = 100010;
int n, m;
int a[N], s[N];

int main()
{
	scanf_s("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i]; //前缀和的初始化

	while (m--)
	{
		int l, r;
		scanf_s("%d%d", &l, &r);
		cout << s[r] - s[l - 1]; //区间和的计算
	}
	return 0;
}