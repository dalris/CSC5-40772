/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 10, 2020, 4:01 PM
 * Purpose:  Calculate the total purchase amount
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
    const int salesTaxPrcnt = 7;
    
    float item1 = 15.95, item2 = 24.95, item3 = 6.95, item4 = 12.95,
            item5 = 3.95;
    float subTotal = item1 + item2 + item3 + item4 + item5;
    float salesTax = (subTotal * salesTaxPrcnt) / 100;
    float finalCost = subTotal + salesTax;
    
    
    cout << "Item 1: $" << item1 << "\n";
    cout << "Item 2: $" << item2 << "\n";
    cout << "Item 3: $" << item3 << "\n";
    cout << "Item 4: $" << item4 << "\n";
    cout << "Item 5: $" << item5 << "\n";
    cout << "The subtotal is: $" << subTotal << "\n";
    cout << "The sales tax is: $" << salesTax << "\n";
    cout << "The final cost is: $" << finalCost << "\n";

    return 0;
}
