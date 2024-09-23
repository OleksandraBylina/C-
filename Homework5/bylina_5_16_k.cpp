#include <iostream>
using namespace std;


float mod(float an) {
    if (an < 0) {
        return -an;
    }
    return an;
}




int main() {
    float x;
    cin >> x;
    float sum = 1 + ((1.0 / 2.0)) * x;
    float a0 = 1;
    float an = (1.0 / 2.0) * x;
    float epsilon = 0.000001;
    int up_counter = 1;
    int down_counter = 2;
    for (int i = 2 ; ; i++) {

        sum += an;
        down_counter += 2;
        an = ((an * up_counter) / float(down_counter)) * (-x);
        if (i % 2 == 0) {
            up_counter += 2;
        }
        if (mod(an) < epsilon) {
            cout << i << endl;
            break;
        }
    }
    cout << sum;


}
