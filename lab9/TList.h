#ifndef TLIST_H
#define TLIST_H

#include <cstdint>
#include <future>
#include <mutex>
#include <thread>
#include <functional>
#include "trapeze.h"
#include "square.h"
#include "rectangle.h"
#include "TIterator.h"
#include "TListItem.h"

template <class T>
class TList
{
public:
    TList();
    void Push(const std::shared_ptr<T> &obj);
    void PushFirst(const std::shared_ptr<T> &obj);
    const bool IsEmpty() const;
    uint32_t GetLength();
    std::shared_ptr<T> Pop(int32_t ind);
    void Del();

    TIterator<TListItem<T>,T> begin();
    TIterator<TListItem<T>,T> end();

    template <class A> friend std::ostream& operator<<(std::ostream &os, const TList<A> &list);
    virtual ~TList();

private:
    uint32_t length;
    std::shared_ptr<TListItem<T>> head;
    std::mutex mutex;

    void PushLast(const std::shared_ptr<T> &obj);
    void PushAtIndex(const std::shared_ptr<T> &obj, int32_t ind);
    std::shared_ptr<T> PopFirst();
    std::shared_ptr<T> PopLast();
    std::shared_ptr<T> PopAtIndex(int32_t ind);
};

#endif
