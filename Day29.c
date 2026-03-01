#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* rotateRight(struct Node* head, int n, int k) {
    if (head == NULL || k == 0)
        return head;
    k = k % n;
    if (k == 0)
        return head;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head;
    int steps = n - k;
    temp = head;
    for (int i = 1; i < steps; i++)
        temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;
}
int main() {
    int n, k, x;
    scanf("%d", &n);
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct Node* newNode = createNode(x);
        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    scanf("%d", &k);
    head = rotateRight(head, n, k);
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    return 0;
}
