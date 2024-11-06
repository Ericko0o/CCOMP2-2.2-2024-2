#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package {
public:
    TwoDayPackage(const std::string& nombreRem, const std::string& dirRem, const std::string& ciudadRem,
                  const std::string& estadoRem, const std::string& zipRem,
                  const std::string& nombreDest, const std::string& dirDest, const std::string& ciudadDest,
                  const std::string& estadoDest, const std::string& zipDest,
                  double peso, double costoPorOnza, double tarifaFija)
        : Package(nombreRem, dirRem, ciudadRem, estadoRem, zipRem,
                  nombreDest, dirDest, ciudadDest, estadoDest, zipDest, peso, costoPorOnza),
          tarifaFija(tarifaFija) {}

    virtual double calcularCosto() const override {
        return Package::calcularCosto() + tarifaFija;
    }

private:
    double tarifaFija;  // tarifa adicional para el servicio de entrega en dos dias
};

#endif
