//Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).
  #include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;
void merge(Pair* arr, int left, int mid, int right, int* count) {
    int i = left, j = mid + 1, k = 0;
    Pair temp[right - left + 1];
    int rightCount = 0;
    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}
void mergeSort(Pair* arr, int left, int right, int* count) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);
    merge(arr, left, mid, right, count);
}
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    Pair* arr = (Pair*)malloc(sizeof(Pair) * numsSize);
    int* count = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }
    mergeSort(arr, 0, numsSize - 1, count);
    *returnSize = numsSize;
    free(arr);
    return count;
}                                                                                               
