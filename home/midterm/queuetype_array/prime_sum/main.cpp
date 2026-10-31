#include <iostream>
#include "queuetype.h"

using namespace std;

struct State{
    int sum;
    int cost;
};

int getMinimumPrimes(int target){
    if(target == 0) return 0;

    int primes[] = {2, 3, 5};

    State startState;
    startState.sum = 0;
    startState.cost = 0;

    QueueType<State> q(target);
    bool* visited = new bool[target + 1]();

    q.enqueue(startState);
    visited[0] = true;

    while(!q.isEmpty()){
        State currentState;
        q.dequeue(currentState);

        if(currentState.sum == target){
            delete [] visited;
            visited = nullptr;
            return currentState.cost;
        }
        for(int i = 0; i < 3; i++){
            int nextSum = currentState.sum + primes[i];

            if(nextSum <= target && !visited[nextSum]){
                State nextState;
                nextState.sum = nextSum;
                nextState.cost = currentState.cost + 1;

                q.enqueue(nextState);
                visited[nextSum] = true;
            }
        }
    }

    delete[] visited;
    return -1;
}

int main(){
    int n = 987;

    cout << getMinimumPrimes(n) << endl;
    return 0;
}