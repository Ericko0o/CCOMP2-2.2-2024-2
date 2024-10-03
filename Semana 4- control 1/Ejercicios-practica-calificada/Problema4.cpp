// Problema 4

#include <iostream>
using namespace std;

// class Date con validacion de mes
class Date {
private:
    int month; int day; int year;
public:
    Date(int m, int d, int y) : day(d), year(y) {
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            month = 1;
        }
    }
    // setters
    void setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
        } else {
            month = 1;
        }
    }
    void setDay(int d) {
        day = d;
    }
    void setYear(int y) {
        year = y;
    }
    // getters
    int getMonth() const {
        return month;
    }
    int getDay() const {
        return day;
    }
    int getYear() const {
        return year;
    }
    // funcion displaydate
    void displayDate() const {
        cout << month << "/" << 
        day << "/" << 
        year << std::endl;
    }
};
int main() {
    Date date1(5, 15, 2024);  // mes valido
    Date date2(13, 10, 2024); // mes invalido
    cout << "Fecha 1: ";
    date1.displayDate();
    cout << "Fecha 2: ";
    date2.displayDate();

    return 0;
}
