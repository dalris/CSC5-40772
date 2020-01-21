/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 17
 * Purpose:  Average
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float avg;
    float a, b, c, d, e;
    //Initialize or input i.e. set variable values
    cout << "Input 5 numbers to average." << "\n";
    cin >> a >> b >> c >> d >> e;
    //Map inputs -> outputs
    
    //Display the outputs
    avg = (a + b + c + d + e) / 5;
    cout << fixed << setprecision(1) << "The average = " << avg;
    //Exit stage right or left!
    return 0;
}