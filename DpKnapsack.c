#include<stdio.h>
#include<stdlib.h>

int max(int a ,int b);
void dpknapsack(int n,int m,int p[],int w[]){
    int i,j;
    int v[n+1][m+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0 || j==0){
                v[i][j]=0;
            }else if(j<w[i]){
                v[i][j]=v[i-1][j];
            }else{
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
            }
        printf("%d ",v[i][j]);
        }
    printf("\n");
    }
    printf("Optimal profit is %d\n",v[n][m]);
    printf("Selected objects are\n");
    while(m!=0){
        if(v[n][m]!=v[n-1][m]){
            printf("%d\n",n);
            m-=w[n];
        }
        n--;
    }
}

int max(int a ,int b){
    return (a>b)?a:b;
}

int main(){
    int n,m;
    int p[50],w[50];
    printf("Enter number of objects\n");
    scanf("%d",&n);
    printf("Enter knapsack capacity\n");
    scanf("%d",&m);
    printf("Enter profit of each object\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    printf("Enter weight of each object\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    dpknapsack(n,m,p,w);
    return 0;
}
// Output:
// Enter number of objects
// 4
// Enter knapsack capacity
// 50
// Enter profit of each object
// 60 100 120 40
// Enter weight of each object
// 10 20 30 40
//OPTIMAL PROFIT IS 220
//SELECTED OBJECTS ARE
//2
//3
//4
