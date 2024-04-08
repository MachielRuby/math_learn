#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 510;

int n, m; //稠密图 邻接矩阵
int g[N][N];
int dist[N]; //记录七点到其他点的最短距离
bool st[N]; //记录某个点的最短路有无确定

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist); // 将距离数组初始化为最大值，表示未探索过的距离为无穷大
	dist[1] = 0; // 起始节点到自身距离为0

	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j; // 选择未探索过且距离最小的点作为当前节点
		}
		st[t] = true; // 将当前节点标记为已探索

		for (int j = 1; j <= n; j++)
		{
			dist[j] = min(dist[j], dist[t] + g[t][j]);
			// 更新起始节点到其他节点的距离，选择当前节点经过的路径距离更短的情况
		}
		if (dist[n] == 0x3f3f3f)return -1; // 判断是否无法到达目标节点
	}
	return dist[n]; // 返回起始节点到目标节点的最短距离

}

int main()
{
	cin >> n >> m;

	memset(g, 0x3f, sizeof g);

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);
	}

	int  t = dijkstra();

	printf("%d\n", t);

	return 0;
}