/*
  Author: Mohammad Adeel
  Course: CSCI 136
  Instructor: G.P.
  Assignment: Lab 4, Task 1

  This program take the length (height) and width from the user, so long as it is 3 or greater, and outputs a shape with the desired dimensions.
*/


#include <iostream>
using namespace std;

int main()
{
    char asterisk = '*';
    int width;
    int height;
 
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
    while (width < 1);

    
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
    for (int count =0; count<=width; count++)
        {
         cout << asterisk;
        }
         cout << endl;
    return 0;
}

/***************************************************************************************************
TESTING OUTPUT

---OUTPUT1---

Enter width (1 or greater): 
1
Enter height (1 or greater): 
1
**
**

---OUTPUT2---
Enter width (1 or greater): 
2
Enter height (1 or greater): 
2
***
***



---OUTPUT3---
Enter width (1 or greater): 
3
Enter height (1 or greater): 
3
****
*  *
****


[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4a
Enter width (1 or greater): 
10
Enter height (1 or greater): 
8
***********
*         *
*         *
*         *
*         *
*         *
*         *
***********
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4a
Enter width (1 or greater): 
8
Enter height (1 or greater): 
10
*********
*       *
*       *
*       *
*       *
*       *
*       *
*       *
*       *
*********

---OUTPUTS for ERROR CHECKING---

[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4a
Enter width (1 or greater): 
2
Enter width (1 or greater): 
2
Enter width (1 or greater): 
1
Enter width (1 or greater): 
-5
Enter width (1 or greater): 
3
Enter height (1 or greater): 
3
****
*  *
****


****************************************************************************************************/

