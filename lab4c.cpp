/*
  Author: Mohammad Adeel
  Course: CSCI 136
  Instructor: G.P.
  Assignment: Lab 4, Task 3

  This program asks the user to input the desired side length. After receiving valid input, the program outputs an isosceles triangle that looks like the south-eastern half of a square.
*/

#include <iostream>
using namespace std;

int main()
{
    int side;
    int newLine;
    char asterisk = '*';
    
//asks the user for the side at least once and keeps asking until the user enters a value of 2 or greater
    do
        {
         cout << "Enter side length (2 or greater!): \n";
         cin >> side;
        }
    while (side < 2);
    
/*
represents each subsequent line. Used to create lines with decreasing length. It starts with one less than the side because the rest is represented by space, which is where the north-western half of the square would be.
*/

    newLine = side-1;
    
    
    /*
    Uses an outer loop with two separate inner loops nested inside of it. The out loop produces the height-side of the triangle. The first inner loop creates the empty space before the asterisks. The second inner loops creates the asterisks and iterates an amount equal to the difference of side-newLine.
    */
    for (int count = 0; count<side; count++)
        {
         for (int space=0; space<newLine; space++)
            {
             cout << " ";
            }
         for(int astrCount=0; astrCount<(side-newLine); astrCount++)
            {
             cout << asterisk;
            }
         cout << endl;
         newLine = newLine - 1;
        }
    return 0;
}

/*****************************************************************************************************
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4c
Enter side length (2 or greater!): 
2
 *
**
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4c
Enter side length (2 or greater!): 
3
  *
 **
***
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4c
Enter side length (2 or greater!): 
4
   *
  **
 ***
****
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4c
Enter side length (2 or greater!): 
5
    *
   **
  ***
 ****
*****
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4c
Enter side length (2 or greater!): 
7
      *
     **
    ***
   ****
  *****
 ******
*******

----ERROR CHECKING----
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4c
Enter side length (2 or greater!): 
-10
Enter side length (2 or greater!): 
-5
Enter side length (2 or greater!): 
-3
Enter side length (2 or greater!): 
-2
Enter side length (2 or greater!): 
-1
Enter side length (2 or greater!): 
1
Enter side length (2 or greater!): 
10
         *
        **
       ***
      ****
     *****
    ******
   *******
  ********
 *********
**********




*****************************************************************************************************/
