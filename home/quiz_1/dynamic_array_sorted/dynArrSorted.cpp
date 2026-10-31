#include <iostream>
#include "dynArrSorted.h"

template <class T>
dynArrSorted<T>::dynArrSorted(int capacity)
{
    this->capacity = capacity;
    data = new T[capacity];
    length = 0;
    this->currentPos = -1;
}

template <class T>
dynArrSorted<T>::dynArrSorted(const dynArrSorted &copy)
{
    this->capacity = copy.capacity;
    this->length = copy.length;
    this->data = new T[this->capacity];

    for (int i = 0; i < copy.length; i++)
    {
        this->data[i] = copy.data[i];
    }
    this->currentPos = copy.currentPos;
}

template <class T>
dynArrSorted<T>::~dynArrSorted()
{
    this->length = 0;
    delete[] data;
    data = nullptr;
    this->capacity = 0;
    this->currentPos = -1;
}

template <class T>
void dynArrSorted<T>::makeEmpty()
{
    this->length = 0;
    this->currentPos = -1;
}

template <class T>
bool dynArrSorted<T>::isEmpty()
{
    return this->length == 0;
}

template <class T>
bool dynArrSorted<T>::isFull()
{
    return this->length == this->capacity;
}

template <class T>
void dynArrSorted<T>::getNextItem(T &item)
{
    if (this->currentPos < this->length - 1)
    {
        this->currentPos++;
        item = this->data[currentPos];
    }
    else if (!isEmpty())
    {
        this->resetList();
        this->getNextItem(item);
    }
    else
    {
        std::cout << "List Empty";
    }
}

template <class T>
void dynArrSorted<T>::resetList()
{
    this->currentPos = -1;
}

template <class T>
void dynArrSorted<T>::insertItem(const T &item)
{

    if(isFull()){
        std::cout << "List is Full! Cannot Insert" << std::endl;
        return;
    } 

    int location = 0;
    bool moreToSearch = location < length;

    while (moreToSearch)
    {
        if (item > data[location])
        {
            location++;
            moreToSearch = location < length;
        }
        else if (item < data[location])
        {
            moreToSearch = false;
        }
    }

    for (int i = length; i > location; i--)
        {
            data[i] = data[i - 1];
        }
        
        data[location] = item;
        length++;
}

template <class T>
void dynArrSorted<T>::deleteItem(const T &item)
{
    for (int i = 0; i < length; i++)
    {
        if (item == data[i]){
            for(int j = i + 1; j < length; j++){
                data[j - 1] = data[j];
            }
            length--;
            break;
        }
    }
}

template <class T>
void dynArrSorted<T>::retrieveItem(T &item, bool &found)
{
    found = false;
    int beg = 0, end = length - 1;
    int mid;
    bool moreToSearch = beg <= end;
    
    while(moreToSearch && !found){
        mid = (beg + end)/ 2;
        if(item > data[mid]){
            beg = mid + 1;
            moreToSearch = beg <= end;
        }
        else if(item < data[mid]){
            end = mid - 1;
            moreToSearch = beg <= end;
        }
        else{
            found = true;
            item = data[mid];
        }
    }
}

template <class T>
void dynArrSorted<T>::getItemAtIndex(int index, T &item)
{
    if (index >= length || index < 0)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    else
    {
        item = data[index];
    }
}
