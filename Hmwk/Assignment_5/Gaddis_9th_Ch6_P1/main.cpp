/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 29
 * Purpose:  Item Cost
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
float calculateRetail(float, float);

//Execution Begins Here
int main(int argc, char** argv) {
    float wholeCost, mkPrcnt, retailCost;
    
    cout << "Enter the wholesale cost:" << "\n";
    cin >> wholeCost;
    
    cout << "Enter the markup percentage:" << "\n";
    cin >> mkPrcnt;
    
    retailCost = calculateRetail(wholeCost, mkPrcnt);
    
    cout << fixed;
    cout << setprecision(2) << "The retail price is $" << retailCost;

    //Exit stage right!
    return 0;
}

float calculateRetail(float cost, float prcnt){
    float retail;

    retail = cost + (cost * (prcnt / 100));
    
    return retail;
}