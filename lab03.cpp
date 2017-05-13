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
