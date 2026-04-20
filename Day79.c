//Find shortest distances from source vertex in a weighted graph with non-negative weights.
#include <stdio.h>
#include <limits.h>

int main() {
    int n, m, u, v, w, i, j, src;
    scanf("%d %d", &n, &m);
    int cost[100][100];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cost[i][j] = INT_MAX;
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w;
    }
    scanf("%d", &src);
    int dist[100], vis[100];
    for(i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        vis[i] = 0;
    }
    dist[src] = 0;
    for(i = 1; i <= n; i++) {
        int min = INT_MAX, u;
        for(j = 1; j <= n; j++)
            if(!vis[j] && dist[j] < min)
                min = dist[j], u = j;
        vis[u] = 1;
        for(j = 1; j <= n; j++)
            if(!vis[j] && cost[u][j] != INT_MAX && dist[j] > dist[u] + cost[u][j])
                dist[j] = dist[u] + cost[u][j];
    }
    for(i = 1; i <= n; i++)
        printf("%d ", dist[i]);
    return 0;
}
