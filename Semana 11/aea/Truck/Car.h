#ifndef CAR_H
#define CAR_H
using namespace std;
#include "Vehicle.h"
class Car : public Vehicle {
        string style;
    public:
        Car(const string &myLicense, const int myYear,
                const string &myStyle) :
                Vehicle(myLicense, myYear), style(myStyle) {}
        const string getDesc() const {
            ostringstream output;
            output << year << " " << style << " " <<
                    license;
            return output.str();
        }
        const string &getStyle() const {
            return style;
        }
};
#endif


