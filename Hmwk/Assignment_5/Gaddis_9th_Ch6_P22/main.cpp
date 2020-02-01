/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 29
 * Purpose:  Prime Number
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
bool isPrime(int);

//Execution Begins Here
int main(int argc, char** argv) {
    int pNumber;
    
    cout << "Enter a number:" << "\n";
    cin >> pNumber;
    
    if(isPrime(pNumber) == true){
        cout << pNumber << " is a prime number.";
    }else if(isPrime(pNumber) == false){
        cout << pNumber << " is not a prime number.";
    }

    //Exit stage right!
    return 0;
}

bool isPrime(int num){
    if(num != 2 && num % 2 == 0){
        return false;
    }else{
        return true;
    }
}