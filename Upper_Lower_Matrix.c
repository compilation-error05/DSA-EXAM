#include<stdio.h>
int main(){
    int arr[3][3]={{1,9,10},{0,2,9},{1,0,8}};
    int flag=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i>j && arr[i][j]!=0){
                flag=0;
                break;
            }
        }
    }
    if(flag==0)printf("Upper\n");
    else printf("Not Upper\n");

}
