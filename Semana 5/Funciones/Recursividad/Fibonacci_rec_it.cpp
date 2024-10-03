#include <iostream>
using namespace std;

/**
int factorial(int n) {
    // cb: n es 0 o 1, el factorial es 1
    if (n <= 1) {
        return 1;
    }
    // Caso recursivo: n * factorial de (n - 1)
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    cout << "ingrese un número: ";
    cin >> num;
    cout << "El factorial de " << num << " es: " << factorial(num) << endl;
    return 0;
}

*/
/**
int fibonacci(int n) {
    if(n == 0 || n == 1){
        return 1;
    }   else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    cout<<fibonacci(5)<<endl;
}
*/

 //Fibonacci iterativo
int fibonacci_it(int n) {
    int fib=1;
    int n1=0;
    int n2=0;
    for(int i = 0; i < n; i++){
        n1 = fib;
        n2= n1;
        fib= n1 + n2;
    }
    return fib;
}

int main(){
    cout<<fibonacci_it(5)<<endl;
}
