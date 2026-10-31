#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

template <class element>
void swap(element& one, element& two);

template <class element>
struct Heap {
    element* elements; 
    int numElements;  

    void reheapDown(int root, int bottom);
    void reheapUp(int root, int bottom);
};

#include "heap.cpp"
#endif 