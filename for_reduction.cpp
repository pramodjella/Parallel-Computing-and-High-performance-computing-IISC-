#include <iostream>
#include <omp.h>

int main() {
    int sum = 0;
    
    // The `reduction` clause correctly handles the sum
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= 100; ++i) {
        sum += i;
    }

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}