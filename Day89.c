//Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.
#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > maxPages) return 0;
        if(sum + arr[i] <= maxPages) {
            sum += arr[i];
        } else {
            students++;
            sum = arr[i];
        }
    }
    return students <= m;
}
int allocateBooks(int arr[], int n, int m) {
    if(m > n) return -1;
    int max = arr[0], sum = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        sum += arr[i];
    }
    int low = max, high = sum, ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n = 4, m = 2;
    int arr[] = {12, 34, 67, 90};
    printf("%d\n", allocateBooks(arr, n, m)); // Output: 113
    return 0;
}
