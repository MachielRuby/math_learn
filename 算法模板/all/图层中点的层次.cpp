接下来行，每行包含两个整数和，表示存在一条从走到的长度为的边。
输出格式
输出一个整数，表示点到点的最短距离。

#include<iostream>
using namespace std;
#include<algorithm>
#include<cstring>

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N], q[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}

int bfs()
{
	int hh = 0, tt = 0;
	q[0] = 1;
	memset(d, -1, sizeof d);

	d[1] = 0;
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (d[j] == -1)
			{
				d[j] = d[t] + 1;
				q[++tt] = j;
			}
		}
	}
	return d[n];
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	cout << bfs() << endl;
	return 0;
}

4 5
1 2
2 3
3 4
1 3
1 4
1