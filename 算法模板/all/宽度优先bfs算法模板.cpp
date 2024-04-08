queue<int> q;
st[1] = true; // 表示1号点已经被遍历过
q.push(1);

while (q.size())
{
    int u = q.front();
    q.pop();

    for (int p = h[u]; p != -1; p = ne[p])
    {
        int v = e[p];
        if (!st[v])
        {
            st[v] = true; // 表示点j已经被遍历过
            q.push(v);
        }
    }