#include <iostream>
#include <string>

class Singleton {
public:
  Singleton(const Singleton&) = delete; //copy constructor deleted
  Singleton& operator=(const Singleton&) = delete;//copy overloading not allowed

  static Singleton* instance() {
    if (!instance_) {
      instance_ = new Singleton();
      std::cout << "1st Time" << std::endl;
      return instance_;
    }
    std::cout << "Next Time" << std::endl;
    return instance_;
  }

  void checkSingleton() { std::cout << "Singleton call" << std::endl; }
private:
  Singleton() { std::cout << "Singleton Constructor" << std::endl; }
  static Singleton* instance_;
};

Singleton* Singleton::instance_ = nullptr;

int main(int argc, char* argv[]) {
  Singleton *singleton;
  std::cout << "---------" << std::endl;
  singleton = Singleton::instance();
  std::cout << "---------" << std::endl;
  singleton->checkSingleton();
  std::cout << "---------" << std::endl;
  singleton->checkSingleton();
  std::cout << "---------" << std::endl;
  Singleton *singleton1;
  std::cout << "---------" << std::endl;
  singleton1 = Singleton::instance();
  std::cout << "---------" << std::endl;
  singleton1->checkSingleton();
}