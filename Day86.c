// Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid * mid == n) {
            printf("%d", mid);
            return 0;
        }
        else if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}
