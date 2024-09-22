#include <iostream>
#include <string>

class Singleton {
public:
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton* instance() {
    if (!instance_) {
      instance_ = new Singleton();
      std::cout << "First Time" << std::endl;
    }
    std::cout << "Next Time" << std::endl;
    return instance_;
  }

  void checkSingleton() { std::cout << "Singleton has been created" << std::endl; }
private:
  Singleton() { std::cout << "Singleton" << std::endl; }
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
  Singleton *singleton1 = Singleton::instance();
  singleton1->checkSingleton();
}