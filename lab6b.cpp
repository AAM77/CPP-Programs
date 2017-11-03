/*

Author: Mohammad Adeel
Course: {136}
Section: Tuesday 7:00PM - 8:40PM
Instructor: G.P.
Assignment: "Lab 6, Task 1"

This program presents a shape menu to the user
and performs value validation by continuing to
run the program until the user enters 'E' or 
'e' to exit.

It also performs input type validation to ensure
the user enters a character for the shape menu 
option and enters an integer for the parameters
pertaining to the dimensions of the shapes
(i.e. width, height, side length, radius)
  
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool alphaChar(char character);
void shapeMenu(char shapeChoice);
void rectangle(int width, int height);
void triangle(int side, int removeRows);
void circle(int radius);
void wrongType(void);
void menu(void);


int main()
{
    char shapeChoice;

    //start do-while loop that continues until the user inputs 'E' or 'e'
    do
    {
        //Introduces the initial prompt.
        //I could not figure out how to check for type char vs. type string in a more elegant fashion
        //so I created a function alphaChar() that checks to see that, at the very least,
        //the input is not an integer.
        //It then uses invoke the function alphaChar() to check that, at the very least, the input was not an integer
        //and checks if a string by using (cin.get() != '\n') to evaluate if there is anything after the first character
        //If it is an integer, decimal, or otherwise, the program tells the user that it is of an invalid type
        //Otherwise, if the user enters more than one character in the form of a string, the program
        // determines if the character after the first is a newline ('\n'), if it is, then it
        //assumes it is a single characters, otherwise, if not a '\n', it assumes it is a string and
        //clears cin, ignoring all trailing characters, and prompts the user to enter a proper type
        menu();

        cout << "Enter (R)ectangle, (T)riangle, (C)ircle, or (E)nd \n";
        
        
        while (cin >> shapeChoice)
        {
            if ((alphaChar(shapeChoice) == false) || (cin.get() != '\n'))
            {
                cout << "Wrong Type -- Enter a character: \n";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            else
            {
                break;
            }
        }
        
        //The while statement first checks to see if the input character is an upper or lower case R, T, C, or E
        //If the input character is not R, T, C, or E, the program then then tells the user that
        //s/he input an invalid choice and prompts the user for another input.
        //Evaluates if it is of a valid type using the same while loop as above for input type vlaidation

        while (!( shapeChoice == 'R' || shapeChoice == 'r' ||
                  shapeChoice == 'T' || shapeChoice == 't' ||
                  shapeChoice == 'C' || shapeChoice == 'c' || 
                  shapeChoice == 'E' || shapeChoice == 'e' ))
        {
            cout << "! * INVALID CHOICE * ! \n";
            cout << "Enter (R)ectangle, (T)riangle, (C)ircle, or (E)nd \n";
            while (cin >> shapeChoice)
            {
                if ((alphaChar(shapeChoice) == false) || (cin.get() != '\n'))
                {
                    cout << "Wrong Type -- Enter a character: \n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }

                else
                {
                    break;
                }
            }
                   
        }//end while not R, T, C, or E

        shapeMenu(shapeChoice); //The Switch

    } while (!(shapeChoice == 'E' || shapeChoice == 'e' ));
    //end do-while loop
    

    return 0;
    
}//end main



//////////////////////////////////////
//                                 //
//  LIST OF FUNCTION DEFINITIONS   //
//                                //
////////////////////////////////////


void menu(void)
//Simply prints out the menu options
{
    cout << "\n"
         << "\n"
         << "** * * * MENU * * * ** \n"
         << "Options: \n"
         << "(R) Rectangle \n"
         << "(T) Triangle \n"
         << "(C) Circle \n"
         << "(E) End to exit program \n"
         << "\n";
}

bool alphaChar(char character)
//precondition: value must be between 'A' and 'Z' or 'a' && 'z'
//postcondition: true if an alpha char, false if anything else
{
    
    if (('A' <= character && character <= 'Z') || ('a' <= character && character <= 'z'))
        return true;
    else
        return false;
    
} //end function alphaChar


void wrongType(void)
//performs input validation to check for type int.
{
    cout << "Wrong type -- enter a non-decimal integer: \n";
    cin.clear();
    cin.ignore(1000, '\n');
}//end checkInteger


void shapeMenu(char shapeChoice)
//This function is a switch to handle what happens based on the input the user enters.
//It calls the appropriate functions.
//precondition: must input capital or lower case R, T, C, or E to match case
//postcondition: if precondition true, run appropriate case, else default and rerun
{
    int width;
    int height;
    int side;
    int removeRows;
    int radius;
    
    switch (shapeChoice)
    {
        case 'R':
        case 'r':
        {
            //Used do-while loop so that the program
            //(1) asks at least once even if the bolean expression is false
            //(2) keeps iterating to ask for a value until a valid input is entered
            //The width/height >1 prevents negative values and unsensible output
            do
            {
                cout << "Enter width (1 < w < 180): \n";
                
                //the !(cin>>shapeDimension) checks to make sure that the input is a number.
                //the (cin.get() != '\n') checks to make sure the number
                //is an integer (e.g. 5)and not a floating point (e.g. 5.0)
                //It outputs a "Wrong type" error message if it is not an integer
                //prompts the user again.
                //otherwise it continues.
                while(!(cin >> width) || (cin.get() != '\n'))
                {
                    wrongType();
                }
            }
            while (width < 1 || width > 179);


            do
            {
                cout << "Enter height (1 < h < 180): \n";
                while(!(cin >> height) || (cin.get() != '\n'))
                {
                    wrongType();
                }
            }
            while (height < 1 || height > 179);

            rectangle(width, height);
            break;
        }

        case 'T':
        case 't':
        {
            //asks the user for the side at least once
            //and keeps asking until the user enters a value of 2 or greater
            do
            {
                cout << "Enter side length (2 < side < 181): \n";
                while(!(cin >> side) || (cin.get() != '\n'))
                {
                    wrongType();
                }
            }
            while (side < 2 || side > 180);

            //Asks the user for the number of lines to remove.
            //It keeps asking until the user enters a value that is
            //(1) positive & (2) less than the desired length of the side.
            do
            {
                cout << "Enter how much to cut off of the height (0 <= k <= side's length!): \n";
                while(!(cin >> removeRows) || (cin.get() != '\n'))
                {
                    wrongType();
                }
            }
            while (removeRows < 0 || removeRows > side);
        }

            triangle(side, removeRows);
            break;

        case 'C':
        case 'c':
        {                 
            //keeps asking for input of radius until the value is greater than zero (0) 
            do
            {
                cout << "Enter a radius for the circle (0 < r < 91): \n";
                while(!(cin >> radius) || (cin.get() != '\n'))
                {
                    wrongType();
                }
            }
            while (radius <= 0 || radius > 90); 

            circle(radius);
            break;
        }

        case 'E':
        case 'e':
            {
                cout << "You have exited the program. \n";
                break;
            }

        default:
                cout << "Invalid input! \n";

    }//end switch
}//end shapeMenu


void rectangle(int width, int height)
//precondition: width > 2, height > 2
//postcondition: prompt again if precondition false, print rectanle if precondition true
//This function uses the input width and height to print out that many number of asterisks
//to display a rectangular shape of the input dimensions

{
    
    char asterisk = '*';

    //creates the top side of the square equal to width
    for (int count=0; count<=width; count++)
    {
        cout << asterisk;
    }
        cout << endl;
    
    //creates the center part of the square with empty space in the center.
    //Uses nested for loops with the outer loop creating the first and last asterisk,
    //and the inner loop creates the space between them.
    for (int count=0; count<height-2; count++)
    {
        cout << asterisk;
        for (int space=0; space <= width-2; space++)
        {
            cout << " ";
        }
         cout << asterisk << endl;
    }
    
    //creates the bottom side of the square
    for (int count =0; count<=width; count++)
    {
        cout << asterisk;
    }
        cout << endl;
}//end rectangle





void triangle(int side, int removeRows)
//This function uses the input side to print out that many number of asterisks
//to display a rectangular shape with the appropriate dimensions
//It also removes the number of desired rows from the triangle.
{
    
    
    char asterisk = '*';

    //used to generate the first line and each subsequent line.
    //Here, the first line is equal to the length of the difference between the input value for the side and k.
    int newLine = side-removeRows; 
    
    
    
    //Uses nested loops:
    //outer loop creates the height-side of the triangle and controls the length of each subsequent line.
    //inner loop creates the top-side of the triangle and each subsequent line.
    
    for (int count = 0; count<(side-removeRows); count++)
    {
        for (int astrCount=0; astrCount<newLine; astrCount++)
        {
            cout << asterisk;
        }
        cout << endl;
        newLine = newLine - 1;
    }
}//end triangle





void circle(int radius)
//This function outputs a circle of the given radius
{

    char asterisk = '*';

    int radius_Sqrd = (radius*radius);
    int diameter = 2*radius;

    // These nested loops take care of calculating the distance from the center and determining if the
    // resulting value is less than or equal to the diameter (that is, within the circle)

    for (int valueX=0; valueX <= diameter; valueX++)
    {
        for (int valueY=0; valueY <= diameter; valueY++)
        {
            int coordinatePoint = ((valueX-radius)*(valueX-radius))+((valueY-radius)*(valueY-radius));

             // Determines if the coordinatePoint is the same as radius*radius.
             // If it is, then the point is in the circle and an asterisk is printed
             // If the CoordinatePouint is not the same as radius*radius, and a space is printed

             if (coordinatePoint < radius_Sqrd )
             {
                 cout << asterisk;
             }

             // if coordinatePoint is not the same as radius*radius, then the point is not in the
             // circle and a space is printed instead

             else
             {
                cout << " ";
             }
        }
        cout << endl;
    }   
}//end circle



/************************************************************************************************************
Task 1 Question: When I entered a letter into my previous program, it returned an infinite loop. I had to
control-C to exit out of it.

If I enter a value that is larger than my screen size, the program outputs a shape that appears overlapped by
printing the characters overflowing past the screen in between the lines.
If I enter too large of a number, the computer runs for a very long time as it fills the screen with
asterisks and continues to print them until it has printed enough asterisks to satisfy the criteria laid out
in the respective function.

I corrected for overflow by forcing the user to enter values between a certain range. It is not elegant,
since I do not know what their screen size is, but it should suffice until I learn more C++.

************************************************************************************************************/

/************************************************************************************************************

[[TESTING]]


Note:
Input is marked by -- <<<< ****[[[[     ]]]]**** INPUT THAT WORKED >>>>


1. Testing the Rectangle function
** * * * MENU * * * ** 
Options: 
(R) Rectangle 
(T) Triangle 
(C) Circle 
(E) End to exit program 

Enter (R)ectangle, (T)riangle, (C)ircle, or (E)nd 
a dsds dsd ./.s d./.d 
Wrong Type -- Enter a character: 
./
Wrong Type -- Enter a character: 
.
Wrong Type -- Enter a character: 
/
Wrong Type -- Enter a character: 
1
Wrong Type -- Enter a character: 
2
<<<< ****[[[[  Wrong Type -- Enter a character:  ]]]]**** INPUT THAT WORKED >>>>
r
Enter width (1 < w < 180): 
h
Wrong type -- enter a non-decimal integer: 
f
Wrong type -- enter a non-decimal integer: 
d
Wrong type -- enter a non-decimal integer: 
1.0
Wrong type -- enter a non-decimal integer: 
0.0
Wrong type -- enter a non-decimal integer: 
0
Enter width (1 < w < 180): 
200
<<<< ****[[[[  Enter width (1 < w < 180):  ]]]]**** INPUT THAT WORKED >>>>
10
Enter height (1 < h < 180): 
-
Wrong type -- enter a non-decimal integer: 
0.0
Wrong type -- enter a non-decimal integer: 
500
****[[[[  Enter height (1 < h < 180):  ]]]]**** INPUT THAT WORKED 
5

***********
*         *
*         *
*         *
***********




2. Immediately after the rectangle ended, it looped back:

** * * * MENU * * * ** 
Options: 
(R) Rectangle 
(T) Triangle 
(C) Circle 
(E) End to exit program 

Enter (R)ectangle, (T)riangle, (C)ircle, or (E)nd 
e E
****[[[[  Wrong Type -- Enter a character:  ]]]]**** INPUT THAT WORKED 
e
You have exited the program. <~~~~~~~ final output message



OTHER TESTING:
I tested the inputs for the triangle and circle in a similar manner. They all worked as desired.

I input lower case and uppercase letters for the menu (R or r), (T or t), (C or c), (E or e)
The output correctly responded by calling the switch function and then the appropriate shape function.

I input incorrect alphabetical characters, and it looped back to tell me I had made an invalid choice.
I kept looping back until I entered a valid menu choice.

For the menu, I input non-alphabetical characters, numbers, and strings, and it output a "Type Error"
message until I entered the proper type. If I input an incorrect alphabetical character at this point,
it looped back to tell me it was an invalid menu choice.

For the parameters of each of each function, I input alphabetical characters, strings, decimal numbers
(whole, rational, and irrational), and other non-numerical/non-alphabetical characters. If gave me a
"Type error" each time until I entered a valid number. If the integer was out of the displayed range, it
looped me back to the message to enter an integer within the displayed range.

Once everything correct was input, it looped back to the start of the program until I entered 'E' or 'E'
to exit.

************************************************************************************************************/