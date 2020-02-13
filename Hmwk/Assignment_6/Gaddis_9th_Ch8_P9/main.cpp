/* 
 * File:   main.cpp
 * Author: Danziel Nguyen
 * Created on Feb 9
 * Purpose:  Bubble Sort
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void swap(int, int);
int bubbleSort(int[], int, int);
int selectionSort(int[], int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    int arr1[] = {
            81,36,37,85,52,70,38,55,31,37,
            27,58,32,40,99,79,92,31,32,64,
            92,35,85,66,27,67,23,11,91,88,
            17,18,71,49,13,82,68,82,23,12};
    int arr2[] = {
            81,36,37,85,52,70,38,55,31,37,
            27,58,32,40,99,79,92,31,32,64,
            92,35,85,66,27,67,23,11,91,88,
            17,18,71,49,13,82,68,82,23,12};
    int start, end, selCt, bubCt;
    
    cout << "Enter the starting location to sort:" << "\n";
    cin >> start;
    cout << "Enter the ending locaton to sort:" << "\n";
    cin >> end;
    
    selCt = selectionSort(arr2, start, end);
    bubCt = bubbleSort(arr1, start, end);
    
    cout << "Selection Sort " << selCt << "\n";
    cout << "Bubble Sort " << bubCt;
    
    //Exit stage right!
    return 0;
}

void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}  

int bubbleSort(int arr[], int start, int end)  
{  
    int swapCtr = 0;
    for(int i = start; i < end; i++){   
        for(int j = start; j < end - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swapCtr++;
            }
        }
    }
    return swapCtr;
}  

int selectionSort(int arr[], int start, int end)  
{  
    int swapCtr = 0;
    for (int i = start; i < end; i++){
        int min = i;  
        for (int j = i + 1; j < end; j++){
            if (arr[j] < arr[min]){
                min = j;
                swap(&arr[min], &arr[i]);
                swapCtr++;
            }
        }
    }  
    return swapCtr;
}  