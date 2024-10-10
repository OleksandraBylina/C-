#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int hour;
    int minute;
    int second;
}Time;

int main() {
    int h = 0;
    int m = 0;
    int s = 0;

    int m_adder = 0;
    int h_adder = 0;

    printf("Write a second:\n");
    scanf("%i", &s);
    while (s > 59) {
        s = s - 60;
        m_adder += 1;
    }

    printf("Write a minute:\n");
    scanf("%i", &m);
    m += m_adder;
    while (m > 59) {
        m = m - 60;
        h_adder += 1;
    }

    printf("Write an hour:\n");
    scanf("%i", &h);
    h += h_adder;
    while (h > 23) {
        h = h - 24;
    }

    Time time;
    time.second = s;
    time.minute = m;
    time.hour = h;

    if (h < 10) {
        printf("0");
    }
    printf("%i : ", h);
    if (m < 10) {
        printf("0");
    }
    printf("%i : ", m);
    if (s < 10) {
        printf("0");
    }
    printf("%i", s);
}