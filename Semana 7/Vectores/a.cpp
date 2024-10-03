#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

using namespace std;

void outputVector(const vector<int> &); // "const" -> PAra no modificar, por que solo necesito imprimir.
void inputVector(vector<int>&);

int main(){
    vector<int> integer1{7};
    vector<int> integer2{10};

    cout << "\nSize of vector integer1 is" << integer1.size()
            <<"\nvector after initialization: ";

    outputVector(integer1);
    cout << "\nSize of vector integer2 is" << integer2.size()
            <<"\nvector after initialization: ";
    outputVector(integer2);

    cout << "\nEnter 17 integers: " << endl;
    inputVector(integer1);
    inputVector(integer1);


    cout<<"\nAfter input, the vectors contain:\n"
            <<"integers1:"

}

void outputVector(const vector<int> & items){
    for(int item : items){ // Copia de cada elemento del vvector.
        cout << item << " ";
    }
}


void inputVector(vector<int> items){
    for(int &item : items){ // no es una copia, es una referencia
        cin >> item;
    }
}



