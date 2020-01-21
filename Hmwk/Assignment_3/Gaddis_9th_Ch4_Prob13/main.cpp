/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 20
 * Purpose: Book Club
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
    int books;
    
    cout << "Enter how many books you purchased this month:" << "\n";
    cin >> books;
    
    if(books == 0){
        cout << "You earned 0 points.";
    }else if(books == 1){
        cout << "You earned 5 points.";
    }else if(books == 2){
        cout << "You earned 15 points.";
    }else if(books == 3){
        cout << "You earned 30 points.";
    }else if(books >= 4){
        cout << "You earned 60 points.";
    }
    return 0;
}