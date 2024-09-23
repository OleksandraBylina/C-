#include <stdio.h>


bool fib_checker(int n) {
    int trivial1 = 0;
    int trivial2 = 1;
    int main = 0;
    while (main < n) {
        main = trivial1 + trivial2;
        trivial1 = trivial2;
        trivial2 = main;
        if (main == n) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    scanf("%i", &N);
    int arr[N];
    for (int q = 0 ; q < N ; q++) {
        int a;
        scanf("%i", &a);
        arr[q] = a;
    }
    int fib_counter = 0;
    for (int w = 0 ; w < N ; w++) {
        if (fib_checker(arr[w]) == true) {
            fib_counter++;
        }
    }
    printf("%i", fib_counter);
}
