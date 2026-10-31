#include <iostream>
#include "unsortedlinkedlist.h"

using namespace std;

int main(){
    UnsortedType<int> list;
    list.insertItem(3);
    list.insertItem(5);
    list.insertItem(31);
    list.insertItem(6);
    list.insertItem(5);
    list.insertItem(2);
    list.insertItem(8);
    list.insertItem(7);

    list.resetList();
    int length = list.lengthIs();
    for(int i = 0; i < length; i++){
        int buffer;
        list.getNextItem(buffer);
        cout << buffer << '\t';
    }
    return 0;
}