#include "cstdlib"
#include "iostream"
#include "Square.h"
#include "TArray.h"

void Display()
{
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "1) Add trapezoid" << std::endl;
    std::cout << "2) Add square" << std::endl;
    std::cout << "3) Add rectangle" << std::endl;
    std::cout << "4) Delete figure from array" << std::endl;
    std::cout << "5) Print array"  << std::endl;
    std::cout << "6) Print figure from array with index"  << std::endl;
    std::cout << "0) Exit" << std::endl;
}
int main(int argc, char **argv) {
    TArray<Figure> array;
    array.Push_back(std::make_shared<Square>(15));
    //auto u = array.begin();
    //std::cout << **u << std::endl;
    array.Push_back(std::make_shared<Square>(741));
    //++u;
    //std::cout << **u << std::endl;
    array.Push_back(std::make_shared<Square>(5));
    array.Push_back(std::make_shared<Square>(78));
    //for (auto i : array) std::cout << i->Area() << std::endl;
    //auto t = array.begin();
    std::cout << array << "ENDVECTOR\n";
    /*std::cout << **t << std::endl;
    ++t;
    std::cout << **t << std::endl;
    std::cout << **u << std::endl;
    */return 0;
}
