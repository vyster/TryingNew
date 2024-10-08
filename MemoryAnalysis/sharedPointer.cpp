
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

void sharedPtrExample() {
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>(200);
    {
        std::shared_ptr<MyClass> ptr2 = ptr1; // Shared ownership
        ptr2->display();
        std::cout << "Reference count: " << ptr1.use_count() << std::endl;
    } // ptr2 goes out of scope

    std::cout << "Reference count after ptr2 is destroyed: " << ptr1.use_count() << std::endl;
    ptr1->display();
} // ptr1 goes out of scope, and the MyClass instance is deleted

int main() {
    sharedPtrExample();
    return 0;
}