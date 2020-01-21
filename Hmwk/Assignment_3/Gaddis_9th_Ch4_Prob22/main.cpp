/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 20
 * Purpose: Freezing and Boiling points
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
    int temp;
    
    cout << "Enter a temperature:" << "\n";
    cin >> temp;
    
    if(temp <= -173){
        cout << "Ethyl alcohol will freeze" << "\n";
    }else if(temp >= 172){
        cout << "Ethyl alcohol will boil" << "\n";
    }
    
    if(temp <= -38){
        cout << "Mercury will freeze" << "\n";
    }else if(temp >= 676){
        cout << "Mercury will boil" << "\n";
    }
    
    if(temp <= -362){
        cout << "Oxygen will freeze" << "\n";
    }else if(temp >= -306){
        cout << "Oxygen will boil" << "\n";
    }
    
    if(temp <= 32){
        cout << "Water will freeze" << "\n";
    }else if(temp >= 212){
        cout << "Water will boil" << "\n";
    }

    return 0;
}