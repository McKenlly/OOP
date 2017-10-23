#ifndef OOP_TQUEUEITEM_H
#define OOP_TQUEUEITEM_H
#include "Square.h"


class TQueueItem {
public:
    TQueueItem(const Square& square);
    TQueueItem(const TQueueItem& orig);
    friend std::ostream& operator<<(std::ostream& os, const TQueueItem& obj);

    TQueueItem* SetNext(TQueueItem* next);
    TQueueItem* GetNext();
    Square GetSquare() const;

    virtual ~TQueueItem();
public:
    Square square;
    TQueueItem *next;
};



#endif //OOP_TQUEUEITEM_H
