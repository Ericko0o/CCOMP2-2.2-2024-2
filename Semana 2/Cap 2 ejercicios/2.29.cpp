#include <iostream>
using namespace std;

int main() {
    cout << "Face length     Surface area (cm^2)     Volume (cm^3)" << endl;

    for (int sideLength = 0; sideLength <= 4; sideLength++) {
        int surfaceArea = 6 * sideLength * sideLength;
        int volume = sideLength * sideLength * sideLength;

        cout << sideLength << "               " << surfaceArea << "                        " << volume << endl;
    }

    return 0;
}