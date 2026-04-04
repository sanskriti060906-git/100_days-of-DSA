//Problem: Perform DFS starting from a given source vertex using recursion.
#include <stdio.h>

int adj[100][100], vis[100], n;
void dfs(int u) {
    vis[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < n; v++)
        if (adj[u][v] && !vis[v])
            dfs(v);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            adj[i][x] = 1;
        }
    }
    int s;
    scanf("%d", &s);
    dfs(s);
    return 0;
}
