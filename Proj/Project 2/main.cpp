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
#include <cstdlib> // for Random
#include <ctime> // for time
#include <fstream> // for File output
#include <cctype> // for converting to uppercase
#include <math.h> // for rounding numbers

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){
    //Set Random Number seed
    srand(time(0));

    int roll1, roll2, roll3, dice1, dice2, dice3, point1 = 0, point2 = 0;
    char fileAsk, betAsk;
    bool betting = true, bRoll = true, pRoll = true;
    // Money may have cents (atypical) due to professor requirements
    const float bank = 1000.50, stBal = 100.00;
    float noCover = 0, cover = 0, bet = 0, bankBal, balance;

    // Let the player know the starting amounts
    std::cout << "The starting bank is $" << bank << "\n";
    std::cout << "Player starting balance is $" << stBal << "\n\n";
    
    bankBal = bank;
    balance = stBal;
    noCover = bank;

    // Do While loop in order to set all bets
    // Bets are made until the full bank is covered or until the player
    //  decides to stop betting
    do{
        std::cout << "The bank is: $" << bank << "\n";
        std::cout << "The current unconvered amount is: $" << noCover << "\n";
        std::cout << "Player current balance is: $" << balance << "\n\n";
        std::cout << "Would you like to make a bet? [Y/N]: ";
        std::cin >> betAsk;
        betAsk = toupper(betAsk); // Set the input to uppercase (y to Y)

        std::cout << "\n";
        
        // Input Validation
        while(betAsk != 'Y' && betAsk != 'N'){
            std::cout << "Please enter a valid input [Y/N]: ";
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

        // Roll three dice
        roll1 = (rand() % 6) + 1;
        roll2 = (rand() % 6) + 1;
        roll3 = (rand() % 6) + 1;

        // Manually sorting the three dice from least to greatest
        //  because of project restriction of no arrays allowed
        // Least to greatest makes it easier to track certain dice
        //  combinations later on
        if(roll1 <= roll2){
            dice1 = roll1;
            dice2 = roll2;
            if(dice1 < roll3){
                dice3 = roll3;
            }else{
                dice1 = roll3;
                dice2 = roll1;
                dice3 = roll2;
            }
        }else if(roll1 > roll2){
            dice1 = roll2;
            dice2 = roll1;
            if(dice1 < roll3){
                dice3 = roll3;
            }else{
                dice3 = dice2;
                dice2 = dice1;
                dice1 = roll3;
            }
        }

        // Display the banker's three dice rolls
        std::cout << "The banker's roll is: ";
        std::cout << dice1 << " " << dice2 << " and " << dice3 << "\n\n";
        
        // All three dice rolled the same are a "triples" automatic win
        if(dice1 == dice2 == dice3){
            std::cout << "Triples, banker automatic win" << "\n";
            if(bet > 0){
                std::cout << "Player loses $" << bet << "\n"; 
                bankBal += bet + cover;
            }else{
                bankBal += cover;
            }
            bRoll = false;
            pRoll = false;
        // A roll of 4, 5, 6 is a "straight kill" automatic win
        }else if(dice1 == 4 && dice2 == 5 && dice3 == 6){
            std::cout << "4-5-6 straight kill, banker automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "Player loses $" << bet << "\n"; 
                bankBal += bet + cover;
            }else{
                bankBal += cover;
            }
            bRoll = false;
            pRoll = false;
        // A non-6 pair rolled with a 6 is an automatic win
        }else if(dice1 == dice2 && dice1 != 6 && dice3 == 6){
            std::cout << "Non-6 pair with a 6, banker automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "Player loses $" << bet << "\n"; 
                bankBal += bet + cover;
            }else{
                bankBal += cover;
            }
            bRoll = false;
            pRoll = false;
        // A roll of 1, 2, 3 is a "straight lose" automatic loss
        }else if(dice1 == 1 && dice2 == 2 && dice3 == 3){
            std::cout << "1-2-3 straight lose, banker automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 2 << "\n";
                balance += (bet * 2);
                bankBal -= (bet * 2);
            }
            bRoll = false;
            pRoll = false;
        // A non-1 pair rolled with a 1 is an automatic loss
        }else if(dice2 == dice3 && dice2 != 1 && dice1 == 1){
            std::cout << "Non-1 pair with a 1, banker automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 2 << "\n";
                balance += (bet * 2);
                bankBal -= (bet * 2);
            }
            bRoll = false;
            pRoll = false;
        // A pair rolled with a different number grants a point equal to
        //  the individual number
        }else if(dice1 == dice2){
            point1 = dice3;
            std::cout << "The banker's point is: " << point1 << "\n";
            bRoll = false;
        }else if(dice2 == dice3){
            point1 = dice1;
            std::cout << "The banker's point is: " << point1 << "\n";
            bRoll = false;
        }else if(dice1 == dice3){
            point1 = dice2;
            std::cout << "The banker's point is: " << point1 << "\n";
            bRoll = false;
        }
        // If any conditions are met, bRoll = false and the program continues
    }

    // Begin the player's dice rolls
    while(pRoll == true){
        std::cout << "Player rolls the dice." << "\n";

        // Same as the banker, three dice are rolled
        roll1 = (rand() % 6) + 1;
        roll2 = (rand() % 6) + 1;
        roll3 = (rand() % 6) + 1;

        // Manually sorting the player's three dice
        if(roll1 <= roll2){
            dice1 = roll1;
            dice2 = roll2;
            if(dice1 < roll3){
                dice3 = roll3;
            }else{
                dice1 = roll3;
                dice2 = roll1;
                dice3 = roll2;
            }
        }else if(roll1 > roll2){
            dice1 = roll2;
            dice2 = roll1;
            if(dice1 < roll3){
                dice3 = roll3;
            }else{
                dice3 = dice2;
                dice2 = dice1;
                dice1 = roll3;
            }
        }

        // Display the player's three dice rolls
        std::cout << "The player's roll is: ";
        std::cout << dice1 << " " << dice2 << " and " << dice3 << "\n\n";

        // All three dice rolled as 1 is an automatic win with a bet
        //  multiplier of 5
        if(dice1 == 1 && dice2 == 1 && dice3 == 1){
            std::cout << "Triple 1s, player automatic win" << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 5 << "\n";
                balance += (bet * 5);
                bankBal -= (bet * 5);
            }
            pRoll = false;
        // Non-1 triples is an automatic win with a bet multipler of 3
        }else if(dice1 == dice2 == dice3 && dice1 != 1){
            std::cout << "Triples, player automatic win" << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 3 << "\n";
                balance += (bet * 3);
                bankBal -= (bet * 2);
            }
            pRoll = false;
        }else if(dice1 == 4 && dice2 == 5 && dice3 == 6){
            std::cout << "4-5-6 straight kill, player automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 2 << "\n"; 
                balance += (bet * 2);
                bankBal -= (bet * 2);
            }
            pRoll = false;
        }else if(dice1 == 1 && dice2 == 2 && dice3 == 3){
            std::cout << "1-2-3 straight lose, player automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "Player loses $" << bet << "\n";
                bankBal += bet + cover;
            }
            pRoll = false;
        // Set the player's point just like the banker's point if
        //  a pair is rolled
        }else if(dice1 == dice2){
            point2 = dice3;
            std::cout << "The player's point is: " << point2 << "\n";
            pRoll = false;
        }else if(dice2 == dice3){
            point2 = dice1;
            std::cout << "The player's point is: " << point2 << "\n";
            pRoll = false;
        }else if(dice1 == dice3){
            point2 = dice2;
            std::cout << "The player's point is: " << point2 << "\n";
            pRoll = false;
        }

        std::cout << "\n";
        
        // Compare the banker and player's points. Highest wins
        if(point2 != 0){
            if(point1 > point2){
                std::cout << "Banker has a higher point. Player loses $"
                    << bet << "\n";
                bankBal += bet + cover;
            }else{
                std::cout << "Player has a higher point. Player wins $"
                    << bet * 2 << "\n";
                balance += (bet * 2);
                bankBal -= (bet *2);
            }
        }
    }

    // Display the final banker and player balances
    std::cout << "\n";
    std::cout << "The banker ends with $" << round(bankBal) << "\n";
    std::cout << "The player ends with $" << round(balance) << "\n";

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

    // Switch statement to record the result or not
    switch(fileAsk){
        case 'Y':{
            std::ofstream logs;
            logs.open ("records.txt", std::ofstream::in | std::ofstream::ate);
            // Check if the file was opened successfully before writing
            if(logs.is_open()){
                logs << "The banker ended with $" << bankBal << "\n";
                logs << "The player ends with $" << balance << "\n";
                logs.close();
                std::cout << "Session recorded." << "\n";
            }else{
                std::cout << "Unable to open file." << "\n";
            }
            break;
        }
        case 'N':{
            break;
        }
        default:{
            break;
        }
    }

    return 0;
}