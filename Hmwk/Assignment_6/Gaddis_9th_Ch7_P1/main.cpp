/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Feb 9
 * Purpose:  Largest and Smallest in Array
 */

//System Libraries
#include <iostream>
#include <algorithm>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    int arr[10];
    
    cout << "Enter 10 integers:" << "\n";
    for(int i = 0; i < 10; i++){
        cin >> arr[i];
    }
    
    sort(begin(arr), end(arr));
    
    cout << arr[9] << " is the highest number." << "\n";
    cout << arr[0] << " is the lowest number.";
    
    //Exit stage right!
    return 0;
}