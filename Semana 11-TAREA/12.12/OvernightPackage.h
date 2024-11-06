#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package {
public:
    OvernightPackage(const std::string& nombreRem, const std::string& dirRem, const std::string& ciudadRem,
                     const std::string& estadoRem, const std::string& zipRem,
                     const std::string& nombreDest, const std::string& dirDest, const std::string& ciudadDest,
                     const std::string& estadoDest, const std::string& zipDest,
                     double peso, double costoPorOnza, double costoAdicionalPorOnza)
        : Package(nombreRem, dirRem, ciudadRem, estadoRem, zipRem,
                  nombreDest, dirDest, ciudadDest, estadoDest, zipDest, peso, costoPorOnza),
          costoAdicionalPorOnza(costoAdicionalPorOnza) {}

    virtual double calcularCosto() const override {
        return peso * (costoPorOnza + costoAdicionalPorOnza);
    }

private:
    double costoAdicionalPorOnza;  // costo adicional para envio nocturno
};

#endif
