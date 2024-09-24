#include <iostream>
#include <string>

class Singleton {
public:
  Singleton(const Singleton&) = delete; // copy constructor deleted
  Singleton& operator=(const Singleton&) = delete;//copy overloading not allowed
  Singleton& operator=(const Singleton&&) = delete; // Move assignment deleted

  static Singleton* getInstance() {
    if (!instance_) {
      instance_ = new Singleton();//create memory when called for first time
      std::cout << "1st Time" << std::endl; //
      return instance_;
    }
    std::cout << "Next Time" << std::endl;
    return instance_;
  }

  void callSingleton() { std::cout << "Singleton call" << std::endl; }

private:
  //void operator delete(void*) {};??
  Singleton() { std::cout << "Singleton Constructor" << std::endl; } //make constructor private
  static Singleton* instance_; // make the instance static and private
};

Singleton* Singleton::instance_ = nullptr;


int main(int argc, char* argv[]) {
  Singleton *singleton;
  std::cout << "---------" << std::endl;// 
  //delete singleton->instance_; should not be done
  singleton = Singleton::getInstance(); //constructor only called once
  // std::cout << "---------" << std::endl;
  // singleton->callSingleton();
  // std::cout << "---------" << std::endl;
  // singleton->callSingleton();
  std::cout << "---------" << std::endl;
  Singleton *singleton1;
  std::cout << "---------" << std::endl;
  singleton1 = Singleton::getInstance();
  // std::cout << "---------" << std::endl;
  // singleton1->callSingleton();
}

// //For threadsafe Singleton please read https://github.com/dcblack/singleton/tree/master

