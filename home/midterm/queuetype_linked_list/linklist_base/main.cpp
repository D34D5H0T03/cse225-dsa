#include <iostream>
#include "queuetype.h"

using namespace std;

int main(){
    QueueType<int> queue;

    for(int i = 0; i < 5; i++){
        queue.enqueue(i);
    }

    for(int i = 0; i < 5; i++){
        int buffer;
        queue.dequeue(buffer);
        cout << buffer << '\t';
    }
    return 0;
}