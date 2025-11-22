#include <iostream>
using namespace std;

class Parent {
public:
    void message() {
        cout << "My name is shan Ali " << endl;
    }
};

class Child : public Parent {
public:
    void show() {
        cout << "I am student of BSCS" << endl;
    }
};

int main() {
    Child c;
    c.message();  
    c.show();    
}

