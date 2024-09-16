#include <stdio.h>
#include <math.h>

float mod(float n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

int main() {
    float el = (1.0);
    float last_sum = 0;
    float sum = (1.0);
    float epsilon = 0.000000000001;
    int i = 1;
    while (1){
        el *= ((1 - 2.0 * i) / (6.0 * i + 3 ));
        sum += el;
        if (mod(sum * 2 * sqrt(3) - last_sum * 2 * sqrt(3)) < epsilon) {
            sum *= 2 * sqrt(3);
            break;
        }
        last_sum = sum;
        i++;
    }
    printf("%f", sum);
}

