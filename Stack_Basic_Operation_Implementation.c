#include<stdio.h>
#define n 5;
int st[5];int top=-1;
void push(int arr[],int e){
    if(top==-1){
        top++;
        arr[top]=e;
    }
    else if(top==5-1){
        printf("Stack is full\n");
    }
    else{
        top++;
        arr[top]=e;
    }
}
void pop(int arr[]){
    if(top==-1){
        printf("\nStack is empty\n");
    }
    else{
        printf("Poped element is::%d\n",arr[top]);
        top--;
    }
}
void top_element(int arr[]){
    if(top==-1){
        printf("empty\n");
    }
    else{
        printf("top element is:: %d\n",arr[top]);
    }
}

int main(){
    push(st,5);
    pop(st);
    top_element(st);
    push(st,5);
    push(st,100);
    push(st,3);
    pop(st);

}
