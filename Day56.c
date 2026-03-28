//Problem Statement: Check whether a given binary tree is symmetric around its center.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *l,*r;
};

struct Node* newNode(int x){
    struct Node* n = malloc(sizeof(struct Node));
    n->data=x; n->l=n->r=NULL;
    return n;
}
struct Node* build(int a[], int n){
    struct Node* t[n];
    for(int i=0;i<n;i++)
        t[i]=(a[i]==-1)?NULL:newNode(a[i]);
    for(int i=0;i<n;i++)
        if(t[i]){
            if(2*i+1<n) t[i]->l=t[2*i+1];
            if(2*i+2<n) t[i]->r=t[2*i+2];
        }
    return t[0];
}
int check(struct Node* a, struct Node* b){
    if(!a && !b) return 1;
    if(!a || !b) return 0;
    return a->data==b->data && check(a->l,b->r) && check(a->r,b->l);
}
int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    struct Node* root = build(a,n);
    printf(check(root,root)?"YES":"NO");
}
