#ifndef SORTEDLINKEDLIST_H_INCLUDED
#define SORTEDLINKEDLIST_H_INCLUDED

class FullList {};
class EmptyList {};

template<class ItemType>
class SortedType{
    struct NodeType{
        ItemType info;
        NodeType* next;
    };

    private:
        NodeType* listData;
        int length;
        NodeType* currentPos;
    public:
        SortedType();
        ~SortedType();
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

#include "sortedlinkedlist.cpp"
#endif