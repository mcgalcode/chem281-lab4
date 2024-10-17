#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <filesystem>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;
namespace fs = std::filesystem;

// Define the parameters
const double D = 1.0;       // Diffusion coefficient
const double dx = 0.01;     // Spatial step size
const double dt = 0.5 * dx * dx / D; 
const int N = 100;          // Number of spatial points
const int T = 10000;         // Number of time steps

// Initial condition: Gaussian distribution
void initialize(std::vector<double>& C) {
    double mean = 0.0;
    double sigma = 0.1;
    for (int i = 0; i < N; ++i) {
        double x = i * dx;
        C[i] = exp(-0.5 * pow((x - mean) / sigma, 2));
    }
}

// Boundary conditions: C(0, t) = C(1, t) = 0
void apply_boundary_conditions(std::vector<double>& C) {
    C[0] = 0.0;
    C[N - 1] = 0.0;
}

// Explicit finite difference method with saving frames for a video visualization
void solve_diffusion(std::vector<double>& C, std::vector<double>& C_new, double initial_max) {
    std::vector<double> x(N);
    for (int i = 0; i < N; ++i) {
        x[i] = i * dx;
    }

    plt::figure();
    plt::xlabel("Position (x)");
    plt::ylabel("Concentration (C)");
    plt::title("Concentration Profile over Time");

    for (int t = 0; t < T; ++t) {
        // Save the current concentration profile as an image
        int sample_freq = 20;
        if (t % sample_freq == 0) { // Save frame every 10 time steps for better performance
            std::cout << "Saving frame: " << t << std::endl;
            plt::clf();
            plt::plot(x, C);
            plt::ylim(0.0, initial_max); // Ensure y-axis limits are consistent
            plt::xlabel("Position (x)");
            plt::ylabel("Concentration (C)");
            plt::title("Concentration Profile over Time");            
            std::stringstream ss;
            ss << "frame_" << std::setw(6) << std::setfill('0') << t / sample_freq << ".png";
            plt::save(ss.str());     
        }   

        #pragma omp parallel for
        for (int i = 1; i < N - 1; ++i) {
            C_new[i] = C[i] + D * dt / (dx * dx) * (C[i + 1] - 2 * C[i] + C[i - 1]);
        }

        // Apply boundary conditions
        apply_boundary_conditions(C_new);

        // Swap C and C_new to prepare for next step
        std::swap(C, C_new);
    }
}

void create_video() {
    // Command to combine frames into a video using FFmpeg
    std::string command = "ffmpeg -framerate 10 -i frame_%06d.png -c:v libx264 -pix_fmt yuv420p diffusion.mp4";
    std::system(command.c_str());
}

void cleanup_frames() {
    // Remove all frame_*.png files
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.path().extension() == ".png" && entry.path().stem().string().find("frame_") == 0) {
            fs::remove(entry.path());
        }
    }
}

int main() {
    std::vector<double> C(N, 0.0);
    std::vector<double> C_new(N, 0.0);

    // Initialize the concentration
    initialize(C);
    apply_boundary_conditions(C);

    double initial_max = *std::max_element(C.begin(), C.end());

    // Solve the diffusion equation with saving frames
    solve_diffusion(C, C_new, initial_max);

    // Create video from saved frames
    create_video();

    cleanup_frames();

    return 0;
}