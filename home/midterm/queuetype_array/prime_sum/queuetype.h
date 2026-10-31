#ifndef QUEUETYPE_H_INCLUDED
#define QUEUETYPE_H_INCLUDED

class FullQueue
{};
class EmptyQueue
{};

template <class ItemType>
class QueueType
{
private:
    int front;
    int rear;
    ItemType* data;
    int maxqueue;
public:
    QueueType();
    QueueType(int max);
    ~QueueType();
    void makeEmpty();
    bool isEmpty();
    bool isFull();
    void enqueue(ItemType newItem);
    void dequeue(ItemType& item);
    int length();
};


#include "queuetype.cpp"
#endif