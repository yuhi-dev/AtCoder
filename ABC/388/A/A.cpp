#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    std::string result = S[0] + std::string("UPC");

    std::cout << result << std::endl;

    return 0;
}