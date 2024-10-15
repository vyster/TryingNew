#include <iostream>
#include <algorithm>

class A
{
public:
	// Simple constructor that initializes the resource.
	explicit A(size_t length)
		: mLength(length), mData(new int[length])
	{
		std::cout << "A(size_t). length = "
			<< mLength << "." << std::endl;
	}

	// Destructor.
	~A()
	{
		std::cout << "~A(). length = " << mLength << ".";

		if (mData != NULL) {
			std::cout << " Deleting resource.";
			delete[] mData;  // Delete the resource.
		}

		std::cout << std::endl;
	}

	// Copy constructor.
	A(const A& other)
		: mLength(other.mLength), mData(new int[other.mLength])
	{
		std::cout << "A(const A&). length = "
			<< other.mLength << ". Copying resource with copy constructor." << std::endl;

		std::copy(other.mData, other.mData + mLength, mData);
	}

	// Copy assignment operator.
	A& operator=(const A& other)
	{
		std::cout << "operator=(const A&). length = "
			<< other.mLength << ". Copying resource with assignment." << std::endl;

		if (this != &other) {
			delete[] mData;  // Free the existing resource.
			mLength = other.mLength;
			mData = new int[mLength];
			std::copy(other.mData, other.mData + mLength, mData);
		}
		return *this;
	}

	// Move constructor.
	A(A&& other) : mData(NULL), mLength(0)
	{
		std::cout << "A(A&&). length = "
			<< other.mLength << ". Moving resource.\n";

		// Copy the data pointer and its length from the 
		// source object.
		mData = other.mData;
		mLength = other.mLength;

		// Release the data pointer from the source object so that
		// the destructor does not free the memory multiple times.
		other.mData = NULL;
		other.mLength = 0;
	}

	// Move assignment operator.
	A& operator=(A&& other)
	{
		std::cout << "operator=(A&&). length = "
			<< other.mLength << "." << std::endl;

		if (this != &other) {
			// Free the existing resource.
			delete[] mData;

			// Copy the data pointer and its length from the 
			// source object.
			mData = other.mData;
			mLength = other.mLength;

			// Release the data pointer from the source object so that
			// the destructor does not free the memory multiple times.
			other.mData = NULL;
			other.mLength = 0;
		}
		return *this;
	}

	// Retrieves the length of the data resource.
	size_t Length() const
	{
		return mLength;
	}

private:
	size_t mLength; // The length of the resource.
	int* mData;     // The resource.
};

#include <vector>

int main()
{
	std::vector<A> v;
	A aObj(25);       // lvalue
	v.push_back(std::move(aObj));  //calls push_back(T&&)

	std::cout << aObj.Length() << "\n";

	// Create a vector object and add a few elements to it.
	v.push_back(A(25));
	v.push_back(A(75));

	// Insert a new element into the second position of the vector.
	v.insert(v.begin() + 1, A(50));

	return 0;
}


// Rvalues and move semantics
// You need a C++11 compiler in order to perform these exercises.

// How to build and run
// If you save your code in a.cpp and use g++
// g++ --std=c++14 a.cpp -o a && ./a
// Exercise 1
// Add the following to a new class A:

// A private member _number which is a pointer to an int
// A public constructor that:
// Accepts an int as input argument
// Allocates an int on the heap and sets its value according to the input argument
// Points _number to the newly allocated int
// Prints to standard out what int value it has been initialized with
// A destructor that:
// Prints what value _number points to before it frees the associated memory
// Prints nullptr if _number does not point to an int
// class A shall generate the following output:

// class A constructor: 3
// class A destructor: 3
// Given this code:

// A a1{3}
// Exercise 2
// Add a copy constructor to class A so that it can handle the following code. Print out a line to indicate that the copy constructor has been used.

// A a1{3};
// A a2{a1};
// A a3{A{4}};
// The output shall be:

// class A constructor: 3
// class A copy constructor: 3
// class A constructor: 4
// class A destructor: 4
// class A destructor: 3
// class A destructor: 3
// Please note that the copy constructor was not used when creating a3 because of compiler optimization.

// Exercise 3
// Add a move constructor to class A. Print out a line to indicate that the move constructor has been used. The following code:

// vector<A> v;
// v.push_back(A{5});
// Should generate this output;

// class A constructor: 5
// class A move constructor: 5
// class A destructor: nullptr
// class A destructor: 5
// Exercise 4
// Add a copy assignment operator to class A. Print out a line to indicate that the copy assignment operator has been used.

// The following code:

// A a5{7};
// A a6{8};
// a6 = a5;
// Shall generate this output:

// class A constructor: 7
// class A constructor: 8
// class A copy assignment operator: 7
// class A destructor: 7
// class A destructor: 7
// Exercise 5
// Add a move assignment operator to class A. Print out a line to indicate that the move assignment operator has been used.

// The following code:

// A a7{9};
// a7 = A{10};
// Shall generate this output:

// class A constructor: 9
// class A constructor: 10
// class A move assignment operator: 10
// class A destructor: nullptr
// class A destructor: 10
// Exercise 6
// Use the move function to force move semantics to be used when creating a new instance of class A.

// The following code:

// A a8{11};
// A a9{move(a8)};
// Shall generate this output:

// class A constructor: 11
// class A move constructor: 11
// class A destructor: 11
// class A destructor: nullptr