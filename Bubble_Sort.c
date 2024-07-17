#include<stdio.h>
int arr[5]={45,6,78,12,0};
#define n 5
int main(){
    for(int i=0;i<n;i++){//j ta aggey aggey cholbe w.r.t i so (i=0 holey j=i+1)(i<n holey j<n-1)
            for(int j=i+1;j<n-1;j++){
            if(arr[i]<arr[j]){
                //swap
                int a=arr[i];
                arr[i]=arr[j];
                arr[j]=a;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}