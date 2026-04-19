//Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm
#include <stdio.h>
#define MAX 100
#define INF 9999

int main() {
    int n, m, u, v, w, i, j;
    scanf("%d %d", &n, &m);
    int cost[MAX][MAX];
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cost[i][j] = INF;
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        cost[u][v] = w;
        cost[v][u] = w;
    }
    int visited[MAX] = {0};
    visited[1] = 1;
    int mincost = 0, edges = 0;
    while(edges < n - 1) {
        int min = INF, a = -1, b = -1;
        for(i = 1; i <= n; i++) {
            if(visited[i]) {
                for(j = 1; j <= n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        visited[b] = 1;
        mincost += min;
        edges++;
    }
    printf("%d", mincost);
    return 0;
}
