#include <iostream>
#include <bitset>
#include <cstdint>
using namespace std;

int main() {
    uint32_t n;
    cin >> n;
    int count = bitset<32>(n).count();
    cout << count;
}