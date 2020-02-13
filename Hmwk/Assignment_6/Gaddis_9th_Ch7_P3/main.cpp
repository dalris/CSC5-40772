/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Feb 9
 * Purpose:  Chips and Salsa
 */

//System Libraries
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void swap(string & a, string & b){
    string tmp = a;
    a = b;
    b = tmp;
}

//Execution Begins Here
int main(int argc, char** argv) {
    string name[5] = {"mild", "medium", "sweet", "hot", "zesty"}, minName, maxName;
    float profits[5], sales = 0, minSale, maxSale;
    
    cout << fixed;
    
    for(int i = 0; i < 5; i++){
        cout << "Enter the sales of " << name[i] << " salsa:$" << "\n";
        cin >> profits[i];
        sales += profits[i];
    }
    
    cout << "Type     Sales" << "\n";
    for(int i = 0; i < 5; i++){
        cout << setprecision(2) << left << setw(9) << name[i] << "$" << profits[i] << "\n";
    }

    cout << setprecision(2) << "Total Sales was $" << sales << "\n";
    
    for (int i = 0; i < 4; i++){
        int min = i;  
        for (int j = i + 1; j < 5; j++){
            if (profits[j] < profits[min]){
                min = j;
            }
        }
        swap(profits[min], profits[i]);
        swap(name[min], name[i]);
    }  
    
    cout << name[0] << " was the lowest selling product." << "\n";
    cout << name[4] << " was the highest selling product.";
    //Exit stage right!
    return 0;
}

