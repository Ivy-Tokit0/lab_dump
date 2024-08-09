#include<stdio.h>
int count, x[10], w[10], d;
void subset(int cs, int k, int r){
    int i;
    x[k]=1;
    if(cs+w[k]==d){
        printf("Subset %d\n",++count);
        for(i=0;i<=k;i++){
            if(x[i]==1){
                printf("%d ",w[i]);
            }
        }
        printf("\n");
    }
    else if(cs+w[k]+w[k+1]<=d){
        subset(cs+w[k],k+1,r-w[k]);
    }
    if(cs+r-w[k]>=d && cs+w[k]<=d){
        x[k]=0;
        subset(cs,k+1,r-w[k]);
    }
}

int main(){
    int sum=0,n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    printf("Enter the required sum\n");
    scanf("%d",&d);
    if((sum<d)||(w[0]>d)){
        printf("No solution\n");
    }else
        subset(0,0,sum);
    return 0;
}
// Output:
// Enter number of elements
// 5
// Enter the elements
// 2 5 8 4 6
// Enter the required sum
// 9
// Subset 1
// 2 4
// Subset 2
// 5 4
// Subset 3
// 8 1
// Subset 4
// 6 3
// Subset 5
// 2 5 1
// Subset 6
// 2 6 1
