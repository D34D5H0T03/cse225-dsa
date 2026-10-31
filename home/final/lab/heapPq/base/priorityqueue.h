#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include "heap.h"

class FullQueue {};
class EmptyQueue {};

template <class element>
class PriorityQueue {
    public:
        PriorityQueue(int max);
        ~PriorityQueue(); 

        void makeEmpty();
        bool isEmpty();
        bool isFull();
        void enqueue(element newItem);
        void dequeue(element& item);

    private:
        int length;
        Heap<element> items;
        int maxItems;
};

#include "priorityqueue.cpp"
#endif // PRIORITYQUEUE_H_INCLUDED