/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 29
 * Purpose:  Company Divisions
 */

//System Libraries
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
float getSales(string);
void findHighest(vector <pair <string, float> > vect);
bool vectSort(const pair<string, float> &a, const pair<string, float> &b);

//Execution Begins Here
int main(int argc, char** argv) {
    string divisions[4] = { "Northeast", "Southeast", "Northwest", "Southwest" };
    float sales[4];
    vector< pair <string, float> > divVector;
    
    for(int i = 0; i < 4; i++){
        sales[i] = getSales(divisions[i]);
        divVector.push_back(make_pair(divisions[i], sales[i]));
    }

    findHighest(divVector);
    
    //Exit stage right!
    return 0;
}

float getSales(string division){
    float sales;
    
    cout << "Enter the sales for " << division << " division:$" << "\n";
    cin >> sales;
    
    while(sales < 0){
        cout << "Invalid input, please enter a valid sales figure:" << "\n";
        cin >> sales;
    }
    
    return sales;
}

void findHighest(vector < pair <string, float> > vect){
    sort(vect.begin(), vect.end(), vectSort);
    
    cout << fixed << setprecision(2) << "The " << vect[3].first
        << " division had the highest sales of $" << vect[3].second;
}

bool vectSort(const pair<string, float> &a, const pair<string, float> &b){
    return (a.second < b.second);
}