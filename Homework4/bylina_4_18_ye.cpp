#include <stdio.h>

int main() {
    int k;
    float x;
    scanf("%i %f", &k, &x);
    float first_trivial = 1.0;
    for (int i = 1 ; i < k + 1 ; i++) {
        first_trivial *= (-x) / i;
    }
    if (k = 0) {
        printf("1");
    }
    printf("%f", first_trivial);
}