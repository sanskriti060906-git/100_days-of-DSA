//Problem Statement:Construct a binary tree from given preorder and inorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
int preIndex = 0;
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}
int search(int in[], int start, int end, int val) {
    for(int i = start; i <= end; i++)
        if(in[i] == val)
            return i;
    return -1;
}
struct Node* build(int pre[], int in[], int start, int end) {
    if(start > end) return NULL;
    struct Node* root = newNode(pre[preIndex++]);
    if(start == end) return root;
    int pos = search(in, start, end, root->data);
    root->left = build(pre, in, start, pos - 1);
    root->right = build(pre, in, pos + 1, end);

    return root;
}
void postorder(struct Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main() {
    int n;
    scanf("%d", &n);
    int pre[n], in[n];
    for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
    struct Node* root = build(pre, in, 0, n - 1);
    postorder(root);
    return 0;
}
