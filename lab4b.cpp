/*
  Author: Mohammad Adeel
  Course: CSCI 136
  Instructor: G.P.
  Assignment: Lab 4, Task 2

  This program asks the user to input the desired side length of the sides of the triangle. After receiving valid input, the program outputs an isosceles triangle that looks like the north-western half of a square.
*/

#include <iostream>
using namespace std;

int main()
{
    
    int side;
    char asterisk = '*';

//asks the user for the side at least once and keeps asking until the user enters a value of 2 or greater
    do
        {
         cout << "Enter side length (2 or greater): \n";
         cin >> side;
        }
    while (side < 2);
    
    int newLine = side; ////used to generate the first line and each subsequent line.
    
    /*
    uses nested loops: outer loop creates the height-side of the triangle. inner loop creates the top-side of the triangle.
    */
    for (int count = 0; count<side; count++)
        {
         for (int astrCount=0; astrCount<newLine; astrCount++)
            {
             cout << asterisk;
            }
         cout << endl;
         newLine = newLine - 1;
        }
    return 0;
}


/***************************************************************************************************
TESTING OUTPUT

[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4b
Enter side length (2 or greater): 
2
**
*
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4b
Enter side length (2 or greater): 
1
Enter side length (2 or greater): 
1
Enter side length (2 or greater): 
3
***
**
*
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4b
Enter side length (2 or greater): 
4
****
***
**
*
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4b
Enter side length (2 or greater): 
5
*****
****
***
**
*
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4b
Enter side length (2 or greater): 
6
******
*****
****
***
**
*
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4b
Enter side length (2 or greater): 
7
*******
******
*****
****
***
**
*


ERROR CHECKING
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4b
Enter side length (2 or greater): 
1
Enter side length (2 or greater): 
-120
Enter side length (2 or greater): 
-100
Enter side length (2 or greater): 
-20
Enter side length (2 or greater): 
-10
Enter side length (2 or greater): 
10
**********
*********
********
*******
******
*****
****
***
**
*

*******************************************************************************************************/


