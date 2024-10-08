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

class iPadM1 : public MakingiPad {
public:
  iPadM1() { std::cout << "iPadM1 made in NewYork" << std::endl; }
  ~iPadM1() {}
  void checkProduct() { std::cout << "iPadM1 API called" << std::endl;}

};

class iPadM2 : public MakingiPad {
public:
  iPadM2() { std::cout << "iPadM2 made in California" << std::endl; }
  ~iPadM2() {}
  void checkProduct() { std::cout << "iPadM2 API called" << std::endl; }

};

class MacbookM1 : public MakingMacbook {
public:
  MacbookM1() { std::cout << "MacbookM1 made in NewYork" << std::endl; }
  ~MacbookM1() {}
  void checkProduct() { std::cout << "MacbookM1 API called" << std::endl; }

};

class MacbookM2 : public MakingMacbook {
public:
  MacbookM2() { std::cout << "MacbookM2 made in California" << std::endl; }
  ~MacbookM2() {}
  void checkProduct() { std::cout << "MacbookM2 API called" << std::endl; }

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
  MakingiPad* createiPad() { return new iPadM1; }
  MakingMacbook* createMacbook() { return new MacbookM1; }
};

class FactoryCalifornia : public AppleCompany {
public:
  FactoryCalifornia() { std::cout << "Factory in California triggered" << std::endl; }
  ~FactoryCalifornia() {}
  MakingiPad* createiPad() { return new iPadM2; }
  MakingMacbook* createMacbook() { return new MacbookM2; }
};

int main(int argc, char* argv[]) {

  AppleCompany* cf1 = new FactoryNewyork();//vtable??
  MakingiPad* iPad1 = cf1->createiPad();//what client does
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
