/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 20
 * Purpose: Rectangle Areas
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
    int width1, width2, height1, height2;
    
    cout << "Enter the width of rectangle 1:" << "\n";
    cin >> width1;
    cout << "Enter the height of rectangle 1:" << "\n";
    cin >> height1;
    cout << "Enter the width of rectangle 2:" << "\n";
    cin >> width2;
    cout << "Enter the height of rectangle 2:" << "\n";
    cin >> height2;
    
    if(width1 * height1 > width2 * height2){
        cout << "Rectangle 1 has the greater area";
    }else if(width1 * height1 < width2 * height2){
        cout << "Rectangle 2 has the greater area";
    }else if(width1 * height1 == width2 * height2){
        cout << "The rectangles have the same area";
    }
    
    return 0;
}