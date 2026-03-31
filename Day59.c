//Problem Statement:Construct a binary tree from given inorder and postorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
int postIndex;

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}
int find(int in[], int start, int end, int val) {
    for(int i = start; i <= end; i++)
        if(in[i] == val)
            return i;
    return -1;
}
struct Node* build(int in[], int post[], int start, int end) {
    if(start > end) return NULL;
    struct Node* root = newNode(post[postIndex--]);
    if(start == end) return root;
    int pos = find(in, start, end, root->data);
    root->right = build(in, post, pos + 1, end);
    root->left  = build(in, post, start, pos - 1);
    return root;
}
void preorder(struct Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int n;
    scanf("%d", &n);
    int inorder[n], postorder[n];
    for(int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for(int i = 0; i < n; i++) scanf("%d", &postorder[i]);
    postIndex = n - 1;
    struct Node* root = build(inorder, postorder, 0, n - 1);
    preorder(root);
    return 0;
}
