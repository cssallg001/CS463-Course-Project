# CS463-Semester_Project

CS 463		Project Proposal		Sean Allgaier
Project Choice: Option #2 - Programming Project  

Description: 
I would like to create a program written in C++ that uses the CLI to prompt the user to choose one of the different types of Block Ciphers. Once the user chooses a Block Cipher, the user will then be prompted to input 4 hex values, these values together will be used as the 16-bit input for the Block Ciphers. The program will then output the resulting value to the console for the user to view. Once the program is finished running, the user will be asked whether or not they would like to continue to run the program.  

Use Homework #5 as the main reference  

Static values within program:	
IV = A9
8-bit key = C5  
(Note: Haven’t decided yet whether or not these two sets of hex values will remain static or if the user will be prompted to input the values instead.)  

> CLI Menu Tree:  
> “Pick a number: ”  
> 1 - Electronic Code Book (ECB)  
>> Prompt user for hex values  
>>> • Output Result of ECB  
> 2 - Cipher Block Chaining Mode (CBC)  
>>  • Prompt user for hex values  
>>> • Output Result of CBC  
> 3 Output Feedback Mode (CFB)    
• Prompt user for hex values  
• Output Result of CFB  
• 4 Counter Mode (CTR)  
	• Prompt user for hex values  
• Output Result of CTR  
• 5 alois Counter Mode (GCM)  
• Prompt user for hex values  
• Output Result of GCM  
	“Continue? [Y / N]”  
