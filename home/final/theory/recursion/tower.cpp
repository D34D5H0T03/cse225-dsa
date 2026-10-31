#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // 1. Base Case
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // 2. Move n-1 disks from source to auxiliary (using destination as temporary storage)
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // 3. Move the largest disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // 4. Move the n-1 disks from auxiliary to destination (using source as temporary storage)
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int numDisks = 3; 
    // A = Source peg, C = Destination peg, B = Auxiliary peg
    towerOfHanoi(numDisks, 'A', 'C', 'B'); 
    return 0;
}