/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 26
 * Purpose:  Distance
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
    int speed, hours;
    
    cout << "What is the speed of the vehicle in mph?" << "\n";
    cin >> speed;
    
    cout << "How many hours has it traveled?" << "\n";
    cin >> hours;
    
    cout << "Hour   Distance Traveled" << "\n";
    
    for(int i = 1; i <= hours; i++){
        cout << i << setw(15) << i * speed << "\n";
    }
    
    return 0;
}