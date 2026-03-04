//Implement push and pop operations on a stack and verify stack operations.
#include <stdio.h>
#define MAX 100
int main() {
    int stack[MAX];
    int top = -1;
    int n, m, i, x;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        stack[++top] = x;
    }
    scanf("%d", &m);
    for(i = 0; i < m && top >= 0; i++) {
        top--;
    }
    for(i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    return 0;
}
