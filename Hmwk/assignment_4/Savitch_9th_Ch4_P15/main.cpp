/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 26
 * Purpose:  Vending Machine
 */

//System Libraries
#include <iostream>
#include <iomanip> //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    const float cost = 3.50;
    float total = 0.0;

    cout << fixed;
    
    do{
      int coinMenu = 0;
      
        cout << "List of coins:" << "\n";
        cout << "1. Nickel" << "\n";
        cout << "2. Dime" << "\n";
        cout << "3. Quarter" << "\n";
        cout << "4. Dollar" << "\n";
        cout << "Enter number for coin:" << "\n";
        cin >> coinMenu;
        
        switch(coinMenu){
            case 1:{
                total += 0.05;
                break;
            }
            case 2:{
                total += 0.10;
                break;
            }
            case 3:{
                total += 0.25;
                break;
            }
            case 4:{
                total += 1.00;
                break;
            }
        }
        
        cout << setprecision(2) << "\n" << "Current amount: $" << total << "\n";
        
    }while(total < cost);
    
    cout << "Enjoy your deep-fried twinkie" << "\n";
    
    if(total > cost){
        cout << setprecision(2) << "Change to be returned: $" << total - cost << "\n";
    }
    
    return 0;
}