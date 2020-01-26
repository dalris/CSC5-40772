/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 26
 * Purpose:  Ocean Level
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
    float mlPerYr;
    
    cout << "Enter how many millimeters the ocean is rising per year:" << "\n";
    cin >> mlPerYr;
    
    cout << "Year" << "\t" << "Rise(mm)" << "\n";
    
    cout << fixed;
    
    for(int i = 1; i <= 30; i++){
        cout << setprecision(1) << i << "\t" << mlPerYr * i << "\n";
    }
    
    return 0;
}