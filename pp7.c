#include<stdio.h>
void main(){
    double a,b,c,d;
    printf("Enter the value of a,b,c:");
    scanf("%lf%lf%lf",&a,&b,&c);
    d=b*b-4*a*c;
    if(d>0)
        printf("Real and equal");
    else if(d<0)
        printf("Real and distinct");
    else
        printf("Complex and imaginary");
}