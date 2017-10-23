#ifndef OOP_QUEUE_H
#define OOP_QUEUE_H
#include "Square.h"
#include "TQueueItem.h"


class TQueue {
public:
    TQueue();
    TQueue(const TQueue& obj);

    void push(const Square &&square);
    bool empty();
    Square pop();
    friend std::ostream& operator<<(std::ostream& os, const TQueue& obj);
    virtual ~TQueue();
private:
    TQueueItem *head;
    TQueueItem *tail;
};



#endif //OOP_QUEUE_H
