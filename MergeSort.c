#include<stdio.h>
#include<stdlib.h>
#include<math.h>
static int count=0;
void MergeSort(int a[],float n){
    int b[10000],c[10000],j=0,i,f,d;
    f=floor(n/2);
    d=ceil(n/2);
    if(n>1){
        count++;
        for(i=0;i<f;i++)
            b[i]=a[i];
        for(i=f;i<n;i++)
            c[j++]=a[i];
        MergeSort(b,f);
        MergeSort(c,d);
        Merge(b,c,a,f,d);
    }
}
void Merge(int b[],int c[],int a[], int f, int d){
    int i=0,j=0,k=0;
    while(i<f && j<d){
        count++;
        if(b[i]<=c[j]){
            a[k++]=b[i];
            i=i+1;
        }
        else{
            a[k++]=c[j];
            j=j+1;
        }
    }
    while(i<f)
        a[k++]=b[i++];
    while(j<d)
        a[k++]=c[j++];
}
int main(){
    int a[10000],m,i;
    printf("\nEnter the size of the array : ");
    scanf("%d",&m);
    printf("\nThe array elements are : ");
    for(i=0;i<m;i++){
        a[i]=rand();
        printf("%d\t",a[i]);
    }
    MergeSort(a,m);
    printf("\nThe sorted elements are : ");
    for(i=0;i<m;i++)
        printf("%d\t",a[i]);
    printf("\nNumber of times the basic operation executed : %d",count);
}