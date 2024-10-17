#include <iostream>
#include <cmath>
using namespace std;

int main() {
    FILE* f = fopen("11_1.int32", "rb");
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    rewind(f);

    int num_el = file_size / sizeof(float);
    float *arr = (float*)malloc(num_el * sizeof(float));
    size_t read_elements = fread(arr, sizeof(float), num_el, f);
    for (int i = 0; i < num_el; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    float first_num = arr[0];
    float last_num = arr[num_el - 1];
    cout << last_num - first_num;

    free(arr);
    fclose(f);

}