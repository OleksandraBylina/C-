#include <iostream>
using namespace std;

int factorial(int i) {
    int f = 1;
    for (int c = 1 ; c < i + 1; c++) {
        f *= c;
    }
    return f;

}

int main() {
    int n;
    float u;
    float v;
    cin >> n;
    cin >> u;
    cin >> v;
    float a0 = u;
    float b0 = v;
    float an;
    float bn;
    float sum = (u * v) / 2;
    for (int i = 2 ; i < n + 1 ; i++) {
        an = 2 * b0 + a0;
        bn = 2 * a0 * a0 + b0;
        sum += (an * bn) / factorial(i + 1);
    }

    cout << sum << endl;


}