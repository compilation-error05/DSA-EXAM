#include<stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;
node* createNode(int x){
    node* nn=(node*)malloc(sizeof(node));
    nn->data=x;nn->left=nn->right=NULL;
}
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int height(node*h){
    if(h==NULL){
        return 0;
    }
    int lh=height(h->left);int rh=height(h->right);
    return(1+max(rh,lh));
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
    root->left->left->right=createNode(9);

    printf("%d\n",height(root));
    
    printf("\n");

    return 0;
}
