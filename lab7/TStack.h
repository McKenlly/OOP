#ifndef TSTACK_H
#define TSTACK_H

#include "figure.h"
#include <memory>
#include <iostream>

template <class T, class D> class TStack
{
private:
    class Node {
    public:
        T data;
        std::shared_ptr<Node> next;
        Node();
        Node(const D&);
    };

    std::shared_ptr<Node> head;
    int count;
public:
    TStack();

    void Push(const D&);
    void Print();
    void RemoveByType(const int&);
    void RemoveBySquare(const double&);
};

#include "TStack.hpp"
#endif