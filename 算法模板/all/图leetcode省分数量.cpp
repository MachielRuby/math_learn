class Solution {
public:
    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        memset(h,-1,sizeof h);
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    add(i, j);  // 修改此处
                }
            }
        }

        int provinces = 0;
        vector<bool> visited(n, false);  // 修改此处

        for (int i = 0; i < n; i++) {  // 修改此处
            if (!visited[i]) {
                dfs(i, visited);
                provinces++;
            }
        }

        return provinces;
    }

    void dfs(int u, vector<bool>& visited) {
        visited[u] = true;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int v = e[i];
            if (!visited[v]) {
                dfs(v, visited);
            }
        }
    }

private:
    int h[200];
    int ne[40000];
    int e[40000];
    int idx = 0;
};
