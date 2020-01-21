/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 20
 * Purpose: Finding which is larger
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
    int intA, intB;
    
    cout << "Enter a number:" << "\n";
    cin >> intA;
    
    cout << "Enter a number:" << "\n";
    cin >> intB;
    
    if(intA > intB){
        cout << intA << " is larger";
    }else if(intB > intA){
        cout << intB << " is larger";
    }
    
    return 0;
}