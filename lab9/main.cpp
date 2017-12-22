#include <iostream>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <random>
#include "trapeze.h"
#include "rectangle.h"
#include "square.h"
#include "TList.h"


int main(void)
{
    TList<Figure> list;
    TStack<std::shared_ptr<std::function<void(void)> > > stack;
    std::mutex mtx;

    std::function<void(void)> LambdaInsert = [&]() {
        std::lock_guard<std::mutex> guard(mtx);

        for (int i = 0; i < 10; ++ i) {
            std::cout << "std::function<void(void)>: Insert" << std::endl;

            switch(rand()%3) {
                case 0: {
                    std::cout << "Inserted Trapezoid" << std::endl;
                    list.PushFirst(std::shared_ptr<Trapezoid>(new Trapezoid(rand()%300, rand()%300, rand()%300)));
                    break;
                }

                case 1: {
                    std::cout << "Inserted Rectangle" << std::endl;
                    list.PushFirst(std::shared_ptr<Rectangle>(new Rectangle(rand()%300, rand()%300)));
                    break;
                }
                case 2: {
                    std::cout << "Inserted Square" << std::endl;
                    list.PushFirst(std::shared_ptr<Square>(new Square(rand()%300)));
                    break;
                }
            }
        }
    };


        std::function<void(void)> LambdaRemove = [&]() {
        std::lock_guard<std::mutex> guard(mtx);
        std::cout << "std::function<void(void)>: Remove" << std::endl;
        if (list.IsEmpty()) {
            std::cout << "List is empty" << std::endl;
        } else {
            double sqr = rand()%50000;
            std::cout << "Remove figure with area " << sqr << std::endl;

            for (size_t i = 0; i < 5; ++i) {
                auto iter = list.begin();
                for (size_t k = 0; k < list.GetLength(); ++k) {
                    if (iter->GetSquare() < sqr) {
                        list.Pop(k);
                        break;
                    }
                    ++iter;
                }
            }
        }
    };

    std::function<void(void)> LambdaPrint = [&]() {
        std::lock_guard<std::mutex> guard(mtx);

        std::cout << "std::function<void(void)>: Print" << std::endl;
        if(!list.IsEmpty()) {
            std::cout << list << std::endl;
        } else {
            std::cout << "List is empty." << std::endl;
        }
    };

    stack.Push(std::shared_ptr<std::function<void(void)>>(&LambdaPrint, [](std::function<void(void)>*){}));
    stack.Push(std::shared_ptr<std::function<void(void)>>(&LambdaRemove, [](std::function<void(void)>*){}));
    stack.Push(std::shared_ptr<std::function<void(void)>>(&LambdaPrint, [](std::function<void(void)>*){}));
    stack.Push(std::shared_ptr<std::function<void(void)>>(&LambdaInsert, [](std::function<void(void)>*){}));

    //Достаем ляммбда функции
    while (!stack.IsEmpty()) {
        std::shared_ptr<std::function<void(void)>> Lambda = std::move(stack.Top());
        std::future<void> ft = std::async(*Lambda);
        ft.get();
        stack.Pop();
    }

    return 0;
}
