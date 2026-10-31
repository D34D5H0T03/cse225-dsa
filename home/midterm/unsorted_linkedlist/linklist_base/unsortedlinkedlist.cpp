#include "unsortedlinkedlist.h"
#include <iostream>

template <class ItemType>
UnsortedType<ItemType>::UnsortedType(){
    this->listData = nullptr;
    this->length = 0;
    this->currentPos = nullptr;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType(){
    NodeType* tempPtr;
    while(listData != nullptr){
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template <class ItemType>
int UnsortedType<ItemType>::lengthIs(){
    return length;
}

template <class ItemType>
bool UnsortedType<ItemType>::isFull(){
    NodeType* location;
    try{
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc& exception){
        return true;
    }
}

template <class ItemType>
bool UnsortedType<ItemType>::isEmpty(){
    return length == 0;
}

template <class ItemType>
void UnsortedType<ItemType>::insertItem(ItemType item){
    if(isFull()){
        throw FullList();
    }
    else{
        NodeType* newNode;
        newNode = new NodeType;
        newNode->info = item;
        newNode->next = listData;
        listData = newNode;
        length++;
    }
}

template <class ItemType>
void UnsortedType<ItemType>::retrieveItem(ItemType& item, bool& found){
    if(isEmpty()){
        throw EmptyList();
    }
    NodeType* location;
    location = listData;
    found = false;
    bool moreToSearch = (location != nullptr);

    while(moreToSearch && !found){
        if(location->info == item){
            found = true;
        }
        else{
            location = location->next;
            moreToSearch = (location != nullptr);
        }
    }
}

template <class ItemType>
void UnsortedType<ItemType>::deleteItem(ItemType item){
    if(isEmpty()){
        throw EmptyList();
    }
    NodeType* location = listData;
    NodeType* tempPtr;

    if(item == listData->info){
        tempPtr = listData;
        listData = listData->next;
    }
    else{
        while((location->next)->info != item){
            location = location->next;
        }
        tempPtr = location->next;
        location->next = (location->next)->next;
    }

    delete tempPtr;
    this->length--;
}

template <class ItemType>
void UnsortedType<ItemType>::makeEmpty(){
    NodeType* tempPtr;
    while(listData != nullptr){
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template <class ItemType>
void UnsortedType<ItemType>::resetList(){
    this->currentPos = listData;
}

template <class ItemType>
void UnsortedType<ItemType>::getNextItem(ItemType& item){
    if(isEmpty()){
        throw EmptyList();
    }
    if(currentPos == nullptr){
        resetList();
    }
    item = currentPos->info;
    currentPos = currentPos->next;
}