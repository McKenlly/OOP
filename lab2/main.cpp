#include <iostream>
#include <cstdlib>
#include "Square.h"
#include "TQueueItem.h"
#include "Queue.h"
int main() {
    TQueue a;
    a.push(Square(1));
    std::cout << a << "\n";
    a.push(Square(4));
    std::cout << a << "\n";
    a.push(Square(6));
    std::cout << a << "\n";
    a.push(Square(5));
    a.pop(); a.pop(); a.pop();
    std::cout << a;
    Square t(5);
    if (t == a.pop())
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
    t = a.pop();
    std::cout <<  t   << std::endl;
    std:: cout << t++ << std::endl;
    std:: cout << ++t << std::endl;

    return 0;
}
