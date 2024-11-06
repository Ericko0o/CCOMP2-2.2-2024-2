#ifndef DATE_H
#define DATE_H

class Date {
public:
    Date(int dia, int mes, int año) 
        : dia(dia), mes(mes), año(año) {}

    int getMes() const { return mes; }
    
private:
    int dia;
    int mes;
    int año;
};

#endif
