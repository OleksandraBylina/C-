#include <stdio.h>
#include <math.h>
int sign(float x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}
float abser(float x) {
    if (x < 0) {
        return -x;
    }
    else {
        return x;
    }
}
int main() {
    float x;
    scanf("%f", &x);
    printf("A: %f\n", abser(x));
    printf("B: %f\n", abser((abser(abser(x) - 1.0)) - 1));
    printf("C: %i\n", sign(x));
    printf("D: %f\n", sin(abser(x)));
}