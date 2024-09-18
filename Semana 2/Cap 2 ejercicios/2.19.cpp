#include <iostream>

int main() {
    int num1, num2, num3;

    std::cout << "Input three different integers: ";
    std::cin >> num1 >> num2 >> num3;

    int sum = num1 + num2 + num3;
    int average = sum / 3;
    int product = num1 * num2 * num3;

    // num <
    int smallest = num1;
    if (num2 < smallest) {
        smallest = num2;
    }
    if (num3 < smallest) {
        smallest = num3;
    }

    // num >
    int largest = num1;
    if (num2 > largest) {
        largest = num2;
    }
    if (num3 > largest) {
        largest = num3;
    }

    std::cout << "Sum is " << sum << std::endl;
    std::cout << "Average is " << average << std::endl;
    std::cout << "Product is " << product << std::endl;
    std::cout << "Smallest is " << smallest << std::endl;
    std::cout << "Largest is " << largest << std::endl;

    return 0;
}
