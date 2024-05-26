#include<stdio.h>
#define n 10
int arr[10];int t1=-1;int t2=n-1;
void push1(int x){
    if(t1==t2-1){
        printf("FULL1\n");
    }else{
        t1++;arr[t1]=x;
    }
}
void push2(int x){
    if(t2==t1+1){
        printf("FULL2\n");
    }else{
        t2--;arr[t2]=x;
    }
}
int pop1()
{
        if(t1==-1){
            return -1;
        }
        else{
            int ans=arr[t1];
            t1--;
            return ans;
        }
}
int pop2()
{
        if(t2==n-1){
            return -1;
        }
        else{
            int ans=arr[t2];
            t2++;
            return ans;
        }
}
int main(){
    push1(1);
push1(2);
push1(3);
push2(4);
push2(5);

// After pushing: 1 2 3 | 5 4
int popped1 = pop1(); // Should return 3
int popped2 = pop2(); // Should return 5
}
