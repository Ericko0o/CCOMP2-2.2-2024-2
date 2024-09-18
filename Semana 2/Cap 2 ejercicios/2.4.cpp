#include <iostream>

int main() {
    int x = 0;
    int y = 0;
    int z = 0;
    int result = 0;
    std::cout << "Please enter three integers: ";
    std::cin >> x >> y >> z;

    result = x * y * z;
    std::cout << "The product is " << result << std::endl;

    return 0;
}
