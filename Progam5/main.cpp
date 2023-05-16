//  Progam5PartA student testscores
//  Created by Minjing Liang on 9/25/20.
//  Copyright © 2020 Minjing Liang. All rights reserved.
#include <iostream>
#include <iomanip>
using namespace std;
//function prototype
void selectionSort(double*,int);
double averageScore (double*, int);
void display(double*, int, double);

int main() {
    int num;
    double average;
    cout << "Please enter number of tests:"<<endl;
    cin >> num;
    double *testScore = new double [num]; // dynamic allocate memory to pointer variable
    for (int i = 0; i < num; i++){
        cout << "Test" << (i + 1) << ": ";
        cin >> *(testScore + i);
        while (*(testScore + i) < 0){   // valid input
            cout << "Negative values are not valid,";
            cout << "please enter again: "<< endl;
            cin >> *(testScore + i);
        }
    }
    selectionSort(testScore, num);  // call sort function
    average = averageScore(testScore,num); // call get average function
    display(testScore,num,average);  // call display function
    delete [] testScore;   // release the memory
    return 0;
}
void selectionSort(double *array, int size){  //selection sort function ascending order
    int start, minIndex;
    double minValue;
    for (start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = * (array+start);
        for (int i = start + 1; i < size; i++)
        {
            if (*(array + i) < minValue)
            {
                minValue = *(array +i);
                minIndex = i;
            }
        }
       *(array+minIndex) = *(array+start);
        *(array+start) = minValue;
    }
}
double averageScore (double * array, int size){  //function to get average score
    double total = 0;
    for (int i = 0; i < size; i++)
        total += *(array +i);
    return total / size;
}
void display(double *array, int size, double ave){  // display all scores and average
    
    cout << "\n\n\tTest Scores and Average "<< endl;
    cout << "\t------------------------\n\n";
    for (int i = 0; i < size; i++)
        cout << setw(5) << "Test" << i+1;
    cout << "  Average" <<endl;
    for (int i = 0; i < size; i++)
        cout << setw(5) << *(array + i) << " ";
    cout <<setw(7)<< fixed << setprecision(2) << ave <<endl;
}



