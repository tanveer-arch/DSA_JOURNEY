#include <iostream>
using namespace std;

// WRONG
class Demo {
    int value;           // Non-static
    static int count;    // Static

public:
    static void show() {
        cout << value;   // ERROR: cannot access non-static member
        cout << count;   // OK
    }
};

// Definition of static member
int Demo::count = 0;

// CORRECT
static void show() {
    cout << Demo::count;  // Use scope resolution
}

int main() {
    return 0;
}
