#include <iostream>
#include <omp.h>

int main() {
    int counter = 0;

    #pragma omp parallel num_threads(4)
    {
        for (int i = 0; i < 1000; ++i) {
            // The `critical` directive prevents race conditions
            #pragma omp critical
            {
                counter++; // Only one thread can increment counter at a time
            }
        }
    }
    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}