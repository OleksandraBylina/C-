#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c;
    scanf ("%f", a);
    scanf ("%f", b);
    scanf ("%f", c);
    float p = (a + b + c) / 2.0;
    float square = sqrt((p - a) * (p - b) * (p - c) * p);

    float ha = square / (2.0 * a);
    float hb = square / (2.0 * b);
    float hc = square / (2.0 * c);
    printf("%f %f %f \n", ha, hb, hc);

    float ma = 0.5 * sqrt(2.0 * pow(b, 2) + 2.0 * pow(c, 2) - pow(a, 2));
    float mb = 0.5 * sqrt(2.0 * pow(a, 2) + 2.0 * pow(c, 2) - pow(b, 2));
    float mc = 0.5 * sqrt(2.0 * pow(b, 2) + 2.0 * pow(a, 2) - pow(c, 2));
    printf("%f %f %f \n", ma, mb, mc);

    float ba = sqrt(b * c * (1.0 - ((pow(a, 2) / pow((b + c), 2)))));
    float bb = sqrt(a * c * (1.0 - ((pow(b, 2) / pow((a + c), 2)))));
    float bc = sqrt(b * a * (1.0 - ((pow(c, 2) / pow((b + a), 2)))));
    printf("%f %f %f \n", ba, bb, bc);


}
