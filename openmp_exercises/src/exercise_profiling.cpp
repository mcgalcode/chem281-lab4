#include "openmp_exercise_1.h"
#include "openmp_exercise_2.h"
#include "openmp_exercise_3.h"
#include "openmp_exercise_4.h"
#include "openmp_exercise_5.h"

#include <chrono>
#include <iostream>

int main() {
    double serial_time;
    double parallel_time;
    std::cout << "################################################" << std::endl;
    std::cout << "Exercise 1: Independent Work" << std::endl;
    serial_time =   independent_work_serial();
    parallel_time = independent_work_parallel();
    if (parallel_time > 0.9 * serial_time) {
        std::cout << "\nHmmmm... perhaps this exercise could use some parallelization...\n" << std::endl;
    } else {
    std::cout << "Looks like the parallelization worked!" << std::endl;
    }
    std::cout << "################################################" << std::endl;

    std::cout << "################################################" << std::endl;
    std::cout << "Exercise 2: Array Sum Atomic" << std::endl;
    serial_time =   array_sum_atomic_serial();
    parallel_time = array_sum_atomic_parallel();
    if (parallel_time > 0.9 * serial_time) {
        std::cout << "\nHmmmm... perhaps this exercise could use some parallelization...\n" << std::endl;
    } else {
        std::cout << "Looks like the parallelization worked!" << std::endl;
    }   
    std::cout << "################################################" << std::endl;

    std::cout << "################################################" << std::endl;
    std::cout << "Exercise 3: Array Sum Reduction" << std::endl;
    serial_time =   array_sum_reduction_serial();
    parallel_time = array_sum_reduction_parallel();
    if (parallel_time > 0.9 * serial_time) {
        std::cout << "\nHmmmm... perhaps this exercise could use some parallelization...\n" << std::endl;
    } else {
        std::cout << "Looks like the parallelization worked!" << std::endl;
    }   
    std::cout << "################################################" << std::endl;

    std::cout << "################################################" << std::endl;
    std::cout << "Exercise 4: Matrix Multiplication with collapse" << std::endl;
    serial_time =   matrix_mult_collapse_serial();
    parallel_time = matrix_mult_collapse_parallel();
    if (parallel_time > 0.9 * serial_time) {
        std::cout << "\nHmmmm... perhaps this exercise could use some parallelization...\n" << std::endl;
    } else {
        std::cout << "Looks like the parallelization worked!" << std::endl;
    }   
    std::cout << "################################################" << std::endl;

    std::cout << "################################################" << std::endl;
    std::cout << "Exercise 5: Trapezoidal Rule" << std::endl;
    serial_time =   trapezoid_rule_serial();
    parallel_time = trapezoid_rule_parallel();
    if (parallel_time > 0.9 * serial_time) {
        std::cout << "\nHmmmm... perhaps this exercise could use some parallelization...\n" << std::endl;
    } else {
        std::cout << "Looks like the parallelization worked!" << std::endl;
    }   
    std::cout << "################################################" << std::endl;
}
