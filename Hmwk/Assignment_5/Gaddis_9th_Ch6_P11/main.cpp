/* 
 * File: main.cpp
 * Author: Danziel Nguyen
 * Created on Jan 29
 * Purpose:  Test Scores
 */

//System Libraries
#include <iostream>
#include <iomanip>

using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getScore(int &);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);

//Execution Begins Here
int main(int argc, char** argv) {
	int test1, test2, test3, test4, test5;

	// get the score of 5 tests
	for(int i = 0; i < 5; i++){
		if(i == 0){
			getScore(test1);
		}else if(i == 1){
			getScore(test2);
		}else if(i == 2){
			getScore(test3);
		}else if(i == 3){
			getScore(test4);
		}else if(i == 4){
			getScore(test5);
		}
	}

	calcAverage(test1, test2, test3, test4, test5);
	
    //Exit stage right!
	return 0;
}

void getScore(int &score){
	int validScore;
	
	cout << "Enter a test score:" << "\n";
	cin >> validScore;

	while(validScore < 0){
		cout << "Invalid test score, please reenter:" << "\n";
		cin >> validScore;
	}
	
	score = validScore;
}

void calcAverage(int score1, int score2, int score3, int score4, int score5){
    int dropScore, sum;
    float average;
    
	dropScore = findLowest(score1, score2, score3, score4, score5);
	sum = score1 + score2 + score3 + score4 + score5 - dropScore;
	average = sum / 4.0;

	cout << fixed << setprecision(1);
	cout << "The average is " << average;
}

int findLowest(int score1, int score2, int score3, int score4, int score5){
	int lowestScore;
	
	if(score1 <= score2){
		lowestScore = score1;
	}else{
		lowestScore = score2;
	}
		
	if(score3 < lowestScore){
		lowestScore = score3;
	}else if(score4 < lowestScore){
		lowestScore = score4;
	}else if(score5 < lowestScore){
		lowestScore = score5;
	}
	
	return lowestScore;
}
