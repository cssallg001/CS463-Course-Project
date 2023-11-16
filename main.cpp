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

// using namespace std;

// Declaring functions
void menu();
void inputErrorMessage(int errorChoice);
bool verifyInput(std::string input, std::string inputType);
std::string hexBinaryConvert(std::string value, bool hexBinaryOption);
std::string binaryToHex(std::string binaryValue);
std::string hexToBinary(std::string hexValue);
std::string ECB(std::string hexInput);
std::string CBC(std::string hexInput);
std::string OFB(std::string hexInput);
std::string CFB(std::string hexInput);
std::string CTR(std::string hexInput);
std::string hexChoice();
std::string XOR(std::string value1, std::string value2);

//--------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    menu();
    std::cout << std::endl << std::endl << "Ending..." << std::endl << std::endl; 
    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

void inputErrorMessage(int errorType)
{
    std::string errorTypeMessage;


    if (errorType == 0)
    {
        errorTypeMessage = "menu option";
    }
    else if (errorType == 1)
    {
        errorTypeMessage = "hex value";
    }
    else if (errorType == 2)
    {
        errorTypeMessage = "erroTypeMessage3";          // Note: Update as more error types are figured out
    }
    else if (errorType == 3)
    {
        errorTypeMessage = "erroTypeMessage4";          // Note: Update as more error types are figured out
    }


    std::cin.clear();                                                   // Clears user input
    std::cin.ignore(256, '\n'); 
    std::cout << "Error: Invalid \'" << errorTypeMessage << "\', please try again." << std::endl << std::endl;      
}

//--------------------------------------------------------------------------------------------------------------------------------------------

void menu()
{
    std::string value;
    bool hexBinaryValue, proceed = 1;
    std::string hexKey = "C5", IV = "A9"; 
    std::string blockCipherChoice;
    std::string encryptionResult;


        // Menu to prompt user to choose between the different encryption methods
        std::cout << std::endl
        // << "0         1         2         3         4         5" << std::endl
        // << "012345678901234567890123456789012345678901234567890" << std::endl
            << "###################################################" << std::endl
            << "               CS 463 Course Project               " << std::endl
            << "                 By Sean Allgaier                  " << std::endl
            << "###################################################" << std::endl << std::endl;
    while (proceed == 1)
    {
        std::cout << std:: endl
            << "###################################################" << std::endl
            << "              Current Variable Values              " << std::endl
            << "---------------------------------------------------" << std::endl
        //  << "                      IV = A9                      " << std::endl
        //  << "                   8-bit key = C5                  " << std::endl
            << "                      IV = " << IV << "                      " <<std::endl
            << "                   8-bit key = " << hexKey << "                  " << std::endl
            << "###################################################" << std::endl
            << "                      Options                      " << std::endl
            << "---------------------------------------------------" << std::endl
            << "                      #1: ECB                      " << std::endl
            << "                      #2: CBC                      " << std::endl
            << "                      #3: OFB                      " << std::endl
            << "                      #4: CFB                      " << std::endl
            << "                      #5: CTR                      " << std::endl
            << "                      #6: Exit                     " << std::endl
            << "###################################################" << std::endl
            << std::endl;
    
    
        // Jump point 
        userInput:
        // Declaring variables
        std::cout << "Pick an option: ";
        std::cin >> blockCipherChoice;

        // Loops through each character of "blockCipherChoice" to make sure that the std::string is completely capatilized 
        for (int i = 0; i < blockCipherChoice.size(); i++)
        {
            if (!isdigit(blockCipherChoice[i]))
                blockCipherChoice[i] = toupper(blockCipherChoice[i]);
        }

        // // Loop that prevents program from moving on until user makes a valid std::string input
        // while (std::cin.fail())
        // {
        //     inputErrorMessage(0);                                                    // Outputs error message                                        
        //     goto userInput;
        // }



        // Series of "if" + "else if" statements to verify whether or not the user's input is valid
        // and to execute the functions for the menu options
        if (
            (blockCipherChoice == "1" || blockCipherChoice == "2" || blockCipherChoice == "3" || blockCipherChoice == "4" || blockCipherChoice == "5" || blockCipherChoice == "6")
            ||
            (blockCipherChoice == "ECB" || blockCipherChoice == "CBC" || blockCipherChoice == "OFB" || blockCipherChoice == "CFB" || blockCipherChoice == "CTR" || blockCipherChoice == "EXIT")
            ) 
        {
            // if: Option 1 (ECB)
            if (blockCipherChoice == "1" || blockCipherChoice == "ECB")
            {
                std::string hexInput = hexChoice();
                encryptionResult = ECB(hexInput);
            }

            // else if: Option 2 (CBC)
            if (blockCipherChoice == "2" || blockCipherChoice == "CBC")
            {
                std::string hexInput = hexChoice();
                encryptionResult = CBC(hexInput);
            }

            // else if: Option 3 (OFB)
            if (blockCipherChoice == "3" || blockCipherChoice == "OFB")
            {
                std::string hexInput = hexChoice();
                encryptionResult = OFB(hexInput);
            }
            // else if: Option 4 (CFB)
            if (blockCipherChoice == "4" || blockCipherChoice == "CFB")
            {
                std::string hexInput = hexChoice();
                encryptionResult = CFB(hexInput);
            }
            // else if: Option 5 (CTR)
            if (blockCipherChoice == "5" || blockCipherChoice == "CTR")
            {
                std::string hexInput = hexChoice();
                encryptionResult = CTR(hexInput);
            }
            // else if: Option 6 (Exit)
            if (blockCipherChoice == "6" || blockCipherChoice == "EXIT")
            {
                // To be further implemented
                proceed = 0;
            }
        }

        // If "menuChoice" does not fit within any of the specified parameters above, execute "inputErrorMessage" function and jump to "userInput".
        else
        {
            inputErrorMessage(0);                                                    // Outputs error message                                        
            goto userInput;
        }
        std::cout << std::endl << std::endl << "---------------------------------------------------" << std::endl << std::endl;
    }

    


    //hexBinaryConvert(value, hexBinaryValue);
    //binaryToHex(binaryValue);
    //hexToBinary(hexValue);




}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string ECB(std::string hexInput)
{
    std::string ECBresult;

    std::cout << "blockCipherChoice = ECB" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;

    return ECBresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string CBC(std::string hexInput)
{
    std::string CBCresult;

    std::cout << "blockCipherChoice = CBC" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;

    return CBCresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string OFB(std::string hexInput)
{    
    std::string OFBresult;

    std::cout << "blockCipherChoice = OFB" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;

    return OFBresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string CFB(std::string hexInput)
{
    std::string CFBresult;

    std::cout << "blockCipherChoice = CFB" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;

    return CFBresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string CTR(std::string hexInput)
{   
    std::string CTRresult;

    std::cout << "blockCipherChoice = CTR" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;

    return CTRresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string hexBinaryConvert(std::string value, bool hexBinaryOption)
{
    std::string convertedValue;
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

std::string binaryToHex(std::string binaryValue)
{
    std::string hexValue;



    return hexValue;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string hexToBinary(std::string hexValue)
{
    std::string binaryValue;


    return binaryValue;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string XOR(std::string value1, std::string value2)
{
    std::string xorResult;

    return xorResult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

bool verifyInput(std::string input, std::string inputType)
{
    bool inputVerification;


    return inputVerification;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string hexChoice()
{
    std::string hexValue;

    // Jump point 
    hexValueJumpPoint:

    std::cout << std::endl << "Enter four hex values to be used as the 16-bit input: ";
    std::cin >> hexValue;

    // Loops through each character of "hexValue" to make sure that the std::string is completely capatilized 
    for (int i = 0; i < hexValue.size(); i++)
    {
        hexValue[i] = toupper(hexValue[i]);
    }

    // If statement to verify that "hexValue" contains four characters
    if (hexValue.size() == 4)
    {
        // Loop statement that verifies that each individual character of "hexValue" is a valid hex value.
        for (int i = 0; i < hexValue.size(); i++)
        {
            if (
                hexValue[i] != '0' && hexValue[i] != '1' && hexValue[i] != '2' && hexValue[i] != '3' && hexValue[i] != '4'&& hexValue[i] != '5' && hexValue[i] != '6' && hexValue[i] != '7' && hexValue[i] != '8' && hexValue[i] != '9'
                &&
                hexValue[i] != 'A' && hexValue[i] != 'B' && hexValue[i] != 'C' && hexValue[i] != 'D' && hexValue[i] != 'E' && hexValue[i] != 'F'
                )
            {
                inputErrorMessage(1);                                                    // Outputs error message                                        
                goto hexValueJumpPoint;
            }
        }
    }
    else 
    {
        inputErrorMessage(1);                                                            // Outputs error message                                        
        goto hexValueJumpPoint;
    }

    //std:: cout << std::endl << "16-bit input: " << std::endl;

    std::cout << std::endl << std::endl;

    return hexValue;
}

//--------------------------------------------------------------------------------------------------------------------------------------------
