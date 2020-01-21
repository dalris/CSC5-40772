/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 17
 * Purpose:  Temp
 */

//System Libraries
#include <iostream>
#include <iomanip> //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float fHeit, cGrade;
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    
    //Display the outputs
    cout << "Temperature Converter" << "\n";
    cout << "Input Degrees Fahrenheit" << "\n";
    cin >> fHeit;
    
    cGrade = (fHeit - 32.0) * (5.0/9.0);

    cout << fixed << setprecision(1) << fHeit << " Degrees Fahrenheit = "
        << cGrade << " Degrees Centigrade";


    //Exit stage right or left!
    return 0;
}