#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();
        std::cout << "Thread " << thread_id << " is working..." << std::endl;

        // All threads wait here until everyone has reached this point
        #pragma omp barrier

        std::cout << "Thread " << thread_id << " is synchronized and continuing." << std::endl;
    }
    return 0;
}