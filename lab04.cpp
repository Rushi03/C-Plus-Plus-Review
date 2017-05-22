//**************************************************************************************************
// FILE: Lab04.cpp
//
// OBJECTIVES
// After completing this lab project, the student should be able to:
//
// 1. Define and use local variables of the int, double, and string data types.
// 2. Use cout to display string literals and variables.
// 3. Use cin to read values from the keyboard into variables.
// 4. Use the arithmetic operators.
// 5. Call math functions from the C++ Standard Library.
// 6. Write a function definition, call functions, pass arguments, and return values.
//
// AUTHOR
// Rushi Patel
//
//
// COURSE AND LAB INFO
// CSE100 Principles of Programming with C++, Spring 2017
// Lab 4   Date/Time:   TA:
//--------------------------------------------------------------------------------------------------
//
// TESTING SECTION
//
// --------------------------------------------------------------------------------------------
// TEST CASE 1
// --------------------------------------------------------------------------------------------
// DESCRIPTION:
// Tests that the program computes and displays the correct lucky number.
//
// TEST CASE INPUT DATA:
// Customer name    = Wilma
// Birthdate month  = 3
// Birthdate day    = 13
// Birthdate year   = 1970
// Height in inches = 80
// Weight in lbs    = 120
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Wilma, your lucky number is 5. Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// "Wilma, your lucky number is 5. Thank you, that will be $25."
//
// TEST CASE RESULT:
// PASSED
//
// --------------------------------------------------------------------------------------------
// TEST CASE 2
// --------------------------------------------------------------------------------------------
// TEST CASE INPUT DATA:
// Customer name    = Maggie
// Birthdate month  = 12
// Birthdate day    = 31
// Birthdate year   = 2014
// Height in inches = 29
// Weight in lbs    = 33
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Maggie, your lucky number is 6. Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// "Maggie, your lucky number is 6. Thank you, that will be $25."
//
// TEST CASE RESULT:
// PASSED
//
// --------------------------------------------------------------------------------------------
// TEST CASE 3
// --------------------------------------------------------------------------------------------
// TEST CASE INPUT DATA:
// Customer name    = Homer
// Birthdate month  = 7
// Birthdate day    = 14
// Birthdate year   = 1960
// Height in inches = 55
// Weight in lbs    = 292
//
// EXPECTED OUTPUT GIVEN THE INPUT:
// "Homer, your lucky number is 10. Thank you, that will be $25."
//
// OBSERVED OUTPUT:
// "Homer, your lucky number is 10. Thank you, that will be $25."
//
// TEST CASE RESULT:
// PASSED
//
//**************************************************************************************************

//--------------------------------------------------------------------------------------------------
// Include the necessary header files.
//--------------------------------------------------------------------------------------------------
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

ios::sync_with_stdio(false);             // Faster at reading input

const double CM_PER_INCH = 2.54;         // Centimeters per inch
const double LB_PER_KG = 2.20462262;     // Pounds per kilogram

//--------------------------------------------------------------------------------------------------
// calc_lucky() - Given the customer's birth date, month, year, height in cm, and weight in kg, cal-
// culates the lucky number and returns it as an int.
//--------------------------------------------------------------------------------------------------
int calc_lucky(int date, double height, int month, double weight, int year)
{
  int term1, term2, term3, lucky;
  double term4;

  term1 = 100 * pow(month, 2);
  term2 = 10 * pow(date, 3);
  term3 = (term1 + term2) / year;
  term4 = pow(weight, 6) / height;
  lucky = static_cast<int> (term3 + sqrt(term4)) % 10 + 1;
  return lucky;
}

//--------------------------------------------------------------------------------------------------
// convert_inch_to_cm() - Given a value in inches, returns the equivalent value in centimeters.
//--------------------------------------------------------------------------------------------------
double convert_inch_to_cm(double inches)
{
  return inches * CM_PER_INCH;
}

//--------------------------------------------------------------------------------------------------
// convert_lb_to_kg() - Given a value in pounds, returns the equivalent value in kilograms.
//--------------------------------------------------------------------------------------------------
double convert_lb_to_kg(double lbs)
{
  return lbs / LB_PER_KG;
}

//--------------------------------------------------------------------------------------------------
// get_int() - Displays the specified string prompt, reads an integer value from the keyboard, and
// returns the value. See http://www.devlang.com/static/s17/cse100/Get.cpp.
//--------------------------------------------------------------------------------------------------
int get_int(string prompt)
{
  int n;
  cout << prompt;
  cin >> n;
  return n;
}

//--------------------------------------------------------------------------------------------------
// get_string() - Displays the specified string prompt, reads a string value from the keyboard, and
// returns the string. See http://www.devlang.com/static/s17/cse100/Get.cpp.
//--------------------------------------------------------------------------------------------------
string get_string(string prompt)
{
  string s;
  cout << prompt;
  cin >> s;
  return s;
}

//--------------------------------------------------------------------------------------------------
// main()
//--------------------------------------------------------------------------------------------------
int main()
{
  int date, height_in, lucky, month, year, weight_lb;
  double height_cm, weight_kg;
  string name;

  cout << "Zelda's Lucky Number Calculator";

  name = get_string("What is your first name? ");
  month = get_int("In what month were you born? ");
  date = get_int("What was the date? ");
  year = get_int("What was the year (yyyy)? ");
  height_in = get_int("What is your height (inches)? ");
  weight_lb = get_int("What is your weight (lbs)? ");
  height_cm = convert_inch_to_cm(height_in);
  weight_kg = convert_lb_to_kg(weight_lb);
  lucky = calc_lucky(date, height_cm, month, weight_kg, year);

  cout << name << ", your lucky number is " << lucky << ". Thank you, that will be $25." << endl;

  return 0;
}
