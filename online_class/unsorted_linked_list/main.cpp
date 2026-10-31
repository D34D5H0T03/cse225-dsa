#include <iostream>
#include "unsortedtype.h"

using namespace std;

int main(){
    UnsortedType<int> list1;

    list1.InsertItem(5);
    list1.InsertItem(6);
    list1.ResetList();
    int item = 0;
    list1.GetNextItem(item);
    cout << item;
    return 0;
}