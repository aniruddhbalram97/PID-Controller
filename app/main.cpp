
/**
 * @file main.cpp
 * @author Aniruddh Balram(Driver)
 * @author Aneesh Chodisetty(Navigator)
 * @brief PID Controller
 * @version 0.1
 * @date 2022-10-01
 * 
 * @copyright Copyright University of Maryland(c) 2022
 * 
 */
#include "pid.hpp"

int main() {
    /// Instantiating PID Controller Object
    PID pid_instance = PID(0.1, 100, -100, 0.1, 0.01, 0.5);
    double changing_process_value = 10;
    /// Live computation of PID for 100 iterations
    for (int i = 0; i < 100; i++) {
        double increment = pid_instance.compute(changing_process_value, 0);
        std::cout << "The final value: "<< changing_process_value 
        << " & The increment: " << increment << std::endl;
        changing_process_value += increment;
    }
    return 0;
}