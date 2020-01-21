/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 17
 * Purpose:  Cookies
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float cookies, calories;

    cout << "Calorie Counter" << "\n";
    cout << "How many cookies did you eat?" << "\n";
    cin >> cookies;

    calories = 300 * (cookies / 4);
    
    cout << "You consumed " << calories << " calories.";

    //Exit stage right or left!
    return 0;
}