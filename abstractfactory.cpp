#include <iostream>

class AppleProduct {
public:
  AppleProduct() { std::cout << "Some Apple Product being Created" << std::endl; }
  virtual ~AppleProduct() {}
  virtual void checkProduct() = 0;
};

class MakingiPad :public AppleProduct {
public:
  MakingiPad() { std::cout << "iPad Making Notification" << std::endl; }
  virtual ~MakingiPad() {}
  //virtual void checkProduct() = 0;
};

class MakingMacbook :public AppleProduct{
public:
  MakingMacbook() { std::cout << "Macbook Making Notification" << std::endl; }
  virtual  ~MakingMacbook() {}
  //virtual void checkProduct() = 0;
};

class iPad1 : public MakingiPad {
public:
  iPad1() { std::cout << "iPad made in NewYork" << std::endl; }
  ~iPad1() {}
  void checkProduct() { std::cout << "iPad1 API called" << std::endl;}

};

class iPad2 : public MakingiPad {
public:
  iPad2() { std::cout << "iPad made in California" << std::endl; }
  ~iPad2() {}
  void checkProduct() { std::cout << "iPad2 API called" << std::endl; }

};

class Macbook1 : public MakingMacbook {
public:
  Macbook1() { std::cout << "Macbook1 made in NewYork" << std::endl; }
  ~Macbook1() {}
  void checkProduct() { std::cout << "Macbook1 API called" << std::endl; }

};

class Macbook2 : public MakingMacbook {
public:
  Macbook2() { std::cout << "Macbook2 made in California" << std::endl; }
  ~Macbook2() {}
  void checkProduct() { std::cout << "Macbook2 API called" << std::endl; }

};

class AppleCompany {
public:
  AppleCompany() { std::cout << "Apple has a requirement" << std::endl; }
  virtual ~AppleCompany() {}//making destructor virtual
  virtual MakingiPad* createiPad() = 0;//making pure virtual function
  virtual MakingMacbook* createMacbook() = 0;
};

class FactoryNewyork : public AppleCompany {
public:
  FactoryNewyork() { std::cout << "Factory in Newyork triggered" << std::endl; }
  ~FactoryNewyork() {}
  MakingiPad* createiPad() { return new iPad1; }
  MakingMacbook* createMacbook() { return new Macbook1; }
};

class FactoryCalifornia : public AppleCompany {
public:
  FactoryCalifornia() { std::cout << "Factory in California triggered" << std::endl; }
  ~FactoryCalifornia() {}
  MakingiPad* createiPad() { return new iPad2; }
  MakingMacbook* createMacbook() { return new Macbook2; }
};

int main(int argc, char* argv[]) {

  AppleCompany* cf1 = new FactoryNewyork();//vtable??
  MakingiPad* iPad1 = cf1->createiPad();
  iPad1->checkProduct();
  MakingMacbook* Macbook1 = cf1->createMacbook();
  Macbook1->checkProduct();

  std::cout<<std::endl;

  AppleCompany* cf2 = new FactoryCalifornia();
  MakingiPad* iPad2 = cf2->createiPad();
  iPad2->checkProduct();
  MakingMacbook* Macbook2 = cf2->createMacbook();
  Macbook2->checkProduct();
}
