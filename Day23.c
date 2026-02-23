//Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
struct Node* insert(struct Node* head, int data) {
    if (!head) return newNode(data);
    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = newNode(data);
    return head;
}
struct Node* merge(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}
void print(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() {
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        l1 = insert(l1, x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        l2 = insert(l2, x);
    }
    struct Node* result = merge(l1, l2);
    print(result);
    return 0;
}
