//Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n, key, x;
    struct Node *head = NULL, *temp = NULL, *newNode, *prev;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;
        if(head == NULL)
            head = newNode;
        else {
            temp = head;
            while(temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    scanf("%d", &key);
    temp = head;
    prev = NULL;
    while(temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp) {
        if(prev == NULL)
            head = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }
    temp = head;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}
