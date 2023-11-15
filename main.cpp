// Title: Course Project
// By: Sean Allgaier
// Course: CS 463
// Semester: Fall 2023
// Profesor: Dr. Charles Cartledge

#include <bitset>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <cmath>

using namespace std;

// Declaring functions
void menu();
void errorMessage();
string hexBinaryConvert(string value, bool hexBinaryOption);
string binaryToHex(string binaryValue);
string hexToBinary(string hexValue);
string ECB(string hexInput);
string CBC(string hexInput);
string OFB(string hexInput);
string CFB(string hexInput);
string CTR(string hexInput);

//--------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    menu();
    cout << endl << "Ending..." << endl << endl; 
    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

void menu()
{
    string value, binaryValue, hexValue, hexInput;
    bool hexBinaryValue, proceed = 1;

    // Menu to prompt user to choose between the different encryption methods
    std::cout << endl
    //      0         1         2         3         4         5           
    //      012345678901234567890123456789012345678901234567890
        << "###################################################" << endl
        << setw(32)
        << "Course Project" << endl
        << setw(33)
        << "By Sean Allgaier" << endl
        << "###################################################" << endl;
    
    while (proceed == 1)
    {




    }

    
    errorMessage();
    ECB (hexInput);
    CBC (hexInput);
    OFB (hexInput);
    CFB (hexInput);
    CTR (hexInput);
    hexBinaryConvert(value, hexBinaryValue);
    binaryToHex (binaryValue);
    hexToBinary (hexValue);




}

//--------------------------------------------------------------------------------------------------------------------------------------------

void errorMessage()
{
    std::cin.clear();                                                   // Clears user input
    std::cin.ignore(256, '\n'); 
    std::cout << "Invalid input, please try again." << endl << endl;      
}

//--------------------------------------------------------------------------------------------------------------------------------------------

string ECB(string hexInput)
{
    string ECBresult;

    return ECBresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

string CBC(string hexInput)
{
    string CBCresult;

    return CBCresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

string OFB(string hexInput)
{    
    string OFBresult;

    return OFBresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

string CFB(string hexInput)
{
    string CFBresult;

    return CFBresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

string CTR(string hexInput)
{   
    string CTRresult;


    return CTRresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

string hexBinaryConvert(string value, bool hexBinaryOption)
{
    string convertedValue;
    // value == hex/binary value that will be converted.
    // hexBinaryOption == value that determines the function being performed

    /*
    if (hexBinaryOption == 0)
        binaryToHex(value);
    else if (hexBinaryOption == 1)
        hexToBinary(value);
    else
    {
        errorMessage();
    }
    */




    return convertedValue;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

string binaryToHex(string binaryValue)
{
    string hexValue;



    return hexValue;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

string hexToBinary(string hexValue)
{
    string binaryValue;


    return binaryValue;
}
