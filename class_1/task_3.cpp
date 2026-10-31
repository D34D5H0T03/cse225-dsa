#include <iostream>

using namespace std;

string even_odd_check(int a);

int main(){
    cout << "Enter a Number: ";
    int a;
    cin >> a;

    cout << even_odd_check(a) << endl;

    return 0;
}

string even_odd_check(int a){
    return (a & 1) ? "Odd" : "Even";
}