
#include <iostream>

void stackExample() {
    int a = 10;          // Allocated on the stack
    double b = 20.5;     // Allocated on the stack
    std::cout << "a: " << a << ", b: " << b << std::endl;
    
} // 'a' and 'b' are automatically deallocated here

int main() {
    stackExample();
    return 0;
}
