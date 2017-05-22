//**************************************************************************************************
// FILE: Lab02.cpp
//
// DESCRIPTION: Displays average rainfall for a three month period.
//
// AUTHOR: Rushi Patel
//
// COURSE: CSE100 Principles of Programming with C++, Spring 2017
//
// LAB INFO: Lab 2 Date/Time:  Lab TA:
//**************************************************************************************************
#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
    double april, may, june, average;

    cout << "Enter April rain amount (inches)? ";
    cin >> april;

    cout << "Enter May rain amount (inches)? ";
    cin >> may;

    cout << "Enter June rain amount (inches)? ";
    cin >> june;

    average = (april + may + june) / 3.0;

    cout << fixed << setprecision(2);
    cout << "The average rainfall was " << average << " inches." << endl;

    return 0;
}
