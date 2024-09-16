#include <stdio.h>
#include <math.h>



float ReLu(float x) {
    if (x > 0) {
        return x;
    }
    else {
        return 0;
    }
}

float ReLu_derivative(float x) {
    if (x > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    float x;
    scanf("%f", &x);
    printf("%f\n", ReLu(x));
    printf("%f\n", ReLu_derivative(x));
}