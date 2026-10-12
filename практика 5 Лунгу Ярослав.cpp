#include <iostream>
#include <cmath>

int main() {
    int y = 5;

    // Способ 1: for
    int day1 = 0;
    for (double x = 1.0; x <= y; x *= 1.1) {
        day1++;
    }
    std::cout << "Способ 1 (for): " << day1 << "\n";
    
    int day2 = 0;
    double x = 1.0;
    while (x <= y) { 
        day2++;
        x *= 1.1;
    }
    std::cout << "Способ 2 (while): " << day2 << "\n";
    
    int d3 = static_cast<int>(ceil(log(y / 1.0) / log(1.1)));
    if (1.0 > y) d3 = 0; 
    std::cout << "Способ 3(log): " << d3 << "\n";
}