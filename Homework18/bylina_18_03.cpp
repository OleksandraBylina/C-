//
// Created by bylin on 11.11.2024.
//
#include <stdexcept>
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
class BlackBox {
private:
    T elements[100];
    int count;

public:
    BlackBox() : count(0) {}

    void push(const T& element) {
        if (count < 100) {
            elements[count++] = element;
        } else {
            throw overflow_error("BlackBox is full");
        }
    }

    T pop() {
        if (count == 0) {
            throw underflow_error("BlackBox is empty");
        }
        int index = rand() % count;
        T element = elements[index];
        elements[index] = elements[--count];
        return element;
    }

    T xpop() const {
        if (count == 0) {
            throw underflow_error("BlackBox is empty");
        }
        int index = rand() % count;
        return elements[index];
    }
};
