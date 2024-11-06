#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "Time.h"

using namespace std;

// setTime: valida y establece una nueva hora usando el formato de 24 horas
void Time::setTime(int h, int m, int s) {
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
        hour = h;
        minute = m;
        second = s;
    } else {
        throw invalid_argument("hour, minute and/or second was out of range");
    }
}

// toUniversalString: devuelve la hora en formato de 24 horas (HH:MM:SS)
string Time::toUniversalString() const {
    ostringstream output;
    output << setfill('0') << setw(2) << hour << ":"
           << setw(2) << minute << ":"
           << setw(2) << second;
    return output.str();
}

// toStandardString: devuelve la hora en formato de 12 horas (HH:MM:SS AM/PM)
string Time::toStandardString() const {
    ostringstream output;
    output << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
           << setfill('0') << setw(2) << minute << ":"
           << setw(2) << second << (hour < 12 ? " AM" : " PM");
    return output.str();
}
