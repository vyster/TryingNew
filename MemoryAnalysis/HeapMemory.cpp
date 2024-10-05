#include <iostream>

void heapExample() {
    // Single object allocation
    int* ptr = new int; // Allocate memory for an integer
    *ptr = 42;
    std::cout << "Value pointed by ptr: " << *ptr << std::endl;
    delete ptr; // Deallocate memory

    // Array allocation
    int* arr = new int[5]; // Allocate memory for an array of 5 integers
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
    delete[] arr; // Deallocate array memory
}

int main() {
    heapExample();
    return 0;
}