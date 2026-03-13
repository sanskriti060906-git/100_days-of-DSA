// Implement a Queue using a linked list supporting enqueue and dequeue operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(front == NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}
int dequeue(){
    if(front == NULL)
        return -1;
    struct Node* temp = front;
    int val = temp->data;
    front = front->next;
    if(front == NULL)
        rear = NULL;
    free(temp);
    return val;
}
int main(){
    int n, x;
    char op[10];
    scanf("%d",&n);
    while(n--){
        scanf("%s",op);
        if(strcmp(op,"enqueue")==0){
            scanf("%d",&x);
            enqueue(x);
        }
        else if(strcmp(op,"dequeue")==0){
            printf("%d\n",dequeue());
        }
    }
    return 0;
}
