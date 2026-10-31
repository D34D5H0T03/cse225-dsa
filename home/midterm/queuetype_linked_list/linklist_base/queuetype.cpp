#include "queuetype.h"
#include <iostream>

template <class ItemType>
QueueType<ItemType>::QueueType(){
    this->front = nullptr;
    this->rear = nullptr;
}

template <class ItemType>
QueueType<ItemType>::~QueueType(){
    NodeType* tempPtr;

    while(front != nullptr){
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = nullptr;
}

template <class ItemType>
void QueueType<ItemType>::makeEmpty(){
    NodeType* tempPtr;

    while(front != nullptr){
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = nullptr;
}

template <class ItemType>
bool QueueType<ItemType>::isEmpty(){
    return (front == nullptr);
}

template <class ItemType>
bool QueueType<ItemType>::isFull(){
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
void QueueType<ItemType>::enqueue(ItemType item){
    if(isFull()){
        throw FullQueue();
    }
    else{
        NodeType* newNode;
        newNode = new NodeType;
        newNode->info = item;
        newNode->next = nullptr;
        if(rear == nullptr){
            front = newNode;
        }
        else{
            rear->next = newNode;
        }
        rear = newNode;
    }
}

template <class ItemType>
void QueueType<ItemType>::dequeue(ItemType& item){
    if(isEmpty()){
        throw EmptyQueue();
    }
    else{
        NodeType* tempPtr;
        tempPtr = front;

        item = front->info;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete tempPtr;
    }
}
