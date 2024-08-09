#include<stdio.h>
void main(){
    //Euclids method of finding Greatest Common Divisor
    int r,m,n;
    printf("Enter two numbers:");
    scanf("%d%d",&m,&n);
    while(n!=0){
        r=m%n;
        m=n;
        n=r;
    }
    printf("%d is the G.C.D",m);
}