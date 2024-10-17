#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include <chrono>


/***********************************************************
 * EXERCISE 1 Independent Work Parallelization
***********************************************************/
const int N = 100000000;

/* For reference: DO NOT CHANGE */
double independent_work_serial() {
    std::vector<double> data(N, 1.0);
    std::vector<double> results(N, 0.0);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        results[i] = std::sin(data[i]) + std::cos(data[i]);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Independent work SERIAL computation completed." << std::endl;
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;
    return elapsed.count();
}

/* PARALLELIZE ME - Change anything you want in here, just make
    sure the elapsed time is still the return value
*/
double independent_work_parallel() {
    std::vector<double> data(N, 1.0);
    std::vector<double> results(N, 0.0);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        results[i] = std::sin(data[i]) + std::cos(data[i]);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Independent work in PARALLEL computation completed." << std::endl;
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;
    return elapsed.count();
}