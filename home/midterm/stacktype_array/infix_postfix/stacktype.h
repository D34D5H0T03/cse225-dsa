#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

const int MAX_ITEMS = 10;

class FullStack{};
class EmptyStack{};

template <class itemType>
class StackType
{
private:
    int tos;
    itemType data[MAX_ITEMS];
    int size;

public:
    StackType();
    bool isFull();
    int length();
    bool isEmpty();
    void makeEmpty();
    void push(itemType item);
    void pop();
    itemType top();
};


#include "stacktype.cpp"
#endif