//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#define MAX 100

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        indegree[v]++;
    }
    int queue[MAX], front = 0, rear = 0;
    for(int i = 0; i < V; i++)
        if(indegree[i] == 0)
            queue[rear++] = i;
    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for(int i = 0; i < V; i++) {
            if(graph[node][i]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }
    return 0;
}
