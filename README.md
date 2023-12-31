# CS463-Course-Project

## Info
> Title: Course Project  
> By: Sean Allgaier  
> Course: CS 463  
> Semester: Fall 2023  
> Professor: Dr. Charles Cartledge  

## Description 
### Project Proposal:

> "I would like to create a program written in C++ that uses the CLI to prompt the user to choose one of the different types of Block Ciphers. Once the user chooses a Block Cipher, the user will then be prompted to input 4 hex values, these values together will be used as the 16-bit input for the Block Ciphers. The program will then output the resulting value to the console for the user to view. Once the program is finished running, the user will be asked whether or not they would like to continue to run the program."

### Static values within program: 
> * IV = A9 
> * 8-bit key = C5 

(Note: Haven’t decided yet whether or not these two sets of hex values will remain static or if the user will be prompted to input the values instead.)  

## CLI Menu Tree:  

### “Pick a number:”  
### 1. Electronic Code Book (ECB)  
- Prompt user for hex values  
- Output Result of ECB  
- “Continue? [Y / N]”  

### 2. Cipher Block Chaining Mode (CBC)  
- Prompt user for hex values  
- Output Result of CBC  
- “Continue? [Y / N]”  

### 3. Output Feedback Mode (OFB) 
- Prompt user for hex values  
- Output Result of OFB     
- “Continue? [Y / N]”  

### 4. Cipher Feedback Mode (CFB) 	   
- Prompt user for hex values  
- Output Result of CFB  
- “Continue? [Y / N]”  

### 5. Counter Mode (CTR)  
- Prompt user for hex values  
- Output Result of CTR  
- “Continue? [Y / N]”  

### 6. Toggle Work
- Disabled (Default): Hides the math of the cipher blocks
- Enabled: Shows the math of the cipher blocks 

### 7. Exit

## Block Cipher Logic
[Click here to view the block cipher logic](block_cipher_logic.md)

## Instructions
[Click here to view the instructions](instructions.md)
