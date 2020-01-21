/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 20
 * Purpose: Switch statement
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
   int var1;
   
   cout << "Enter a number between 1 and 10:" << "\n";
   cin >> var1;
   
   while(var1 < 1 || var1 > 10){
       cout << "Entered number is not valid, reenter number:" << "\n";
       cin >> var1;
   }
   
   switch(var1){
       case 1:
       cout << var1 << " is I in Roman numerals";
       break;
       case 2:
       cout << var1 << " is II in Roman numerals";
       break;
       case 3:
       cout << var1 << " is III in Roman numerals";
       break;
       case 4:
       cout << var1 << " is IV in Roman numerals";
       break;
       case 5:
       cout << var1 << " is V in Roman numerals";
       break;
       case 6:
       cout << var1 << " is VI in Roman numerals";
       break;
       case 7:
       cout << var1 << " is VII in Roman numerals";
       break;
       case 8:
       cout << var1 << " is VIII in Roman numerals";
       break;
       case 9:
       cout << var1 << " is IX in Roman numerals";
       break;
       case 10:
       cout << var1 << " is X in Roman numerals";
       break;
   }
   
    //Exit stage right!
    return 0;
}