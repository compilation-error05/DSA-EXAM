#include<stdio.h>
#define n 2
int arr[2];
int front=-1,rear=-1;
void enqueue(int arr[],int e){
    if(rear==-1 && front==-1){
        front=rear=0;
        arr[rear]=e;
    }
    else if(((rear+1)%n)==front){
        printf("\nFULL\n");
    }
    else{
        rear=(rear+1)%n;
        arr[rear]=e;
    }
}
void dequeue(int arr[]){
    if(front ==-1 && rear==-1){
        printf("Empty\n");
    }else if(front==rear){
        printf("Dequed element is ::%d\n",arr[front]);
        front=rear=-1;
    }else{
        printf("Dequed elemnt is ::%d\n",arr[front]);
        front=(front+1)%n;
    }
}
int main(){
    enqueue(arr,22);
    enqueue(arr,10);
    enqueue(arr,11);
    dequeue(arr);
    dequeue(arr);
    dequeue(arr);
}
