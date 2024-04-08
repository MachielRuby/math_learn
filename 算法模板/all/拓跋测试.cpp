#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N]; // d记录每个点的入度

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool topsort()
{
    int hh = 0, tt = -1;
    
    // 初始化队列，将所有入度为0的节点加入队列
    for (int i = 1; i <= n; i ++)
        if (!d[i])
            q[++ tt] = i;
    
    // 进行拓扑排序
    while (hh <= tt)
    {
        int t = q[hh ++]; // 出队列
        
        // 遍历节点 t 的邻接节点
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j] --; // 更新邻接节点 j 的入度
            if (d[j] == 0) q[++ tt] = j; // 若入度为0，则加入队列
        }
    }
    
    return tt == n - 1; // 判断是否图中所有点都入队，若是，则代表图为拓扑图，有拓扑序
}

int main()
{
    cin >> n >> m; // 输入节点数和边数
    
    memset(h, -1, sizeof h); // 初始化邻接表
    
    // 构建图，并统计每个节点的入度
    for (int i = 0; i < m; i ++)
    {
        int a, b;
        cin >> a >> b; // 输入边的起始节点和目标节点
        add(a, b); // 添加边到邻接表
        d[b] ++; // 更新目标节点的入度
    }
    
    if (topsort()) // 判断是否存在拓扑序
    {
        // 输出拓扑序
        for (int i = 0; i < n; i ++) printf("%d ", q[i]);
    }
    else puts("-1"); // 不存在拓扑序，输出-1
    
    return 0;
}

输入样例

3 3
1 2
2 3
1 3
输出样例

1 2 3

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出-1
。
