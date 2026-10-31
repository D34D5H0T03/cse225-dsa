#include "queuetype.h"

template <class ItemType>
QueueType<ItemType>::QueueType(){
    this->maxqueue = 501;
    this->front = maxqueue - 1;
    this->rear = maxqueue - 1;
    this->data = new ItemType[maxqueue];
}

template <class ItemType>
QueueType<ItemType>::QueueType(int max){
    this->maxqueue = max + 1;
    this->front = maxqueue - 1;
    this->rear = maxqueue - 1;
    this->data = new ItemType[maxqueue];
}

template <class ItemType>
QueueType<ItemType>::~QueueType(){
    delete [] data;
    this->data = nullptr;
}

template <class ItemType>
void QueueType<ItemType>::makeEmpty(){
    this->front = this->maxqueue - 1;
    this->rear = this->maxqueue - 1;
}

template <class ItemType>
bool QueueType<ItemType>::isEmpty(){
    return (front == rear);
}

template <class ItemType>
bool QueueType<ItemType>::isFull(){
    return ((rear + 1) % maxqueue == front);
}

template <class ItemType>
int QueueType<ItemType>::length(){
    return (rear - front + maxqueue) % maxqueue;
}

template <class ItemType>
void QueueType<ItemType>::enqueue(ItemType item){
    if(isFull()){
        throw FullQueue();
    }
    rear = (rear + 1) % maxqueue;
    this->data[rear] = item;
}

template <class ItemType>
void QueueType<ItemType>::dequeue(ItemType& item){
    if(isEmpty()){
        throw EmptyQueue();
    }
    front = (front + 1) % maxqueue;
    
    item = this->data[front];
}
