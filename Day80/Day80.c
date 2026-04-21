// Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.
#include <stdio.h>

int main() {
    int n, i, j, k;
    scanf("%d", &n);
    int dist[n][n];
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
            if(dist[i][j] == -1 && i != j)
                dist[i][j] = 1000000000;
        }
    }
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(dist[i][j] == 1000000000)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
