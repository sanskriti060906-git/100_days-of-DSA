//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = 8;
    int sum = 0, max_len = 0;
    int hash[1000];
    for(int i = 0; i < 1000; i++)
        hash[i] = -1;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(sum == 0)
            max_len = i + 1;
        if(hash[sum + 500] != -1) {
            int len = i - hash[sum + 500];
            if(len > max_len)
                max_len = len;
        } else {
            hash[sum + 500] = i;
        }
    }
    printf("%d", max_len);
    return 0;
}
