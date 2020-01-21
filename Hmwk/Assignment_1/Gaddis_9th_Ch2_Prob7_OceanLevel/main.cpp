/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 10, 2020, 3:56 PM
 * Purpose:  Calculate the ocean levels during certain years
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
    const float oceanRise = 1.5;
    
    float oceanLevel;
    
    cout << "The ocean's level in 5 years will be: "
            << oceanLevel + (oceanRise * 5) << " millimeters\n";
    cout << "The ocean's level in 7 years will be: "
            << oceanLevel + (oceanRise * 7) << " millimeters\n";
    cout << "The ocean's level in 10 years will be: "
            << oceanLevel + (oceanRise * 10) << " millimeters\n";
    
    return 0;
}
