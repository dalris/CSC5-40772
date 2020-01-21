/* 
 * File: main.cpp
 * Author: Danziel Nguyen
 * Date: January 17
 * Purpose: Diet Coke
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    const float sweetPrcnt = .001;
    const int canWeight = 350;
    
    int mouseLethal = 5, mouseWeight = 35;
    float dieterWeight, dieterLethal, cans;
    
    cout << "Program to calculate the limit of Soda Pop Consumption." << "\n";
    cout << "Input the desired dieters weight in lbs." << "\n";
    cin >> dieterWeight;
    
    dieterLethal = mouseLethal * ((dieterWeight*453.592) / mouseWeight);
    
    cans = dieterLethal / (canWeight * sweetPrcnt);
    
    cout << "The maximum number of soda pop cans" << "\n";
    cout << "which can be consumed is " << trunc(cans) << " cans";
    
    //Exit stage left
    return 0;
}