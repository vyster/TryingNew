
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "MyClass constructed with data = " << data << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass with data = " << data << " destructed" << std::endl;
    }

    void display() const {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

void uniquePtrExample() {
    // Create a unique_ptr managing a MyClass instance
    std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>(100);
    ptr1->display();

    // Transfer ownership to ptr2
    std::unique_ptr<MyClass> ptr2 = std::move(ptr1);
    if (!ptr1) {
        std::cout << "ptr1 is now empty." << std::endl;
    }
    ptr2->display();

    // ptr2 goes out of scope and the MyClass instance is automatically deleted
}

int main() {
    uniquePtrExample();
    return 0;
}