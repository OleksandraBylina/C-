#include <stdio.h>
#define MAX_N 10

int inverse_matrix(int N, float matrix[MAX_N][MAX_N], float inverse[MAX_N][MAX_N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                inverse[i][j] = 1.0;
            } else {
                inverse[i][j] = 0.0;
            }
        }
    }


    for (int i = 0; i < N; i++) {
        float diag_element = matrix[i][i];
        if (diag_element == 0) {
            printf("Matrix cannot be inverted\n");
            return 0;
        }

        // Нормализуем строку
        for (int j = 0; j < N; j++) {
            matrix[i][j] /= diag_element;
            inverse[i][j] /= diag_element;
        }

        // Обрабатываем остальные строки
        for (int k = 0; k < N; k++) {
            if (k != i) {
                float scalar = matrix[k][i];
                for (int j = 0; j < N; j++) {
                    matrix[k][j] -= scalar * matrix[i][j];
                    inverse[k][j] -= scalar * inverse[i][j];
                }
            }
        }
    }
    return 1;
}

void print_matrix(int N, float matrix[MAX_N][MAX_N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.3f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf("%i", &N);
    if (N > MAX_N) {
        printf("The matrix is too big %d.\n", MAX_N);
        return 1;
    }
    float matrix[MAX_N][MAX_N], inverse[MAX_N][MAX_N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }


    if (inverse_matrix(N, matrix, inverse)) {
        printf("Inverted matrix:\n");
        print_matrix(N, inverse);
    }
    else {
        printf("Matrix cannot be inverted.\n");
    }

    return 0;
}
