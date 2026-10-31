#include "priorityqueue.h"
#include "heap.h"

template <class element>
PriorityQueue<element>::PriorityQueue(int max) {
    maxItems = max;
    items.elements = new element[max]; 
    length = 0;
}

template <class element>
PriorityQueue<element>::~PriorityQueue() {
    delete [] items.elements;
}

template <class element>
void PriorityQueue<element>::makeEmpty() {
    length = 0;
}

template <class element>
bool PriorityQueue<element>::isFull() {
    return length == maxItems;
}

template <class element>
bool PriorityQueue<element>::isEmpty() {
    return length == 0;
}

template <class element>
void PriorityQueue<element>::enqueue(element newItem) {
    if (length == maxItems) {
        throw FullQueue();
    } else {
        length++;
        items.elements[length - 1] = newItem;   
        items.reheapUp(0, length - 1);       
    }
}

template <class element>
void PriorityQueue<element>::dequeue(element& item) {
    if (length == 0) {
        throw EmptyQueue();
    } else {
        item = items.elements[0];               
        items.elements[0] = items.elements[length - 1]; 
        length--;                                 
        items.reheapDown(0, length - 1);         
    }
}