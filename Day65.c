//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>

int adj[100][100], vis[100];
int dfs(int node, int parent, int n) {
    vis[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!vis[i]) {
                if (dfs(i, node, n)) return 1;
            } else if (i != parent) return 1;
        }
    }
    return 0;
}
int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(i, -1, n)) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}
