/* 
 * File: main.cpp
 * Author: Danziel Nguyen
 * Date: January 17
 * Purpose: Sums
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    int numbers[10];
    int posSum = 0, negSum = 0, sum = 0;
    
    cout << "Input 10 numbers, any order, positive or negative" << "\n";
    for(int i = 0; i < 10; i++){
        cin >> numbers[i];
    }
    
    sort(numbers, numbers + 10);
    
    for(int i = 0; i < 10; i++){
        if(numbers[i] < 0){
            negSum += numbers[i];
        }else if(numbers[i] > 0){
            posSum += numbers[i];
        }
    }
    
    cout << "Negative sum = " << setw(3) << negSum << "\n";
    cout << "Positive sum = " << setw(3) << posSum << "\n";
    cout << "Total sum    = " << setw(3) << sum;
    
    
    //Exit stage left
    return 0;
}