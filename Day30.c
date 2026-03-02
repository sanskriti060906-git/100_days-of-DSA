// Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int c,e;
    struct node* next;
}node;
int main(){
    int n,c,e;
    scanf("%d",&n);
    node *head=NULL,*temp,*newnode;
    for(int i=0;i<n;i++){
        scanf("%d%d",&c,&e);
        newnode=(node*)malloc(sizeof(node));
        newnode->c=c;
        newnode->e=e;
        newnode->next=NULL;
        if(head==NULL) head=newnode;
        else{
            temp=head;
            while(temp->next) temp=temp->next;
            temp->next=newnode;
        }
    }
    temp=head;
    while(temp){
        if(temp->e==0) printf("%d",temp->c);
        else if(temp->e==1) printf("%dx",temp->c);
        else printf("%dx^%d",temp->c,temp->e);
        if(temp->next) printf(" + ");
        temp=temp->next;
    }
}
