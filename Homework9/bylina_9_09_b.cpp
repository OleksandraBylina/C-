
#include <stdlib.h>
#include <stdio.h>

int main() {
    int **arr;
    int n;
    int m;
    int el;
    scanf ("%i", &n);
    scanf ("%i", &m);
    arr = (int **)calloc(n, sizeof(int*)); //виділення пам'яті для масиву

    for (int i = 0; i < n; i++) {
        arr[i] = (int *)calloc(m, sizeof(int)); //виділення пам'яті для кожного рядка масиву
    }

    for (int i = 0; i < n; i++) { //зчитування елементів з консолі
        for (int j = 0; j < m; j++) {
            scanf("%i", &el);
            arr[i][j] = el;
        }

    }

    int num_col;
    printf("Write the number of the column:");
    scanf("%i", &num_col);
    while (num_col < 1 || num_col > m) { //зчитування інформації про номер потрібного стовпця

        printf("Your number is incorrect, try more:");
        scanf("%i", &num_col);

    }

    for (int i = 0; i < n; i++) {
        arr[i] = (int *)realloc(arr[i], (m + 1) * sizeof(int)); //виділення пам'яті щоб в кожному рядку було +1 елемент
        for (int j = m; j > num_col - 1; j--) {
            arr[i][j] = arr[i][j - 1];
        }
        arr[i][num_col - 1] = 0;
    }




    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + 1; j++) {

            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    }

