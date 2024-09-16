#include <stdio.h>
#include <math.h>

float m(int n , float x) {
    float el;
    float sum = 1;
    for (int i = 1 ; i < n ; i++) {
        el = pow(x, pow(3, i));
        sum += el;
    }
    return sum;
}

int main() {
    int n;
    float x;
    scanf("%i %f", &n, &x);
    printf("%f", m(n , x));
}