# Assert the minimum cmake version
cmake_minimum_required(VERSION 3.22)

# Set the project name
project(openmp_exercises)

# Require a modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Find Python3
find_package(Python3 COMPONENTS Development NumPy REQUIRED)

# Include directories
include_directories(${Python3_INCLUDE_DIRS})
include_directories(${Python3_NumPy_INCLUDE_DIRS})
include_directories(/lib/matplotlib-cpp/)  # Replace with the actual path to matplotlib-cpp

# Add OpenMP support
find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

# Add the executable
add_executable(FickSolver src/diffusion.cpp)
add_library(OpenMPExerciseLib src/openmp_exercise_1.cpp
                              src/openmp_exercise_2.cpp
                              src/openmp_exercise_3.cpp
                              src/openmp_exercise_4.cpp
                              src/openmp_exercise_5.cpp)
add_executable(ExerciseProfiler src/exercise_profiling.cpp)

# Link libraries
target_link_libraries(FickSolver ${Python3_LIBRARIES})
target_link_libraries(ExerciseProfiler PRIVATE OpenMPExerciseLib)

target_include_directories(OpenMPExerciseLib PRIVATE include)
target_include_directories(ExerciseProfiler PRIVATE include)