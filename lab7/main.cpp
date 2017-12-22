#include "TList.h"
#include <iostream>
#include "trapeze.h"
#include "square.h"
#include "rectangle.h"
#include "TStack.h"

void Display(void)
{
    std::cout << "Display:" << std::endl;
    std::cout << "1) Add Trapezoid" << std::endl;
    std::cout << "2) Add Rectangle" << std::endl;
    std::cout << "3) Add Square" << std::endl;
    std::cout << "4) Delete" << std::endl;
    std::cout << "5) Print"  << std::endl;
    std::cout << "0) Exit" << std::endl;
}

int main(void)
{
    //Инициализация контейнеров контейнера
    TStack<TList<Figure>, std::shared_ptr<Figure> > stack;
    int act, index;
    do {
        Display();
        std::cin >> act;
        system("clear");
        switch(act) {
            case 1:
            
                stack.Push(std::make_shared<Trapezoid>(std::cin));
                break;
            case 2:
                
                stack.Push(std::make_shared<Rectangle>(std::cin));
                break;
            case 3:
                stack.Push(std::make_shared<Square>(std::cin));
                break;
            case 4: {
                std::cout << "Enter principle of removal" << std::endl;
                std::cout << "1) by type" << std::endl;
                std::cout << "2) lesser than square" << std::endl;
                std::cin >> index;
                switch (index) {
                    case 1: {
                        std::cout << "Enter type" << std::endl;
                        std::cout << "1) Trapezoid" << std::endl;
                        std::cout << "2) Rectangle" << std::endl;
                        std::cout << "3) Square" << std::endl;
                        std::cin >> index;
                        stack.RemoveByType(index);
                        break;
                    }
                    case 2: {
                        double area;
                        std::cout << "Enter square" << std::endl;
                        std::cin >> area;
                        stack.RemoveBySquare(area);
                        break;
                    }
                    default: {std::cout << "Unknown command\n"; break;}
                }
                break;
            }
            case 5:
                stack.Print();
                break;
            case 0:
                break;
            default:
                std::cout << "Incorrect command" << std::endl;;
                break;
        }
    } while(act);

    return 0;
}
