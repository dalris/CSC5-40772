/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 20
 * Purpose: Speed of Sound
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    const int airFt = 1100, waterFt = 4900, steelFt = 16400;
    
    int menu;
    float waveTime, distance = -1;
    
    cout << "Choose which medium the sound wave will travel in." << "\n";
    cout << "1.Air" << "\n";
    cout << "2.Water" << "\n";
    cout << "3.Steel" << "\n";
    cin >> menu;
    
    while(distance < 0){
        cout << "Enter the distance the wave will travel:" << "\n";
        cin >> distance;
    }
    
    cout << fixed;
    
    switch(menu){
        case 1:
        waveTime = distance / airFt;
        cout << setprecision(4) << "The wave will take " << waveTime << " seconds";
        break;
        case 2:
        waveTime = distance / waterFt;
        cout << setprecision(4) << "The wave will take " << waveTime << " seconds";
        break;
        case 3:
        waveTime = distance / steelFt;
        cout << setprecision(4) << "The wave will take " << waveTime << " seconds";
        break;
    }
    //Exit stage right!
    return 0;
}