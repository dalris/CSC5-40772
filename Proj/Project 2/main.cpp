/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on 2020/02/03
 * Purpose:  Project 1: Sì-Wŭ-Liù (a.k.a. Cee-lo)
 * v1:
 *  - One banker with preset bank
 *  - One normal player (User)
 *  - Single round play
 * v2:
 *  - Restructuring program to use arrays and functions
 */

//System Libraries
#include <iostream>
#include <cstdlib> // for random
#include <ctime> // for time
#include <fstream> // for file output
#include <cctype> // for converting to uppercase & checking input
#include <math.h> // for rounding numbers
#include <algorithm> // for sorting array
#include <vector> // for using vectors
#include <string> // for using strings

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void roll(int *arr);
void roll(std::vector<int> &vect);
void sortVect(std::vector<int> &vect);
void swap(int*, int*);
void bubbleSort(int *, int);
void selectionSort(int *, int);
bool askFile();

//Execution Begins Here
int main(int argc, char** argv){
    //Set Random Number seed
    srand(time(0));

    static const int size = 3;
    int bDice[size], point1 = 0, point2 = 0, pickSort;
    char betAsk;
    bool betting = true, bRoll = true, pRoll = true, logRes;
    // Money may have cents (atypical) due to professor requirements
    const float bank = 1000.50, stBal = 100.00;
    float noCover = 0, cover = 0, bet = 0, bankBal, balance;
    std::vector<int> pDice;
    std::string pName;

    // String for player name
    std::cout << "Enter your name: ";
    std::cin >> pName;

    // Let the player know the starting amounts
    std::cout << "The starting bank is $" << bank << "\n";
    std::cout << "Your starting balance is $" << stBal << "\n\n";
    
    bankBal = bank;
    balance = stBal;
    noCover = bank;

    // Do While loop in order to set all bets
    // Bets are made until the full bank is covered or until the player
    //  decides to stop betting
    do{
        std::cout << "The bank is: $" << bank << "\n";
        std::cout << "The current unconvered amount is: $" << noCover << "\n";
        std::cout << "Your current balance is: $" << balance << "\n\n";
        std::cout << "Would you like to make a bet? [Y/N] (Q to quit game): ";
        std::cin >> betAsk;
        betAsk = toupper(betAsk); // Set the input to uppercase (y to Y)

        std::cout << "\n";
        
        // Input Validation
        while(betAsk != 'Y' && betAsk != 'N' && betAsk != 'Q'){
            std::cout << "Please enter a valid input [Y/N/Q]: ";
            std::cin >> betAsk;
            betAsk = toupper(betAsk);
            std::cout << "\n";
        }

        // Switch statement to ask if the player wants to bet money
        switch(betAsk){
            case 'Y':{
                if(balance >= noCover){
                    std::cout << "You can bet up to $" << noCover << ": ";
                    std::cin >> bet;
                    std::cout << "\n";

                    // Input validation
                    while(bet > noCover){
                        std::cout << "You can bet up to $" << noCover << ": ";
                        std::cin >> bet;
                        std::cout << "\n";
                    }

                    // Track player and banker balances
                    //  also track the covered and uncovered portion of
                    //  the bank
                    balance -= bet;
                    std::cout << "Your new balance is: $" << balance << "\n";
                    noCover -= bet;
                    cover += bet;
                }else{
                    std::cout << "You can bet up to $" << balance << ": ";
                    std::cin >> bet;
                    std::cout << "\n";
                    
                    while(bet > balance){
                        std::cout << "You can bet up to $" << balance << ": ";
                        std::cin >> bet;
                        std::cout << "\n";
                    }

                    balance -= bet;
                    std::cout << "Your new balance is: $" << balance << "\n";
                    noCover -= bet;
                    cover += bet;
                }
                break;
            }
            case 'N':{
                betting = false;
                break;
            }
            case 'Q':{
                exit(0);
            }
            default:{ // Just in case something fails
                std::cout << "You did not make a bet." << "\n";
                break;
            }
        }
        
        // Automatically end betting phase if the entire bank has been covered
        if(noCover == 0){
            betting = false;
        }

        // Automatically end betting phase if player cannot bet more money
        if(balance == 0){
            betting = false;
        }
    }while(betting == true);

    // Only remove the covered amount of the bank from the end balance
    bankBal -= cover;

    std::cout << "\n";

    // If no bets are made the banker takes the full banked portion back
    if(cover == 0){
        std::cout << "There were no bets made. The banker pockets the bank."   
            << "\n";
        bRoll = false;
        pRoll = false;
    }

    // Begin the banker's dice rolls
    while(bRoll == true){
        std::cout << "Banker rolls the dice." << "\n";

        // Roll then sort banker's three dice
        roll(bDice);

        // Ask what type of sort to use
        std::cout << "How would you like to sort the dice?" << "\n";
        std::cout << "1. Bubble Sort" << "\n";
        std::cout << "2. Selection Sort" << "\n";
        std::cin >> pickSort;

        while(pickSort != 1 && pickSort != 2){
            std::cout << "Please select a valid option." << "\n";
            std::cout << "1. Bubble Sort" << "\n";
            std::cout << "2. Selection Sort" << "\n";
            std::cin >> pickSort;
        }

        switch(pickSort){
        case 1:{
            bubbleSort(bDice, size);
            break;
        }
        case 2:{
            selectionSort(bDice, size);
            break;
        }
        default:
            break;
        }

        // Display the banker's three dice rolls
        std::cout << "The banker's roll is: ";
        std::cout << bDice[0] << " " << bDice[1] << " and "
            << bDice[2] << "\n\n";
        
        // All three dice rolled the same are a "triples" automatic win
        if(bDice[0] == bDice[1] == bDice[2]){
            std::cout << "Triples, banker automatic win" << "\n";
            if(bet > 0){
                std::cout << "You lose $" << bet << "\n"; 
                bankBal += bet + cover;
            }else{
                bankBal += cover;
            }
            bRoll = false;
            pRoll = false;
        // A roll of 4, 5, 6 is a "straight kill" automatic win
        }else if(bDice[0] == 4 && bDice[1] == 5 && bDice[2] == 6){
            std::cout << "4-5-6 straight kill, banker automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "You lose $" << bet << "\n"; 
                bankBal += bet + cover;
            }else{
                bankBal += cover;
            }
            bRoll = false;
            pRoll = false;
        // A non-6 pair rolled with a 6 is an automatic win
        }else if(bDice[0] == bDice[1] && bDice[0] != 6 && bDice[2] == 6){
            std::cout << "Non-6 pair with a 6, banker automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "You lose $" << bet << "\n"; 
                bankBal += bet + cover;
            }else{
                bankBal += cover;
            }
            bRoll = false;
            pRoll = false;
        // A roll of 1, 2, 3 is a "straight lose" automatic loss
        }else if(bDice[0] == 1 && bDice[1] == 2 && bDice[2] == 3){
            std::cout << "1-2-3 straight lose, banker automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "You win $" << bet * 2 << "\n";
                balance += (bet * 2);
                bankBal -= (bet * 2);
            }
            bRoll = false;
            pRoll = false;
        // A non-1 pair rolled with a 1 is an automatic loss
        }else if(bDice[1] == bDice[2] && bDice[1] != 1 && bDice[0] == 1){
            std::cout << "Non-1 pair with a 1, banker automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "You win $" << bet * 2 << "\n";
                balance += (bet * 2);
                bankBal -= (bet * 2);
            }
            bRoll = false;
            pRoll = false;
        // A pair rolled with a different number grants a point equal to
        //  the individual number
        }else if(bDice[0] == bDice[1]){
            point1 = bDice[2];
            std::cout << "The banker's point is: " << point1 << "\n";
            bRoll = false;
        }else if(bDice[1] == bDice[2]){
            point1 = bDice[0];
            std::cout << "The banker's point is: " << point1 << "\n";
            bRoll = false;
        }else if(bDice[0] == bDice[2]){
            point1 = bDice[1];
            std::cout << "The banker's point is: " << point1 << "\n";
            bRoll = false;
        }
        // If any conditions are met, bRoll = false and the program continues
    }

    // Begin the player's dice rolls
    while(pRoll == true){
        std::cout << pName << " rolls the dice." << "\n";

        // Roll then sort player's three dice
        roll(pDice);
        sortVect(pDice);

        // Display the player's three dice rolls
        std::cout << "Your roll is: ";
        std::cout << pDice[0] << " " << pDice[1] << " and "
            << pDice[2] << "\n\n";

        // All three dice rolled as 1 is an automatic win with a bet
        //  multiplier of 5
        if(pDice[0] == 1 && pDice[1] == 1 && pDice[2] == 1){
            std::cout << "Triple 1s, " << pName << " automatic win" << "\n";
            if(bet > 0){
                std::cout << "You win $" << bet * 5 << "\n";
                balance += (bet * 5);
                bankBal -= (bet * 5);
            }
            pRoll = false;
        // Non-1 triples is an automatic win with a bet multipler of 3
        }else if(pDice[0] == pDice[1] == pDice[2] && pDice[0] != 1){
            std::cout << "Triples, " << pName << " automatic win" << "\n";
            if(bet > 0){
                std::cout << "You win $" << bet * 3 << "\n";
                balance += (bet * 3);
                bankBal -= (bet * 2);
            }
            pRoll = false;
        }else if(pDice[0] == 4 && pDice[1] == 5 && pDice[2] == 6){
            std::cout << "4-5-6 straight kill, " << pName << "automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "You win $" << bet * 2 << "\n"; 
                balance += (bet * 2);
                bankBal -= (bet * 2);
            }
            pRoll = false;
        }else if(pDice[0] == 1 && pDice[1] == 2 && pDice[2] == 3){
            std::cout << "1-2-3 straight lose, " << pName << "automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "You lose $" << bet << "\n";
                bankBal += bet + cover;
            }
            pRoll = false;
        // Set the player's point just like the banker's point if
        //  a pair is rolled
        }else if(pDice[0] == pDice[1]){
            point2 = pDice[2];
            std::cout << pName << "'s point is: " << point2 << "\n";
            pRoll = false;
        }else if(pDice[1] == pDice[2]){
            point2 = pDice[0];
            std::cout << pName << "'s point is: " << point2 << "\n";
            pRoll = false;
        }else if(pDice[0] == pDice[2]){
            point2 = pDice[1];
            std::cout << pName << "'s point is: " << point2 << "\n";
            pRoll = false;
        }

        std::cout << "\n";
        
        // Compare the banker and player's points. Highest wins
        if(point2 != 0){
            if(point1 > point2){
                std::cout << "Banker has a higher point. You lose $"
                    << bet << "\n";
                bankBal += bet + cover;
            }else{
                std::cout << pName << " has a higher point. You win $"
                    << bet * 2 << "\n";
                balance += (bet * 2);
                bankBal -= (bet *2);
            }
        }
    }

    // Display the final banker and player balances
    std::cout << "\n";
    std::cout << "The banker ends with $" << round(bankBal) << "\n";
    std::cout << pName << " ends with $" << round(balance) << "\n";

    // Ask if the user wants to output the result to a file
    logRes = askFile();
    if(logRes == true){
        std::ofstream logs;
        logs.open ("records.txt", std::ofstream::in | std::ofstream::ate);
        // Check if the file was opened successfully before writing
        if(logs.is_open()){
            logs << "The banker ended with $" << bankBal << "\n";
            logs << pName << " ends with $" << balance << "\n";
            logs.close();
            std::cout << "Session recorded." << "\n";
        }else{
            std::cout << "Unable to open file." << "\n";
        }
    }

    return 0;
}

// Roll 3 dice array
void roll(int *arr){
    for(int i = 0; i < 3; i++){
        arr[i] = (rand() % 6) + 1;
    }
}

// Roll 3 dice vector, overloaded
void roll(std::vector<int> &vect){
    for(int i = 0; i < 3; i++){
        vect.push_back((rand() % 6) + 1);
    }
}

// Sort the vector
void sortVect(std::vector<int> &vect){
    sort(vect.begin(), vect.end());
}

// Swap function
void swap(int *x, int *y){  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  

// Bubble sort function with array
void bubbleSort(int *arr, int n){  
    for (int i = 0; i < n - 1; i++){
      for (int j = 0; j < n - i - 1; j++){
        if (arr[j] > arr[j + 1]){
            swap(&arr[j], &arr[j + 1]);
        }
      }
    }  
}

// Selection sort function with array
void selectionSort(int *arr, int n){  
    int var;  
  
    for (int i = 0; i < n-1; i++){  
        var = i;  
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[var]){
                var = j;
            }
            swap(&arr[var], &arr[i]);
        }
    }  
} 

// Ask user if they want to record to file and validate input
bool askFile(){
    bool confirm;
    char fileAsk;

    // Ask if the player would like to record the result in a file
    std::cout << "Would you like to record this result? [Y/N]: ";
    std::cin >> fileAsk;
    fileAsk = toupper(fileAsk);
    
    // Input validation
    while(fileAsk != 'Y' && fileAsk != 'N'){
        std::cout << "Please enter a valid response [Y/N]: ";
        std::cin >> fileAsk;
        fileAsk = toupper(fileAsk);
    }

    if(fileAsk == 'Y'){
        confirm = true; 
    }else if(fileAsk == 'N'){
        confirm = false;
    }
    
    return confirm;
}