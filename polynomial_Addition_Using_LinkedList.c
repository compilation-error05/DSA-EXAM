#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int expo;
    int coff;
    struct node* next;
}node;
void createpoly(node**);
void dispoly(node*);
void addpoly(node* ,node* ,node*);
void createpoly(node** h) {
    node *nn, *link;
    int c;

    do {
        nn = (node*)malloc(sizeof(node));

        printf("Enter exponent: ");
        scanf("%d", &(nn->expo));

        printf("Enter coefficient: ");
        scanf("%d", &(nn->coff));

        nn->next = NULL;

        if (*h == NULL) {
            *h = nn;
            link = nn;
        } else {
            link->next = nn;
            link = nn;
        }

        printf("Enter 0 to discontinue: ");
        scanf("%d", &c);

    } while (c != 0);
}
void dispoly(node* h){
    node* temp;
    temp=h;
    while (temp != NULL){
        printf("X^%d %d",temp->coff,temp->expo);
        if(temp->next != NULL){
            printf(" + ");
        }
        temp=temp->next;
    }
    printf("\n");
}
void addpoly(node* h1, node* h2, node* ha) {
    node *ptr1 = h1, *ptr2 = h2, *result = ha;
    
    
    while (ptr1 != NULL && ptr2 != NULL) {
        result->next = (node*)malloc(sizeof(node));
        result = result->next;

        if (ptr1->expo > ptr2->expo) {
            result->expo = ptr1->expo;
            result->coff = ptr1->coff;
            ptr1 = ptr1->next;
        } else if (ptr1->expo < ptr2->expo) {
            result->expo = ptr2->expo;
            result->coff = ptr2->coff;
            ptr2 = ptr2->next;
        } else {
            result->expo = ptr1->expo;
            result->coff = ptr1->coff + ptr2->coff;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        result->next = NULL;
    }

    // If any list is remaining, copy the remaining terms
    while (ptr1 != NULL) {
        result->next = (node*)malloc(sizeof(node));
        result = result->next;
        result->expo = ptr1->expo;
        result->coff = ptr1->coff;
        ptr1 = ptr1->next;
        result->next = NULL;
    }

    while (ptr2 != NULL) {
        result->next = (node*)malloc(sizeof(node));
        result = result->next;
        result->expo = ptr2->expo;
        result->coff = ptr2->coff;
        ptr2 = ptr2->next;
        result->next = NULL;
    }
}
int main() {
    node *h1 = NULL;
    node *h2 = NULL;
    node *ha = NULL;

    // Create and input polynomials
    printf("Enter Polynomial 1:\n");
    createpoly(&h1);
    printf("Enter Polynomial 2:\n");
    createpoly(&h2);

    // Display the input polynomials
    printf("Polynomial 1: ");
    dispoly(h1);
    printf("Polynomial 2: ");
    dispoly(h2);

    // Allocate memory for the resultant polynomial
    ha = (node*)malloc(sizeof(node));
    ha->next = NULL;

    // Add the polynomials
    addpoly(h1, h2, ha);

    // Display the resultant polynomial
    printf("Sum of Polynomials: ");
    dispoly(ha->next); 
    // Skip the dummy head node
}
