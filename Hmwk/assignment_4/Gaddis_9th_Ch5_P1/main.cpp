/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 26
 * Purpose:  Sum of Integers
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
    int var1, sum = 0;
    
    cout << "Enter a positive integer value:" << "\n";
    cin >> var1;
    
    while(var1 < 0){
        cout << "Enter a positive integer value:" << "\n";
        cin >> var1;
    }
    
    for(int i = 1; i <= var1; i++){
        sum += i;
    }
    
    cout << "The sum of all the integers from 1 to " << var1 << " is " << sum;

    //Exit stage right!
    return 0;
}