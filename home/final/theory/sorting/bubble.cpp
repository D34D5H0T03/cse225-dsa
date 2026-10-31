#include <iostream>

using namespace std;

template <class Item>
void Swap(Item& a, Item& b){
    Item temp = a;
    a = b;
    b = temp;
}

template <class Item>
void bubbleSort(Item items[], int length){
    for(int i = 0; i < length - 1; i++){
        for(int j = 0; j < length - i - 1; j++){
            if(items[j] < items[j + 1]){
                Swap(items[j], items[j + 1]);
            }
        }
    }
}

int main(){
    int arr[] = {3, 5, 4, 7, 2, 1, 8, 6, 9, 0, 12, 341, 21, 412, 32};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, size);

    for(int i = 0; i < size; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;

    return 0;
}