#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(4)
    {
        std::cout << "Thread " << omp_get_thread_num() << " working." << std::endl;

        #pragma omp master
        {
            // This block is executed only by the master thread (thread 0)
            std::cout << "Master thread is performing a task." << std::endl;
        }

        // Other threads are not blocked and can continue
        std::cout << "Thread " << omp_get_thread_num() << " finished." << std::endl;
    }
    return 0;
}