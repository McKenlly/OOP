#include "cstdlib"
#include "iostream"
#include "TArray.h"

int main(int argc, char **argv) {
    TArray *simpleArr = new TArray();
    std::cin >> *simpleArr;
    std::cout << *simpleArr << std::endl;
    std::cout << (*simpleArr)[2] << std::endl;
    Square temp = Square(1000);
    Square copy = (*simpleArr)[2];
    simpleArr->Replace(copy, temp);
//    std::cout << *simpleArr << std::endl;
    (*simpleArr).Push_back(temp);
    std::cout << "Replaced object in index 2 and push "
            "in back " << temp << std::endl;
    std::cout << *simpleArr << std::endl;
    TArray copyArr(simpleArr);
    for (int i = 0; i < copyArr.Size(); i++) {
        copyArr[i].Print();
        std::cout << "Area this figure: " << copyArr[i].Area()
                                           << std::endl;
        std::cout << std::endl;
    }
    delete simpleArr;
    return 0;
}
