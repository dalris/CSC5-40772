/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 20
 * Purpose: Object Mass
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
    float mass, weight;
    
    cout << "Enter the mass of an object:" << "\n";
    cin >> mass;
    
    weight = mass * 9.8;
    
    if(weight > 1000){
        cout << "The object is too heavy";
    }else if(weight < 10){
        cout << "The object is too light";
    }else{
        cout << fixed;
        cout << setprecision(1) << "The object weighs " << weight << " newtons";
    }

    //Exit stage right!
    return 0;
}