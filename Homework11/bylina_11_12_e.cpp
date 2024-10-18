#include <iostream>
#include <cstdio>
#include <cstring>
#define N 20

using namespace std;

struct Toy {
    char name[50];
    double price;
    int low_age;
    int high_age;
};


void file_opener(const char* filename, Toy* toys_list, int* size) {
    FILE* f = fopen(filename, "rb");


    int i = 0;
    while (fread(&toys_list[i], sizeof(Toy), 1, f) == 1) {
        i++;
        if (i >= N) break;
    }
    *size = i;
    fclose(f);
}

void toy_printer(Toy* toy) {
    printf("Name: %s\n", toy->name);
    printf("Price: %.2lf\n", toy->price);
    printf("Low_age: %i\n", toy->low_age);
    printf("High_age: %i\n", toy->high_age);
}

void toy_printer_to_file(Toy* toy, FILE* out_file) {
    fwrite(toy, sizeof(Toy), 1, out_file);
}

void stopper(Toy* toys_list, int size, int age, double price, char* output_filename) {
    bool flag = false;
    FILE* out_file = fopen(output_filename, "wb");
    for (int i = 0; i < size; i++) {
        for (int e = i + 1; e < size; e++) {
            if ((toys_list[i].price + toys_list[e].price) < price) {
                if ((age >= toys_list[i].low_age && age <= toys_list[i].high_age) &&
                    (age >= toys_list[e].low_age && age <= toys_list[e].high_age)) {
                    toy_printer(&toys_list[i]);
                    toy_printer(&toys_list[e]);
                    toy_printer_to_file(&toys_list[i], out_file);
                    toy_printer_to_file(&toys_list[e], out_file);
                    flag = true;
                    break;

                }
            }
            if (flag == true) {
                break;
            }
        }
        if (flag == true) {
            break;
        }


    }

}
int main() {
    double price;
    int age;
    scanf("%lf", &price);
    scanf("%i", &age);
    Toy toys_list[N];
    int size = 0;
    file_opener("11_2.int32", toys_list, &size);
    stopper(toys_list, size, price, age, "output_toys.int32");
    }


