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
class PID{
    public:
        PID(double _dt,
        double _max,
        double _min, 
        double _kp,
        double _kd,
        double _ki);
        double compute(double process_value, double set_point);
        double getKP();
        double getKD();
        double getKI();
        ~PID();
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
PID:: PID(double _dt, double _max, double _min, double _kp, double _kd, double _ki) {
    dt = _dt;
    max = _max;
    min = _min;
    kp = _kp;
    kd = _kd;
    ki = _ki;
    integral = 0;
    pre_error = 0;
}
/**
 * @brief Method to compute the PID output
 * 
 * @param process_value The actual output
 * @param set_point The desired output
 * @return double 
 */
double PID:: compute(double process_value, double set_point) {
    return 1.2;
}

/**
 * @brief Returns value of kp
 * 
 * @return double 
 */
double PID:: getKP() {
    return kp;
}

/**
 * @brief Returns value of kd
 * 
 * @return double 
 */
double PID:: getKD() {
    return kd;
}

/**
 * @brief Returns value of ki
 * 
 * @return double 
 */
double PID:: getKI() {
    return ki;
}
PID:: ~PID() {}
