#include <iostream>
using namespace std;


class Base {
public:
    virtual ~Base() {cout << "Destructor Base"; }
};

class Derived : public Base {
public:
    ~Derived() {cout << "Destructor Derived"; }
};

Base* basePtr = new Derived();
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);





