/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 10, 2020, 3:33 PM
 * Purpose:  Calculate Sales Tax
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
    const int stateTax = 4;
    const int countyTax = 2;
    
    int purchase = 95;
    float totalTax;
    float totalCost;
    
    totalTax = purchase * (stateTax + countyTax) / 100;
    totalCost = purchase + totalTax;
    
    return 0;
}
