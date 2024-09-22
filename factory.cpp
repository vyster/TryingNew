#include <iostream>
#include <string>

class Product {
public:
  Product() { std::cout << "Some Apple Product being Created" << std::endl; }
  virtual ~Product() {}
  virtual void checkProduct() = 0;
};

class concreateiPad : public Product {
public:
  concreateiPad() { std::cout << "iPad Created" << std::endl; }
  ~concreateiPad() {}
  void checkProduct() { std::cout << "iPad is still here" << std::endl; }
};

class concreateMacbook : public Product {
public:
  concreateMacbook() { std::cout << "Macbook Created" << std::endl; }
  ~concreateMacbook() {}\
  void checkProduct() { std::cout << "Macbook is still here" << std::endl; }
};

class AppleCompany {
public:
  AppleCompany() { std::cout << "Apple Company Client Facing Constructor" << std::endl; }
  virtual ~AppleCompany() {}
  virtual Product* createiPad() = 0;
  virtual Product* createMacbook() = 0;
};

class AppleCreater : public AppleCompany {
public:
  AppleCreater() { std::cout << "Apple Creater class" << std::endl; }
  ~AppleCreater() {}
  Product* createiPad() { return new concreateiPad; }
  Product* createMacbook() { return new concreateMacbook; }
};

int main(int argc, char* argv[]) {
  std::cout << "Factory Design Pattern" << std::endl;
  AppleCompany *creater = new AppleCreater;
  Product *productA = creater->createiPad();
  productA->checkProduct();
  Product *productB = creater->createMacbook();
  productB->checkProduct();
}
