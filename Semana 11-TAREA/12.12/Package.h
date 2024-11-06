#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
public:
    // constructor que inicializa todos los datos requeridos del paquete
    Package(const std::string& nombreRem, const std::string& dirRem, const std::string& ciudadRem,
            const std::string& estadoRem, const std::string& zipRem,
            const std::string& nombreDest, const std::string& dirDest, const std::string& ciudadDest,
            const std::string& estadoDest, const std::string& zipDest,
            double peso, double costoPorOnza)
        : nombreRemitente(nombreRem), direccionRemitente(dirRem), ciudadRemitente(ciudadRem),
          estadoRemitente(estadoRem), codigoPostalRemitente(zipRem),
          nombreDestinatario(nombreDest), direccionDestinatario(dirDest), ciudadDestinatario(ciudadDest),
          estadoDestinatario(estadoDest), codigoPostalDestinatario(zipDest) {
        
        if (peso > 0.0)
            this->peso = peso;
        else
            throw std::invalid_argument("El peso debe ser positivo");

        if (costoPorOnza > 0.0)
            this->costoPorOnza = costoPorOnza;
        else
            throw std::invalid_argument("El costo por onza debe ser positivo");
    }

    virtual ~Package() = default;

    // metodo para calcular el costo, basado en el peso y el costo por onza
    virtual double calcularCosto() const {
        return peso * costoPorOnza;
    }

    // metodos para obtener la información del remitente y destinatario
    std::string obtenerInfoRemitente() const {
        return nombreRemitente + "\n" + direccionRemitente + "\n" + ciudadRemitente + ", " + estadoRemitente + " " + codigoPostalRemitente;
    }

    std::string obtenerInfoDestinatario() const {
        return nombreDestinatario + "\n" + direccionDestinatario + "\n" + ciudadDestinatario + ", " + estadoDestinatario + " " + codigoPostalDestinatario;
    }

protected:
    double peso;  // peso del paquete en onzas
    double costoPorOnza;  // costo por onza para el envio

private:
    // datos del remitente
    std::string nombreRemitente;
    std::string direccionRemitente;
    std::string ciudadRemitente;
    std::string estadoRemitente;
    std::string codigoPostalRemitente;

    // datos del destinatario
    std::string nombreDestinatario;
    std::string direccionDestinatario;
    std::string ciudadDestinatario;
    std::string estadoDestinatario;
    std::string codigoPostalDestinatario;
};

#endif
