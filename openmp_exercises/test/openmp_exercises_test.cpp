#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "openmp_exercise_1.h"
#include "openmp_exercise_2.h"

TEST(OpenMPExercise1, Assertions) {
  double serial_result = independent_work_serial();
  double parallel_result = independent_work_parallel();
  EXPECT_LT(parallel_result, serial_result);
}