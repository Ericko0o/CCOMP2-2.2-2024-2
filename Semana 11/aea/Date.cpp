#include <array>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Date.h"
using namespace std;
Date::Date(unsigned int mn, unsigned int dy, unsigned int yr)
        :month{mn}, day{checkDay(dy)}, year{yr} {
    if(mn < 1 || mn > monthsPerYear) {
        throw invalid_argument("month must be 1-12");
    }
    cout << "Date object constructor for date " << toString() << endl;
}
string Date::toString() const {
    ostringstream output;
    output << month << '/' << day << '/' << year;
    return output.str();
}
Date::~Date() {
    cout << "Date object destructor for date" << toString() << endl;
}



