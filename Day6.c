// Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
#include <stdio.h>
int main() {
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (n > 0) {
        printf("%d", a[0]);
    }
    for (i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            printf(" %d", a[i]);
        }
    }
  return 0;
}
