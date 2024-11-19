#include <iostream>
using namespace std;
class Shape {
public:
    Shape() = default;
    Shape(string description) : description(description) {};
    // Función virtual a implementar en clase derivada
    virtual void draw() const {
        cout << "Dibujando " << description << "\n";
    }
protected:
    string description{""};
};
class Circle : public Shape {
public:
    Circle() = default;
    Circle(string description, double radius)
            :Shape(description),radius(radius){};
    // Implementación de la función virtual
    void draw() const override {
        cout << "Dibujando " << description
                  << " con radio"<<radius<<endl;
    }
protected:
    double radius;
};
class Square : public Shape {
public:
    Square() = default;
    Square(string description, double l)
            : Shape(description), l(l) {};
    // Implementación de la función virtual
    void draw() const override {
        cout << "Dibujando " << description
                  << " con lado " << l <<endl;
    }
protected:
    double l;
};
void draw_shape(Shape *shape_ptr) {
    shape_ptr->draw();
}
int main() {
    Shape *shape = new Shape("Forma");
    Shape *circulo = new Circle("Circulo", 4.5);
    Shape *cuadrado = new Square("Cuadrado", 6);
    draw_shape(shape);
    draw_shape(circulo);
    draw_shape(cuadrado);
    return 0;
}

