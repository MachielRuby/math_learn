include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

// 树和图的深度优先搜索代码
void dfs(int u)
{
    st[u] = true; // 标记当前点已被搜索
    
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}

int main()
{
    memset(h, -1, sizeof h);
    
    dfs(1); // 从第一个点开始搜索
    
}