/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 17
 * Purpose:  Trig
 */

//System Libraries
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath> //Input/Output Library
using namespace std;


//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    const double pi = 3.14;
    double angle, sine, cosine, tangent;
    
    cout << "Calculate trig functions" << "\n";
    cout << "Input the angle in degrees." << "\n";
    cin >> angle;
    
    sine = sin((angle*M_PI)/180);
    cosine = cos((angle*M_PI)/180);
    tangent = tan((angle*M_PI)/180);

    cout << fixed;
    cout << setprecision(0) << "sin(" << angle << ") = " << setprecision(4) << sine << "\n";
    cout << setprecision(0) << "cos(" << angle << ") = " << setprecision(4) << cosine << "\n";
    cout << setprecision(0) << "tan(" << angle << ") = " << setprecision(4) << tangent;
    
    return 0;
}