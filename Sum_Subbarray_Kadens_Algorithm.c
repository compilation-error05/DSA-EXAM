#include<stdio.h>
#include<limits.h>
int main(){
    int arr[2]={-1,-2};
    int max=INT_MIN;
    int max_till_here=0;
    for(int i=0;i<2;i++){
        max_till_here=max_till_here+arr[i];
        if(max<max_till_here){
            max=max_till_here;
        }
        if(max_till_here<0){
            max_till_here=0;
        }
    }
    printf("%d\n",max);
}