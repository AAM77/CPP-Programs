/*
  Author: Mohammad Adeel
  Course: CSCI 136
  Instructor: G.P.
  Assignment: Lab 4, Task 4

  This program asks the user to input the desired side length. After receiving valid input, the program outputs an isosceles triangle that looks like the north-western half of a square.
  
  This version of the program is similar to task 2, except that this one allows the user determine how many rows s/he would like to remove from the top of the triangle.
*/

#include <iostream>
using namespace std;

int main()
{
    
    int side;
    int k; //how many rows to exclude
    char asterisk = '*';
    
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
         cout << "Enter how much to cut off of the height (0 < k < side-length!): \n";
         cin >> k;
        }
    while (k < 0 || k > side);
    

    //used to generate the first line and each subsequent line. Here, the first line is equal to the length of the difference between the input value for the side and k.
    int newLine = side-k; 
    
    
    /*
    Uses nested loops: outer loop creates the height-side of the triangle and controls the length of each subsequent line. inner loop creates the top-side of the triangle and each subsequent line.
    */
    for (int count = 0; count<(side-k); count++)
        {
         for (int astrCount=0; astrCount<newLine; astrCount++)
            {
             cout << asterisk;
            }
         cout << endl;
         newLine = newLine - 1;
        }
}

/*****************************************************************************************************

[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4d
Enter side length (2 or greater!): 
2
Enter how much to cut off of the height (0 < k < side-length!): 
1       
*
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4d
Enter side length (2 or greater!): 
3
Enter how much to cut off of the height (0 < k < side-length!): 
2
*
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4d
Enter side length (2 or greater!): 
3
Enter how much to cut off of the height (0 < k < side-length!): 
1
**
*
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4d
Enter side length (2 or greater!): 
5
Enter how much to cut off of the height (0 < k < side-length!): 
2
***
**
*
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4d
Enter side length (2 or greater!): 
5
Enter how much to cut off of the height (0 < k < side-length!): 
1
****
***
**
*
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4d
Enter side length (2 or greater!): 
10
Enter how much to cut off of the height (0 < k < side-length!): 
3
*******
******
*****
****
***
**
*

----ERROR CHECKING----

[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4d
Enter side length (2 or greater!): 
-10
Enter side length (2 or greater!): 
-2
Enter side length (2 or greater!): 
1
Enter side length (2 or greater!): 
11
Enter how much to cut off of the height (0 < k < side-length!): 
15
Enter how much to cut off of the height (0 < k < side-length!): 
-15
Enter how much to cut off of the height (0 < k < side-length!): 
-4
Enter how much to cut off of the height (0 < k < side-length!): 
-1
Enter how much to cut off of the height (0 < k < side-length!): 
-2
Enter how much to cut off of the height (0 < k < side-length!): 
4
*******
******
*****
****
***
**
*


*****************************************************************************************************/
