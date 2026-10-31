#include "heap.h"

template <class element>
void swap(element& one, element& two) {
    element temp;
    temp = one;
    one = two;
    two = temp;
}

template <class element>
void Heap<element>::reheapUp(int root, int bottom) {
    int parent;
    
    if (bottom > root) { 
        parent = (bottom - 1) / 2;
        
        if (elements[parent] < elements[bottom]) {
            swap(elements[parent], elements[bottom]);
            reheapUp(root, parent);
        }
    }
}

template <class element>
void Heap<element>::reheapDown(int root, int bottom) {
    int maxChild;
    int leftChild = root * 2 + 1;
    int rightChild = root * 2 + 2;

    if (leftChild <= bottom) { 
    
        if (leftChild == bottom) { 
            maxChild = leftChild;
        } 
        else { 
            if (elements[leftChild] <= elements[rightChild]) {
                maxChild = rightChild;
            } 
            else {
                maxChild = leftChild;
            }
        }

        if (elements[root] < elements[maxChild]) {
            swap(elements[root], elements[maxChild]);
            reheapDown(maxChild, bottom);
        }
    }
}