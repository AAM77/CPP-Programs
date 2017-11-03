/*
Author: Mohammad Adeel
Course: {136}
Section: Tuesday 7:00PM - 8:40PM
Instructor: G.P.
Assignment: "Lab 6, task 0"

This program presents a shape menu to the user
and performs value validation by continuing to
run the program until the user enters 'E' or 
'e' to exit.

*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void rectangle(int width, int height);
void triangle(int side, int removeRows);
void circle(int radius);
void menu(void);
void shapeMenu(char shapeChoice);


int main()
{
    char shapeChoice;

    //start while loop
    do
    {
        cout << "\n";
        cout << "Welcome to shoddy shapes! \n";
        cout << "Please read carefully, as our menu options may have changed. \n";

        menu();

        cout << "Enter (R)ectangle, (T)riangle, (C)ircle, or (E)nd \n";
        cin >> shapeChoice;
        
        if (!( shapeChoice == 'R' || shapeChoice == 'r' ||
               shapeChoice == 'T' || shapeChoice == 't' ||
               shapeChoice == 'C' || shapeChoice == 'c' ||
               shapeChoice == 'E' || shapeChoice == 'e' ))
        {
            cout << "!!!!! INCORRECT CHOICE !!!!! \n";
            
            menu();

            cout << "Enter (R)ectangle, (T)riangle, (C)ircle, or (E)nd \n";
            cin >> shapeChoice;

        }// end else
        
        else
        {
            shapeMenu(shapeChoice);
        }

        
    }//end switch-while loop
    while ( !(shapeChoice == 'E' || shapeChoice == 'e') );
    
    //switch
    

    return 0;
    
}//end main




void menu(void)
{
    cout << "\n"
         << "********************** \n"
         << "** * * * MENU * * * ** \n"
         << "********************** \n"
         << "Options: \n"
         << "(R) Rectangle \n"
         << "(T) Triangle \n"
         << "(C) Circle \n"
         << "(E) End to exit program \n"
         << "\n";
}

void shapeMenu(char shapeChoice)
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

            /*
            Used do-while loop so that the program
            (1) asks at least once even if the bolean expression is false
            (2) keeps iterating to ask for a value until a valid input is entered
            The width/height >=3 prevents negative values and unsensible output
            */

            do
            {
                cout << "Enter width (1 or greater): \n";
                cin >> width;
            }
            while (width < 1);


            do
            {
                cout << "Enter height (1 or greater): \n";
                cin >> height;
            }

            while (height < 1);

            rectangle(width, height);
            break;
        }

        case 'T':
        case 't':
        {

            //asks the user for the side at least once and keeps asking until the user enters a value of 2 or greater
            do
            {
                cout << "Enter side length (2 or greater!): \n";
                cin >> side;
            }
            while (side < 2);

            //Asks the user for the number of lines to remove. It keeps asking until the user enters a value that is (1) positive & (2) less than the desired length of the side.
            do
            {
                cout << "Enter how much to cut off of the height (0 <= k <= side's length!): \n";
                cin >> removeRows;
            }
            while (removeRows < 0 || removeRows > side);
        }

            triangle(side, removeRows);
            break;

        case 'C':
        case 'c':
        {                 

            //asks for input of radius until the value is greater than zero (0) 
            do
            {
                cout << "Enter a radius for the circle: \n";
                cin >> radius;
            }
            while (radius <= 0); 

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
            {
                cout << "Invalid input! \n";
            }

    }//end switch

    
}




void rectangle(int width, int height)
{
    
    char asterisk = '*';

    //creates the top side of the square equal to width
    for (int count=0; count<=width; count++)
    {
        cout << asterisk;
    }
        cout << endl;
    
    //creates the center part of the square with empty space in the center. Uses nested for loops with the outer loop creating the first and last asterisk, and the inner loop creates the space between them.
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
    for (int count = 0; count<=width; count++)
    {
        cout << asterisk;
    }
        cout << endl;
    
}



void triangle(int side, int removeRows)
{
    
    
    char asterisk = '*';

    //used to generate the first line and each subsequent line. Here, the first line is equal to the length of the difference between the input value for the side and k.
    int newLine = side-removeRows; 
    
    
    /*
    Uses nested loops: outer loop creates the height-side of the triangle and controls the length of each subsequent line. inner loop creates the top-side of the triangle and each subsequent line.
    */
    for (int count = 0; count<(side-removeRows); count++)
    {
        for (int astrCount=0; astrCount<newLine; astrCount++)
        {
            cout << asterisk;
        }
        cout << endl;
        newLine = newLine - 1;
    }
}


void circle(int radius)
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

             // if coordinatePoint is not the same as (radius * radius), then the point is not in the
             // circle and a space is printed instead

             else
             {
                cout << " ";
             }
        }
        cout << endl;
    }   
}