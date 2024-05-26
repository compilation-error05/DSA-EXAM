#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void create(node**);
void display(node*);
node* oddeven(node*);

int main() {
    node* h1 = NULL;
    printf("Create a linked list\n");
    create(&h1);
    printf("BEFORE\n");
    display(h1);
    node* h2 = oddeven(h1);
    printf("\nAFTER\n");
    display(h2);
}
void create(node** head) {
    node* nn, * link;
    int c; 
    do {
        nn = (node*)malloc(sizeof(node));
        printf("enter the data: ");
        scanf("%d", &nn->data); // Corrected the format specifier

        nn->next = NULL;
        if (*head == NULL) {
            *head = nn;
            link = nn;
        } else {
            link->next = nn;
            link = nn;
        }
        printf("Enter '0' to discontinue: ");
        scanf(" %d", &c); 
    } while (c != 0); 
}

void display(node* head) {
    if (head == NULL)
        printf("NULL\n");
    node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
node* oddeven(node* head){
    if (head == NULL || head->next == NULL || head->next->next == NULL)return head;

    node* odd=head;//points to 1,3,5... odd elements
    node* even=head->next;//points to the even elements
    node* joineven=even;
    while(even !=NULL && even->next!=NULL)//as even is always moves earlier than odd so we can just use even 
    {
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=joineven;//CREATES THE LINK B/W THE ODD PAIRS AND EVEN PAIRS
    return head;
}
//https://www.prepbytes.com/blog/cpp-programming/infix-to-postfix-conversion-using-stack-in-cpp/
