#include <stdio.h>
#include <stdlib.h>

void Selection_Sort(int a[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            count++;
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("\nNumber of times basic operations executed: %d", count);
}

int main() {
    int n,a[n];
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    printf("\nThe array elements are: ");
    for (int i = 0; i < n; i++) {
        a[i] = rand();
        printf("%d\t", a[i]);
    }
    Selection_Sort(a, n);
    printf("\nSorted elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    return 0;
}
// Output: Enter the size of the array: 5
// The array elements are: 1804289383 846930886 1681692777 1714636915 1957747793
// Number of times basic operations executed: 10
// Sorted elements are: 846930886 1681692777 1714636915 1804289383 1957747793
//time complexity of selection sort is O(n^2) 