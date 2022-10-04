/**
 * @file test.cpp
 * @author Aniruddh Balram(Driver)
 * @author Aneesh Chodisetty(Navigator)
 * @brief Testing the PID Controller Parameters
 * @version 0.1
 * @date 2022-10-01
 *
 * @copyright Copyright University of Maryland(c) 2022
 *
 */

#include <gtest/gtest.h>
#include "pid.hpp"

/**
 * @brief Test for checking invalid dt
 *
 */
TEST(ParameterVerificationTest, InValidParameters) {
  EXPECT_THROW(PID pid_instance1(0.0, 0.0, 0.0, 0.0, 0.0, 0.0),
               std::domain_error);
  EXPECT_THROW(PID pid_instance2(0.0, 2.0, 5.0, 1.0, 2.0, 3.0),
               std::domain_error);
}

/**
 * @brief Test for verifying parameters
 *
 */
TEST(ParameterVerificationTest, ValidParameters) {
  PID pid_instance(0.1, 0.0, 0.0, 1.0, 2.0, 3.0);
  EXPECT_EQ(1.0, pid_instance.getKP());
  EXPECT_EQ(2.0, pid_instance.getKD());
  EXPECT_EQ(3.0, pid_instance.getKI());
}

/**
 * @brief Test for validating the output
 *
 */
TEST(ExpectedOutputTest, ValidRangeOfParameters) {
  /// Instantiating PID Controller Object
  PID pid_instance = PID(0.1, 100, -100, 0.1, 0.01, 0.5);
  double changing_process_value = 20;

  /// Live computation of PID for 100 iterations
  for (int i = 0; i < 100; i++) {
    double increment = pid_instance.compute(changing_process_value, 10);
    changing_process_value += increment;
  }
  ASSERT_NEAR(10, changing_process_value, 1);
}
