#include<stdio.h>
void main(){
    int a[]={25,11,7,76,65};
    int l=sizeof(a)/sizeof(a[0]);
    int min=a[0];
    for(int i=0;i<l;i++){
        if(a[i]<min)
            min=a[i];
    }
    printf("minimun in the array is %d",min);
}