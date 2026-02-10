// Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

int main() {
    int n, k, i;
    int count = 0, found = 0;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    for(i = 0; i < n;i++) {
        count++; 
        if(a[i] == k) {
            found = 1;
            break;
        }
    }
    if(found == 1)
        printf("Key found\n");
    else
        printf("Key not found\n");
    printf("Comparisons = %d", count);

    return 0;
}
