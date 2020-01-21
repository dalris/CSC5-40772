/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 10, 2020, 3:40 PM
 * Purpose:  Calculate final restaurant bill
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
    const float taxPrcnt = 6.75;
    const int tipPrcnt = 20;
    
    float bill = 88.67;
    float billTax;
    float billTip;
    float finalBill;
    
    billTax = (bill * taxPrcnt) / 100;
    billTip = ((bill + billTax) * tipPrcnt) / 100;
    finalBill = bill + billTax + billTip;
    
    cout << "The meal cost: $" << bill << "\n";
    cout << "The tax was: $" << billTax << "\n";
    cout << "The tip was: $" << billTip << "\n";
    cout << "The final bill was: $" << finalBill << "\n";
    
    return 0;
}
