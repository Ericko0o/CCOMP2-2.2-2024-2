#include <iostream>
using namespace std;


int main() {
    int x(0);

    while (x < 10) {
        x=x+1;
        if(x == 5){
            break; // continue -> imprime hasta 10
        }
        cout << x << endl;
    }
}

