#include <iostream>
#include "dynArr.h"

using namespace std;

int main(){
    // 1. Instantiate the templated class with a primitive type (int)
    std::cout << "--- Initializing Array ---" << std::endl;
    dynArr<int> list(5); 

    // 2. Test boundary insertions
    std::cout << "\n--- Testing Insertions ---" << std::endl;
    list.insertItem(10);
    list.insertItem(20);
    list.insertItem(30);
    list.insertItem(40);
    list.insertItem(50);
    list.insertItem(60); // Should trigger "Array is full"

    // 3. Test the ADT Retrieval
    std::cout << "\n--- Testing Retrieval ---" << std::endl;
    int searchVal = 30;
    bool isFound = false;
    list.retrieveItem(searchVal, isFound);
    
    if (isFound) {
        std::cout << "Successfully found: " << searchVal << std::endl;
    } else {
        std::cout << "Could not find: " << searchVal << std::endl;
    }

    // 4. Test Deletion (The O(1) swap-and-pop)
    std::cout << "\n--- Testing Deletion ---" << std::endl;
    list.deleteItem(20); // Deletes 20, swaps 50 into its place
    std::cout << "Item 20 deleted." << std::endl;

    // 5. Test Iteration (State Machine)
    std::cout << "\n--- Testing Iteration ---" << std::endl;
    list.resetList(); // Good practice before iterating
    
    int currentItem = 0;
    // We expect 4 items printed (10, 50, 30, 40) since 20 was deleted 
    // and replaced by the last element (50).
    while (!list.isEmpty()) {
        list.getNextItem(currentItem);
        std::cout << "Iterated value: " << currentItem << std::endl;
        
        // Break out manually to avoid infinite loop since we 
        // kept the recursive reset logic in getNextItem
        if (currentItem == 40) break; 
    }

    dynArr<int> list2(10);
    int buffer;

    cout << "Enter unsorted Values: ";
    for(int i = 0; i < 10; i++){
        cin >> buffer; 
        list2.insertItem(buffer);
    }
    cout << "Beofre Sort" << endl;
    for(int i = 0; i < 10; i++){
        int borrower;
        list2.getNextItem(borrower);
        cout << borrower << " , ";
    }
    list2.resetList();

    list2.insertionSort();

    cout << "After Sort" << endl;

    for(int i = 0; i < 10; i++){
        int borrower;
        list2.getNextItem(borrower);
        cout << borrower << " , ";
    }
    return 0;
}