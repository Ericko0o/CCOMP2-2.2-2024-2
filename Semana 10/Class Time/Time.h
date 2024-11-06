#ifndef TIME_H
#define TIME_H

#include <string>

class Time {
public:
    void setTime(int, int, int); // establece la hora, minutos y segundos
    std::string toUniversalString() const; // formato de hora 24 horas
    std::string toStandardString() const; // formato de hora 12 horas

private:
    unsigned int hour{0};   // 0 - 23 (formato de reloj de 24 horas)
    unsigned int minute{0}; // 0 - 59
    unsigned int second{0}; // 0 - 59
};

#endif
