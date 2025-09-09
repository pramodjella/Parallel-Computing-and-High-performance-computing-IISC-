#include <iostream>
#include <omp.h>

int main() {
    std::cout << "This is the main thread." << std::endl;

    #pragma omp parallel
    {
        // This code block will be executed by multiple threads
        int thread_id = omp_get_thread_num();
        #pragma omp critical
        std::cout << "Hello from thread " << thread_id << std::endl;
    }

    std::cout << "Back to the main thread." << std::endl;
    return 0;
}