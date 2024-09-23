#include <iostream>
#include <string>

class Product {
public:
  Product() { std::cout << "Some Apple Product being Created" << std::endl; }
  virtual ~Product() {}
  virtual void checkProduct() = 0;
};

class makingiPad : public Product {
public:
  makingiPad() { std::cout << "iPad Created" << std::endl; }
  ~makingiPad() {}
  void checkProduct() { std::cout << "iPad is still here" << std::endl; }
};

class makingMacbook : public Product {
public:
  makingMacbook() { std::cout << "Macbook Created" << std::endl; }
  ~makingMacbook() {}\
  void checkProduct() { std::cout << "Macbook is still here" << std::endl; }
};

class AppleCompany {
public:
  AppleCompany() { std::cout << "Apple Company Client Facing Constructor" << std::endl; }
  virtual ~AppleCompany() {}
  virtual Product* createiPad() = 0;
  virtual Product* createMacbook() = 0;
};

class AppleFactory : public AppleCompany {
public:
  AppleFactory() { std::cout << "Apple Creater class" << std::endl; }
  ~AppleFactory() {}
  Product* createiPad() { return new makingiPad; }
  Product* createMacbook() { return new makingMacbook; }
};

int main(int argc, char* argv[]) {
  std::cout << "Factory Design Pattern" << std::endl;
  AppleCompany *factory = new AppleFactory;
  Product *productA = factory->createiPad();
  productA->checkProduct();
  Product *productB = factory->createMacbook();
  productB->checkProduct();
}
