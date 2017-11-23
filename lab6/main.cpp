#include <cstdlib>
#include <iostream>
#include "./VectorForFigure/TArray.h"
#include <ctime>
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
    TVector<Figure> *array = new TVector<Figure>;
    //std::shared_ptr<Figure> ptr, ptr2;
    clock_t start = clock();
    while (std::cin >> action){
        //Display();
        Figure *s1;
        switch(action) {
            case 1:
                s1 = new Trapezoid(std::cin);
                array->Push_back(*s1);
                //delete s1;
                break;
            case 2:
                s1 = new Square(std::cin);
                array->Push_back(*s1);
                //delete s1;
                break;
            case 3:
                s1 = new Rectangle(std::cin);
                array->Push_back(*s1);
                //delete s1;
                break;
            case 4:
                //std::cout << "Enter index" << std::endl;
                int index;
                std::cin >> index;
                array->Delete(index);
                break;
            case 5:
                if (array->Empty()) {
                    std::cout << "Array is empty" << std::endl;
                }
                else {
                    for (auto i:*array) {
                        std::cout << (*i) << std::endl;
                    }
                }
                break;
            case 6:
                //std::cout << "Enter index" << std::endl;
                int ind;
                std::cin >> ind;
                if (array->Empty()) {
                //    std::cout << "Array is empty" << std::endl;
                }
                else {
//                    if (array->Size() > ind || (*array)[ind]. != nullptr)
//                        (*array)[ind]->Print();
//                    else
//                        std::cout << "No such Figure" << std::endl;
                }
                break;
            case 0:
                break;
            default:
  //              std::cout << "Incorrect command" << std::endl;;
                break;
        }
    } 
    clock_t end = clock();
    double time = (double) (end - start);
    printf("Time with allocator = %lf\n", time / CLOCKS_PER_SEC);
    delete array;
    return 0;
}
