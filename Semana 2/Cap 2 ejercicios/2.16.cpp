#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
   int numero1{0};
   int numero2{0};
   int sum{0};
   int producto{0};
   int dif{0};
   int cociente{0};

   cout<<"Ingrese dos numero: ";
   cin>>numero1 >>numero2;
   sum= numero1 + numero2;
   producto= numero1 * numero2;
   dif= numero1 - numero2;
   cociente= numero1 / numero2;

   cout<<"Suma:"<<sum<<"  producto:"<<producto<<"  diferencia:"<<dif<<"  cociente:"<<cociente<< endl;


}