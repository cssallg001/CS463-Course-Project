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
#include <vector>

// using namespace std;

// Declaring functions
void menu();
bool continueMenu();
bool boolWorkChoice();
void inputErrorMessage(int errorChoice);
void showWork(std::string blockCipherType);
std::string hexChoice();
std::string binary2Hex(std::string binaryString);
std::string hex2Binary(std::string hexString);
std::string XOR(std::string value1, std::string value2);
std::string ECB(std::string hexInput, std::string hexKey, std::string IV);
std::string CBC(std::string hexInput, std::string hexKey, std::string IV);
std::string OFB(std::string hexInput, std::string hexKey, std::string IV);
std::string CFB(std::string hexInput, std::string hexKey, std::string IV);
std::string CTR(std::string hexInput, std::string hexKey, std::string IV);

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
        errorTypeMessage = "Invalid menu option";
    }
    else if (errorType == 1)
    {
        errorTypeMessage = "Invalid hex value(s)";
    }
    else if (errorType == 2)
    {
        errorTypeMessage = "Invalid number of hex values";
    }
    else if (errorType == 3)
    {
        errorTypeMessage = "errorTypeMessage4";          // Note: Update as more error types are figured out
    }

    std::cin.clear();                                                   // Clears user input
    std::cin.ignore(256, '\n'); 
    std::cout << std::endl << "ERROR: " << errorTypeMessage << ", please try again." << std::endl;      
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

        // Loops through each character of "blockCipherChoice" to make sure that the string is capatilized 
        for (int i = 0; i < blockCipherChoice.size(); i++)
        {
            if (!isdigit(blockCipherChoice[i]))
                blockCipherChoice[i] = toupper(blockCipherChoice[i]);
        }

        // // Loop that prevents program from moving on until user makes a valid string input
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
                encryptionResult = ECB(hexInput, hexKey, IV);

            }

            // else if: Option 2 (CBC)
            if (blockCipherChoice == "2" || blockCipherChoice == "CBC")
            {
                std::string hexInput = hexChoice();
                encryptionResult = CBC(hexInput, hexKey, IV);
            }

            // else if: Option 3 (OFB)
            if (blockCipherChoice == "3" || blockCipherChoice == "OFB")
            {
                std::string hexInput = hexChoice();
                encryptionResult = OFB(hexInput, hexKey, IV);
            }
            // else if: Option 4 (CFB)
            if (blockCipherChoice == "4" || blockCipherChoice == "CFB")
            {
                std::string hexInput = hexChoice();
                encryptionResult = CFB(hexInput, hexKey, IV);
            }
            // else if: Option 5 (CTR)
            if (blockCipherChoice == "5" || blockCipherChoice == "CTR")
            {
                std::string hexInput = hexChoice();
                encryptionResult = CTR(hexInput, hexKey, IV);
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
        std::cout << std::endl << "###################################################" << std::endl;
    }


    std::cout << std:: endl << "Encryption Results: " << std::endl;




}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string ECB(std::string hexInput, std::string hexKey, std::string IV)
{
    std::string ECBresult;

    std::cout << "blockCipherChoice = ECB" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;


    std::string binaryHexInput = hex2Binary(hexInput);
    std::string binaryHexKey = hex2Binary(hexKey);
    std::string binaryIV = hex2Binary(IV);




    boolWorkChoice();


















    return ECBresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string CBC(std::string hexInput, std::string hexKey, std::string IV)
{
    std::string CBCresult;

    std::cout << "blockCipherChoice = CBC" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;

    return CBCresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string OFB(std::string hexInput, std::string hexKey, std::string IV)
{    
    std::string OFBresult;

    std::cout << "blockCipherChoice = OFB" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;

    return OFBresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string CFB(std::string hexInput, std::string hexKey, std::string IV)
{
    std::string CFBresult;

    std::cout << "blockCipherChoice = CFB" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;

    return CFBresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string CTR(std::string hexInput, std::string hexKey, std::string IV)
{   
    std::string CTRresult;

    std::cout << "blockCipherChoice = CTR" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;

    return CTRresult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string binary2Hex(std::string binaryString)
{
    std::string hexValue;



    return hexValue;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string hex2Binary(std::string hexString)
{
    std::vector<std::string> binaryVector;
    std::string newBinaryValue;

    for (int i = 0; i < hexString.size(); i++)
    {
        switch(hexString[i])
        {
            case '0':
                binaryVector[i] = "0000";
                break;
            case '1':
                binaryVector[i] = "0001";
                break;
            case '2':
                binaryVector[i] = "0010";
                break;
            case '3':
                binaryVector[i] = "0011";
                break;
            case '4':
                binaryVector[i] = "0100";
                break;
            case '5':
                binaryVector[i] = "0101";
                break;
            case '6':
                binaryVector[i] = "0101";
                break;
            case '7':
                binaryVector[i] = "0111";
                break;
            case '8':
                binaryVector[i] = "1000";
                break;
            case '9':
                binaryVector[i] = "1001";
                break;
            case 'A':
                binaryVector[i] = "1010";
                break;
            case 'B':
                binaryVector[i] = "1011";
                break;
            case 'C':
                binaryVector[i] = "1100";
                break;
            case 'D':
                binaryVector[i] = "1101";
                break;
            case 'E':
                binaryVector[i] = "1110";
                break;
            case 'F':
                binaryVector[i] = "1111";
                break;
        }
    }

    for (int i = 0; i < binaryVector.size(); i++)
    {
        newBinaryValue += binaryVector[i];
    }
















    return newBinaryValue;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string XOR(std::string value1, std::string value2)
{
    std::string xorResult;

    return xorResult;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string hexChoice()
{
    std::string hexValue;

    // Jump point 
    hexValueJumpPoint:

    std::cout << std::endl << "Enter four hex values to be used as the 16-bit input: ";
    std::cin >> hexValue;

    // Loops through each character of "hexValue" to make sure that the std::string is capatilized 
    for (int i = 0; i < hexValue.size(); i++)
    {
        hexValue[i] = toupper(hexValue[i]);
    }

    // If statement to verify that the string "hexValue" contains four characters
    if (hexValue.size() == 4)
    {
        // Loop statement that verifies that each individual character of the string "hexValue" is a valid hex value.
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
        inputErrorMessage(2);                                                            // Outputs error message                                        
        goto hexValueJumpPoint;
    }

    //std:: cout << std::endl << "16-bit input: " << std::endl;

    //std::cout << std::endl;

    return hexValue;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

bool continueMenu()
{

    continueChoiceInput:
    std::string continueChoice;
    std::cout << "Would you like work to be shown? (Y/N): ";
    std::cin >> continueChoice;

    if (continueChoice.size() == 1 && (toupper(continueChoice[0]) == 'Y' || toupper(continueChoice[0] == 'N')))
    {
        if (continueChoice == "Y")
            return true;
        else
            return false;

    }
    // If "continueChoice" does not fit within the specified parameters above, execute "inputErrorMessage" function and jump to "continueChoiceInput".
    else
    {
        inputErrorMessage(0);                                                    // Outputs error message                                        
        goto continueChoiceInput;
    }
    
}

//--------------------------------------------------------------------------------------------------------------------------------------------

bool boolWorkChoice()
{
    workChoiceInput:
    std::string workChoice;
    std::cout << "Would you like work to be shown? (Y/N): ";
    std::cin >> workChoice;

    if (workChoice.size() == 1 && (toupper(workChoice[0]) == 'Y' || toupper(workChoice[0] == 'N')))
    {
        if (workChoice == "Y")
            return true;
        else
            return false;

    }
    // If "workChoice" does not fit within the specified parameters above, execute "inputErrorMessage" function and jump to "workChoiceInput".
    else
    {
        inputErrorMessage(0);                                                    // Outputs error message                                        
        goto workChoiceInput;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------

void showWork(std::string blockCipherType)
{

}

//--------------------------------------------------------------------------------------------------------------------------------------------
