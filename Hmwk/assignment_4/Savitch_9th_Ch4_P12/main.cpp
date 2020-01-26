/* 
 * File:   main.cpp
 * Author: Danziel Nguyen 
 * Created on Jan 26
 * Purpose:  Clothing Sizes after 10 years
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <math.h> //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    float height, weight, age;
    char choice = 'y';
    
    cout << fixed;
    
    do{
        cout << "Enter height(inches):" << "\n\n";
        cin >> height;
        
        cout << "Enter Weight(pounds):" << "\n\n";
        cin >> weight;

        cout << "Enter age:" << "\n\n";
        cin >> age;

        
        cout << setprecision(1) << "Hat size = " << (weight / height) * 2.9 << "\n";

        if(age < 40){
            cout << setprecision(1) << "Jacket size = " << (height * weight) / 288 << "\n";
        }else if(age >= 40){
            float adjustment;
            
            adjustment = floor((age - 30.0) / 10.0) * (1.0/8.0);

            cout << "Jacket size = " << ((height * weight) / 288) + adjustment << "\n";
        }
        
       if(age + 10 < 40){
            cout << setprecision(1) << "Jacket size in 10 years = " << (height * weight) / 288 << "\n";
        }else if(age + 10 >= 40){
            float adjustment;
            
            adjustment = floor((age + 10.0 - 30.0) / 10.0) * (1.0/8.0);

            cout << "Jacket size in 10 years = " << ((height * weight) / 288) + adjustment << "\n";
        }
        
        if(age < 30){
            cout << "Waist size = " << weight / 5.7 << "\n";
        }else if(age >= 30){
            float adjustment;
            
            adjustment = floor((age - 28.0) / 2.0) * (1.0/10.0);
            
            cout << "Waist size = " << (weight / 5.7) + adjustment << "\n";
        }
        
        if(age + 10 < 30){
            cout << "Waist size in 10 years = " << weight / 5.7 << "\n";
        }else if(age + 10 >= 30){
            float adjustment;
            
            adjustment = floor((age + 10.0 - 28.0) / 2.0) * (1.0/10.0);
            
            cout << "Waist size in 10 years = " << (weight / 5.7) + adjustment << "\n";
        }


        cout << "\n" << "Run again:" << "\n";
        cin >> choice;
        cin.clear();
    }while(choice == 'y');

    
    return 0;
}