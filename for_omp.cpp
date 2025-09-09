#include <iostream>
#include <omp.h>

int main() {
    int sum = 0;
    
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 1; i <= 100; ++i) {
            // Each thread works on a subset of the loop's iterations
            sum += i; // This has a data race! (See next example)
        }
    }

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}