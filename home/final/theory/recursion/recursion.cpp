#include <iostream>

using namespace std;

int puzzle(int base, int limit){
    if(base > limit){
        return -1;
    }
    else if(base == limit){
        return 1;
    }
    else{
        return base * puzzle(base + 1, limit);
    }
}

int func(int num){
    if(num == 0){
        return 0;
    }
    return num + func(num + 1);
}

int power(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    else{
        return base * power(base, exponent - 1);
    }
}

int Sum(int info[], int fromIndex, int toIndex){
    if (fromIndex <= toIndex)
        return info[fromIndex] + Sum(info, fromIndex + 1, toIndex);
    else
        return 0;
}

int main(){

    int info[] = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << Sum(info, 0, 7);
    cout << endl;

    return 0;
}