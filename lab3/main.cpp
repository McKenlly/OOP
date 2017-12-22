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
    int action = 0;
    TArray array;
    std::shared_ptr<Figure> ptr, ptr2;
    do {
        Display();
        std::cin >> action;
        switch(action) {
            case 1:
                ptr = std::make_shared<Trapezoid>(std::cin);
                array.Push_back(ptr);
                break;
            case 2:
                ptr = std::make_shared<Square>(std::cin);
                array.Push_back(ptr);
                break;
            case 3:
                ptr = std::make_shared<Rectangle>(std::cin);
                array.Push_back(ptr);
                break;
            case 4:
                std::cout << "Enter index" << std::endl;
                int index;
                std::cin >> index;
                array.Delete(index);
                break;
            case 5:
                if (array.Empty()) {
                    std::cout << "Array is empty" << std::endl;
                }
                else {
                    std::cout << array << std::endl;
                }
                break;
            case 6:
                std::cout << "Enter index" << std::endl;
                int ind;
                std::cin >> ind;
                if (array.Empty()) {
                    std::cout << "Array is empty" << std::endl;
                }
                else {
                    if (array.Size() > ind)
                        array[ind]->Print();
                    else
                        std::cout << "No such Figure" << std::endl;
                }
                break;
            case 0:
                break;
            default:
                std::cout << "Incorrect command" << std::endl;;
                break;
        }
    } while (action);
    return 0;
}
