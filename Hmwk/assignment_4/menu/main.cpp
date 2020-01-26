/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 26
 * Purpose:  Menu
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    unsigned char nProbs;//Number of problems in menu < 10
    unsigned char choose;//User's choice
    
    //Initialize values
    nProbs='3';
    
    //Loop on menu and problems
    do{
        //Display the menu
        cout<<"Choose the Problem Solution to Display"<<endl;
        cout<<"1. Problem solution for 1"<<endl;
        cout<<"2. Problem solution for 2"<<endl;
        cout<<"3. Problem solution for 3"<<endl;
        cout<<"4. Problem solution for 4"<<endl;
        cout<<"5. Problem solution for 5"<<endl;
        cout<<"6. Problem solution for 6"<<endl;
        cout<<"7. Problem solution for 7"<<endl;
        cout<<"8. Problem solution for 8"<<endl;
        cout<<"9. Problem solution for 9"<<endl<<endl;
        cin>>choose;
        
        //Dependent upon the choice
        switch(choose){
            case '1':{
                int var1, sum = 0;
    
                cout << "Enter a positive integer value:" << "\n";
                cin >> var1;

                while(var1 < 0){
                    cout << "Enter a positive integer value:" << "\n";
                    cin >> var1;
                }

                for(int i = 1; i <= var1; i++){
                    sum += i;
                }

                cout << "The sum of all the integers from 1 to " << var1 << " is " << sum;
                
                break;
            }
            case '2':{
                float mlPerYr;
    
                cout << "Enter how many millimeters the ocean is rising per year:" << "\n";
                cin >> mlPerYr;

                cout << "Year" << "\t" << "Rise(mm)" << "\n";

                cout << fixed;

                for(int i = 1; i <= 30; i++){
                    cout << setprecision(1) << i << "\t" << mlPerYr * i << "\n";
                }
                
                break;
            }
            case '3':{
               float calories;

               cout << "Enter how many calories are burned per minute:" << "\n";
               cin >> calories;

               cout << "Min" << "\t" << "Calories burned" << "\n";
               cout << fixed;

               for(int i = 1; i <= 6; i++){
                   cout << setprecision(1) << i * 5 << "\t" << i * 5 * calories << "\n";
               }
               
               break;
            }
            case '4':{
                int speed, hours;
    
                cout << "What is the speed of the vehicle in mph?" << "\n";
                cin >> speed;

                cout << "How many hours has it traveled?" << "\n";
                cin >> hours;

                cout << "Hour   Distance Traveled" << "\n";

                for(int i = 1; i <= hours; i++){
                    cout << i << setw(15) << i * speed << "\n";
                }
                
                break;
            }
            case '5':{
                int floors, floorRms, floorOcc, totalRms = 0, totalOcc = 0;

                cout << "Enter how many floors there are:" << "\n";
                cin >> floors;

                for(int i = 1; i <= floors; i++){
                    cout << "Enter how many rooms are on floor " << i << ":" << "\n";
                    cin >> floorRms;

                    cout << "Enter how many are occupied:" << "\n";
                    cin >> floorOcc;

                    totalRms += floorRms;
                    totalOcc += floorOcc;
                }

                cout << "There are " << totalOcc << " rooms occupied." << "\n";
                cout << "There are " << totalRms - totalOcc << " rooms unoccupied." << "\n";

                cout << fixed;
                cout << setprecision(1) << (totalOcc * 100.00) / totalRms << "% of rooms are occupied.";
                
                break;
            }
            case '6':{
                float flt1, flt2, flt3;

                cout << "Enter first number:" << "\n" << "\n";
                cin >> flt1;

                cout << "Enter Second number:" << "\n" << "\n";
                cin >> flt2;

                cout << "Enter third number:" << "\n" << "\n";
                cin >> flt3;

                cout << fixed;

                if(flt1 > flt2){
                    cout << "Largest number from two parameter function:" << "\n";
                    cout << setprecision(1) << flt1 << "\n" << "\n";

                    if(flt1 > flt3){
                        cout << "Largest number from three parameter function:" << "\n";
                        cout << setprecision(1) << flt1 << "\n";
                    }else{
                        cout << "Largest number from three parameter function:" << "\n";
                        cout << setprecision(1) << flt3 << "\n";
                    }
                }else{
                    cout << "Largest number from two parameter function:" << "\n";
                    cout << setprecision(1) << flt2 << "\n" << "\n";

                    if(flt2 > flt3){
                        cout << "Largest number from three parameter function:" << "\n";
                        cout << setprecision(1) << flt2 << "\n";
                    }else{
                        cout << "Largest number from three paremeter function:" << "\n";
                        cout << setprecision(1) << flt3 << "\n";
                    }
                }
                
                break;
            }
            case '7':{
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

                    if(age < 30){
                        cout << "Waist size = " << weight / 5.7 << "\n\n";
                    }else if(age >= 30){
                        float adjustment;

                        adjustment = floor((age - 28.0) / 2.0) * (1.0/10.0);

                        cout << "Waist size = " << (weight / 5.7) + adjustment << "\n\n";
                    }


                    cout << "Run again:" << "\n";
                    cin >> choice;
                    cin.clear();
                }while(choice == 'y');
                
                break;
            }
            case '8':{
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
               break;
            }
            case '9':{
                const float cost = 3.50;
                float total = 0.0;

                cout << fixed;

                do{
                  int coinMenu = 0;

                    cout << "List of coins:" << "\n";
                    cout << "1. Nickel" << "\n";
                    cout << "2. Dime" << "\n";
                    cout << "3. Quarter" << "\n";
                    cout << "4. Dollar" << "\n";
                    cout << "Enter number for coin:" << "\n";
                    cin >> coinMenu;

                    switch(coinMenu){
                        case 1:{
                            total += 0.05;
                            break;
                        }
                        case 2:{
                            total += 0.10;
                            break;
                        }
                        case 3:{
                            total += 0.25;
                            break;
                        }
                        case 4:{
                            total += 1.00;
                            break;
                        }
                    }

                    cout << setprecision(2) << "\n" << "Current amount: $" << total << "\n";

                }while(total < cost);

                cout << "Enjoy your deep-fried twinkie" << "\n";

                if(total > cost){
                    cout << setprecision(2) << "Change to be returned: $" << total - cost << "\n";
                }
               break;
            }
            default:cout<<"Exiting Menu"<<endl;
        }
    }while(choose<=nProbs);

    //Exit stage right!
    return 0;
}