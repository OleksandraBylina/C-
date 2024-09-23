#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    float a0 = 1;
    float a1 = 1;
    float a2 = 1;
    float an;
    int x = 8;
    float sum  = (7.0 / 8.0);
    for (int i = 4 ; i < n + 1 ; i++) {
        an = a0 + a2;
        a0 = a1;
        a1 = a2;
        a2 = an;
        x *= 2;
        sum += (an / x);

    }
    switch(n) {
        case 1:
            cout << 1.0 / 2.0;
            break;
        case 2:
            cout << 3.0 / 4.0;
            break;
        case 3:
            cout << 7.0 / 8.0;
            break;
        default:
            cout << sum;
    }

}
