#include <iostream>

int main() {
    int vals[3] = {100, 200, 300};
    int* pArr[3] = {&vals[2], &vals[0], &vals[1]};
    int** base = pArr;

    **(base + 1) += 50;
    **(base) -= 100;

    std::cout << vals[0] << " , " << vals[1] << " , " << vals[2] << std::endl;
    return 0;
}