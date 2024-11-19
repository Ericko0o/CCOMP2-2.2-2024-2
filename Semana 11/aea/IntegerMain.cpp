#include <iostream>
#include "Integer.h"
using namespace std;
int main() {
    Integer i;
    Integer *ptr = &i;
    cout<<ptr->getVal()<<endl;
    cout<<(*ptr).getVal()<<endl;
    cout<<i.getVal()<<endl;
    cout<<(&i)->getVal()<<endl;
    return 0;
}

