#include "sortedlinkedlist.h"
#include <iostream>

template <class ItemType>
SortedType<ItemType>::SortedType(){
    this->listData = nullptr;
    this->currentPos = nullptr;
    this->length = 0;
}

template <class ItemType>
SortedType<ItemType>::~SortedType(){
    NodeType* location;

    while(listData != nullptr){
        location = listData;
        listData = listData->next;
        delete location;
    }
    this->currentPos = nullptr;
    this->length = 0;
}

template <class ItemType>
void SortedType<ItemType>::makeEmpty(){
    NodeType* location;

    while(listData != nullptr){
        location = listData;
        listData = listData->next;
        delete location;
    }
    this->currentPos = nullptr;
    this->length = 0;
}

template <class ItemType>
bool SortedType<ItemType>::isEmpty(){
    return length == 0;
}

template <class ItemType>
bool SortedType<ItemType>::isFull(){
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
int SortedType<ItemType>::lengthIs(){
    return length;
}

template <class ItemType>
void SortedType<ItemType>::insertItem(ItemType item){
    if(isFull()){
        throw FullList();
    }
    NodeType* location = listData;

    NodeType* newNode = new NodeType;
    newNode->info = item;

    NodeType* predLoc = nullptr;

    bool moreToSearch = (location != nullptr);

    while(moreToSearch){
       if(location->info < item){
        predLoc = location;
        location = location->next;
        moreToSearch = (location != nullptr)
       }
       else{
        moreToSearch = false;
       }
    }

    if(predLoc == nullptr){
        newNode->next = listData;
        listData = newNode;
    }
    else{
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

template <class ItemType>
void SortedType<ItemType>::retrieveItem(ItemType& item, bool& found){
    if(isEmpty()){
        throw EmptyList();
    }

    NodeType* location = listData;
    found = false;
    bool moreToSearch = (location != nullptr);

    while(moreToSearch && !found){
        if(location->info == item){
            found = true;
        }
        else if(location->info < item){
            location = location->next;
            moreToSearch = location != nullptr;
        }
        else{
            moreToSearch = false;
        }
    }
}

template <class ItemType>
void SortedType<ItemType>::deleteItem(ItemType item){
    if(isEmpty()){
        throw EmptyList();
    }
    NodeType* location = listData;
    NodeType* tempLocation = nullptr;

    if(listData->info == item){
        tempLocation = location;
        listData = listData->next;
        delete tempLocation;
    }
    else{
        while((location->next)->info != item){
            location = location->next;
        }
        tempLocation = location->next;
        location->next = (location->next)->next;
        delete tempLocation;
    }
    length--;
}

template <class ItemType>
void SortedType<ItemType>::resetList(){
    currentPos = listData;
}

template <class ItemType>
void SortedType<ItemType>::getNextItem(ItemType& item){
    if(isEmpty()){
        throw EmptyList();
    }
    if(currentPos == nullptr){
        resetList();
    }

    item = currentPos->info;
    currentPos = currentPos->next;
}

