#ifndef DYNARR_H
#define DYNARR_H

template <class T>
class dynArr{
    private: 
    T *data;
    int length;
    int currentPos;
    int capacity;

    public:
    dynArr(const dynArr& copy);
    dynArr(int capacity);
    ~dynArr();

    void makeEmpty();
    void insertItem(const T& item);
    void deleteItem(const T& item);
    void retrieveItem(T& item, bool& found);
    void getNextItem(T& item);
    void getItemAtIndex(int index, T& item);
    bool isEmpty();
    bool isFull();
    void resetList();
    void insertionSort();
    
};

#include "dynArr.cpp"
#endif