#include<stdio.h>
void main(){
    double price,tax,total,taxp;
    printf("Enter price,tax percentage(in numbers):");
    scanf("%lf%lf",&price,&tax);
    taxp=price*(tax/100);
    total=price+taxp;
    printf("Total price including of taxes is %lf",total);
}