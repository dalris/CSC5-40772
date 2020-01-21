/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 20
 * Purpose: Calculate Area
 */

//System Libraries
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    int menu;
    
    cout << fixed;
    cout << "Geometry Calculator" << "\n";
    cout << "1. Calculate the Area of a Circle" << "\n";
    cout << "2. Calculate the Area of a Rectangle" << "\n";
    cout << "3. Calculate the Area of a Triangle" << "\n";
    cout << "4. Quit" << "\n";
    cin >> menu;
    
    if(menu < 1 || menu > 4){
        cout << "Invalid entry, Reenter: " << "\n";
        cin >> menu;
    }
    
    switch(menu){
        case 1:{
            float radius;
            
            cout << "Enter the radius of the circle:" << "\n";
            cin >> radius;
            
            while(radius < 0){
                cout << "Invalid entry, Reenter:" << "\n";
                cin >> radius;
            }
            
            cout << setprecision(1) << "The area of the circle is " << 3.14159 * pow(radius,2);
            
            break;
        }
        case 2:{
            float length, height;
            
            cout << "Enter the length of the rectangle:" << "\n";
            cin >> length;
            
            while(length < 0){
                cout << "Invalid entry, Reenter:" << "\n";
                cin >> length;
            }
            cout << "Enter the height of the rectangle:" << "\n";
            cin >> height;
            
            while(height < 0){
                cout << "Invalid entry, Reenter:" << "\n";
                cin >> height;
            }
            
            cout << setprecision(1) << "The area of the rectangle is " << length * height;
            
            break;
        }
        case 3:{
            float base, height;
            
            cout << "Enter the base of the triangle:" << "\n";
            cin >> base;
            
            while (base < 0){
                cout << "Invalid entry, Reenter:" << "\n";
                cin >> base;
            }
            
            cout << "Enter the height of the triangle:" << "\n";
            cin >> height;
            
            while (height < 0){
                cout << "Invalid entry, Reenter:" << "\n";
                cin >> height;
            }
            
            cout << setprecision(1) << "The area of the triangle is " << (base * height) / 2.0;
            
            break;
        }
        case 4:
        break;
    }

    //Exit stage right!
    return 0;
}