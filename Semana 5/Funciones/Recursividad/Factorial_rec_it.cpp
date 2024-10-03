#include <iostream>
using namespace std;

int factorial_rec(int n) {
    if(n==0 || n==1){
        return 1;
    }   else {
        return n * factorial_rec(n-1);
    }
}

int factorial_it(int n) {
    int fac=1;
}

int main(){
    cout<<factorial_rec(5)<<endl;
}
