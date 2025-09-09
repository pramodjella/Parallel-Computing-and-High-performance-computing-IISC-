#include <iostream>
#include <omp.h>

void task_a() {
    std::cout << "Task A done by thread " << omp_get_thread_num() << std::endl;
}

void task_b() {
    std::cout << "Task B done by thread " << omp_get_thread_num() << std::endl;
}

int main() {
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            task_a();
        }

        #pragma omp section
        {
            task_b();
        }
    }
    return 0;
}