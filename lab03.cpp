//**************************************************************************************************
// FILE: Lab03.cpp
//
// DESCRIPTION: Reads three exam scores for three students, calculates and displays the average
// exam score and the standard deviation of the exam scores.
//
// AUTHORS: Rushi Patel
//
// COURSE: CSE100 Principles of Programming with C++, Spring 2017
//
// LAB INFO: Lab 3 Date/Time:  Lab TA:
// -------------------------------------------------------------------------------------------------
// TESTING
//
// Test Case 1
// -----------
// Description: Tests that the program computes and displays correct exam average and standard
// deviation.
//
// Input Data:
// Homer's exam score: 73
// Lisa's exam score: 100
// Ralph's exam score: 44
//
// Expected Output:
// The exam average score is: 72.33%
// The exam standard deviation is: 28.01
//
// Actual Output:
// The exam average score is: 72.33%
// The exam standard deviation is: 28.01
//
// Test 1 Case Results: Passed
//
// Test Case 2
// -----------
// Homer's exam score: 75
// Lisa's exam score: 90
// Ralph's exam score: 54
//
// Expected Output:
// The exam average score is: 73%
// The exam standard deviation is: 18.08
//
// Actual Output:
// The exam average score is: 73%
// The exam standard deviation is: 18.08
//
// Test 2 Case Results: Passed
//
// Test Case 3
// -----------
// Homer's exam score: 80
// Lisa's exam score: 100
// Ralph's exam score: 70
//
// Expected Output:
// The exam average score is: 83.33%
// The exam standard deviation is: 15.275
//
// Actual Output:
// The exam average score is: 83.33%
// The exam standard deviation is: 15.275
//
// Test 3 Case Results: Passed
//
//**************************************************************************************************
#include <iostream>
#include <cmath>
#include <iomanip>

constant int NUM_STUDENTS = 3;

int main()
{
    int exam_h, exam_l, exam_r;
    double exam_avg, exam_variance, exam_stddev;

    // Homer's exam score
    cout << "Enter exam score for Homer: ";
    cin >> exam_h;

    // Lisa's exam score
    cout << "Enter exam score for Lisa: ";
    cin >> exam_l;

    // Raplh's exam score
    cout << "Enter exam score for Ralph: ";
    cin >> exam_r;

    exam_avg = (exam_h + exam_l + exam_r) / NUM_STUDENTS;
    exam_variance = (pow(exam_h - exam_avg, 2) + pow(exam_l - exam_avg, 2) + pow(exam_r - exam_avg, 2)) / (NUM_STUDENTS - 1);
    exam_stddev = sqrt(exam_variance);

    cout << endl;
    cout << "The average exam score is: " << exam_avg << "%" << endl;
    cout << "The exam standard deviation is: " << exam_stddev << endl;

    return 0;
  }
