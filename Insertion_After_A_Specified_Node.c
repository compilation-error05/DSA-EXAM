#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

void create(node** h,int val){
    node *nn=(node*)malloc(sizeof(node));nn->next=NULL;nn->data=val;
    if((*h)==NULL){
        *h=nn;
    }else{
        node *temp=*h;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    }
}
void print(node*h){
     node *temp=h;
        while (temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }

}
void insert(node **h, int val, int ele) {
    node *nn = (node *)malloc(sizeof(node));
    nn->data = val;
    nn->next = NULL;
    int flag = 0;

    if (*h == NULL) {
        *h = nn;
    } else {
        node *temp = *h;
        while (temp != NULL) {
            if (temp->data == ele) {
                nn->next = temp->next;
                temp->next = nn;
                flag = 1;
                break; // No need to continue searching once found
            }
            temp = temp->next;
        }
        if (flag == 0)
            printf("No element found\n");
    }
}
int main(){
    node* head=NULL;
    for(int i=0;i<7;i++){
        int n;
        scanf("%d",&n);
        create(&head,n);
    }
    print(head);
    insert(&head,9,17);printf("NEW\n");
    print(head);
}