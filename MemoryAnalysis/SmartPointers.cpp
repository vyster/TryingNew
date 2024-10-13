
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


// By leveraging modern C++ features, you can write safer and more efficient code, minimizing manual memory management and reducing the likelihood of bugs related to improper memory handling.


