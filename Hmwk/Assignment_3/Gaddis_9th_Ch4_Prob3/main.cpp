/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 20
 * Purpose: Magic Date
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
    int mnth, day, year;
    
    cout << "Enter a month:" << "\n";
    cin >> mnth;
    cout << "Enter a day:" << "\n";
    cin >> day;
    cout << "Enter a year:" << "\n";
    cin >> year;
    
    if(mnth * day == year){
        cout << "The date is magic";
    }else{
        cout << "The date is not magic";
    }

    //Exit stage right!
    return 0;
}