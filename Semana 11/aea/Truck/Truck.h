#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"
using namespace std;
class Truck : public Vehicle {
        string capacity;
    public:
        Truck(const string &myLicense, const int myYear,
                const string &myCapacity) :
                Vehicle(myLicense, myYear), capacity(myCapacity) {}
        const string getDesc() const {
            ostringstream output;
            output << year <<" "<< capacity <<"Ton."<<
                    license;
            return output.str();
        }
        const string &getCapacity() const {
            return capacity;
        }
};
#endif

