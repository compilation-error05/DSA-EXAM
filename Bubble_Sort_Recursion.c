#include<stdio.h>
int arr[5]={45,6,78,12,0};
#define n 5
void bubble(int arr[],int size){
    if(size==1){
        return;//in this condition the array contains 0 elemnts
    }
    int count = 0;//for optimization
    for(int i=0;i<size-1;i++){
        if(arr[i]<arr[i+1]){//after the first iteration the smallest elemnt will be in 0th index
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            count++;
        }
    }
    if(count==0)return;
    bubble(arr, size-1);//we reduce the size of array by 1
}
int main(){
    bubble(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}