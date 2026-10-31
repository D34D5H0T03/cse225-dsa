#include "stacktype.h"
#include <iostream>

template <class itemType>
StackType<itemType>::StackType(){
    this->tos = -1;
    this->size = 0;
}

template <class itemType>
bool StackType<itemType>:: isEmpty(){
    return (size == 0);
}

template <class itemType>
bool StackType<itemType>:: isFull(){
    return (size == MAX_ITEMS);
}

template <class itemType>
int StackType<itemType>::length(){
    return size;
}

template <class itemType>
void StackType<itemType>::makeEmpty(){
    this->tos = -1;
    this->size = 0;
}

template <class itemType>
void StackType<itemType>::push(itemType item){
    if(isFull()){
        throw FullStack(); 
    }
    this->tos++;
    data[tos] = item;
    this->size++;
}

template <class itemType>
void StackType<itemType>::pop(){
    if(isEmpty()){
        throw EmptyStack(); 
    }
    this->tos--;
    this->size--;
}

template <class itemType>
itemType StackType<itemType>::top(){
    if(isEmpty()){
        throw EmptyStack(); 
    }
    return data[tos];
}



