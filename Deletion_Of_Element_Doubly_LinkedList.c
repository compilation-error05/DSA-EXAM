#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;
void delbeg(node**);
void delend(node**);
void delpos(node**,int pos);
void delbeg(node **h){
    if(*h==NULL){
        printf("list is empty\n");
    }else{
        node* temp=h;
        *h=(*h)->next;
        (*h)->prev=NULL;
        free(temp);
    }
}
void delend(node **h){
    if(*h==NULL){
        printf("List is empty\n");
    }else{
        node* temp=*h;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        node* t=temp;
        temp=temp->prev;
        temp->next=NULL;
        free(t);
    }
}
void delpos(node **h,int pos){
    if(*h==NULL){
        printf("List is empty\n");
    }else if(pos<0){
        printf("Not possible\n");
    }else{
        node *temp = *h;
        int i = 1;
        while (i < pos && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Invalid position\n");
        } else if (temp->next == NULL) {
            delend(h);
        } else if (temp->prev == NULL) {
            delbeg(h);
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
}
void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    
}

    
