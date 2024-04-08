#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10, M = N * 2;

int n, m;
int h[N], e[M], ne[M], idx;
bool st[N];

int ans = N; // 记录最大连通块点的最小值

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

// 让搜索函数返回以u为根的子树中节点数量
int dfs(int u)
{
    st[u] = true; // 标记当前点已被搜索
    
    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) 
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s; // sum记录当前节点的子树中的节点数量
        }
    }
    
    res = max(res, n - sum); // n - sum表示当前节点子树以外的连通块
    
    ans = min(res, ans);
    
    return sum;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    
    for (int i = 0; i < n - 1; i ++)
    {
        int a, b;
        cin >> a >> b;
        
        add(a, b), add(b, a);
    }
    
    dfs(1); // 从第一个点开始搜索
    
    cout << ans << endl;
    
    return 0;
}