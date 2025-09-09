#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(4)
    {
        std::cout << "Hello from thread " << omp_get_thread_num() << std::endl;

        #pragma omp single
        {
            // This block is executed by only one thread.
            std::cout << "This message is printed just once." << std::endl;
        }

        std::cout << "All threads are now past the barrier." << std::endl;
    }
    return 0;
}