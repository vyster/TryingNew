//https://www.geeksforgeeks.org/data-races-in-cpp/ 
//https://dev.to/shreyosghosh/multithreading-handling-race-conditions-and-deadlocks-in-c-4ae4




#include <iostream>
using namespace std;

void logicT1(int &x, int &y){

    //t.unlock()
    cout<<(x<y?y=0);

}
void logicT2(int &x, int &y){
    //
    cout<<(x>y?x=0);
    t.lock();
}

int main() {
    
    // t1 t2
    int a;
    int b;
    std::thread t1(logicT1,a,b);
    std::thread t2(logicT2,a,b);
    t1.join();
    t2.join();
    for(int i =0 ;i<10<i++)
    {
        if(i%2==0)
            t1
        else 
    }
    // join these threads

    //if 

    return 0;
}





Data Races in C++
Last Updated : 19 Jun, 2024
In C++, data race is a commonly occurring problem in concurrent programming. It occurs when two or more threads concurrently access the same memory location, and at least one of the accesses is a write. Data races lead to undefined behaviour, which means the program can exhibit unpredictable behavior, crash, or produce incorrect results. Preventing data races is crucial for writing safe and reliable concurrent programs.

In this article we will discuss what are data races, what are its causes and how we can prevent them from happening in our program.

What Causes Data Race in C++?
There are many possible causes of the data races on C++. It can occur due to the concurrent execution of threads without proper synchronization. In a multi-threaded environment, if threads do not coordinate their access to shared data, it can result in:

Inconsistent Data: Different threads might read different values from the same variable.
Corrupted Data: One thread might overwrite the data being used by another thread.
Example of Data Race in C++
The following program demonstrate the data race condition in a concurrent program:



1
// C++ Program to illustrate the data race condition
2
#include <iostream>
3
#include <thread>
4
using namespace std;
5
​
6
// Global counter variable
7
int counter = 0;
8
​
9
// Function to increment the counter
10
void increment()
11
{
12
    for (int i = 0; i < 100000; ++i) {
13
        ++counter;
14
    }
15
}
16
​
17
int main()
18
{
19
    // Create two threads that run the increment function
20
    // concurrently
21
    thread t1(increment);
22
    thread t2(increment);
23
​
24
    // Wait for both threads to finish
25
    t1.join();
26
    t2.join();
27
​
28
    // Print the final counter value
29
    cout << "Counter value: " << counter << endl;
30
    return 0;
31
}
Output 1

Counter value: 146377
Output 2

Counter value: 200000
As seen from the above program, we may get different value in every execution. This is due to the data race condition.

How to Avoid Data Race in C++?
We can prevent the data races from happening by synchronizing the thread using various synchronizing primitives available in C++. Some of the are as follows:

Mutex
Atomic Operations
Condition Variable
1. Preventing Data Race using Mutexes
A std::mutex can be used to ensure mutual exclusion, meaning that only one thread can access the critical section (shared data) of code at a time. Locking a mutex before accessing shared data ensures that only one thread can access the data at a time. We can unlock it when we are done working on it.

Syntax

std::mutex name        // creating mutex

// In the callable
lock_guard<mutex> lock_name(name)    // locking mutex
The mutex locked using lock_guard does not need to be explicitly unlocked at the end. They automatically gets unlocked when lock goes out of scope.

Example:



1
// C++ Program to demonstrate how to use mutex for thread
2
// synchronization
3
#include <iostream>
4
#include <mutex>
5
#include <thread>
6
​
7
using namespace std;
8
​
9
// Define a mutex to protect the shared counter
10
mutex mtx;
11
int counter = 0;
12
​
13
// Function to increment the counter
14
void incrementCounter()
15
{
16
    // locking mutex using lock_guard
17
    lock_guard<mutex> lock(mtx);
18
    for (int i = 0; i < 100000; ++i) {
19
        ++counter;
20
    }
21
​
22
    // mutex unlocked after going out of scope
23
}
24
​
25
int main()
26
{
27
    // Create two threads that call incrementCounter
28
    thread t1(incrementCounter);
29
    thread t2(incrementCounter);
30
​
31
    // Wait for both threads to finish
32
    t1.join();
33
    t2.join();
34
​
35
    // Print the final counter value
36
    cout << "Counter: " << counter << endl;
37
    return 0;
38
}

Output

Counter: 200000
To know more about mutex in C++, refer to the article - Mutex in C++

2. Atomic Operations
In C++, std::atomic provides atomic operations on fundamental data types, which means these operations are performed as a single, indivisible step. Atomic operations prevent data races without the need for explicit locks.

Syntax

std::atomic <type> var_name;
Example



1
// C++ program to illustrate how to aviod the data race
2
// using atomics
3
#include <atomic>
4
#include <iostream>
5
#include <thread>
6
​
7
using namespace std;
8
​
9
// Define an atomic integer for the counter
10
atomic<int> counter(0);
11
​
12
// Function to increment the counter
13
void incrementCounter()
14
{
15
    for (int i = 0; i < 100000; ++i) {
16
        ++counter;
17
    }
18
}
19
​
20
int main()
21
{
22
    // Create two threads that call incrementCounter
23
    thread t1(incrementCounter);
24
    thread t2(incrementCounter);
25
​
26
    // Wait for both threads to finish
27
    t1.join();
28
    t2.join();
29
​
30
    // Print the final counter value
31
    cout << "Counter: " << counter << endl;
32
    return 0;
33
}

Output

Counter: 200000
To know more about C++ Atomics, refer to the article - C++ 11 - <atomic> Header

3. Condition Variables
Condition variables are used to block a thread until a particular condition is met. They are used in conjunction with a mutex to wait for or signal changes in shared data.

Syntax

condition_variable name;
Example:



1
// C++ Program to illustrate how to use condition variable
2
// to avoid the data race
3
#include <condition_variable>
4
#include <iostream>
5
#include <mutex>
6
#include <thread>
7
​
8
using namespace std;
9
​
10
mutex mtx;
11
// Condition variable for synchronization
12
condition_variable cv;
13
// Flag indicating whether work is ready
14
bool ready = false;
15
​
16
void wait_for_work()
17
{
18
    unique_lock<mutex> lock(mtx);
19
    // Wait until ready is true
20
    cout << "Start Waiting" << endl;
21
    cv.wait(lock, [] { return ready; });
22
    // resuming the work here
23
    cout << "Resuming the work after notification" << endl;
24
}
25
​
26
// Function to set ready flag
27
void set_ready()
28
{
29
    lock_guard<mutex> lock(mtx);
30
    // Mark work as ready
31
    ready = true;
32
    // Notify waiting threads
33
    cout << "Notification Sent from the other thread"
34
         << endl;
35
    cv.notify_one();
36
}
37
​
38
int main()
39
{
40
    thread worker(wait_for_work);
41
    thread producer(set_ready);
42
​
43
    // Wait for the worker thread to finish
44
    worker.join();
45
    producer.join();
46
​
47
    return 0;
48
}

Output

Start Waiting
Notification Sent from the other thread
Resuming the work after notification


#include <iostream>
using namespace std;

///;[3, 45, 6, 9, 1, 78, 98, 45, 6, 16]

///[45, 78, 9, 78, 78, 98, -1, -1, 16, -1]
vector<int> fSol(vector<int> input)
{
    int n = input.size();
    vector<int>out(n,-1);
    stack<int> st;
    for(int i =(n-1) ;i>=0; i--) {
        //
        if(st.empty())
            continue;
        //input[i]
        //vector<int> store;
        while(st.top()<input[i])
        {
            st.pop();
        }
        out[i] = st.top();
        st.push(input[i]);
    }

    return out;
}



int main() {
    
    string s = "567783447759"; // 975494579 //774595477
    vector<char> v{'9', '8', '7', '6','5', '4', '3', '2', '1', '0'};
    // 5 - 4
    //6 -3
    //7 -2
    //8 -1
    //3 -1
    //4 -2 
    // 9 - 7
    unordered_map<char, int> map;
    for(char i: s)
        m[i]++;
    string ans = "";
    char m = '%';
    for(char i : v){
        if(map[i]==1 && m=='%'){
            //place it in middle
            m = i;
        }
        else if(map[i]%2 == 1 && m=='%'){
            //find both middle and extreme ends
            m = i;//
            int k = map[i]/2;
            while(k--)
                ans += i;
        }
        else {
            int k = map[i]/2;
            while(k--)
                ans += i;
        }
    }

    return (ans + to_string(m) + reverse(ans));

}
