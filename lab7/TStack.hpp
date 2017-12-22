#ifdef TLIST_H

template <class T, class D> TStack<T, D>::TStack()
{
    head = std::make_shared<Node>(Node());
    count = 0;
}

template <class T, class D> TStack<T, D>::Node::Node()
{
    next = nullptr;
}

template <class T, class D> TStack<T, D>::Node::Node(const D& item)
{
    data.PushFront(item);
}

template <class T, class D> void TStack<T, D>::RemoveByType(const int& type)
{
    auto tmp = head;
    while(tmp) {
        if (tmp->data.GetLength()) {
            for (int i = 0; i < 5; ++i) {
                auto iter = tmp->data.begin();
                for (int k = 0; k < tmp->data.GetLength(); ++k) {
                    if (iter->type() == type) {
                        tmp->data.Pop(k + 1);
                        break;
                    }
                    ++iter;
                }
            }
        }
        tmp = tmp->next;
    }
}

template <class T, class D> void TStack<T, D>::Push(const D& item)
{
    auto tmp = head;
    if (tmp->data.GetLength() < 5) {
        tmp->data.PushFront(item);
    } else {
        auto newNode = std::make_shared<Node>(Node(item));
        newNode->next = head;
        head = newNode;
        ++count;
    }
}


template <class T, class D> void TStack<T, D>::Print()
{
    auto tmp = head;
    while (tmp) {
        if (tmp->data.GetLength()) {
            tmp->data.sort();
            for (const auto &i: tmp->data) {
                i->Print();
            }
            std::cout << std::endl;
        }
        tmp = tmp->next;
    }
}


template <class T, class D> void TStack<T, D>::RemoveBySquare(const double& sqr)
{
    auto tmp = head;
    while(tmp) {
        if (tmp->data.GetLength()) {
            for (int i = 0; i < 5; ++i) {
                auto iter = tmp->data.begin();

                for (int k = 0; k < tmp->data.GetLength(); ++k) {
                    if (iter->getSquare() < sqr) {
                        tmp->data.Pop(k + 1);
                        break;
                    }
                    ++iter;
                }
            }
        }
        tmp = tmp->next;
    }
}

#endif