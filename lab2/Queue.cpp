#include "Queue.h"

TQueue:: TQueue():head(nullptr), tail(nullptr){
    std::cout << "Queue created\n";
}
TQueue::TQueue(const TQueue& orig) {
    head = orig.head;
    tail = orig.tail;
}

std::ostream& operator<<(std::ostream& os, const TQueue& obj) {
    TQueueItem *item = obj.head;
    while (item != nullptr) {
        os << (*item);
        item = item->GetNext();
    }
    return os;
}


void TQueue::push(const Square &&obj) {
    TQueueItem *other = new TQueueItem(obj);
    if (head != nullptr) {
        tail->next = other;
        tail = other;
    }
    else
        head = tail = other; //Если список не пуст, добавление первого элемента
    //other->SetNext(head);
    //head = other;
}
bool TQueue::empty() {
    return head == nullptr;
}
Square TQueue::pop() {
    Square result;
    if (head != nullptr) {
        TQueueItem *old_head = head;
        head = head->GetNext();
        result = old_head->GetSquare();
        old_head->SetNext(nullptr);
        delete(old_head);
    }
    else {
        std::cout << "Error. No element in queue\n";
    }
    return result;
}
TQueue::~TQueue() {
    std::cout << "Queue deleted\n";
    delete head;
}
