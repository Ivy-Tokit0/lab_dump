#include<stdio.h>
void main(){
    int l,b;
    printf("Enter the length and Breadth of Rectangle:");
    scanf("%d%d",&l,&b);
    printf("Area of rectangle is %d\n",(l*b));
    printf("Perimeter of rectangle is %d",(2*(l+b)));
}