#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <sstream>
using namespace std;
class Vehicle {
    protected:
        string license;
        int year;
    public:
        Vehicle(const string &myLicense, const int myYear)
                : license(myLicense), year(myYear) {}
        virtual const string getDesc() const = 0;
        const string &getLicense() const {
            return license;
        }
        const int getYear() const {
            return year;
        }
};
#endif


