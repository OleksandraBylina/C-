#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char name[30];
    int group_number;
    int mark1;
    int mark2;
    int mark3;

} Student;

int main() {
    int n;
    scanf("%i", &n);
    Student arr[n];
    for (int s = 0 ; s < n ; s++) {
        Student A;
        printf("Write a name of a student:\n");
        char name[100];
        scanf("%30s", name);
        strcpy(A.name, name);
        printf("Write a group_number of a student:\n");
        int g;
        scanf("%i", &g);
        A.group_number = g;
        printf("Write a mark for mathematical analysis of a student: \n");
        int m1;
        scanf("%i", &m1);
        A.mark1 = m1;
        printf("Write a mark for analytic geometry of a student:\n");
        int m2;
        scanf("%i", &m2);
        A.mark2 = m2;
        printf("Write a mark for concrete math of a student:\n");
        int m3;
        scanf("%i", &m3);
        A.mark3 = m3;
        arr[s] = A;
    }
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    for (int a = 0 ; a < n ; a++) {
        sum1 += arr[a].mark1;
        sum2 += arr[a].mark2;
        sum3 += arr[a].mark3;
    }
    int avar_num1 = sum1 / n;
    int avar_num2 = sum2 / n;
    int avar_num3 = sum3 / n;
    int worst_number = avar_num1;
    int worst_number_counter = 0;
    int summ_mass[3] = {avar_num1, avar_num2, avar_num3};
    summ_mass[0] = avar_num1;
    for (int q = 0 ; q < n ; q++) {
        if  (summ_mass[q] < worst_number) {
            worst_number = summ_mass[q];
            worst_number_counter = q;
        }
    }
    if (worst_number_counter == 0) {
        printf("The discipline with the worst mark is mathematical analysis :(");
    }
    else if (worst_number_counter == 1) {
        printf("The discipline with the worst mark is analytic geometry :(");
    }
    else {
        printf("The discipline with the worst mark is concrete math :(");
    }


}