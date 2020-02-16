/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Feb 14
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX = 80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int read(char [][COLMAX], int &);//Outputs row and columns detected from input
void sort(char [][COLMAX], int, int);//Sort by row
void print(const char [][COLMAX], int, int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv){
    //Declare all Variables Here
    const int ROW = 30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn, colDet, rowIn, rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout << "Read in a 2 dimensional array of characters and sort by Row" << "\n";
    cout << "Input the number of rows <= 20" << "\n";
    cin >> rowIn;
    cout << "Input the maximum number of columns <= 20" << "\n";
    cin >> colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet = rowIn;
    cout << "Now input the array." << "\n";
    colDet = read(array, rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet == rowIn && colDet == colIn){
        sort(array, rowIn, colIn);
        cout << "The Sorted Array" << "\n";
        print(array, rowIn, colIn);
    }else{
        if(rowDet != rowIn)
        cout << (rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.") << "\n";
        if(colDet != colIn)
        cout << (colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.") << "\n";
    }
    
    //Exit
    return 0;
}

int read(char arr[][COLMAX], int &x){
    char temp[80];
    int longest = 0;

    for(int i = 0; i < x; i++){
        cin >> temp;
        strcpy(arr[i], temp);
        if(longest < strlen(arr[i])){
            longest = strlen(arr[i]);
        }
    }

    return longest;
}

void sort(char arr[][COLMAX], int row, int col){
    char temp[80];
    int cmp;

    // cout << "Pre-sort: " << "\n";
    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //         cout << arr[i][j];
    //     }
    //     cout << "\n";
    // }
    
    for(int i = 0; i < row; i++){
        if(strcmp(arr[i], arr[row - 1]) > 0){
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[row - 1]);
            strcpy(arr[row - 1], temp);
        }
    }

    // cout << "Post-sort: " << "\n";
    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //         cout << arr[i][j];
    //     }
    //     cout << "\n";
    // }
}

void print(const char arr[][COLMAX], int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
}
