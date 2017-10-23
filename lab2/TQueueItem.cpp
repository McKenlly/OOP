#include "TQueueItem.h"
#include <iostream>

TQueueItem::TQueueItem(const Square& square) {
    this->square = square;
    this->next = nullptr;
    //std::cout << "Queue item: created\n";
}
TQueueItem::TQueueItem(const TQueueItem& orig) {
    this->square = orig.square;
    this->next = orig.next;
   // std::cout << "Queue item: copied\n";
}
TQueueItem* TQueueItem::SetNext(TQueueItem *next) {
    TQueueItem* old = this->next;
    this->next = next;
    return old;
}
TQueueItem* TQueueItem::GetNext() {
    return this->next;
}
Square TQueueItem::GetSquare() const {
    return this->square;
}
TQueueItem::~TQueueItem() {
    //std::cout << "Queue item: deleted\n";
    delete next;
}

std::ostream& operator<<(std::ostream& os, const TQueueItem& obj) {
    os << "[" << obj.square << "]" << std::endl;
    return os;
}
