/**
 * @file pid.hpp
 * @author Aniruddh Balram(Driver)
 * @author Aneesh Chodisetty(Navigator)
 * @brief PID Controller
 * @version 0.1
 * @date 2022-10-01
 *
 * @copyright Copyright University of Maryland(c) 2022
 *
 */
#pragma once
#include <iostream>
#include <stdexcept>

/**
 * @brief Class for PID Control
 * @param kd Derivative Constant
 * @param kp Proportional Constant
 * @param ki Integral Constant
 * @param dt Time-step
 * @param min Minimum Threshold for Process Value
 * @param max Maximum Threshold for Process Value
 * @param pre_error Error at the beginning
 * @param integral Variable to summed-up integral
 */
class PID {
 public:
  PID(double _dt, double _max, double _min, double _kp, double _kd, double _ki);
  double compute(double process_value, double set_point);
  double getKP();
  double getKD();
  double getKI();
  double CalculateCummulativeError(double cum_error);
  double ErrorDerivativeCalculation(double error);
  // ~PID();
 private:
  double kd;
  double kp;
  double ki;
  double dt;
  double min;
  double max;
  double pre_error;
  double integral;
};
