// 3. Double Deletion :


// Occurs when delete is called more than once on the same memory address, leading to undefined behavior.


// Example of Double Deletion:



#include <iostream>

int main() {
    int* ptr = new int(40);
    delete ptr;
    delete ptr; // Undefined behavior: double deletion
    return 0;
}

// Solution: Set the pointer to nullptr after deletion to prevent multiple deletions.


// delete ptr;
// ptr = nullptr;

