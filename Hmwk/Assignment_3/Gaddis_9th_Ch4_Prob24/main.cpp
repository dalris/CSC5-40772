/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 20
 * Purpose: Telephone Call Charge Rates
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    float startTime, callTime, callCharge;
    
    cout << "Enter the starting time:" << "\n";
    cin >> startTime;
    
    while(startTime > 24.00 || static_cast<float>(startTime) > 59){
        cout << "Invalid entry, Reenter:" << "\n";
        cin >> startTime;
    }
    
    cout << "Enter the number of minutes of the call:" << "\n";
    cin >> callTime;
    
    if(startTime >= 0 && startTime <= 6.59){
        callCharge = callTime * 0.05;
    }else if(startTime >= 7 && startTime <= 19){
        callCharge = callTime * 0.45;
    }else if(startTime >= 19.01 && startTime <= 23.59){
        callCharge = callTime * 0.20;
    }
    
    cout << fixed;
    cout << setprecision(2) << "The charges are $" << callCharge;

    //Exit stage right!
    return 0;
}