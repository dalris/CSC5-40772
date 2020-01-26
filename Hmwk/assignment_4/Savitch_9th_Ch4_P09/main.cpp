/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 26
 * Purpose:  Max of Floats
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
    float flt1, flt2, flt3;
    
    cout << "Enter first number:" << "\n" << "\n";
    cin >> flt1;
    
    cout << "Enter Second number:" << "\n" << "\n";
    cin >> flt2;
    
    cout << "Enter third number:" << "\n" << "\n";
    cin >> flt3;
    
    cout << fixed;
    
    if(flt1 > flt2){
        cout << "Largest number from two parameter function:" << "\n";
        cout << setprecision(1) << flt1 << "\n" << "\n";
        
        if(flt1 > flt3){
            cout << "Largest number from three parameter function:" << "\n";
            cout << setprecision(1) << flt1 << "\n";
        }else{
            cout << "Largest number from three parameter function:" << "\n";
            cout << setprecision(1) << flt3 << "\n";
        }
    }else{
        cout << "Largest number from two parameter function:" << "\n";
        cout << setprecision(1) << flt2 << "\n" << "\n";
        
        if(flt2 > flt3){
            cout << "Largest number from three parameter function:" << "\n";
            cout << setprecision(1) << flt2 << "\n";
        }else{
            cout << "Largest number from three paremeter function:" << "\n";
            cout << setprecision(1) << flt3 << "\n";
        }
    }
    
    return 0;
}