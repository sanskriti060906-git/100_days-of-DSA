//Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int a = arr[0], b = arr[1];
    int min = abs(a + b);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if(abs(sum) < min) {
                min = abs(sum);
                a = arr[i];
                b = arr[j];
            }
        }
    }
    printf("%d %d", a, b);
    return 0;
}
