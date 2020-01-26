/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 26
 * Purpose:  Calories
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
    float calories;
    
    cout << "Enter how many calories are burned per minute:" << "\n";
    cin >> calories;
    
    cout << "Min" << "\t" << "Calories burned" << "\n";
    cout << fixed;
    
    for(int i = 1; i <= 6; i++){
        cout << setprecision(1) << i * 5 << "\t" << i * 5 * calories << "\n";
    }
    
    return 0;
}