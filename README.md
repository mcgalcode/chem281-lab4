# CHEM 281 Lab 3

## Orientation

Welcome to CHEM 281 Lab 4! In this lab, our focus is primarily on utilizing basic OpenMP constructs. It consists of two parts: 1) a series of small exercises for parallelizing loops using different OpenMP clauses and 2) an opportunity to implement a finite difference integration method for solving Fick's second law of diffusion.

### Goals

The goal of this lab is twofold: first, to practice a bit of OpenMP usage, and second, to allow you to experiment with and visualize the results of Fick's second law, which models diffusion in solids.

## 0. Set up your development environment

A Dockerfile containing all of the tools and dependencies you need for this project is included here.

To build the image, and then open an interactive terminal in the resulting container, use:

```
>>> ./build_image.sh
>>> ./interactive.sh
```

If either of these gives you a permission denied error, use `chmod +x` to make them runnable. For example:

```
>>> chmod +x ./interactive.sh
```

## 1. Build the code and run the ExerciseProfiler to see that parallelization should be done.

This code should run without bugs, but you'll see messages suggesting that parallelization might help for each
of the exercises. Note that it's not necessarily the case the parallelization will help in every one of these cases.

```
mkdir build
cd build
cmake ..
make
./ExerciseProfiler
```

You can find the implementations to each of these exercises in the `openmp_exercises/src` directory. The files all start with `openmp_exercise`:

```
src ->
    openmp_exercise_1.cpp
    openmp_exercise_2.cpp
    openmp_exercise_3.cpp
    openmp_exercise_4.cpp
    openmp_exercise_5.cpp
```

## 2. Parallelize each of these test cases

Use OpenMP to parallelize each of these test cases. You shouldn't really have to change the actual C++ code, just add `#pragma` lines for each case. Note that in each file there are `serial` and `parallel` versions of each function. Don't change the serial ones, they are there for timing reference, and for you to look at in case you need to see what the original implementations looked like.

## 3. The Finite Difference Method and Fick's Second Law

Fick's Second law is the governing equation for how concentrations of diffusing species evolve in time. This could be used to model the spread of a gas in a vessel, or the spread of metal atoms diffusing into the lattice of a different metal (typically called a diffusion couple).

[You can read about Fick's second law (and the first law) here.](https://en.wikipedia.org/wiki/Fick%27s_laws_of_diffusion#Fick's_second_law) In this exercise, we will be focusing on experimenting with concentration profiles in a single dimension for simplicity (and so we can easily visualize them).

