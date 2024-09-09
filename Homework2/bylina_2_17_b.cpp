#include <stdio.h>
#include <math.h>

double bent(float x) {
    return (((sqrt(pow(x, 2) + 1.0) - 1.0) / 2.0) + x);
}
double bent_derivative(float x) {
    return (x / (2.0 * (sqrt(pow(x, 2) + 1.0))) + 1);
}
int main() {
    float x;
    scanf("%f", &x);
    printf("%f \n", bent(x));
    printf("%f", bent_derivative(x));

}
