#include<stdio.h>
int r=-1;int f=-1;
int arr[6];int n=6;
void enfront(int arr[],int x){//it moves backward::not a normal
    if((r==n-1 && f==0)||f==r-1){
        printf("FULL\n");
    }
    else if(r==-1 && f==-1){
        f=0;
        arr[f]=x;
    }
    else if(f==0){
        f=n-1;
        arr[f]=x;
    }
    else{
        f--;arr[f]=x;
    }
}
void enrear(int arr[],int x){//it moves forward
    if((r==n-1 && f==0)||f==r-1){
        printf("FULL\n");
    }
    else if(r==-1 && f==-1){
        r=0;
        arr[r]=x;
    }
    else if(r==n-1){
        r=0;arr[r]=x;
    }
    else{
        r++;arr[r]=x;
    }
}
void derear(int arr[]){//it moves backward::not a normal
    if(f==-1 && r==-1){
        printf("Empty\n");
    }
    else if(r==0){
        printf("Dequed element::%d\n",arr[r]);
        r=n-1;
    }
    else if(r==f){
        printf("Dequed element::%d\n",arr[r]);
        r=f=0;//only one element is present
    }
    else{
        printf("Dequed element::%d\n",arr[r]);
        r--;
    }
}
void defront(int arr[]){//it moves forward
    if(f==-1 && r==-1){
        printf("Empty\n");
    }
    else if(f==n-1){
        printf("Dequed element::%d\n",arr[f]);
        f=0;
    }
    else if(r==f){
        printf("Dequed element::%d\n",arr[f]);
        r=f=0;//only one element is present
    }
    else{
        printf("Dequed element::%d\n",arr[f]);
        f++;
    }
}
void main(){
      // Test enqueue and dequeue operations
    enfront(arr, 5);  // [5]
    enrear(arr, 5);   // [5, 5]
    enfront(arr, 0);  // [0, 5, 5]
    enrear(arr, 4);   // [0, 5, 5, 4]
    defront(arr);     // [5, 5, 4]
    derear(arr);      // [5, 5]
    defront(arr);     // [5]
    defront(arr);     // Empty Queue
    defront(arr);     // Empty Queue

    // Test wrapping around
    enfront(arr, 1);  // [1]
    enrear(arr, 2);   // [1, 2]
    enfront(arr, 3);  // [3, 1, 2]
    enrear(arr, 4);   // [3, 1, 2, 4]
    defront(arr);     // [1, 2, 4]
    derear(arr);      // [1, 2]
    enrear(arr, 5);   // [1, 2, 5]
    enfront(arr, 6); 
}