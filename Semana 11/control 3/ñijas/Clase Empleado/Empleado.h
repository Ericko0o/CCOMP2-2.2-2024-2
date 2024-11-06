#include <string>

class Empleado {
    public:
        Empleado(std::string n,std::string a,double s) 
            :nombre(n),apellido(a),salario(s>0?s:0) {} 
            // Inici salario 0 si es negativo o cero.
        std::string getNombre() const {
            return nombre;
        }
        std::string getApellido() const {
            return apellido;
        }
        double getSalario() const {
            return salario;
        }
        void setNombre(std::string n) {
            nombre = n;
        }
        void setApellido(std::string a) {
            apellido = a;
        }
        void setSalario(double s) {
            salario = (s > 0) ? s : 0;  //Ajusta
        }
    private:
        std::string nombre;
        std::string apellido;
        double salario{0};  //Inicializa
};
