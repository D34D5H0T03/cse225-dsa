#include <iostream>
#include "dynArrSorted.h"

using namespace std;

int main(){
    
    dynArrSorted<int> list1(10);
    int buffer;
    cout << "Enter vaules for list: ";
    for(int i = 0; i < 11; i++){
        cin >> buffer;
        list1.insertItem(buffer);
    }

    list1.resetList();

    for(int i = 0; i < 10; i++){
        int borrower;
        list1.getNextItem(borrower);
        cout << borrower << " , ";
    }

    int search_key;
    cout << "Enter search key: ";
    cin >> search_key;

    bool found = false;

    list1.retrieveItem(search_key, found);

    if(!found){
        cout << '\n' << "Item Not in List" << endl;
    }
    else{
        cout << "Item found in list" << endl;
    }


    return 0;
}