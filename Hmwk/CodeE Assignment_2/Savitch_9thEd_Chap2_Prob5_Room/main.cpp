/* 
 * File: main.cpp
 * Author: Danziel Nguyen
 * Date: January 17
 * Purpose: Meeting Room
 * Version:
 */

//System Libraries - Post Here
#include <iostream>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    int maxCap, people;
    
    cout << "Input the maximum room capacity and the number of people" << "\n";
    cin >> maxCap >> people;
    
    if(people > maxCap){
        cout << "Meeting cannot be held." << "\n";
        cout << "Reduce number of people by " << people - maxCap << " to avoid fire violation.";
    }else{
        cout << "Meeting can be held." << "\n";
        cout << "Increase number of people by " << maxCap - people << " will be allowed without violation.";
    }
    
    return 0;
}