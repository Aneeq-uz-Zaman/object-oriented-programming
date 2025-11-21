#include <iostream>
using namespace std;

int main() {
    int val1 = 2300, val2;
    cout << &val1 << endl;
    cout << &val2 << endl;

    int* myPointer;
    cout << sizeof(myPointer) << endl;

    myPointer = &val1;
    cout << *myPointer << endl;

    val2 = *myPointer;
    cout << val2 << endl;

    cout << myPointer << endl;
    cout << *myPointer << endl;

    myPointer = NULL;
    if (myPointer != NULL)
        cout << *myPointer << endl;
    else
        cout << "Pointer is NULL, cannot dereference." << endl;

    return 0;
}
