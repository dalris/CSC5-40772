/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Feb 9
 * Purpose:  Exam Grading
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
    int correct = 0, incorrect = 0, wrongCt = 0;
    char key[20] = {'A', 'D', 'B', 'B', 'C',
                        'B', 'A', 'B', 'C', 'D',
                        'A', 'C', 'D', 'B', 'D',
                        'C', 'C', 'A', 'D', 'B'};
    char answers[20];
    
    cout << "Enter the student's test answers:" << "\n";
    for(int i = 0; i < 20; i++){
        cin >> answers[i];
    }
    
    for(int i = 0; i < 20; i++){
        if(answers[i] == key[i]){
            correct++;
        }else if(answers[i] != key[i]){
            incorrect++;
        }
    }
    
    if(correct >= 15){
        cout << "The student passed." << "\n";
    }else if(correct < 15){
        cout << "The student failed." << "\n";
    }
    
    cout << "There were " << correct << " correct answers." << "\n";
    cout << "There were " << incorrect << " incorrect answers." << "\n";
    cout << "Incorrect questions:" << "\n";
    
    int wrong[incorrect];
    
    for(int i = 0; i < 20; i++){
        if(answers[i] != key[i]){
            wrong[wrongCt] = i + 1;
            wrongCt++;
        }
    }
    
    for(int i = 0; i < incorrect ; i++){
        cout << wrong[i] << "\n";
    }

    //Exit stage right!
    return 0;
}