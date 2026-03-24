//Problem Statement:Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
struct Node* build(int a[], int n){
    if(n==0 || a[0]==-1) return NULL;
    struct Node** q = malloc(n*sizeof(struct Node*));
    int f=0,r=0,i=1;
    struct Node* root = newNode(a[0]);
    q[r++] = root;
    while(i<n){
        struct Node* cur = q[f++];
        if(i<n && a[i]!=-1){
            cur->left = newNode(a[i]);
            q[r++] = cur->left;
        }
        i++;
        if(i<n && a[i]!=-1){
            cur->right = newNode(a[i]);
            q[r++] = cur->right;
        }
        i++;
    }
    return root;
}
struct Node* lca(struct Node* root, int x, int y){
    if(!root) return NULL;
    if(root->data==x || root->data==y) return root;
    struct Node* l = lca(root->left,x,y);
    struct Node* r = lca(root->right,x,y);
    if(l && r) return root;
    return l ? l : r;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int x,y;
    scanf("%d %d",&x,&y);
    struct Node* root = build(a,n);
    struct Node* ans = lca(root,x,y);
    if(ans) printf("%d",ans->data);
    return 0;
}
