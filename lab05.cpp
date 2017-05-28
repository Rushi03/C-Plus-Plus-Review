//******************************************************************************
// FILE: Lab05.cpp
//
// DESCRIPTION
// Reads season statistics for basketball players from an input file named
// "stats-season.txt", computes per-game statistics, and writes the per-game
// statistics to an output file named "stats-game.txt".
//
// AUTHOR
// Rushi Patel
//
// COURSE INFO
// CSE100 Principles of Programming with C++, Spring 2017
// Lab 5, Date/Time:  TA:
//******************************************************************************
#include <cstdlib>    // For exit() function; see terminate() below
#include <fstream>    // For ifstream, ofstream
#include <iomanip>    // For setprecision(), setw()
#include <iostream>   // For cout, endl, fixed, left, right

using namespace std;

//==============================================================================
// Function Prototypes
//
// REMARK
// A prototype is a statement that provides a function declaration to the
// compiler. A prototype consists of just the function header. For example,
// consider this function:
//
// int sqr(int x)                <-- function header
// {                        --+
//     return x * x;          |  <-- function body
// }                        --+
//
// The function header is the first line of the function which consists of:
// (1) the data type of the return value; (2) the name of the function; and
// (3) the data types and names of the parameters.
//
// The function body (or the body of the function) consists of the pair of
// braces and the enclosed statements that are executed when the function is
// called.
//
// A prototype is necessary when a function is defined below the point in the
// source code file from where it is called. There is C++ syntax rule which
// states that a function must either be defined or declared above the point
// from where it is called. For example, in the case of terminate(), the function
// definition is below the function calls from open_input_file() and open_output
// _file(). Therefore, we have written a prototype for terminate() so it will be
// declared above the point from where it is called in those two functions.
//
// An alternative way to solve this problem would be to define terminate() above
// open_input_file() and open_output_file(), e.g.,
//
// void terminate(string msg)  -- terminate is defined above the locations
// {                           -- from where it is called
//     ...
// }
//
// int open_input_file(ifstream& fin, string filename)
// {
//     ...
//     terminate("Could not open input file for reading.");
//     ...
// }
//
// int open_output_file(ofstream& fout, string filename)
// {
//     ...
//     terminate("Could not open output file for writing.");
//     ...
// }
//
// Either way -- define terminate() first or declare terminate() -- is accept-
// able. Personally, I alphabetize the functions in my source code files, and
// then write prototypes for the ones that are defined below the point from
// where they are first called.
//==============================================================================

// Write the prototype for the output_player_stats() function. Hint: just copy-
// and-paste the function header and then make it a statement by writing a semi-
// colon at the end of the line.
output_player_stats();

// Write the prototype for the terminate() function.
terminate();

//------------------------------------------------------------------------------
// FUNCTION: compute_per_game_stats()
//
// DESCRIPTION
// Reads one line at a time from the input file, computes the per game stats for
// the player, and calls output_player_stats() to send the player's stats to the
// output file.
//
// PARAMETERS
// fin  - The input file stream, which is passed by-reference (ifstream&).
// fout - The output file stream, which is passed by-reference (ofstream&).
//------------------------------------------------------------------------------
void compute_per_game_stats(ifstream& fin, ofstream& fout)
{
    // Define int variables: gp, fm, fga, ftm, fta, threem, threea, pts, rebs
    int gp, fm, fga, ftm, fta, threem, threea, pts, rebs;

    // Define double variables: fgp, ftp, threep, ppg, rpg
    double fgp, ftp, threep, ppg, rpg;

    // Define string object/variable: name
    string name;

    // Do not worry about what the 'while' reserved word means. We will discuss
    // it when we cover Ch 5 of the book. If you are curious, the 'while' code
    // causes each line of input to be read, until we reach the line containing
    // "end".
    fin >> name;
    while (name != "end") {

        // Read nine values from fin storing the values in the variables gp, fgm,
        // fga, ftm, fta, threem, threea, pts, and rebs -- in that order.
        fin >> gp;
        fin >> fgm;
        fin >> fga;
        fin >> fta;
        fin >> threem;
        fin >> threea;
        fin >> pts;
        fin >> rebs;

        // Calculate the player's field goal percentage which is fgm / fga. Note:
        // since fgm and fga are both ints, the division will be performed as
        // integer division. However, we must perform floating point division,
        // so typecast fgm to double before dividing.
        fpg = static_cast<double>(fgm) / fga;

        // Calculate the player's free throw percentage which is ftm / fta. Note:
        // Typecast ftm to double.
        ftp = static_cast<double>(ftm) / fta;

        // Calculate the player's three point percentage which is threem / threea.
        // Note: Typecast threem to double.
        threep = static_cast<double>(threem) / threea;

        // Calculate the player's points per game, which is pts / gp. Note:
        // Typecast pts to double.
        ppg = static_cast<double>(pts) / gp;

        // Calculate the player's rebounds per game, which is rebs / gp. Note:
        // Typecast rebs to double.
        rpg = static_cast<double>(rebs) / gp;

        // Call output_player_stats() to output the player's stats. The args are
        // fout, name, gp, fgp, ftp, threep, ppg, and rpg.
        output_player_stats(fout, name, gp, fgp, ftp, threep, ppg, rpg);

        // Read the name of the next player from the input file.
        fin >> name;
   }
}

//------------------------------------------------------------------------------
// FUNCTION: open_input_file()
//
// DESCRIPTION
// Opens the file with name 'filename' for reading. Returns the file stream
// object fin by-reference. If the file cannot be opened for reading then call
// terminate to gracefully exit the program.
//
// PARAMETERS
// fin      - The input file stream (ifstream&).
// filename - The name of the file to be opened (string).
//------------------------------------------------------------------------------
void open_input_file(ifstream& fin, string filename)
{
    // Call the open() function on the fin parameter. Note that the open()
    // function expects the filename string to be a C-string rather than a C++
    // string. We can retrieve the C-string contained within the filename object
    // by calling the c_str() function on filename.
    fin.open(filename.c_str());

    // At this time, the file should be opened for reading. However, if the file
    // could not be opened (most likely because the file is not in the same
    // directory as the binary executable) then we will call terminate() to shut
    // down the program. Note: do not worry about what this code does as we will
    // discuss the if reserved word and how to use it when we cover Ch 4 of the
    // book.
    if (!fin) {
        terminate("Could not open input file for reading.");
    }
}

//------------------------------------------------------------------------------
// FUNCTION: open_output_file()
//
// DESCRIPTION
// Opens the file with name 'filename' for writing. Returns the file stream
// object fout by-reference. If the file cannot be opened for writing then call
// terminate to gracefully exit the program.
//
// PARAMETERS
// fout     - The output file stream (ofstream&).
// filename - The name of the file to be opened (string).
//------------------------------------------------------------------------------
void open_output_file(ofstream& fout, string filename)
{
    // Call the open() function on the fout parameter. See open_input_file()
    // for how to do this.
    fout.open(filename.c_str());

    // See comments in open_input_file().
    if (!fout) {
        terminate("Could not open output file for writing.");
    }
}

//------------------------------------------------------------------------------
// FUNCTION: output_header()
//
// DESCRIPTION
// Outputs the row containing the column header labels to the output file.
//------------------------------------------------------------------------------
void output_header(ofstream& fout)
{
    // Make certain you understand how this code works.
    fout << left << setw(16) << "Name";
    fout << right << setw(4) << "GP";
    fout << setw(6) << "PPG";
    fout << setw(6) << "RPG";
    fout << setw(7) << "FG%";
    fout << setw(7) << "FT%";
    fout << setw(7) << "3P%";
    fout << endl;
}

//------------------------------------------------------------------------------
// FUNCTION: output_player_stats()
//
// DESCRIPTION
// Outputs the stats for one player to the output file. Configures fout to
// properly display the results per the example in the lab project document.
//
// PARAMETERS
// fout    - The output file stream (ofstream&)
// name    - The player's name (string)
// gp      - Games played (int)
// fgp     - Field goal percentage (double)
// ftp     - Free throw percentage (double)
// threep  - Three point percentage (double)
// ppg     - Points per game (double)
// rpg     - Rebounds per game (double)
//------------------------------------------------------------------------------
void output_player_stats(ofstream& fout, string name, int gp, double fgp,
    double ftp, double threep, double ppg, double rpg)
{
    // Configure fout for fixed mode, left justification, and a field width of
    // 16. Then output the value of variable 'name'.
    fout << left << setw(16) << name;

    // Configure fout for right justification, display 1 digit after the decimal
    // point, and a field width of 4. Then output the value of variable gp.
    fout << right << fixed(1) << setw(4) << gp;

    // Configure fout for a field of width 6. Output ppg.
    fout << setw(6) << ppg;

    // Configure fout for a field of width 6. Output rpg.
    fout << setw(6) << rpg;

    // Configure fout for 3 digits after the decimal point, and a field width
    // of 7. Then output the value of variable fgp.
    fout << fixed(3) << setw(7) << fgp;

    // Configure fout for a field of width 7. Output ftp.
    fout << setw(7) << ftp;

    // Configure fout for a field of width 7. Output threep.
    fout << setw(7) << threep;

    // Send a newline to fout.
    fout << \n;
}

//------------------------------------------------------------------------------
// FUNCTION: terminate()
//
// DESCRIPTION
// Called when either the input or output file cannot be opened. Sends msg to
// the output window and then calls the C++SL exit() function to terminate the
// program. The value that exit() returns goes back to the operating system; it
// is a fairly common convention to return negative values indicating error
// conditions.
//
// PARAMETERS
// msg - The message to be displayed (string)
//------------------------------------------------------------------------------
void terminate(string msg)
{
    // Send msg to cout to display the message on the output window.
    cout << msg;

    // There is a function in the C++SL called exit(). It has one parameter,
    // which is an int. exit() will terminate the program and send the int param
    // value back to the operating system. It is a common convention to return a
    // negative integer to indicate that the program terminated because of some
    // error condition.
    //
    // Call exit() passing -1 as the arg.
    exit(-1);
}

//------------------------------------------------------------------------------
// FUNCTION: main()
//
// DESCRIPTION
// main() opens the input and output files. Then it calls compute_per_game_
// stats() to compute and send the player's stats to the output file. Closes
// the input and output files before returning.
//------------------------------------------------------------------------------
int main()
{
    // Define an ifstream object named fin (fin = File INput).
    ifstream fin;

    // Define an ofstream object named fout (fout = File OUTput).
    ofstream fout;

    // Call open_input_file() passing fin and the input file name as args.
    open_input_file(fin, filename);

    // Call open_output_file() passing fout and the output file name as args.
    open_output_file(fout, filename);

    // Call output_header() passing fout as the arg.
    output_header(fout);

    // Call compute_per_game_stats() passing fin and fout as args.
    compute_per_game_stats(fin, fout);

    // Close the input and output files by calling the close() functions on fin
    // and fout.
    fin.close();
    fout.close();

    // Return 0 from main().
    return 0;
}
