#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

// 邻接表存储图模板代码
int h[N], e[M], ne[M], idx; // h存每个节点，e存每条边

// 插入新边
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void traverseGraph(int n)
{
	for (int i = 1; i <= n; ++i) {
		cout << "顶点 " << i << " 的邻接顶点：";
		for (int j = h[i]; j != -1; j = ne[j]) {
			cout << e[j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	memset(h, -1, sizeof h);
	add(1, 2);
	add(2, 3);
	add(4, 2);
	traverseGraph(4);

}