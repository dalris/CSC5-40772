/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Feb 9
 * Purpose:  Employee Data
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
    int empID[7] = {5658845, 4520125,
                    7895122, 8777541, 
                    8451277, 1302850, 7580489};
    int hours[7];
    float payRate[7], wages[7];
    
    for(int i = 0; i < 7; i++){
        cout << "Enter employee " << empID[i] << "'s pay rate:" << "\n";
        cin >> payRate[i];
        cout << "Enter employee " << empID[i] << "'s hours work:" << "\n";
        cin >> hours[i];
        wages[i] = payRate[i] * hours[i];
    }

    for(int i = 0; i < 7; i++){
        cout << fixed << setprecision(2) << "Employee " << empID[i] << "'s gross pay $" << wages[i] << "\n";
    }
    
    //Exit stage right!
    return 0;
}