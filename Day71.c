
#include <stdio.h>
#include <string.h>

int table[100];
int size;
void insert(int key) {
    int h = key % size;
    for (int i = 0; i < size; i++) {
        int idx = (h + i*i) % size;
        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
    }
}
void search(int key) {
    int h = key % size;
    for (int i = 0; i < size; i++) {
        int idx = (h + i*i) % size;
        if (table[idx] == -1) {
            printf("NOT FOUND\n");
            return;
        }
        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }
    }
    printf("NOT FOUND\n");
}
int main() {
    int q, x;
    char op[10];
    scanf("%d", &size);
    scanf("%d", &q);
    for (int i = 0; i < size; i++)
        table[i] = -1;
    while (q--) {
        scanf("%s %d", op, &x);
        if (strcmp(op, "INSERT") == 0)
            insert(x);
        else if (strcmp(op, "SEARCH") == 0)
            search(x);
    }
    return 0;
}
