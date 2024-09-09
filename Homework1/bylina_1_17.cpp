#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%i", &n);
    long double pn = pow(n, 8);
    printf("%20.4Lf", pn);
}

