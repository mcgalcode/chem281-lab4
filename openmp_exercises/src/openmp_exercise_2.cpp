#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include <chrono>



/***********************************************************
 * EXERCISE 2 Array sum using atomic
 * Try using the atomic keyword here to parallelize this task
***********************************************************/

/* For reference: DO NOT CHANGE */
double array_sum_atomic_serial() {
    const int N = 1000000;
    std::vector<int> data(N, 1); // Initialize a vector with 1s
    long long sum = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        sum += data[i];
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "SERIAL: Atomic array sum computation completed." << std::endl;
    std::cout << "SERIAL: Time taken: " << elapsed.count() << " seconds" << std::endl;
    return elapsed.count();
}

/* PARALLELIZE ME - Change anything you want in here, just make
    sure the elapsed time is still the return value
    Try to use the #pragma omp atomic clause to handle this one
*/
double array_sum_atomic_parallel() {
    const int N = 1000000;
    std::vector<int> data(N, 1); // Initialize a vector with 1s
    long long sum = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        sum += data[i];
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "PARALLEL: Atomic array sum computation completed." << std::endl;
    std::cout << "PARALLEL: Time taken: " << elapsed.count() << " seconds" << std::endl;
    return elapsed.count();
}