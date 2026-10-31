#ifndef DYNARRSORTED_H
#define DYNARRSORTED_H

template <class T>
class dynArrSorted{
    private: 
    T *data;
    int length;
    int currentPos;
    int capacity;

    public:
    dynArrSorted(const dynArrSorted& copy);
    dynArrSorted(int capacity);
    ~dynArrSorted();

    void makeEmpty();
    void insertItem(const T& item);
    void deleteItem(const T& item);
    void retrieveItem(T& item, bool& found);
    void getNextItem(T& item);
    void getItemAtIndex(int index, T& item);
    bool isEmpty();
    bool isFull();
    void resetList();
    
};

#include "dynArrSorted.cpp"
#endif