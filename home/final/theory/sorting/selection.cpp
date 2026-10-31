#include <iostream>

using namespace std;

template <class Item>
void Swap(Item& a, Item& b){
    Item temp = a;
    a = b;
    b = temp;
}

template <class Item>
void selectionSort(Item items[], int length){
    for(int i = 0; i < length - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < length; j++){
            if(items[j] < items[minIndex]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            swap(items[i], items[minIndex]);
        }
    }
}

template <class Item>
void mergeSortIterative(Item items[], int length) {
    // currSize tracks the size of sub-arrays being merged (1, 2, 4, 8, etc.)
    for (int currSize = 1; currSize < length; currSize *= 2) {
        
        // leftStart iterates through the array to find the starting point of each pair
        for (int leftStart = 0; leftStart < length - 1; leftStart += 2 * currSize) {
            
            int leftLast = leftStart + currSize - 1;
            int rightFirst = leftStart + currSize;
            
            // rightLast is either the end of the calculated right half, or the end of the array
            int rightLast = min(leftStart + 2 * currSize - 1, length - 1);

            // Only merge if there is actually a right sub-array to merge with
            if (rightFirst < length) {
                merge(items, leftStart, leftLast, rightFirst, rightLast);
            }
        }
    }
}

int main(){
    int arr[] = {3, 5, 4, 7, 2, 1, 8, 6, 9, 0, 12, 341, 21, 412, 32};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    selectionSort(arr, size);

    for(int i = 0; i < size; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;

    return 0;
}