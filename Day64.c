//Problem: Perform BFS from a given source using queue.

#include <stdio.h>

int queue[100], front = -1, rear = -1;
void enqueue(int x) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}
int dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front > rear;
}
int main() {
    int n;
    scanf("%d", &n);
    int adj[100][100];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    int s;
    scanf("%d", &s);
    int visited[100] = {0};
    enqueue(s);
    visited[s] = 1;
    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        for(int i = 0; i < n; i++) {
            if(adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    return 0;
}
