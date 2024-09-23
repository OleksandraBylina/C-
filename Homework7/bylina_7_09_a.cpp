#include <stdio.h>

int main() {
    int n;
    scanf("%i", &n);
    int arr[n];
    for (int q = 0 ; q < n ; q++) {
        int a;
        scanf("%i", &a);
        arr[q] = a;
    }
    int max_el = arr[0];
    for (int w = 0 ; w < n ; w++) {
        if (arr[w] > max_el) {
            max_el = arr[w];
        }
    }
    printf ("%i", max_el);
}
