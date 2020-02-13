/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Feb 9
 * Purpose:  Lotto Linear
 */

//System Libraries
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    vector<int> numbers{13579, 26791, 26792, 33445, 55555,
                        62483, 77777, 79422, 85647, 93121};
    int winning;
    
    cout << "Enter the winning number:" << "\n";
    cin >> winning;
    
    if(find(numbers.begin(), numbers.end(), winning) != numbers.end()){
        cout << "Congratulations you have won!";
    }else{
        cout << "No winning numbers.";
    }


    //Exit stage right!
    return 0;
}