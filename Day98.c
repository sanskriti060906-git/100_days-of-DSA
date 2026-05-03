//Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.
  #include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return x[0] - y[0];
}

int main() {
    int intervals[][2] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = 4;

    qsort(intervals, n, sizeof(intervals[0]), cmp);
    int res[10][2];
    int k = 0;
    res[0][0] = intervals[0][0];
    res[0][1] = intervals[0][1];
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= res[k][1]) {
            if (intervals[i][1] > res[k][1])
                res[k][1] = intervals[i][1];
        } else {
            k++;
            res[k][0] = intervals[i][0];
            res[k][1] = intervals[i][1];
        }
    }
    printf("Merged intervals:\n");
    for (int i = 0; i <= k; i++) {
        printf("[%d, %d] ", res[i][0], res[i][1]);
    }

    return 0;
}
