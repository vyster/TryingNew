// Memory management is a critical aspect of C++ programming, allowing you to control how memory is allocated, used, and deallocated in your applications. Proper memory management ensures efficient use of resources, prevents memory leaks, and avoids undefined behaviors like dangling pointers or double deletions.


// In C++, memory management can be broadly categorized into:


// Automatic (Stack) Memory Management
// Dynamic (Heap) Memory Management
// Resource Acquisition Is Initialization (RAII)
// Smart Pointers
// Let's delve into each of these concepts with C++ code examples.


// 1. Automatic (Stack) Memory Management :


// Variables declared inside a function are typically allocated on the stack. The memory is automatically managed; it’s allocated when the variable is declared and deallocated when the variable goes out of scope.


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

#include


void stackExample() {
int a = 10; // Allocated on the stack
double b = 20.5; // Allocated on the stack
std::cout << "a: " << a << ", b: " << b << std::endl;
} // 'a' and 'b' are automatically deallocated here


int main() {
stackExample();
return 0;
}


// 2. Dynamic (Heap) Memory Management


// Dynamic memory is allocated on the heap using operators like new and new[] and must be manually deallocated using delete and delete[]. Failure to deallocate memory leads to memory leaks.


// Example:


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
// Output:


// Value pointed by ptr: 42
// arr[0] = 0
// arr[1] = 10
// arr[2] = 20
// arr[3] = 30
// arr[4] = 40
// Explanation:


// new int allocates memory for a single integer on the heap.
// new int[5] allocates memory for an array of 5 integers on the heap.
// delete ptr deallocates the memory allocated for the single integer.
// delete[] arr deallocates the memory allocated for the array.
// Important: Always pair new with delete and new[] with delete[] to avoid undefined behavior.
// 3. Resource Acquisition Is Initialization (RAII)


// RAII is a programming idiom where resource allocation is tied to object lifetime. Resources are acquired during object creation (constructor) and released during object destruction (destructor). This ensures that resources are properly released, even in the presence of exceptions.


#include <iostream>
#include <fstream>
#include <string>

class FileHandler {
public:
    FileHandler(const std::string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Cannot open file.");
        }
        std::cout << "File opened: " << filename << std::endl;
    }

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed." << std::endl;
        }
    }

    void write(const std::string& data) {
        if (file.is_open()) {
            file << data << std::endl;
        }
    }

private:
    std::ofstream file;
};

int main() {
    try {
        FileHandler fh("example.txt");
        fh.write("Hello, RAII!");
        // No need to explicitly close the file
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
// Explanation:


// FileHandler's constructor opens a file.
// The destructor ensures that the file is closed when the FileHandler object goes out of scope.
// Even if an exception is thrown, the destructor is called, preventing resource leaks.
// 4. Smart Pointers :


// Smart pointers are template classes provided by the C++ Standard Library to manage dynamic memory automatically. They help prevent memory leaks and other memory-related issues by handling the deallocation of memory when it's no longer needed.


// C++ provides several smart pointers, including:


// std::unique_ptr: Represents exclusive ownership of a resource.
// std::shared_ptr: Represents shared ownership of a resource with reference counting.
// std::weak_ptr: A non-owning reference to a resource managed by std::shared_ptr.
// Example-1: Using std::unique_ptr:


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


// Output :


// MyClass constructed with data = 100
// Data: 100
// ptr1 is now empty.
// Data: 100
// MyClass with data = 100 destructed

// Explanation:


// std::unique_ptr manages the lifetime of the MyClass instance.
// Ownership can be transferred using std::move.
// When the unique_ptr goes out of scope, it automatically deletes the managed object.
// Example-2: Using std::shared_ptr:


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

// Output:


// MyClass constructed with data = 200
// Data: 200
// Reference count: 2
// Reference count after ptr2 is destroyed: 1
// Data: 200
// MyClass with data = 200 destructed

// Explanation:


// std::shared_ptr allows multiple pointers to share ownership of the same resource.
// The resource is deallocated when the last std::shared_ptr referencing it is destroyed.
// use_count() returns the number of std::shared_ptr instances sharing ownership.
// Common Memory Management Issues


// 1. Memory Leaks
// Occurs when dynamically allocated memory is not deallocated. Over time, this can consume all available memory, leading to application crashes.


// Example of a Memory Leak:


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

// Solution: Use smart pointers or ensure that every new has a corresponding delete.


// 2. Dangling Pointers
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


// Best Practices for Memory Management in C++


// Prefer Automatic Storage:
// Use stack allocation whenever possible as it's automatically managed and more efficient.


// Use RAII:
// Encapsulate resource management within classes to ensure resources are released when objects go out of scope.


// Leverage Smart Pointers:
// Utilize std::unique_ptr for exclusive ownership.
// Use std::shared_ptr when multiple ownership is needed.
// Apply std::weak_ptr to break reference cycles in std::shared_ptr.


// Avoid Manual new and delete:
// Prefer factory functions like std::make_unique and std::make_shared to create smart pointers.


// Initialize Pointers:
// Always initialize pointers. Uninitialized pointers can lead to undefined behaviors.


// Use nullptr:
// Use nullptr instead of NULL or 0 to represent null pointers, enhancing type safety.


// Be Mindful of Object Ownership:
// Clearly define which part of your code owns a resource to prevent leaks and dangling pointers.


// Avoid Raw new and delete in Modern C++:
// Modern C++ provides smart pointers and standard library containers that manage memory automatically.


// Advanced Example: Using Smart Pointers with Containers


// Combining smart pointers with containers like std::vector can help manage dynamic collections of objects.


#include <iostream>
#include <memory>
#include <vector>

class Widget {
public:
    Widget(int id) : id(id) {
        std::cout << "Widget " << id << " created." << std::endl;
    }

    ~Widget() {
        std::cout << "Widget " << id << " destroyed." << std::endl;
    }

    void display() const {
        std::cout << "Widget ID: " << id << std::endl;
    }

private:
    int id;
};

int main() {
    // Vector of unique_ptr to Widgets
    std::vector<std::unique_ptr<Widget>> widgets;

    // Adding Widgets to the vector
    widgets.emplace_back(std::make_unique<Widget>(1));
    widgets.emplace_back(std::make_unique<Widget>(2));
    widgets.emplace_back(std::make_unique<Widget>(3));

    // Display Widgets
    for (const auto& widget : widgets) {
        widget->display();
    }

    // Widgets are automatically destroyed when the vector goes out of scope
    return 0;
}

// Output:


// Widget 1 created.
// Widget 2 created.
// Widget 3 created.
// Widget ID: 1
// Widget ID: 2
// Widget ID: 3
// Widget 3 destroyed.
// Widget 2 destroyed.
// Widget 1 destroyed.

// Explanation:


// std::vector holds std::unique_ptr to Widget objects.
// Widgets are automatically destroyed in reverse order of their creation when the vector goes out of scope.
// This approach prevents memory leaks and ensures proper resource management.
// Summary :


// Effective memory management in C++ involves understanding how memory is allocated and deallocated, using tools like RAII and smart pointers to manage resources automatically, and adhering to best practices to prevent common issues like memory leaks, dangling pointers, and double deletions.


// By leveraging modern C++ features, you can write safer and more efficient code, minimizing manual memory management and reducing the likelihood of bugs related to improper memory handling

