/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 10, 2020, 4:09 PM
 * Purpose:  Calculate a car's miles per gallon (MpG)
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
    int gallons = 15;
    int miles = 375;
    
    cout << "The car gets " << miles / gallons << " miles per gallon \n";
    
    return 0;
}
