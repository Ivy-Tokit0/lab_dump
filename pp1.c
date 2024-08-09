#include<stdio.h>
void max(double a,double b){
    if(a>b){
        printf("%lf is the greatest",a);
    }else if(b>a){ 
        printf("%lf5 is the greatest",b);
    }else{
        printf("Both are same values");
    }
}
void main(){
    double x,y;
    printf("Enter the first value:");
    scanf("%lf",&x);
    printf("Enter the second value:");
    scanf("%lf",&y);
    max(x,y);
}