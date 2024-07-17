#include<stdio.h>
int main(){
    int arr[17]={2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
    //int n=sizeof(arr)/sizeof(arr[0]);
    int count[10];
    for(int i=0;i<10;i++){
        count[i]=0;
    }int b[17];
    for(int i=0;i<17;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=17-1;i>=0;i--){
        b[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<17;i++){
        printf("%d\n",b[i]);
    }
}