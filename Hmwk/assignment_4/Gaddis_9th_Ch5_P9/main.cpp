/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 26
 * Purpose:  Hotel Occupancy
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
    int floors, floorRms, floorOcc, totalRms = 0, totalOcc = 0;
    
    cout << "Enter how many floors there are:" << "\n";
    cin >> floors;
    
    for(int i = 1; i <= floors; i++){
        cout << "Enter how many rooms are on floor " << i << ":" << "\n";
        cin >> floorRms;
        
        cout << "Enter how many are occupied:" << "\n";
        cin >> floorOcc;
        
        totalRms += floorRms;
        totalOcc += floorOcc;
    }
    
    cout << "There are " << totalOcc << " rooms occupied." << "\n";
    cout << "There are " << totalRms - totalOcc << " rooms unoccupied." << "\n";

    cout << fixed;
    cout << setprecision(1) << (totalOcc * 100.00) / totalRms << "% of rooms are occupied.";
    
    return 0;
}