#include <iostream>
#include <bitset>
#include <cstdint>
using namespace std;

bool noncyclic_method(uint32_t n){
    if ((n & (n - 1)) < 0){
        return true;
    }
    return false;
}

bool cyclic_method(uint32_t n) {
    while(1) {
        if (n & n == 1) {
            return 1;
        }
        if (n & 1) {
            return 0;
        }


        n = n >> 1;
    }

}

int main() {
    uint32_t n;
    cin >> n;
    bool a = cyclic_method(n);
    if (a == 1) {
        cout << "This number is a degree of 2" << endl;
    }
    else if (a == 0) {
        cout << "This number is NOT a degree of 2" << endl;
    }
    bool b = noncyclic_method(n);
    if (a == 1) {
        cout << "This number is a degree of 2";
    }
    else if (a == 0) {
        cout << "This number is NOT a degree of 2";
    }
}
