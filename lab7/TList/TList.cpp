#ifndef LAB6_TLIST_CPP
#define LAB6_TLIST_CPP
#include "TList.h"

template <class T>
TList<T>::TList() {
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}
template <class T>
TList<T>::~TList() {
    //if (_size > 0)
   //     this->Destroy();
}

template <class T>
bool TList<T>::IsEmpty() {
    return _size == 0;
}
template <class T>
size_t TList<T>::size() const{
    return _size;
}
template <class T>
TList<T>::TList(TList<T> &tCopy) {
    this->_head = nullptr;
    this->_tail = nullptr;

    for (auto ptr: tCopy) {
        //auto p = ptr.GetValue();
        //T *p = new T(ptr.GetValue())
        //std::shared_ptr<TListItem< T >> value_item (new TListItem<T>(&*ptr));
        this->PushBack(&*ptr);
    }
}
template <class T>
TList<T>& TList<T>::operator=(const TList<T> &tCopy) {
    this->Destroy();
    for (auto ptr: tCopy) {
        //auto p = ptr.GetValue();
        //this->PushBack(p);
    }
    return *this;
}

template <class T>
void TList<T>::Destroy() {
    std::cout << "Destroy List\n";
    //TListItem<T> *tmp = _head;
   // tmp->Destroy();
    _size = 0;
}
template <class T>
void TList<T>::PushBack(T *value){
    std::shared_ptr<TListItem< T >> value_item(new TListItem<T>(value));
    if (_head == nullptr) {
        _head = value_item;
        _tail = _head;
    } else {
        _tail->SetNext(value_item);
        _tail = value_item;
    }
    _size++;
}
template<class T>
bool TList<T>::Erase(T &findObject) {
    std::shared_ptr<TListItem<T>> ptr = _head, ptr2;
    for (;_size > 0 && ptr != _tail->GetNext(); ptr = ptr->GetNext()) {
        if (ptr->GetValue()->Area() == findObject.Area()) {
            if (ptr != _tail) {
                if (ptr == _head) {
                    _head = (ptr->GetNext());
                }
                else {
                    ptr2->SetNext(ptr->GetNext());
                }

            } else {
                if (_tail != _head) {
                    _tail = ptr2;
                } else {
                    _head = nullptr;
                    _tail = nullptr;
                }
            }
            _size--;
            break;
            std::cout << "Find Figure and deleted\n";
        }
        ptr2 = ptr;
    }
}

template<class T>
void TList<T>::Sort() {
    if (_size < 2) {
        return;
    }
    while (!IsSorted()) {
        for (auto tmp = begin(); tmp != end(); ++tmp)
        for (auto i = tmp; i != end(); ++i) {
            if (tmp->Area() > i->Area()) {
                std::cout << tmp->Area() << " " << i->Area() << std::endl;
                if (sizeof(**tmp)) {
                    Figure *k = new Square(&**tmp);

                    Erase(*k);
                    PushBack(k);
                    std::cout << "After shifting\n";
                    for (auto h:*this) {
                        std::cout << h->Area() << "\t";
                    }
                    std::cout << std::endl;
                }
                //std::cout << sizeof(**tmp);
                break;
            }
        }
    }
    return;
}

template<class T>
bool TList<T>::IsSorted() {
    if (_size == 1) return true;
    std::shared_ptr<TListItem<T>> ptr = _head, ptr2 = _head->GetNext();
    for (;ptr2 != _tail->GetNext(); ptr = ptr->GetNext(), ptr2 = ptr2->GetNext()) {
       if (ptr->GetValue()->Area() > ptr2->GetValue()->Area()) {
           return false;
       }
    }
    return true;
}

template <class T>
T& TList<T>::Front() {
    return _head->GetValue();
}
template<typename T>
T& TList<T>::Back() {
    return _tail->GetValue();
}
template <class T>
void TList<T>::PopFront() {
    if (!this->IsEmpty()) {
        std::shared_ptr<TListItem<T>> tmp = _head;
        _head = _head->GetNext();
        delete tmp;
        if (_size == 1) {
            delete _tail;
        }
        _size--;
    }
}

template <class T>
TIteratorList<TListItem<T>, T> TList<T>::begin() {
    return TIteratorList<TListItem<T>, T>(_head);
}

template <class T>
TIteratorList<TListItem<T>, T> TList<T>::end() {
    return TIteratorList<TListItem<T>, T>(_tail->GetNext());
}

//void TList<T>::PopBack() {
//    if (this->IsEmpty() != 0) {
//        _head = _head->next;
//        _size--;
//    }
//}
#endif