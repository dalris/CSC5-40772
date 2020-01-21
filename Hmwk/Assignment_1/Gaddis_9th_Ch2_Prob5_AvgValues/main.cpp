/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 10, 2020, 3:52 PM
 * Purpose:  Calculate the average of values
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
    int int1 = 28, int2 = 32, int3 = 37, int4 = 24, int5 = 33;
    int sum = int1 + int2 + int3 + int4 + int5;
    int avg = sum / 5;
    
    cout << "The average is: " << avg << "\n";
    
    return 0;
}
