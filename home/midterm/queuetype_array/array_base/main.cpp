#include <iostream>
#include "queuetype.h"

using namespace std;

int main(){

    QueueType<int> queue(5);
    for (int i = 0; i < 5; i++)
    {
        queue.enqueue(i);
    }
    
    int length = queue.length();
    for (int i = 0; i < length; i++)
    {
        int item = 0;
        queue.dequeue(item);

        cout << item << '\t';
    }

    return 0;
}