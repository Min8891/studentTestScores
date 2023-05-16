//  partb.cpp
//  Progam5
//  Created by Minjing Liang on 9/26/20.
//  Copyright © 2020 Minjing Liang. All rights reserved.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Info
{
    string name;
    double score;
};

// Function prototypes
void getData(Info *, int);
void selectionSort(Info*, int);
double getAverage(Info*, int);
void displayData(Info *, int, double);

int main()
{
    Info *Test;            // To dynamically allocate an array
    double average;        // To hold the average of the scores
    int num;            // To hold number of scores


    // Get number of scores
    cout << "How many scores do you have to average? ";
    cin  >> num;

    // Dynamically allocate an array larger enough
    // to hold the user-defined number of scores
    Test = new Info[num];    // Allocate memory


    getData(Test, num);

    selectionSort(Test, num);

    average = getAverage(Test,num);

    displayData(Test, num, average);

    delete [] Test;
    Test = 0;

    return 0;
}
void getData(Info *Test, int scores)
{
    cout << "Enter the names and scores for each student.\n";
    for (int i = 0; i < scores; i++)
    {
        cout << "Student #" << (i + 1) << endl;
        cout << "   Name: ";
        cin.ignore();
        getline(cin, (Test + i)->name);
        do
        {
            cout << "   Score :";
            cin  >> (Test + i)->score;

            if ((Test + i)->score < 0)
            {
                cout << "Scores must be greater than 0.\n"
                     << "Re-enter ";
            }
            cout << endl;
        } while ((Test + i)->score < 0);
    }
}
void selectionSort(Info *Test, int num)
{
    int start, minIndex;
    Info *minValue = nullptr;

    for (start = 0; start < (num - 1); start++)
    {
        minIndex = start;
        *minValue = Test[start];
        for (int i = start + 1; i < num; i++)
        {
            if ((Test + i)->score< minValue->score)
            {
                *minValue = Test[i];
                minIndex = i;
            }

        }
        Test[minIndex] = Test[start];
        Test[start] = * minValue;
    }
}
double getAverage(Info *Test, int Scores)
{
    double Total = 0;

    for (int i = 0; i < Scores; i++)
    {
        Total += (Test + i)->score;
    }

    return Total / Scores;
}

void displayData(Info *Test, int num, double Avg)
{
    cout << "    Test scores\n";
    cout << "Number of scores: " << num << endl;
    cout << "Scores in ascending-order:\n";
    for (int i = 0; i < num; i++)
    {
        cout << (Test + i)->name << ": " << (Test + i)->score << endl;
    }
    cout << fixed << showpoint << setprecision(2);
    cout << "Average of scores: " << Avg << endl;
}
