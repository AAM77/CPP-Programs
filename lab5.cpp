/**********************************************************************************
  Author: Mohammad Adeel
  Course: {136}
  Section: Tuesday 7:00PM - 8:50PM
  Instructor: G.P.
  Assignment: "Lab 5", tasks 1 - 4 (All in one file, as you requested)

  In this task, we include all of the encryption and decryption functions.
  A switch menu allows the user to select s/he wants to us the Caesar cipher or
  Vigenere cipher for encryption or decryption. At the end the program, it prompts
  the user and asks if s/he wants to run another iteration of the program. If the
  user says yes, it starts over. If the user says no, the program ends.
  The program can also end if s/he enters 'q' or 'Q' at the menu prompt, or
  hit ctrl-D (eof).
***********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

//This first portion is part of the driver function that calls all the functions to
//provide the user with options to encrypt or decrypt a desired string s/he inputs
//All of the functions used are declared here, before the int main() driver function

string encryptCaesar(string inputString, int charShift);
string decryptCaesar(string inputString, int charShift);
string vigenereKey(string inputString, string& vigKey);
string vigenereEncrypt(string inputString, string vigKey);
string vigenereDecrypt(string inputString, string vigKey);
void menu(void);

    
int main()
{
    string userString;      //user unput string the user enters
    string vigKey;          //user input string key used for the Vigenere cipher 
    string vigEncrypted;    //variable for the function call to encrypt via Vigenere cipher
    string vigDecrypted;    //variable for the function call to decrypt via Vigenere cipher
    string csrEncrypted;    //variable for the function call to encrypt via Caeasar cipher
    string csrDecrypted;    //variable for the function call to decrypt via Caeasar cipher
    string key;             //variable for the updated key after function call to vigenere key
    int numShift;           //number to shift by using the caesar cipher 
    char menu_selection;    //variable for the menu options
    char choice;            //variable for yes/no
    
    //Here, I use a for loop that repeats and remains true so long as:
    //(1) count remains 0, (2) the menu selection is not 'q' or 'Q', and
    //(3) an eof key, like ctrl-D has not bee pressed
    //The loop starts by asking for a string to encrypt or decrypt.
    for (int count = 0; count < 1 || menu_selection != 'q' || menu_selection != 'Q' || (!cin.eof()); )
    {
        cout << "Please enter text you want to encrypt or decrypt. \n";
        getline(cin, userString);
        
        if (cin.eof())
        {
            break;
        }
        
        else
        {
            
            //It then displays menu options and prompts the user to select an option
            //If the user enters anything where the first letter is not a, b, c, d, or q,
            //the program restarts from the beginning.
            cout << endl;

            menu();

            cout << endl << "Please select which cipher you want to use (A, B, C, or D): \n"
                 << "Enter 'Q' if you want to end the program and quit. \n"
                 << "The program will restart if you enter anything besides this. \n";
            cin.get(menu_selection);

            cin.ignore(1000, '\n'); //clears the cin buffer so getline() and cin can work properly

            cout << "   \n";
            
            //I needed to include this to make the program break out of the loops and quit properly
            //upon pressing 'q' or 'Q'. I entered both uppercase and lowercase to make is case insensitive.
            if (menu_selection == 'q' || menu_selection == 'Q')
            {
                break;
            }
            else
            {
                //This switch statement contains 4 cases.
                //Case A serves as a driver for the function that encrypts using the Ceasar cipher
                //Case B serves as a driver for the function that decrypts using the Caesar cipher
                //Case C serves as a driver for the function that encrypts using the Vigenere cipher
                //Case D serves as a driver for the function that decrypts using the Vigenere cipher
                //Case Q is an option to quit the menu properly without using ctrl-D
                //Default case restarts the program if the user enters an invalid entry
                //I included an uppercase and lowercase for each case value to make the input case insensitive
                //Each case contains a (TEST) output to demonstrate that the function works properly.
                switch (menu_selection)
                {
                    case 'A':
                    case 'a':
                    {
                        cout << "<<< STARTING CAESAR ENCRYPTION >>> \n \n";

                        cout << "Please enter a numerical value you want to shift by: \n";
                        cin >> numShift;
                        csrEncrypted = (encryptCaesar(userString, numShift));

                        cout << "Original: " << userString << endl;
                        cout << "Encrypted: " << csrEncrypted << endl;
                        cout << "(TEST) RESULT DECRYPTED is: " << (decryptCaesar(csrEncrypted, numShift)) << endl;
                        break;
                    }

                        
                    case 'B':
                    case 'b':
                    {
                        cout << "<<< STARTING CAESAR DECRYPTION >>> \n \n";

                        cout << "Please enter a numerical value you want to shift by: \n";
                        cin >> numShift;
                        csrDecrypted = (decryptCaesar(userString, numShift));

                        cout << "Original: " << userString << endl;
                        cout << "Decrypted: " << csrDecrypted << endl;
                        cout << "(TEST) RESULT ENCRYPTED is: " << (encryptCaesar(csrDecrypted, numShift)) << endl;
                        break;
                    }


                    case 'C':
                    case 'c':
                    {
                        cout << "<<< STARTING VIGENERE ENCRYPTION >>> \n \n";

                        cout << "Enter text to use as the key for encrypting: \n";
                        getline(cin, vigKey);

                        key = (vigenereKey(userString, vigKey));
                        vigEncrypted = (vigenereEncrypt(userString, key));

                        cout << "Original: " << userString << endl;
                        cout << "Encrypted: " << vigEncrypted << endl;
                        cout << "(TEST) RESULT DECRYPTED is: " << (vigenereDecrypt(vigEncrypted, key)) << endl;
                        break;
                    }

                    case 'D':
                    case 'd':
                    {   
                        cout << "<<< STARTING VIGENERE DECRYPTION >>> \n \n";


                        cout << "Enter text to use as the key for decrypting: \n";
                        getline(cin, vigKey);

                        key = (vigenereKey(userString, vigKey));
                        vigDecrypted = (vigenereDecrypt(userString, key));

                        cout << "Original: " << userString << endl;
                        cout << "Decrypted: " << vigDecrypted << endl;
                        cout << "(TEST) RESULT ENCRYPTED is: " << (vigenereEncrypt(vigDecrypted, key)) << endl;
                        break;
                    }

                    case 'Q':
                    case 'q':
                    {
                        cout << "You have quit the program. \n" ;
                        break;
                        return 0;
                    }

                    default:
                    {
                            cout << "\n !!! ALERT: Invalid entry !!! \n \n "
                                 << "The program will now restart: \n \n";
                            continue; 
                    }
                }
                
                //This serves as an option to restart or end the program
                //A yes (y or Y) will start the program over.
                //A no or any other entry will break out of the loop end the program.
                cout << "Do you want to run the program again? (y/n) \n";
                cin >> choice;
                
                cin.ignore(1000, '\n');
                
                if (choice == 'y' || choice == 'Y')
                {
                    count = 0;
                }
                else
                {
                    break;
                    return 0;
                }       
            }
        }
    }


    return 0;
}

//This functions merely outputs a menu.
//I made it separate to make the above slightly more readable.
void menu(void)

{
    cout << "*** MENU OPTIONS *** \n";
    cout << "(A) Caesar Encryption \n";
    cout << "(B) Caesar Decryption \n";
    cout << "(C) Vigenere Encryption \n";
    cout << "(D) Vigenere Decryption \n";
    cout << "(Q) Quit / Exit the program \n";
}


// **** CAESAR ENCRYPTION FUNCTION ****

//This function takes two values
//One value is the input string the user wants to encrypt
//The second value is the number of letters the user wants to shift by
//A positive number shifts to the right.
//If a user enters a value above 26, the modulus reduces it to a value
//between 0 and 26.
//After adjusting the value, it goes through each position of the string
//and determines if it is a letter (uppercase or lowercase)/case-sensitive.
//If the letter goes past the ascii value for 'z' or 'Z' ir restarts at 'a' or 'A', respectively
//If the value is a letter, it shifts it by the desired amount, retaining case (upper/lower)
//If anything other than a letter, it leaves it alone and moves to the next postion.
string encryptCaesar(string inputString, int charShift)
{    
    
    string inputStr = inputString;
    
    if (charShift > 26 || charShift < 26)
    {
        charShift = (charShift % 26);
    }
    
    if (charShift >=0)
    {
        for (int i=0; i<=inputStr.length(); i++)
        {
            if ((inputStr[i] >= 'A' && inputStr[i] <= 'Z') || (inputStr[i] >= 'a' && inputStr[i] <= 'z'))
            {
                if (inputStr[i] >='A' && inputStr[i] <= 'Z')
                {
                    inputStr[i] = ((inputStr[i] + charShift - 'A') % 26) + 'A';
                }

                else if (inputStr[i] >='a' && inputStr[i] <= 'z')
                {
                    inputStr[i] = ((inputStr[i] + charShift - 'a') % 26) + 'a';
                }

                else
                {
                    cout << "!!Something Went Wrong!!";
                }
            }
        }
    }
    
    
    else if (charShift < 0)
    {
        for (int i=0; i<=inputStr.length(); i++)
        {
            if ((inputStr[i] >= 'A' && inputStr[i] <= 'Z') || (inputStr[i] >= 'a' && inputStr[i] <= 'z'))
            {
                if (inputStr[i] >='A' && inputStr[i] <= 'Z')
                {
                    inputStr[i] = ((inputStr[i] + charShift - 'Z') % 26) + 'Z';
                }

                else if (inputStr[i] >='a' && inputStr[i] <= 'z')
                {
                    inputStr[i] = ((inputStr[i] + charShift - 'z') % 26) + 'z';
                }

                else
                {
                    cout << "!!Something Went Wrong!!";
                }
            }
        }
    }

    return(inputStr);
}

// **** CAESAR DECRYPTION FUNCTION ****

//This function takes two values
//One value is the input string the user wants to decrypt
//The second value is the number of letters the user wants to shift by
//A positive number shifts to the right.
//If a user enters a value above 26, the modulus reduces it to a value
//between 0 and 26.
//After adjusting the value, it goes through each position of the string
//and determines if it is a letter (uppercase or lowercase)/case-sensitive.
//If the letter goes past the ascii value for 'z' or 'Z' ir restarts at 'a' or 'A', respectively
//If the value is a letter, it shifts it by the desired amount, retaining case (upper/lower)
//If anything other than a letter, it leaves it alone and moves to the next postion.
//It shifts in an opposite manner to the encyrption function
string decryptCaesar(string inputString, int charShift)
{    
    
    string inputStr = inputString;
    
    if (charShift > 26 || charShift < 26)
    {
        charShift = (charShift % 26);
    }
    
    if (charShift >=0)
    {
        for (int i=0; i<=inputStr.length(); i++)
        {
            if ((inputStr[i] >= 'A' && inputStr[i] <= 'Z') || (inputStr[i] >= 'a' && inputStr[i] <= 'z'))
            {
                if (inputStr[i] >='A' && inputStr[i] <= 'Z')
                {
                    inputStr[i] = ((inputStr[i] + 26 - charShift - 'A') % 26) + 'A';
                }

                else if (inputStr[i] >='a' && inputStr[i] <= 'z')
                {
                    inputStr[i] = ((inputStr[i] + 26 - charShift - 'a') % 26) + 'a';
                }

                else
                {
                    cout << "!!Something Went Wrong!!";
                }
            }
        }
    }
    
    
    else if (charShift < 0)
    {
        for (int i=0; i<=inputStr.length(); i++)
        {
            if ((inputStr[i] >= 'A' && inputStr[i] <= 'Z') || (inputStr[i] >= 'a' && inputStr[i] <= 'z'))
            {
                if (inputStr[i] >='A' && inputStr[i] <= 'Z')
                {
                    inputStr[i] = ((inputStr[i] - 26 + charShift - 'Z') % 26) + 'Z';
                }

                else if (inputStr[i] >='a' && inputStr[i] <= 'z')
                {
                    inputStr[i] = ((inputStr[i] - 26  + charShift - 'z') % 26) + 'z';
                }

                else
                {
                    cout << "!!Something Went Wrong!!";
                }
            }
        }
    }

    return(inputStr);
}

        
// **** VIGENERE GET KEY FUNCTION for ENCRYPTING & DECRYPTING ****

//This function is responsible for getting a key from the user and modifying it
//If the key is shorter in length than the string to be encrypted, the function
//copies the key into an empty string and concatenates as many copies or it as necessary
//to equal or exceed the length of the string to be encrypted
//after the length requirements are met, the function goes through each position of the
//newly created key and determines:
//(1) if the character in the string to be encrypted is a letter of the alphabet
//(2) the case of the letter in the string to be encrypted
//If it is not a letter of the alphabet, the function adds a space after the letter in the key
//and resets the position to one before, so that it continues where it left off.
//If is a letter, the function changes the case of the letter in the key to match the
//case of the string to be encrypted.
string vigenereKey(string inputString, string& vigKey)
{
    string origKey;
    string newKey;
    int g, h;
    
    if (origKey.length() <= inputString.length())
        {
            while (origKey.length() <= inputString.length())
            {
                origKey = origKey + vigKey;
            }
        }
    
    while (newKey.length() <= inputString.length())
    {
        for(g = 0, h = 0; h <= origKey.length(); g++, h++)
        {
            if (inputString[g] < 'A' || inputString[g] > 'z' || (inputString[g] > 'Z' && inputString[g] < 'a'))
            {
                newKey = newKey + ' ';
                h = h-1;
            }
            if ((inputString[g] >= 'A' && inputString[g] <= 'Z') || (inputString[g] >= 'a' && inputString[g] <= 'z'))
            {
                if ((inputString[g] >= 'A' && inputString[g] <= 'Z') && (origKey[h] >= 'a' && origKey[h] <= 'z'))
                {
                    origKey[h] = origKey[h] - 32;
                }

                else if ((inputString[g] >= 'a' && inputString[g] <= 'z') && (origKey[h] >= 'A' && origKey[h] <= 'Z'))
                {
                    origKey[h] = origKey[h] + 32;
                }
                newKey = newKey + origKey[h];
            }
        }
    }           
    
    return(newKey);
}

        
// **** VIGENERE ENCRYPTION FUNCTION ****

//This function is supposed to be used in tandem with the Vigenere function
//It takes the modified key created by the vigenereKey function
//and shifts the letters of the string being encrypted by n-1, where n is
//the position the letter represents (e.g A=1, C=3, Y=25, Z=26, etc.)
//The function uses the ASCII values for all characters and preserves
//the case (upper/lower) of the letters in the original string.
//This function then takes each letter it decrypts/shifts and
//concatenates it to an empty string to create the newly decrypted string

string vigenereEncrypt(string inputString, string vigKey)
{

    string encryptedStr;
    
    int i, k;
    

    for (i=0, k = 0; i<=inputString.length(); i++, k++)
    {   
        char keyValue = (vigKey[k]);
        
         if ((vigKey[k] >= 'A' && vigKey[k] <= 'Z') || (vigKey[k] >= 'a' && vigKey[k] <= 'z'))
        {
            if ((inputString[i] >= 'A' && inputString[i] <= 'Z') || (inputString[i] >= 'a' && inputString[i] <= 'z'))
            {
                if (inputString[i] >= 'A' && inputString[i] <= 'Z')
                {
                    if (vigKey[k] >= 'a' && vigKey[k] <= 'z')
                    {
                        inputString[i] = ((inputString[i] + keyValue + 32) % 26) + 'A';
                    }
                    else
                    {
                        inputString[i] = ((inputString[i] + keyValue) % 26) + 'A';
                    }

                }

                else if (inputString[i] >='a' && inputString[i] <= 'z')
                {
                    if (vigKey[k] >= 'A' && vigKey[k] <= 'Z')
                    {
                        inputString[i] = ((inputString[i] + keyValue - 44) % 26) + 'a';
                    }

                    else
                    {
                        inputString[i] = ((inputString[i] + keyValue - 12) % 26) + 'a';
                    }
                }

                else if (inputString[i] < 'A' ||  inputString[i] > 'Z')
                {
                    cout << "Something went wrong!";
                }
            }
        }
        encryptedStr = encryptedStr + inputString[i];
        //cout << "PARTIAL: " << encryptedStr << "  " << vigKey[k] << endl; //This was meant for debugging purposes
    }
    
    return (encryptedStr);
}


// **** VIGENERE DECRYPTION FUNCTION ****

//This function is supposed to be used in tandem with the Vigenere function
//It takes the modified key created by the vigenereKey function
//and shifts the letters of the string being decrypted by n-1, where n is
//the position the letter represents (e.g A=1, C=3, Y=25, Z=26, etc.)
//The function uses the ASCII values for all characters and preserves
//the case (upper/lower) of the letters in the original string.
//This function then takes each letter it decrypts/shifts and
//concatenates it to an empty string to create the newly decrypted string

string vigenereDecrypt(string inputString, string vigKey)
{

    string encryptedStr;
    
    int i, k;
    

    for (i=0, k = 0; i<=inputString.length(); i++, k++)
    {   
        char keyValue = (vigKey[k]);
        
         if ((vigKey[k] >= 'A' && vigKey[k] <= 'Z') || (vigKey[k] >= 'a' && vigKey[k] <= 'z'))
        {
            if ((inputString[i] >= 'A' && inputString[i] <= 'Z') || (inputString[i] >= 'a' && inputString[i] <= 'z'))
            {
                if (inputString[i] >= 'A' && inputString[i] <= 'Z')
                {
                    if (vigKey[k] >= 'a' && vigKey[k] <= 'z')
                    {
                        inputString[i] = ((inputString[i] - keyValue - 32 + 26) % 26) + 'A';
                    }
                    else
                    {
                        inputString[i] = ((inputString[i] - keyValue + 26) % 26) + 'A';
                    }

                }

                else if (inputString[i] >='a' && inputString[i] <= 'z')
                {
                    if (vigKey[k] >= 'A' && vigKey[k] <= 'Z')
                    {
                        inputString[i] = ((inputString[i] - keyValue - 44 + 26) % 26) + 'a';
                    }

                    else
                    {
                        inputString[i] = ((inputString[i] - keyValue + 26) % 26) + 'a';
                    }
                }

                else if (inputString[i] < 'A' ||  inputString[i] > 'Z')
                {
                    cout << "Something went wrong!";
                }
            }
        }
        encryptedStr = encryptedStr + inputString[i];
        
        //cout << "PARTIAL: " << encryptedStr << "  " << vigKey[k] << endl; //This was meant for debugging purposes
    }
    
    return (encryptedStr);
}

/**********************************************************************************************************************
TESTING

Zulks-MacBook-Pro:lab5 Zulkernan$ g++ -o lab5d lab5d.cpp
Zulks-MacBook-Pro:lab5 Zulkernan$ ./lab5d
Please enter text you want to encrypt or decrypt. 
Hello, world!

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
a
   
<<< STARTING CAESAR ENCRYPTION >>> 
 
Please enter a numerical value you want to shift by: 
23
Original: Hello, world!
Encrypted: Ebiil, tloia!
(TEST) RESULT DECRYPTED is: Hello, world!
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
Hello, world!

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
B
   
<<< STARTING CAESAR DECRYPTION >>> 
 
Please enter a numerical value you want to shift by: 
3
Original: Hello, world!
Decrypted: Ebiil, tloia!
(TEST) RESULT ENCRYPTED is: Hello, world!
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
Hello, world!

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
b
   
<<< STARTING CAESAR DECRYPTION >>> 
 
Please enter a numerical value you want to shift by: 
23
Original: Hello, world!
Decrypted: Khoor, zruog!
(TEST) RESULT ENCRYPTED is: Hello, world!
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
Ebiil, Tloia!

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
b
   
<<< STARTING CAESAR DECRYPTION >>> 
 
Please enter a numerical value you want to shift by: 
23
Original: Ebiil, Tloia!
Decrypted: Hello, World!
(TEST) RESULT ENCRYPTED is: Ebiil, Tloia!
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
Jevpq, wyvnd!

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
b
   
<<< STARTING CAESAR DECRYPTION >>> 
 
Please enter a numerical value you want to shift by: 
3 
Original: Jevpq, wyvnd!
Decrypted: Gbsmn, tvska!
(TEST) RESULT ENCRYPTED is: Jevpq, wyvnd!
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
Hello, world!

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
c
   
<<< STARTING VIGENERE ENCRYPTION >>> 
 
Enter text to use as the key for encrypting: 
cake
Original: Hello, world!
Encrypted: Jevpq, wyvnd!
(TEST) RESULT DECRYPTED is: Hello, world!
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
Hello, world!

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
c
   
<<< STARTING VIGENERE ENCRYPTION >>> 
 
Enter text to use as the key for encrypting: 
cake
Original: Hello, world!
Encrypted: Jevpq, wyvnd!
(TEST) RESULT DECRYPTED is: Hello, world!
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
Jevpq, wyvnd!

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
d
   
<<< STARTING VIGENERE DECRYPTION >>> 
 
Enter text to use as the key for decrypting: 
cake
Original: Jevpq, wyvnd!
Decrypted: Hello, world!
(TEST) RESULT ENCRYPTED is: Jevpq, wyvnd!
Do you want to run the program again? (y/n) 
n
Zulks-MacBook-Pro:lab5 Zulkernan$ ./lab5d
Please enter text you want to encrypt or decrypt. 
Zulks-MacBook-Pro:lab5 Zulkernan$ ./lab5d
Please enter text you want to encrypt or decrypt. 
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
a
   
<<< STARTING CAESAR ENCRYPTION >>> 
 
Please enter a numerical value you want to shift by: 
12
Original: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Encrypted: MNOPQRSTUVWXYZABCDEFGHIJKLmnopqrstuvwxyzabcdefghijkl
(TEST) RESULT DECRYPTED is: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
b
   
<<< STARTING CAESAR DECRYPTION >>> 
 
Please enter a numerical value you want to shift by: 
12
Original: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Decrypted: OPQRSTUVWXYZABCDEFGHIJKLMNopqrstuvwxyzabcdefghijklmn
(TEST) RESULT ENCRYPTED is: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
c
   
<<< STARTING VIGENERE ENCRYPTION >>> 
 
Enter text to use as the key for encrypting: 
cake
Original: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Encrypted: CBMHGFQLKJUPONYTSRCXWVGBAZkfedojihsnmlwrqpavutezyxid
(TEST) RESULT DECRYPTED is: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz343498&$*&#(*@P....ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
c
   
<<< STARTING VIGENERE ENCRYPTION >>> 
 
Enter text to use as the key for encrypting: 
cake
Original: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz343498&$*&#(*@P....ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Encrypted: CBMHGFQLKJUPONYTSRCXWVGBAZkfedojihsnmlwrqpavutezyxid343498&$*&#(*@R....ALGFEPKJITONMXSRQBWVUFAZYJedcnihgrmlkvqpozutsdyxwhcb
(TEST) RESULT DECRYPTED is: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz343498&$*&#(*@P....ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
CBMHGFQLKJUPONYTSRCXWVGBAZkfedojihsnmlwrqpavutezyxid343498&$*&#(*@R....ALGFEPKJITONMXSRQBWVUFAZYJedcnihgrmlkvqpozutsdyxwhcb

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
d
   
<<< STARTING VIGENERE DECRYPTION >>> 
 
Enter text to use as the key for decrypting: 
cake
Original: CBMHGFQLKJUPONYTSRCXWVGBAZkfedojihsnmlwrqpavutezyxid343498&$*&#(*@R....ALGFEPKJITONMXSRQBWVUFAZYJedcnihgrmlkvqpozutsdyxwhcb
Decrypted: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz343498&$*&#(*@P....ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
(TEST) RESULT ENCRYPTED is: CBMHGFQLKJUPONYTSRCXWVGBAZkfedojihsnmlwrqpavutezyxid343498&$*&#(*@R....ALGFEPKJITONMXSRQBWVUFAZYJedcnihgrmlkvqpozutsdyxwhcb
Do you want to run the program again? (y/n) 
y
Please enter text you want to encrypt or decrypt. 
Hello, world!

*** MENU OPTIONS *** 
(A) Caesar Encryption 
(B) Caesar Decryption 
(C) Vigenere Encryption 
(D) Vigenere Decryption 
(Q) Quit / Exit the program 

Please select which cipher you want to use (A, B, C, or D): 
Enter 'Q' if you want to end the program and quit. 
The program will restart if you enter anything besides this. 
q
   
Zulks-MacBook-Pro:lab5 Zulkernan$ 

************************************************************************************************************************************/
