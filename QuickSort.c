#include <stdio.h>
#include <stdlib.h>

int count = 0;

int partition(int a[], int l, int n) {
    int p = a[l];
    int i = l;
    int j = n + 1;
    int temp;

    do {
        do {
            i++;
            count++;
        } while (i < n && a[i] < p);
        do {
            j--;
            count++;
        } while (j > l && a[j] > p);

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[l];
    a[l] = a[j];
    a[j] = temp;

    return j;
}

void Quick_Sort(int a[], int l, int n) {
    if (l < n) {
        int s = partition(a, l, n - 1);
        Quick_Sort(a, l, s - 1);
        Quick_Sort(a, s + 1, n);
    }
}

int main() {
    int m,a[m];
    printf("\nEnter the size of the array : ");
    scanf("%d", &m);
    printf("\nThe array elements are : ");
    for (int i = 0; i < m; i++) {
        a[i] = rand();
        printf("%d\t", a[i]);
    }
    Quick_Sort(a, 0, m);
    printf("\nThe sorted elements are : ");
    for (int i = 0; i < m; i++) {
        printf("%d\t", a[i]);
    }
    printf("\nNumber of times basic operations executed :%d", count);
    return 0;
}
// Output: Enter the size of the array : 5
// The array elements are : 1804289383 846930886 1681692777 1714636915 1957747793
// The sorted elements are : 846930886 1681692777 1714636915 1804289383 1957747793
// Number of times basic operations executed :10
//time complexity of quick sort is O(n^2)
