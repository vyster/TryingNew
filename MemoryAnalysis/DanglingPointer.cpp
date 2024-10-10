// Dangling Pointers
// Occurs when a pointer references memory that has already been deallocated.


// Example of a Dangling Pointer:


#include <iostream>

int* danglingExample() {
    int* ptr = new int(30);
    delete ptr; // Memory is deallocated
    return ptr; // ptr is now dangling
}

int main() {
    int* dPtr = danglingExample();
    std::cout << "Dangling pointer value: " << *dPtr << std::endl; // Undefined behavior
    return 0;
}


// Solution: After deleting a pointer, set it to nullptr to avoid accidental dereferencing.


// delete ptr;
// ptr = nullptr;