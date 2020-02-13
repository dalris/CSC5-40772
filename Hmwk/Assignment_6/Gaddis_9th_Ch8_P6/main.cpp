/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Feb 9
 * Purpose:  binarySearch Names
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
int binarySearch(const string[], int, string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    const int NUM_NAMES = 20;
    int results;
	string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
							 "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
							 "Taylor, Terri", "Johnson, Jill",
							 "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
							 "James, Jean", "Weaver, Jim", "Pore, Bob",
							 "Rutherford, Greg", "Javens, Renee",
							 "Harrison, Rose", "Setzer, Cathy",
							 "Pike, Gordon", "Holland, Beth" };
	string askName;
    
    cout << "Enter a name to search for:" << "\n";
    cin >> askName;
    
    results = binarySearch(names, NUM_NAMES, askName);
    
    if(results == -1){
        cout << "The name was found";
    }else{
        cout << "The name was not found";
    }

    //Exit stage right!
    return 0;
}

int binarySearch(const string array[], int size, string name){
    int first = 0, last = size -1, middle, position = -1;
    bool found = false;
    
    while(!found && first <= last){
        middle = (first + last) / 2;
        if (array[middle] == name){
            found = true;
            position = middle;
        }else if(array[middle] > name){
            last = middle - 1;
        }else{
            first = middle + 1;
        }
    }
    
    return position;
}