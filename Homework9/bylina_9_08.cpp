#include <iostream>
#include <cstdio>

int abser(int n) {
    if (n < 0) {
        return -n;
    }
    else {
        return n;
    }
}


int main() {
    int *arr;
    int n;
    scanf("%i", &n);
    arr = (int *)calloc(n, sizeof(int));
    for (int i = 0 ; i < n ; i++) {
        int el;
        scanf("%i", &el);
        arr[i] = el;

    }
    while (true) {
        int new_size;
        printf("\n If you want to stop making your vector, enter a number 9999");
        scanf("%i", &new_size);
        if (new_size <= n) {
            printf("Incorrect format, the new size must be bigger than the previous \n");
        }
        if (new_size == 9999) {
            break;
        }
        realloc(arr, ((new_size ) * sizeof(int)));
        for (int d = n; d < (new_size) ; d++) {
            int new_el;
            scanf("%i", &new_el);
            arr[d] = new_el;
        }
        n = new_size;
        int sum = 0;
        for (int s = 0 ; s < n ; s++) {
            sum += arr[s];
        }

        int avar = (sum / n);
        printf("Avarage number:%i \n", avar);
        for (int s = 0 ; s < n ; s++) {
            arr[s] = abser(arr[s] - avar);
        }

        for (int s = 0 ; s < n ; s++) {
            printf("%i ", arr[s]);
        }
    }
}













