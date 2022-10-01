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
TEST(InvalidParameterTest, ForZeroValue) {
  PID pid_instance1(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  PID pid_instance2(0.0, 2.0, 5.0, 1.0, 2.0, 3.0);
  EXPECT_THROW(pid_instance1.compute(10,0), std::domain_error);
  EXPECT_THROW(pid_instance2.compute(10,0), std::domain_error);
}

/**
 * @brief Test for verifying parameters
 * 
 */
TEST(ParameterVerificationTest, ValidParameters) {
  PID pid_instance(0.0, 0.0, 0.0, 1.0, 2.0, 3.0);
  EXPECT_EQ(1.0, pid_instance.getKP());
  EXPECT_EQ(2.0, pid_instance.getKD());
  EXPECT_EQ(3.0, pid_instance.getKI());
}

/**
 * @brief Test for verifying output
 * 
 */
TEST(ExpectedOutputTest, ValidRangeOfParameters) {
  PID pid_instance(0.1, 0.0, 20.0, 1.0, 2.0, 3.0);
  ASSERT_NEAR(2000.0, pid_instance.compute(10, 0),10.0);
}