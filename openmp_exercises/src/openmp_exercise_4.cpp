#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>
#include <chrono>



/***********************************************************
 * EXERCISE 4 Matrix Multiplication
 * Try using the reduction keyword here to parallelize this task
***********************************************************/

/* For reference: DO NOT CHANGE */
double matrix_mult_collapse_serial() {
    const int N = 100;
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "SERIAL: Matrix multiplication completed." << std::endl;
    std::cout << "SERIAL: Time taken: " << elapsed.count() << " seconds" << std::endl;
    return elapsed.count();
}

/* PARALLELIZE ME - Change anything you want in here, just make
    sure the elapsed time is still the return value
    Try to use the #pragma omp atomic clause to handle this one
*/
double matrix_mult_collapse_parallel() {
    const int N = 100;
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "PARALLEL: Matrix multiplication completed." << std::endl;
    std::cout << "PARALLEL: Time taken: " << elapsed.count() << " seconds" << std::endl;
    return elapsed.count();
}