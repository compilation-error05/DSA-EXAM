#include<stdio.h>
#define max 5
int s1[max];int s2[max];
int t1=-1;int t2=-1;int count=0;
void push1(int x){
    if(t1==-1){
        t1=0;
        s1[t1]=x;
    }else if(t1==max-1){
        printf("Full\n");
    }else{
        t1++;s1[t1]=x;
    }
}
void push2(int x){
    if(t2==-1){
        t2=0;
        s2[t2]=x;
    }else if(t2==max-1){
        printf("Full\n");
    }else{
        t2++;s2[t2]=x;
    }
}
int pop1(){
    return s1[t1--];
}
int pop2(){
    return s2[t2--];
}
void enqueue(int x){
    push1(x);count++;
}
void dequeue(){
    if(t1==-1 && t2==-1){
        printf("EMPTY\n");
    }
    for(int i=0;i<count;i++){
        int a=pop1();
        push2(a);
    }
    int c=pop2();printf("Poped out element is::%d\n",c);
    count--;
    for(int i=0;i<count;i++){
        int a=pop2();
        push1(a);
    }
}
void display(){
    for(int i=0;i<=t1;i++){
        printf("%d\n",s1[i]);
    }
}
int main() {
    // Test basic enqueue and dequeue operations
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();  // Expected output: 1, 2, 3

    dequeue();  // Poped out element is::1
    display();  // Expected output: 2, 3

    enqueue(4);
    display();  // Expected output: 2, 3, 4

    dequeue();  // Poped out element is::2
    display();  // Expected output: 3, 4

    // Test edge cases
    dequeue();  // Poped out element is::3
    dequeue();  // Poped out element is::4
    dequeue();  // EMPTY

    enqueue(5);
    display();  // Expected output: 5

    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    display();  // Expected output: 5, 6, 7, 8, 9 (last 5 elements)

    dequeue();  // Poped out element is::5
    dequeue();  // Poped out element is::6
    dequeue();  // Poped out element is::7
    dequeue();  // Poped out element is::8
    dequeue();  // Poped out element is::9
    dequeue();  // EMPTY

    return 0;
}