#include <iostream>

void leakExample() {
    int* ptr = new int(50);
    std::cout << "Value: " << *ptr << std::endl;
    // Forgot to delete ptr
}

int main() {
    leakExample();
    // 'ptr' is never deleted, causing a memory leak
    return 0;
}
