/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 10, 2020, 3:54 PM
 * Purpose:  Calculate the annual pay of employees
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here

int main(int argc, char** argv) {
    const int payPeriods = 26;
    
    float payAmount = 2200.0;
    float annualPay;
    
    annualPay = payAmount * payPeriods;
    
    cout << "The annual pay of the employee is: $" << annualPay << "\n";
    
    return 0;
}
