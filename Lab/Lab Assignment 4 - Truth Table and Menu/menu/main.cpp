/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on January 25, 2020, 1:29 PM
 * Purpose:  C++ Template
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
        cout<<"9. Problem solution for 9"<<endl;
        cout<<"10. Problem solution for 10"<<endl<<endl;
        cin>>choose;
        
        //Dependent upon the choice
        switch(choose){
            case '1':{
                int intA, intB;

                cout << "Enter a number:" << "\n";
                cin >> intA;

                cout << "Enter a number:" << "\n";
                cin >> intB;

                if(intA > intB){
                    cout << intA << " is larger";
                }else if(intB > intA){
                    cout << intB << " is larger";
                }
                break;
            }
            case '2':{
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
                break;
            }
            case '3':{
                int mnth, day, year;
    
                cout << "Enter a month:" << "\n";
                cin >> mnth;
                cout << "Enter a day:" << "\n";
                cin >> day;
                cout << "Enter a year:" << "\n";
                cin >> year;

                if(mnth * day == year){
                    cout << "The date is magic";
                }else{
                    cout << "The date is not magic";
                }
                break;
            }
            case '4':{
                int width1, width2, height1, height2;

                cout << "Enter the width of rectangle 1:" << "\n";
                cin >> width1;
                cout << "Enter the height of rectangle 1:" << "\n";
                cin >> height1;
                cout << "Enter the width of rectangle 2:" << "\n";
                cin >> width2;
                cout << "Enter the height of rectangle 2:" << "\n";
                cin >> height2;

                if(width1 * height1 > width2 * height2){
                    cout << "Rectangle 1 has the greater area";
                }else if(width1 * height1 < width2 * height2){
                    cout << "Rectangle 2 has the greater area";
                }else if(width1 * height1 == width2 * height2){
                    cout << "The rectangles have the same area";
                }
                break;
            }
            case '5':{
                float mass, weight;

                cout << "Enter the mass of an object:" << "\n";
                cin >> mass;

                weight = mass * 9.8;

                if(weight > 1000){
                    cout << "The object is too heavy";
                }else if(weight < 10){
                    cout << "The object is too light";
                }else{
                    cout << fixed;
                    cout << setprecision(1) << "The object weighs " << weight << " newtons";
                }
                break;
            }
            case '6':{
                int books;
    
                cout << "Enter how many books you purchased this month:" << "\n";
                cin >> books;

                if(books == 0){
                    cout << "You earned 0 points.";
                }else if(books == 1){
                    cout << "You earned 5 points.";
                }else if(books == 2){
                    cout << "You earned 15 points.";
                }else if(books == 3){
                    cout << "You earned 30 points.";
                }else if(books >= 4){
                    cout << "You earned 60 points.";
                }
                break;
            }
            case '7':{
                const int airFt = 1100, waterFt = 4900, steelFt = 16400;

                int soundMenu;
                float waveTime, distance = -1;

                cout << "Choose which medium the sound wave will travel in." << "\n";
                cout << "1.Air" << "\n";
                cout << "2.Water" << "\n";
                cout << "3.Steel" << "\n";
                cin >> soundMenu;

                while(distance < 0){
                    cout << "Enter the distance the wave will travel:" << "\n";
                    cin >> distance;
                }

                cout << fixed;

                switch(soundMenu){
                    case 1:
                    waveTime = distance / airFt;
                    cout << setprecision(4) << "The wave will take " << waveTime << " seconds";
                    break;
                    case 2:
                    waveTime = distance / waterFt;
                    cout << setprecision(4) << "The wave will take " << waveTime << " seconds";
                    break;
                    case 3:
                    waveTime = distance / steelFt;
                    cout << setprecision(4) << "The wave will take " << waveTime << " seconds";
                    break;
                }
                break;
            }
            case '8':{
                int temp;

                cout << "Enter a temperature:" << "\n";
                cin >> temp;

                if(temp <= -173){
                    cout << "Ethyl alcohol will freeze" << "\n";
                }else if(temp >= 172){
                    cout << "Ethyl alcohol will boil" << "\n";
                }

                if(temp <= -38){
                    cout << "Mercury will freeze" << "\n";
                }else if(temp >= 676){
                    cout << "Mercury will boil" << "\n";
                }

                if(temp <= -362){
                    cout << "Oxygen will freeze" << "\n";
                }else if(temp >= -306){
                    cout << "Oxygen will boil" << "\n";
                }

                if(temp <= 32){
                    cout << "Water will freeze" << "\n";
                }else if(temp >= 212){
                    cout << "Water will boil" << "\n";
                }
                break;
            }
            case '9':{
                int shapeMenu;

                cout << fixed;
                cout << "Geometry Calculator" << "\n";
                cout << "1. Calculate the Area of a Circle" << "\n";
                cout << "2. Calculate the Area of a Rectangle" << "\n";
                cout << "3. Calculate the Area of a Triangle" << "\n";
                cout << "4. Quit" << "\n";
                cin >> shapeMenu;

                if(shapeMenu < 1 || shapeMenu > 4){
                    cout << "Invalid entry, Reenter: " << "\n";
                    cin >> shapeMenu;
                }

                switch(shapeMenu){
                    case 1:{
                        float circRad;

                        cout << "Enter the radius of the circle:" << "\n";
                        cin >> circRad;

                        while(circRad < 0){
                            cout << "Invalid entry, Reenter:" << "\n";
                            cin >> circRad;
                        }

                        cout << setprecision(1) << "The area of the circle is " << 3.14159 * pow(circRad,2);

                        break;
                    }
                    case 2:{
                        float recLen, recHght;

                        cout << "Enter the length of the rectangle:" << "\n";
                        cin >> recLen;

                        while(recLen < 0){
                            cout << "Invalid entry, Reenter:" << "\n";
                            cin >> recLen;
                        }
                        cout << "Enter the height of the rectangle:" << "\n";
                        cin >> recHght;

                        while(recHght < 0){
                            cout << "Invalid entry, Reenter:" << "\n";
                            cin >> recHght;
                        }

                        cout << setprecision(1) << "The area of the rectangle is " << recLen * recHght;

                        break;
                    }
                    case 3:{
                        float triBase, triHght;

                        cout << "Enter the base of the triangle:" << "\n";
                        cin >> triBase;

                        while (triBase < 0){
                            cout << "Invalid entry, Reenter:" << "\n";
                            cin >> triBase;
                        }

                        cout << "Enter the height of the triangle:" << "\n";
                        cin >> triHght;

                        while (triHght < 0){
                            cout << "Invalid entry, Reenter:" << "\n";
                            cin >> triHght;
                        }

                        cout << setprecision(1) << "The area of the triangle is " << (triBase * triHght) / 2.0;

                        break;
                    }
                    case 4:
                    break;
                }
                break;
            }
            case '10':{
                float startTime, callTime, callCharge;

                cout << "Enter the starting time:" << "\n";
                cin >> startTime;

                while(startTime > 24.00 || static_cast<float>(startTime) > 59){
                    cout << "Invalid entry, Reenter:" << "\n";
                    cin >> startTime;
                }

                cout << "Enter the number of minutes of the call:" << "\n";
                cin >> callTime;

                if(startTime >= 0 && startTime <= 6.59){
                    callCharge = callTime * 0.05;
                }else if(startTime >= 7 && startTime <= 19){
                    callCharge = callTime * 0.45;
                }else if(startTime >= 19.01 && startTime <= 23.59){
                    callCharge = callTime * 0.20;
                }

                cout << fixed;
                cout << setprecision(2) << "The charges are $" << callCharge;
                break;
            }
            default:cout<<"Exiting Menu"<<endl;
        }
    }while(choose<=nProbs);

    //Exit stage right!
    return 0;
}