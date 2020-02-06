/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on 2020/02/03
 * Purpose:  Project 1: Sì-Wŭ-Liù (a.k.a. Cee-lo)
 * v1:
 *  - One banker with preset bank
 *  - One normal player (User)
 *  - Single round play
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){
    //Set Random Number seed
    srand(time(0));

    int roll1, roll2, roll3, dice1, dice2, dice3, point1 = 0, point2 = 0;
    char fileAsk, betAsk, betting = 'Y', bRoll = 'Y', pRoll = 'Y';
    // Money will have cents (atypical) due to professor requirements
    const float bank = 100.00, stBal = 100.00;
    float noCover = 0, cover = 0, bet = 0, bankBal, balance;

    std::cout << "The starting bank is $" << bank << "\n";
    std::cout << "Player starting balance is $" << stBal << "\n\n";
    
    bankBal = bank;
    balance = stBal;
    noCover = bank;

    do{
        std::cout << "The bank is: $" << bank << "\n";
        std::cout << "The current unconvered amount is: $" << noCover << "\n";
        std::cout << "Player current balance is: $" << balance << "\n\n";
        std::cout << "Would you like to make a bet? [Y/N]: ";
        std::cin >> betAsk;
        betAsk = toupper(betAsk);

        std::cout << "\n";
        
        while(betAsk != 'Y' && betAsk != 'N'){
            std::cout << "Please enter a valid input [Y/N]: ";
            std::cin >> betAsk;
            betAsk = toupper(betAsk);
            std::cout << "\n";
        }

        switch(betAsk){
            case 'Y':{
                if(balance >= noCover){
                    std::cout << "You can bet up to $" << noCover << ": ";
                    std::cin >> bet;
                    std::cout << "\n";

                    while(bet > noCover){
                        std::cout << "You can bet up to $" << noCover << ": ";
                        std::cin >> bet;
                        std::cout << "\n";
                    }

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
                betting = 'N';
                break;
            }
            default:{
                std::cout << "You did not make a bet." << "\n";
                break;
            }

           
        }

        if(noCover == 0){
                betting = 'N';
        }

    }while(betting == 'Y');

    bankBal -= cover;

    std::cout << "\n";

    if(cover == 0){
        std::cout << "There were no bets made. The banker pockets the bank."   
            << "\n";
        bRoll = 'N';
        pRoll = 'N';
    }

    while(bRoll == 'Y'){
        std::cout << "Banker rolls the dice." << "\n";

        roll1 = (rand() % 6) + 1;
        roll2 = (rand() % 6) + 1;
        roll3 = (rand() % 6) + 1;

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

        std::cout << "The banker's roll is: ";
        std::cout << dice1 << " " << dice2 << " and " << dice3 << "\n\n";
        
        if(dice1 == dice2 == dice3){
            std::cout << "Triples, banker automatic win" << "\n";
            if(bet > 0){
                std::cout << "Player loses $" << bet << "\n"; 
                bankBal += bet + cover;
            }else{
                bankBal += cover;
            }
            bRoll = 'N';
            pRoll = 'N';
        }else if(dice1 == 4 && dice2 == 5 && dice3 == 6){
            std::cout << "4-5-6 straight kill, banker automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "Player loses $" << bet << "\n"; 
                bankBal += bet + cover;
            }else{
                bankBal += cover;
            }
            bRoll = 'N';
            pRoll = 'N';
        }else if(dice1 == dice2 && dice1 != 6 && dice3 == 6){
            std::cout << "Non-6 pair with a 6, banker automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet << "\n"; 
                bankBal += bet + cover;
            }else{
                bankBal += cover;
            }
            bRoll = 'N';
            pRoll = 'N';
        }else if(dice1 == 1 && dice2 == 2 && dice3 == 3){
            std::cout << "1-2-3 straight lose, banker automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 2 << "\n";
                balance += (bet * 2);
            }
            bRoll = 'N';
            pRoll = 'N';
        }else if(dice2 == dice3 && dice2 != 1 && dice1 == 1){
            std::cout << "Non-1 pair with a 1, banker automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 2 << "\n";
                balance += (bet * 2);
            }
            bRoll = 'N';
            pRoll = 'N';
        }else if(dice1 == dice2){
            point1 = dice3;
            std::cout << "The banker's point is: " << point1 << "\n";
            bRoll = 'N';
        }else if(dice2 == dice3){
            point1 = dice1;
            std::cout << "The banker's point is: " << point1 << "\n";
            bRoll = 'N';
        }else if(dice1 == dice3){
            point1 = dice2;
            std::cout << "The banker's point is: " << point1 << "\n";
            bRoll = 'N';
        }
        
    }

    while(pRoll == 'Y'){
        std::cout << "Player rolls the dice." << "\n";

        roll1 = (rand() % 6) + 1;
        roll2 = (rand() % 6) + 1;
        roll3 = (rand() % 6) + 1;

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

        std::cout << "The player's roll is: ";
        std::cout << dice1 << " " << dice2 << " and " << dice3 << "\n\n";

        if(dice1 == 1 && dice2 == 1 && dice3 == 1){
            std::cout << "Triple 1s, player automatic win" << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 5 << "\n";
                balance += (bet * 5);
            }
            pRoll = 'N';
        }else if(dice1 == dice2 == dice3 && dice1 != 1){
            std::cout << "Triples, player automatic win" << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 3 << "\n";
                balance += (bet * 3);
            }
            pRoll = 'N';
        }else if(dice1 == 4 && dice2 == 5 && dice3 == 6){
            std::cout << "4-5-6 straight kill, player automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 2 << "\n"; 
                balance += (bet * 2);
            }
            pRoll = 'N';
        }else if(dice1 == 1 && dice2 == 2 && dice3 == 3){
            std::cout << "1-2-3 straight lose, player automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "Player loses $" << bet << "\n";
                bankBal += bet + cover;
            }
            pRoll = 'N';
        }else if(dice1 == dice2){
            point2 = dice3;
            std::cout << "The player's point is: " << point2 << "\n";
            pRoll = 'N';
        }else if(dice2 == dice3){
            point2 = dice1;
            std::cout << "The player's point is: " << point2 << "\n";
            pRoll = 'N';
        }else if(dice1 == dice3){
            point2 = dice2;
            std::cout << "The player's point is: " << point2 << "\n";
            pRoll = 'N';
        }

        std::cout << "\n";

        if(point2 != 0){
            if(point1 > point2){
                std::cout << "Banker has a higher point. Player loses $"
                    << bet << "\n";
                bankBal += bet + cover;
            }else{
                std::cout << "Player has a higher point. Player wins $"
                    << bet * 2 << "\n";
                balance += (bet * 2);
            }
            pRoll = 'N';
        }
    }

    std::cout << "\n";
    std::cout << "The banker ends with $" << bankBal << "\n";
    std::cout << "The player ends with $" << balance << "\n";

    std::cout << "Would you like to record this result? [Y/N]: ";
    std::cin >> fileAsk;
    fileAsk = toupper(fileAsk);

    while(fileAsk != 'Y' && fileAsk != 'N'){
        std::cout << "Please enter a valid response [Y/N]: ";
        std::cin >> fileAsk;
        fileAsk = toupper(fileAsk);
    }

    switch(fileAsk){
        case 'Y':{
            std::fstream logs;
            logs.open ("records.txt", std::fstream::in | std::fstream::ate);
            if(logs.is_open()){
                logs << "The banker ended with $" << bankBal << "\n";
                logs << "The player ends with $" << balance << "\n";
                logs << "\n";
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