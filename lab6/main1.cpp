#include <iostream>
#include "./TAllocateList/TAllocationBlock.h"

int main() {
    TAllocationBlock temp(40, 1);
    int *x = (int*)temp.allocate();
    for (int i = 0; i < 10; i++) {
        x[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        int t = x[i];
        std::cout << t << "\t";
    }
    temp.deallocate(x);

    int *y = (int*)temp.allocate();
    for (int i = 0; i < 10; i++) {
        int t = y[i];
        y[i] = 10+i;
        std::cout << t << "\t";
    }
    for (int i = 0; i < 10; i++) {
        int t = x[i];
        std::cout << t << "\t";
    }
    return 0;
}