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

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){
    //Set Random Number seed
    srand(time(0));

    int roll1, roll2, roll3, dice1, dice2, dice3, point1 = 0, point2 = 0;
    char betAsk, bRoll = 'Y', pRoll = 'Y';
    // Money will have cents (atypical) due to professor requirements
    float bank = 1000.00, balance = 100.00, bet = 0; 

    std::cout << "The current unconvered bank is: $" << bank << "\n";
    std::cout << "Your current balance is: $" << balance << "\n\n";
    std::cout << "Would you like to make a bet?" << " ";
    std::cin >> betAsk;
    std::cout << "\n";

    switch(betAsk){
        case 'Y':{
            if(balance >= bank){
                std::cout << "You can bet up to $" << bank << ": ";
                std::cin >> bet;
            }else{
                std::cout << "You can bet up to $" << balance << ": ";
                std::cin >> bet;
            }
            break;
        }
        case 'y':{
            if(balance >= bank){
                std::cout << "You can bet up to $" << bank << ": ";
                std::cin >> bet;
            }else{
                std::cout << "You can bet up to $" << balance << ": ";
                std::cin >> bet;
            }
            break;
        }
        case 'N':{
            bet = 0;
            break;
        }
        case 'n':{
            bet = 0;
            break;
        }
        default:{
            std::cout << "You did not make a bet." << "\n";
            bet = 0;
            break;
        }
    }
    
    std::cout << "\n";

    if(bet == 0){
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
        std::cout << dice1 << " " << dice2 << " and " << dice3 << "\n";
        
        if(dice1 == dice2 == dice3){
            std::cout << "Triples, banker automatic win" << "\n";
            if(bet > 0){
                std::cout << "Player loses $" << bet << "\n"; 
            }
            bRoll = 'N';
        }else if(dice1 == 4 && dice2 == 5 && dice3 == 6){
            std::cout << "4-5-6 straight kill, banker automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "Player loses $" << bet << "\n"; 
            }
            bRoll = 'N';
        }else if(dice1 == dice2 && dice1 != 6 && dice3 == 6){
            std::cout << "Non-6 pair with a 6, banker automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet << "\n"; 
            }
            bRoll = 'N';
        }else if(dice1 == 1 && dice2 == 2 && dice3 == 3){
            std::cout << "1-2-3 straight lose, banker automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 2 << "\n";
            }
        }else if(dice2 == dice3 && dice2 != 1 && dice1 == 1){
            std::cout << "Non-1 pair with a 1, banker automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 2 << "\n";
            }
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
    
    std::cout << "\n";

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
        std::cout << dice1 << " " << dice2 << " and " << dice3 << "\n";

        if(dice1 == 1 && dice2 == 1 && dice3 == 1){
            std::cout << "Triple 1s, player automatic win" << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 5 << "\n"; 
            }
            pRoll = 'N';
        }else if(dice1 == dice2 == dice3 && dice1 != 1){
            std::cout << "Triples, player automatic win" << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 3 << "\n"; 
            }
            pRoll = 'N';
        }else if(dice1 == 4 && dice2 == 5 && dice3 == 6){
            std::cout << "4-5-6 straight kill, player automatic win"
                << "\n";
            if(bet > 0){
                std::cout << "Player wins $" << bet * 2 << "\n"; 
            }
            pRoll = 'N';
        }else if(dice1 == 1 && dice2 == 2 && dice3 == 3){
            std::cout << "1-2-3 straight lose, player automatic loss"
                << "\n";
            if(bet > 0){
                std::cout << "Player loses $" << bet << "\n";
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

        if(point2 != 0){
            if(point1 > point2){
                std::cout << "Banker has a higher point. Player loses $"
                    << bet << "\n";
            }else{
                std::cout << "Player has a higher point. Player wins $"
                    << bet * 2 << "\n";
            }
            pRoll = 'N';
        }
    }

    return 0;
}