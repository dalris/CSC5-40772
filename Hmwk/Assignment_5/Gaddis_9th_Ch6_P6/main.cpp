/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 29
 * Purpose:  Kinetic Energy
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
float kineticEnergy(float, float);

//Execution Begins Here
int main(int argc, char** argv) {
    float mass, velocity;
    
    cout << "Enter the object's mass:" << "\n";
    cin >> mass;
    
    cout << "Enter the object's velocity:" << "\n";
    cin >> velocity;
    
    cout << fixed;
    cout << setprecision(1) << "The object has " << kineticEnergy(mass, velocity) << " Joules of energy.";
    
    //Exit stage right!
    return 0;
}

float kineticEnergy(float mass, float vel){
    float kinEn;
    
    kinEn = 0.5*mass*vel*vel;
    
    return kinEn;
}