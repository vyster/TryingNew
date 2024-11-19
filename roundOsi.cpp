#include <iostream>
#include <vector>

char f1[4] = { 'p', 'e', 'a', 'r' };
char f2[4] = { 'p', 'a', 'i', 'r' };
char f3[4] = { 'd', 'a', 'r', 'r' };
char f4[4] = { 'c', 'a', 'r', 'e' };
std::vector<int*> vec;

void print(char** f, size_t fLen, size_t ffLen, size_t val1, size_t val2)
{
    for (size_t ii = 0; 
        (ii + val1) < fLen && (ii + val2) < ffLen && (ii < 2); 
        ii++)
        std::cout << f[val1 + ii][val2 + ii];
    std::cout << '\n';
}

void createYear() {
    static int year = 1996;
    vec.push_back(&(++year)); // Increment year and push its address into the vector
}

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    int* start = &arr[0];
    int* end = &arr[1];
    std::cout << end - start;
    int i = 0b101;    // Binary literal for 5 
    int j = 4 & 2;    // Bitwise AND operation 100 010 -> 0
    std::cout << i << "\n";  // Output i
    std::cout << j << "\n";  // Output j
    createYear();
    createYear();
    createYear();
    char* f[] = { f1, f2, f3, f4 };

    print(f, 4, 4, 0, 0); // Starts from (0, 0)
    print(f, 4, 4, 3, 2); // Starts from (3, 2)

    for (const auto& val : vec) {
        std::cout << *val << '\n'; // Dereference pointer to print the value
    }

    return 0;
}