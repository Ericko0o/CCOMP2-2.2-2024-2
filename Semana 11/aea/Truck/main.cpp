#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include <vector>
using namespace std;
void printCarac(Vehicle *ptr) {
    cout << ptr->getDesc() << endl;
}
int main () {
    Car c("VRS-234", 2024, "Bochito");
    Truck t("VRD-987", 1990, "15");    
    vector<Vehicle*> vehicles;
    vehicles.push_back(&c);
    vehicles.push_back(&t);
    for(Vehicle *p : vehicles) {
        printCarac(p);
    }
    /*Vehicle **ptr = new Vehicle*[2];
    ptr[0] = &c;
    ptr[1] = &t;
    for(int i = 0; i < 2; i++) {
        printCarac(ptr[i]);
    }*/
    return 0;
}
