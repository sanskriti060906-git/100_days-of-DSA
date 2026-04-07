//Problem: Detect cycle in directed graph using DFS and recursion stack.
#include <stdio.h>

int vis[100], rec[100];
int dfs(int v, int adj[100][100], int n) {
    vis[v] = 1;
    rec[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!vis[i] && dfs(i, adj, n)) return 1;
            else if (rec[i]) return 1;
        }
    }
    rec[v] = 0;
    return 0;
}
int main() {
    int n = 4;
    int adj[100][100] = {
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
        {0,1,0,0}
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(i, adj, n)) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
