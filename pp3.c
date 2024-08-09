#include<stdio.h>
void main(){
    int fact=1,n;
    printf("Enter a number:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        fact*=n;
    }
    printf("factorial of %d id %d",n,fact);
}