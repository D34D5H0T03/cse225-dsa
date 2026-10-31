#include <iostream>
#include "stacktype.h"

using namespace std;

int main(){

    StackType<int> stack;
    for(int i = 0; i < 5; i++){
        stack.push(i);
    }

    for(int i = 0; i < 5; i++){
        cout << stack.top() << '\t';
        stack.pop();
    }

    return 0;
}