/**
 * @file main.cpp
 * @author Aniruddh Balram(Driver)
 * @author Aneesh Chodisetty(Navigator)
 * @brief PID Controller algorithm
 * @version 0.1
 * @date 2022-10-01
 *
 * @copyright Copyright University of Maryland(c) 2022
 *
 */
#include "../include/pid.hpp"

/**
 * @brief Construct a new PID::PID object
 *
 * @param _dt Time-step
 * @param _max Maximum threshold of Process Value
 * @param _min Minimum threshold of Process Value
 * @param _kp Proportional Constant
 * @param _kd Derivative Constant
 * @param _ki Integral Constant
 */
PID::PID(double _dt, double _max, double _min, double _kp, double _kd,
         double _ki) {
  dt = _dt;
  max = _max;
  min = _min;
  kp = _kp;
  kd = _kd;
  ki = _ki;
  integral = 0;
  pre_error = 0;
  if (kp <= 0 || kd <= 0 || ki <= 0 || dt <= 0) {
    throw std::domain_error("Invalid input");
  }
}
/**
 * @brief Calculating Integral Error
 *
 * @param cum_error cummulative error
 * @return double
 */
double PID::CalculateCummulativeError(double cum_error) {
  return (cum_error * dt);
}
/**
 * @brief Calculative Error Derivative
 *
 * @param error
 * @return double
 */
double PID::ErrorDerivativeCalculation(double error) {
  return ((error - pre_error) / dt);
}

/**
 * @brief Method to compute the PID output
 *
 * @param process_value The actual output
 * @param set_point The desired output
 * @return double
 */
double PID::compute(double process_value, double set_point) {
  double error = set_point - process_value;
  // integral += error;
  double control_variable =
      PID::getKP() * error +
      PID::getKI() * PID::CalculateCummulativeError(error) +
      PID::getKD() * PID::ErrorDerivativeCalculation(error);

  control_variable = control_variable > max ? max : control_variable;
  control_variable = control_variable < min ? min : control_variable;

  pre_error = error;

  return control_variable;
}

/**
 * @brief Returns value of kp

 *
 * @return double
 */

double PID::getKP() { return kp; }

/**
 * @brief Returns value of kd
 *
 * @return double
 */
double PID::getKD() { return kd; }

/**
 * @brief Returns value of ki
 *
 * @return double
 */
double PID::getKI() { return ki; }
