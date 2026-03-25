//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }
    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}
void vertical(struct Node* root, int hd, int map[200][200], int count[]) {
    if (!root) return;
    int index = hd + 100;
    map[index][count[index]++] = root->data;

    vertical(root->left, hd - 1, map, count);
    vertical(root->right, hd + 1, map, count);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    int map[200][200] = {0};
    int count[200] = {0};
    vertical(root, 0, map, count);
    for (int i = 0; i < 200; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }
    return 0;
}
