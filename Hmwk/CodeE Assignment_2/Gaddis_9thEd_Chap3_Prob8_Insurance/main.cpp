/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 17
 * Purpose:  Insurance
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
    const float insurePrcnt = .80;
    int houseWorth;
    
    cout << "Insurance Calculator" << "\n";
    cout << "How much is your house worth?" << "\n";
    cin >> houseWorth;
    
    cout << "You need $" << houseWorth * insurePrcnt << " of insurance.";

    //Exit stage right or left!
    return 0;
}