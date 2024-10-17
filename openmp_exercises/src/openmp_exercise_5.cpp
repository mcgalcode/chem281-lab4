#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include <chrono>

double f(double x) {
    return x * x;
}

/***********************************************************
 * EXERCISE 5 Trapezoidal Rule
 * Try using the reduction keyword here to parallelize this task
***********************************************************/

/* For reference: DO NOT CHANGE */
double trapezoid_rule_serial() {
    const int num_intervals = 1000000;
    const double a = 0.0;
    const double b = 1.0;
    const double h = (b - a) / num_intervals;
    double integral = 0.0;

    auto start = std::chrono::high_resolution_clock::now();

    double x;
    double local_integral = 0.0;

    for (int i = 1; i < num_intervals; ++i) {
        x = a + i * h;
        local_integral += f(x);
    }

    integral += local_integral;

    // Add the contributions from the endpoints
    integral += (f(a) + f(b)) / 2.0;
    integral *= h;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Estimated integral: " << integral << std::endl;
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return elapsed.count();
}

/* PARALLELIZE ME - IMPORTANT: Add only #pragma omp clauses and {} pairs
   to paralellize this section
*/
double trapezoid_rule_parallel() {
    const int num_intervals = 1000000;
    const double a = 0.0;
    const double b = 1.0;
    const double h = (b - a) / num_intervals;
    double integral = 0.0;

    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel
    {
        double x; // Variable to be made private
        double local_integral = 0.0;

        #pragma omp for private(x)
        for (int i = 1; i < num_intervals; ++i) {
            x = a + i * h;
            local_integral += f(x);
        }

        #pragma omp atomic
        integral += local_integral;
    }

    // Add the contributions from the endpoints
    integral += (f(a) + f(b)) / 2.0;
    integral *= h;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Estimated integral: " << integral << std::endl;
    std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

    return elapsed.count();
}