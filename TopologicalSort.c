#include<stdio.h>
#include<stdlib.h>
int indegree[10],cost[10][10],n,i,j;

void calculate(){
    for(i=0;i<n;i++){
        indegree[i]=0;
        for(j=0;j<n;j++){
                indegree[i]=indegree[i]+cost[j][i];
        }
    }
}

void sourceremoval(){
    int removal[10]={0},count=0,k;
    printf("topological order = \n");
    for(count=0;count<n;count++){
        calculate();
        for(i=0;i<n;i++){
            if(removal[i]==0 && indegree[i]==0){
                break;
            }
        }
        if(i==n){
            printf("Graph is cyclic and has no solution\n");
            return;
        }
        printf("%d\t",i);
        removal[i]=1;
        for(k=0;k<n;k++)
            cost[i][k]=0;
    }
    printf("Above solution is correct\n");
}
int main(){
    int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    sourceremoval();
}
//Enter the number of vertices: 5
//Enter the cost matrix:
//0 1 1 0 0
//0 0 0 1 1
//0 0 0 1 0
//0 0 0 0 1
//0 0 0 0 0
//topological order =
//0    1	2	3	4	Above solution is correct   
