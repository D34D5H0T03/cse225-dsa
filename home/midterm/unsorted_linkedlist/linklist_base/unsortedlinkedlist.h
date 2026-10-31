#ifndef UNSORTEDLINKEDLIST_H_INCLUDED
#define UNSORTEDLINKEDLIST_H_INCLUDED

class FullList {};
class EmptyList {};

template<class ItemType>
class UnsortedType{
    struct NodeType{
        ItemType info;
        NodeType* next;
    };

    private:
        NodeType* listData;
        int length;
        NodeType* currentPos;
    public:
        UnsortedType();
        ~UnsortedType();
        bool isFull();
        bool isEmpty();
        int lengthIs();
        void makeEmpty();
        void retrieveItem(ItemType& item, bool& found);
        void insertItem(ItemType item);
        void deleteItem(ItemType item);
        void resetList();
        void getNextItem(ItemType& item);
};

#include "unsortedlinkedlist.cpp"
#endif