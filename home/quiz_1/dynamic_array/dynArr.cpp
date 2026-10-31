#include <iostream>
#include "dynArr.h"

template <class T>
dynArr<T>::dynArr(int capacity){
    this->capacity = capacity;
    data = new T[capacity];
    length = 0;
    this->currentPos = -1;
}

template <class T>
dynArr<T>::dynArr(const dynArr& copy){
    this->capacity = copy.capacity;
    this->length = copy.length;
    this->data = new T[this->capacity];

    for(int i = 0; i < copy.length; i++){
        this->data[i] = copy.data[i];
    }
    this->currentPos = copy.currentPos;
}

template<class T>
dynArr<T>::~dynArr(){
    this->length = 0;
    delete [] data;
    data = nullptr;
    this->capacity = 0;
    this->currentPos = -1;
}

template <class T>
void dynArr<T>::makeEmpty(){
    this->length = 0;
    this->currentPos = -1;
}

template <class T>
bool dynArr<T>::isEmpty(){
    return this->length == 0;
}

template <class T>
bool dynArr<T>::isFull(){
    return this->length == this->capacity;
}

template <class T>
void dynArr<T>::getNextItem(T& item){
    if(this->currentPos < this->length - 1){
        this->currentPos++;
        item = this->data[currentPos];
    }
    else if(!isEmpty()){
        this->resetList();
        this->getNextItem(item);
    }
    else{
        std::cout << "List Empty";
    }
}

template <class T>
void dynArr<T>::resetList(){
    this->currentPos = -1;
}

template <class T>
void dynArr<T>::insertItem(const T& item){
    if(!isFull()){
        data[length] = item;
        length++;
    }
    else{
        std::cout << "Array is full, cannot insert!";
    }
}

template <class T>
void dynArr<T>::deleteItem(const T& item){
    bool found = false;
    for(int i = 0; i < this->length; i++){
        if(this->data[i] == item){
            found = true;
            data[i] = data[length - 1];
            length--;
            break;
        }
    }
    if(!found){
        std::cout << "Item not in list" << std::endl;
    }
}

template <class T>
void dynArr<T>::retrieveItem(T& item, bool& found){
    found = false;
     for(int i = 0; i < this->length; i++){
        if(this->data[i] == item){
            found = true;
            item = data[i];
            break;
        }
    }
}

template <class T>
void dynArr<T>::getItemAtIndex(int index, T& item){
    if(index >= length || index < 0){
        std::cout << "Invalid index" << std::endl;
        return;
    }
    else{
        item = data[index]; 
    }
}

template <class T>
void dynArr<T>::insertionSort(){
    for(int i = 1; i < length; i++){
        T key = this->data[i];
        int j = i - 1;

        while(j >= 0 && this->data[j] > key){
            this->data[j + 1] = data[j];
            j--;
        }
        this->data[j + 1] = key;
    }
}
