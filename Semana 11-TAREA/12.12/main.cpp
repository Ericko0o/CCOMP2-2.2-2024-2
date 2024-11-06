#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main() {
    // crear un vector de punteros a objetos de tipo Package
    std::vector<std::unique_ptr<Package>> paquetes;

    // agregar objetos de TwoDayPackage y OvernightPackage al vector
    paquetes.push_back(std::make_unique<TwoDayPackage>("Carlos Martínez", "Calle 123", "Ciudad A", "Estado X", "12345",
                                                       "Ana López", "Avenida 456", "Ciudad B", "Estado Y", "67890",
                                                       5.0, 2.5, 3.0));
    paquetes.push_back(std::make_unique<OvernightPackage>("Laura García", "Calle 789", "Ciudad C", "Estado Z", "54321",
                                                          "Juan Pérez", "Avenida 101", "Ciudad D", "Estado W", "09876",
                                                          10.0, 3.0, 1.5));

    double costoTotal = 0.0;

    // procesar cada paquete polimorficamente
    for (const auto& paquete : paquetes) {
        // imprimir la información del remitente y destinatario
        std::cout << "Remitente:\n" << paquete->obtenerInfoRemitente() << "\n";
        std::cout << "Destinatario:\n" << paquete->obtenerInfoDestinatario() << "\n";

        // calcular e imprimir el costo del paquete actual
        double costo = paquete->calcularCosto();
        std::cout << "Costo de envío: $" << std::fixed << std::setprecision(2) << costo << "\n\n";

        // umar el costo total de envio
        costoTotal += costo;
    }

    // mostrar el costo total de envío de todos los paquetes
    std::cout << "Costo total de envío de todos los paquetes: $" << std::fixed << std::setprecision(2) << costoTotal << std::endl;

    return 0;
}
