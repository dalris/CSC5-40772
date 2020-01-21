/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 10, 2020, 4:08 PM
 * Purpose:  Calculate the annual average high temperatures of different cities
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
    int newYork = 85;
    int denver = 88;
    int phoenix = 106;
    
    cout << "The new average July high for New York is: "
            << newYork + ((newYork * 2) / 100) << " Fahrenheit \n";
    cout << "The new average July high for Denver is: "
            << denver + ((denver * 2) / 100) << " Fahrenheit \n";
    cout << "The new average July high for Phoenix is: "
            << phoenix + ((phoenix * 2) / 100) << " Fahrenheit \n";
    
    return 0;
}
