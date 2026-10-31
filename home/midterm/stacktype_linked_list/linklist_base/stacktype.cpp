#include "stacktype.h"
#include <iostream>

template <class ItemType>
StackType<ItemType>::StackType(){
    topPtr = nullptr;
}

template <class ItemType>
StackType<ItemType>::~StackType(){
    NodeType* tempPtr;

    while(topPtr != nullptr){
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

template <class ItemType>
bool StackType<ItemType>::isEmpty(){
    return topPtr == nullptr;
}

template <class ItemType>
bool StackType<ItemType>::isFull(){
    NodeType* location;
    try{
        location = new NodeType;
        delete location;
        return false;
    }catch(std::bad_alloc& exception){
        return true;
    }
}

template <class ItemType>
void StackType<ItemType>::push(ItemType item){
    if(this->isFull()){
        throw FullStack();
    }
    else{
        NodeType* location;
        location = new NodeType;
        location->info = item;
        location->next = topPtr;
        topPtr = location;
    }
}

template <class ItemType>
ItemType StackType<ItemType>::top(){
    if(this->isEmpty()){
        throw EmptyStack();
    }
    else{
        return topPtr->info;
    }
}

template <class ItemType>
void StackType<ItemType>::pop(){
    if(this->isEmpty()){
        throw EmptyStack();
    }
    else{
        NodeType* tempPtr;
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}