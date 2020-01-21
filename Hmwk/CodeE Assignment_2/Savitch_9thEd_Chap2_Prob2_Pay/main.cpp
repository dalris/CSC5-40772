/* 
 * File: main.cpp
 * Author: Danziel Nguyen
 * Date: January 17
 * Purpose: Calculating Annual Pay
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    const float payInc = .076;
    float prevAnn, newAnn, newMnth, retPay;
    
    cout << "Input previous annual salary." << "\n";
    cin >> prevAnn;
    
    newAnn = prevAnn + (prevAnn * payInc);
    newMnth = newAnn / 12;
    
    cout << fixed;
    cout << setprecision(2) << "Retroactive pay    = $" << setw(7) << (prevAnn / 2) * payInc << "\n";
    cout << setprecision(2) << "New annual salary  = $" << setw(7) << newAnn << "\n";
    cout << setprecision(2) << "New monthly salary = $" << setw(7) << newMnth;
    
    //Exit stage left
    return 0;
}