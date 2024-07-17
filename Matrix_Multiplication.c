#include<stdio.h>
int main(){
    int m,n,p,q;
    printf("Enter the no of rows ");
    scanf("%d",&m);
    printf("Enter the no of columns ");
    scanf("%d",&n);
    printf("2nd Matrix\n ");
    printf("Enter the no of rows ");
    scanf("%d",&p);
    printf("Enter the no of columns ");
    scanf("%d",&q);
    int a[m][n];
    int b[p][q];
    int c[m][q];
    int f=n;// factor=m for internal multiplication
    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){
            printf("ELEMENT [%d][%d]",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<p;i++){
        for(int j=0; j<q;j++){
            printf("ELEMENT [%d][%d]",i+1,j+1);
            scanf("%d",&b[i][j]);
        }
    }
    printf("A and B are \n");
    for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                printf("%d  ",a[i][j]);
            }
        printf(" \n");
    }
    
    for(int i=0;i<p;i++){
            for(int j=0; j<q;j++){
                printf("%d  ",b[i][j]);
            }
        printf(" \n");
    }
    if(q!=n){
        printf("Cannot be mulitplied\n");
    }
    else{
        printf("MULTIPLICATION");
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                int sum=0;
                for(int k=0;k<f;k++){
                    sum=a[i][k]*b[k][j]+sum;
                }
                c[i][j]=sum;
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    }
        printf(" \n");
}


    