//Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d", &n);
    int *q = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    scanf("%d", &m);
    int front = 0;
    int rear = n - 1;
    for(int i = 0; i < m; i++)
        front = (front + 1) % n;
    int i = front;
    while(i != rear)
    {
        printf("%d ", q[i]);
        i = (i + 1) % n;
    }
    printf("%d", q[rear]);
    free(q);
    return 0;
}
