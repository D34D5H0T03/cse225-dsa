#include <iostream>
#include <string>
using namespace std;

int main(){

    string name, department;
    int age;

    cout << "Enter name: ";
    getline(cin, name);
    cin.ignore();
    
    cout << '\n' << "Enter Department: ";
    getline(cin, department);
    cin.ignore();

    cout << '\n' << "Enter age: ";
    cin >> age;

    cout <<'\n' << "Name: " << name << '\n'
        << "Department: " << department << '\n'
        << "Age: " << age << endl;
    
    return 0;
}