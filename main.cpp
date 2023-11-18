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

main()
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
        std::cout << std:: endl << "Encryption Result = " << encryptionResult << std::endl;
    }






}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string ECB(std::string hexInput, std::string hexKey, std::string IV)
{
    std::cout << std::endl << std::endl;
    std::cout << "blockCipherChoice = ECB" << std::endl;
    std::cout << "hexInput = " << hexInput << std::endl;


    std::string binaryHexInput = hex2Binary(hexInput);
    std::string binaryHexKey = hex2Binary(hexKey);
    std::string binaryIV = hex2Binary(IV);

    // std::string ecbFunction;

    std::string binaryECBresult;
    std::string hexECBresult;
    std::string binaryLTy1, binaryRTy1, binaryLKy1, binaryRKy1, binaryLCy1, binaryRCy1, binaryY1;
    std::string hexLTy1, hexRTy1, hexLKy1, hexRKy1, hexLCy1, hexRCy1, hexY1;

    std::string binaryLTy2, binaryRTy2, binaryLKy2, binaryRKy2, binaryLCy2, binaryRCy2, binaryY2;
    std::string hexLTy2, hexRTy2, hexLKy2, hexRKy2, hexLCy2, hexRCy2, hexY2;

    // boolWorkChoice();

    std::cout << std::endl << "Y1:" << std::endl;
    hexLTy1 = hexInput[0];
    hexRTy1 = hexInput[1];
    hexLKy1 = hexKey[0];
    hexRKy1 = hexKey[1];
    binaryLCy1 = XOR(hex2Binary(hexLKy1), hex2Binary(hexRTy1));
    binaryRCy1 = XOR(hex2Binary(hexRKy1), hex2Binary(hexLTy1));
    std::cout << "LT = " << hex2Binary(hexLTy1) << std::endl;
    std::cout << "RT = " << hex2Binary(hexRTy1) << std::endl;
    std::cout << "LK = " << hex2Binary(hexLKy1) << std::endl;
    std::cout << "RK = " << hex2Binary(hexRKy1) << std::endl;
    hexLCy1 = binary2Hex(XOR(hex2Binary(hexLKy1), hex2Binary(hexRTy1)));
    hexRCy1 = binary2Hex(XOR(hex2Binary(hexRKy1), hex2Binary(hexLTy1)));
    std::cout << "LC = LK xor RT = " << binaryLCy1 << " = " << hexLCy1 << std::endl;
    std::cout << "RC = RK xor LT = " << binaryRCy1 << " = " << hexRCy1 << std::endl;
    hexY1 = hexLCy1 + hexRCy1;
    std::cout << "Y1 = " << hexY1 << std::endl;

    std::cout << std::endl << "Y2:" << std::endl;
    hexLTy2 = hexInput[2];
    hexRTy2 = hexInput[3];
    hexLKy2 = hexKey[0];
    hexRKy2 = hexKey[1];
    binaryLCy2 = XOR(hex2Binary(hexLKy2), hex2Binary(hexRTy2));
    binaryRCy2 = XOR(hex2Binary(hexRKy2), hex2Binary(hexLTy2));
    std::cout << "LT = " << hex2Binary(hexLTy2) << std::endl;
    std::cout << "RT = " << hex2Binary(hexRTy2) << std::endl;
    std::cout << "LK = " << hex2Binary(hexLKy2) << std::endl;
    std::cout << "RK = " << hex2Binary(hexRKy2) << std::endl; 
    hexLCy2 = binary2Hex(XOR(hex2Binary(hexLKy2), hex2Binary(hexRTy2)));
    hexRCy2 = binary2Hex(XOR(hex2Binary(hexRKy2), hex2Binary(hexLTy2)));
    std::cout << "LC = LK xor RT = " << binaryLCy2 << " = " << hexLCy2 << std::endl;
    std::cout << "RC = RK xor LT = " << binaryRCy2 << " = " << hexRCy2 << std::endl;
    hexY2 = hexLCy2 + hexRCy2;
    std::cout << "Y2 = " << hexY2 << std::endl;

    hexECBresult = hexY1 + hexY2;

    return hexECBresult;
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

    std::vector<std::string> hexVector, binaryVectorString;
    std::string newHexValue;

    // Allocating size of hexVector to be equivalent to the number of hex values that will need to be outputted 
    for (int i = 0; i < binaryString.size()/4; i++)
    {
        hexVector.push_back("");
    }

    // Nested loops that break the "binaryString" up into smaller strings that contain 4 "bits" each
    // and then assigns those groups of 4 bits are assigned a new position within "binaryVectorString".    
    for (int i = 0; i < binaryString.size()/4; i++) 
    {
        // std::cout << i << std::endl;
        std::string tempBinaryString;

        for (int j = i*4; j < (i*4) + 4 ; j++)
        {
            // std::cout << "    " << j << std::endl;
            tempBinaryString += binaryString[j];
        }
        binaryVectorString.push_back(tempBinaryString);
    }

    // Wanted to make this a switch statement but C++ doesn't support using strings for switch statements
    // So have fun reading this broken switch statement and the series of if statements that were super tedious to type out
    for (int i = 0; i < binaryVectorString.size(); i++)
    {
        // switch(binaryVectorString[i])
        // {
        //     case '0000':
        //         hexVector[i] = '0';
        //         break;
        //     case '0001':
        //         hexVector[i] = '1';
        //         break;
        //     case '0010':
        //         hexVector[i] = '2';
        //         break;
        //     case '0011':
        //         hexVector[i] = '3';
        //         break;
        //     case '0100':
        //         hexVector[i] = '4';
        //         break;
        //     case '0101':
        //         hexVector[i] = '5';
        //         break;
        //     case '0110':
        //         hexVector[i] = '6';
        //         break;
        //     case '0111':
        //         hexVector[i] = '7';
        //         break;
        //     case '1000':
        //         hexVector[i] = '8';
        //         break;
        //     case "1001":
        //         hexVector[i] = '9';
        //         break;
        //     case "1010":
        //         hexVector[i] = 'A';
        //         break;
        //     case "1011":
        //         hexVector[i] = 'B';
        //         break;
        //     case "1100":
        //         hexVector[i] = 'C';
        //         break;
        //     case "1101":
        //         hexVector[i] = 'D';
        //         break;
        //     case "1110":
        //         hexVector[i] = 'E';
        //         break;
        //     case "1111":
        //         hexVector[i] = 'F';
        //         break;
        // }

        if (binaryVectorString[i] == "0000")
            hexVector[i] = '0';
        if (binaryVectorString[i] == "0001")
            hexVector[i] = '1';
        if (binaryVectorString[i] == "0010")
            hexVector[i] = '2';
        if (binaryVectorString[i] == "0011")
            hexVector[i] = '3';
        if (binaryVectorString[i] == "0100")
            hexVector[i] = '4';
        if (binaryVectorString[i] == "0101")
            hexVector[i] = '5';
        if (binaryVectorString[i] == "0110")
            hexVector[i] = '6';
        if (binaryVectorString[i] == "0111")
            hexVector[i] = '7';
        if (binaryVectorString[i] == "1000")
            hexVector[i] = '8';
        if (binaryVectorString[i] == "1001")
            hexVector[i] = '9';
        if (binaryVectorString[i] == "1010")
            hexVector[i] = "A";
        if (binaryVectorString[i] == "1011")
            hexVector[i] = "B";
        if (binaryVectorString[i] == "1100")
            hexVector[i] = "C";
        if (binaryVectorString[i] == "1101")
            hexVector[i] = "D";
        if (binaryVectorString[i] == "1110")
            hexVector[i] = "E";
        if (binaryVectorString[i] == "1111")
            hexVector[i] = "F";

        // I hate myself for not Googling a smaller function to convert from binary to hex
        // but dammitt I'm now committed so there's no backing down at this point
        // and if I have to suffer through this then so does everyone else that decides to read this code.
    }

    // Loop that takes all values contained within "hexVector" and combines them into a single string called "hexValue" 
    for (int i = 0; i < hexVector.size(); i++)
    {
        hexValue += hexVector[i];
    }

    return hexValue;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string hex2Binary(std::string hexString)
{
    std::vector<std::string> binaryVector;
    std::string newBinaryValue;

    // Allocates space in "binaryVector" so that it can have the proper number of binary values to represent the hex values of "hexString"
    for (int i = 0; i < hexString.size() * 4; i++)
    {
        binaryVector.push_back("");
    }

    // Switch statement to return binary values equivalent to the hex values contained within "hexString"
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
                binaryVector[i] = "0110";
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

    // Loop that takes all values contained within "binaryVector" and combines them into a single string called "newBinaryValue" 
    for (int i = 0; i < binaryVector.size(); i++)
    {
        newBinaryValue += binaryVector[i];
    }

    // std::cout << "newBinaryValue = " << newBinaryValue << std::endl;

    return newBinaryValue;
}

//--------------------------------------------------------------------------------------------------------------------------------------------

std::string XOR(std::string value1, std::string value2)
{
    std::vector<std::string> xorVector;
    std::string xorResult;
    int size = value1.size();
    int count1 = 0, count2 = 0;

    // Allocates space in "xorVector" so that it can have the same number of binary values as "value1" and "value2"
    for (int i = 0; i < value1.size(); i++)
    {
        xorVector.push_back("");
    }

    // XOR Function
    for (int i = 0; i < xorVector.size(); i++)
    {
        if ((value1[i] == '0' && value2[i] == '0') || (value1[i] == '1' && value2[i] == '1'))
            xorVector[i] = '0';
        else
            xorVector[i] = '1';
        // std::cout << xorVector[i] << std::endl;
    }

    // Takes all values within "xorVector" and concats them into a single string 
    for (int i = 0; i < xorVector.size(); i++)
    {
        xorResult += xorVector[i];
    }

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
