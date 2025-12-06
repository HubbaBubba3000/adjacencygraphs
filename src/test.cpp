
#include <cmath>
#include <iostream>
int main() {
    int i = 0b00010000000000010110;
    for (int j=20-1;j>=0;j--) {
        bool bit = (i >> j) & 1;
        if (bit == 1) {
            std::cout << std::pow(2,j) << ", ";
        }

    }
}
