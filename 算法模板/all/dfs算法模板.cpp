bool st[N];         // 标记是否用过
int h[N], ne[N];

int dfs(int u)
{
    if (...) {...; return;}     // 输出结果，记得加return语句（或者后边部分用else括起）

    st[u] = true;       // st[u] 表示点u已经被遍历过

    for (int p = h[u]; p != -1; p = ne[p])
    {
        int v = e[p];
        if (!st[v]) dfs(v);
    }

    st[u] = false;      // 恢复现场
}
