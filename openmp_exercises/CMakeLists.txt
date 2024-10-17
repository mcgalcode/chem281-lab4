# Assert the minimum cmake version
cmake_minimum_required(VERSION 3.22)

# Set the project name
project(openmp_exercises)

# Require a modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Add FetchContent module
include(FetchContent)

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


#########################################
# BEGIN GoogleTest setup, DO NOT CHANGE #
#########################################
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")

# # Set up GoogleTest according to: https://google.github.io/googletest/quickstart-cmake.html
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

# enable_testing()

# add_executable(OpenMPExercisesTest test/openmp_exercises_test.cpp)
# target_link_libraries(OpenMPExercisesTest GTest::gtest_main)
# target_link_libraries(OpenMPExercisesTest OpenMPExerciseLib)
# target_include_directories(OpenMPExercisesTest PRIVATE include)

# include(GoogleTest)
# gtest_discover_tests(OpenMPExercisesTest)

##########################
# END   GoogleTest setup #
##########################