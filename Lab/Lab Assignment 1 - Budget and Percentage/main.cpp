/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 10, 2020, 4:10 AM
 * Purpose:  Federal and Military Budget
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables and Constants
    float milBdgt, fedBdgt; // Federal and Military budgets
    float mlPrcnt; //Percentage of Military budget
    
    //Initialize Variables
    fedBdgt = 4.1e12f; // Federal budget = 4.1 Trillion
    milBdgt = 7.0e11f; // Military Budget = 700 Billion

    // Output
    cout << "Federal Budget = $" << fedBdgt << endl;
    cout << "Military Budget = $" << milBdgt << endl;
    cout << "The military budget is " << (milBdgt / fedBdgt)*(100) 
            << "% of the federal budget." << endl;
    
    // Finish
    return 0;
}