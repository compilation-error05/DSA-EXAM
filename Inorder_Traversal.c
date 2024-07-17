#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

node* createNode(int x) {
    node *nn = (node*)malloc(sizeof(node));
    nn->data = x;
    nn->left = nn->right = NULL;
    return nn;
}

void inorder(node *h) {
    if (h == NULL) {
        printf("empty\n");
        return;
    }

    node* st[500];
    int top = -1;
    node* current = h;

    while (true) {
        // Traverse to the leftmost node
        while (current != NULL) {
            st[++top] = current;
            current = current->left;
        }

        // If the stack is empty, traversal is complete
        if (top == -1)
            break;

        // Pop the node from the stack and print its data
        current = st[top];top--;
        printf("%d ", current->data);

        // Move to the right child
        current = current->right;
    }
}

int main() {
    // Create a sample binary tree
    node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}
