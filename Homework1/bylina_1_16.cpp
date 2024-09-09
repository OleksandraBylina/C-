#include <stdio.h>
#include <math.h>
int main() {
    double e1 = exp(-(1 * 1));
    double e2 = exp(-(2 * 2));
    double e3 = exp(-(3 * 3));
    double e4 = exp(-(4 * 4));
    double e5 = exp(-(5 * 5));
    printf ("Table A: \n");
    printf("x----|--1---|--2---|--3---|--4---|--5---| \n");
    printf("-----|------|------|------|------|------| \n");
    printf("F(x)-|-%.2f-|-%.2f-|-%.2f-|-%.2f-|-%.2f-| \n \n", e1, e2, e3, e4, e5);

    double sq1 = sqrt(1);
    double sq2 = sqrt(2);
    double sq3 = sqrt(3);
    double sq4 = sqrt(4);
    double sq5 = sqrt(5);
    printf ("Table B: \n");
    printf("x----|--1---|--2---|--3---|--4---|--5---| \n");
    printf("-----|------|------|------|------|------| \n");
    printf("F(x)-|-%.2f-|-%.2f-|-%.2f-|-%.2f-|-%.2f-| \n \n", sq1, sq2, sq3, sq4, sq5);


}

