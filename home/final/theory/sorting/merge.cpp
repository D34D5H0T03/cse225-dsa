#include <iostream>

using namespace std;

template <class Item>
void merge(Item items[], int leftFirst, int leftLast, int rightFirst, int rightLast, int max){
    Item tempArr[max];
    int index = leftFirst;
    int saveFirst = leftFirst;

    while((leftFirst <= leftLast) && (rightFirst <= rightLast)){
        if(items[leftFirst] < items[rightFirst]){
            tempArr[index] = items[leftFirst];
            index++;
            leftFirst++;
        }
        else{
            tempArr[index] = items[rightFirst];
            index++;
            rightFirst++;
        }
    }

    while(leftFirst <= leftLast){
        tempArr[index] = items[leftFirst];
        index++;
        leftFirst++;
    }
    while(rightFirst <= rightLast){
            tempArr[index] = items[rightFirst];
            index++;
            rightFirst++;
    }

    for(int i = saveFirst; i <= rightLast; i++){
        items[i] = tempArr[i];
    }
}

template <class Item>
void mergeSort(Item items[], int first, int last, int maxSize){
    if(first < last){
        int mid = first + (last - first) / 2;

        mergeSort(items, first, mid, maxSize);
        mergeSort(items, mid + 1, last, maxSize);

        merge(items, first, mid, mid + 1, last, maxSize);
    }
}


int main(){
    int arr[] = {3, 5, 4, 7, 2, 1, 8, 6, 9, 0, 12, 341, 21, 412, 32};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, size - 1, size);

    for(int i = 0; i < size; i++){
        cout << arr[i] << '\t';
    }
    cout << endl;

    return 0;
}