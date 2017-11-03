/*
  Author: Mohammad Adeel
  Course: CSCI 136
  Instructor: G.P.
  Assignment: Lab 4, Task 5

  This program takes input for the radius of the desired circle and outputs a circular shape. It
  calculates the distance of points from the center of the circle. If the point is within the circle,
  an asterisk is printed, otherwise a space is printed.

*/


#include <iostream>
using namespace std;

int main()

{
    int radius;
    char asterisk = '*';
    
   //asks for input of radius until the value is greater than zero (0) 
    do
        {
         cout << "Enter a radius for the circle: \n";
         cin >> radius;
        }
    while (radius <= 0); 
 

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
            
    
}


/*****************************************************************************************************

OUTPUT

[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4e
Enter a radius for the circle: 
5
     *     
  *******  
 ********* 
 ********* 
 ********* 
***********
 ********* 
 ********* 
 ********* 
  *******  
     *     
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4e
Enter a radius for the circle: 
6
      *      
   *******   
  *********  
 *********** 
 *********** 
 *********** 
*************
 *********** 
 *********** 
 *********** 
  *********  
   *******   
      *      
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4e
Enter a radius for the circle: 
7    
       *       
    *******    
   *********   
  ***********  
 ************* 
 ************* 
 ************* 
***************
 ************* 
 ************* 
 ************* 
  ***********  
   *********   
    *******    
       *       
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4e
Enter a radius for the circle: 
8
        *        
     *******     
   ***********   
  *************  
  *************  
 *************** 
 *************** 
 *************** 
*****************
 *************** 
 *************** 
 *************** 
  *************  
  *************  
   ***********   
     *******     
        *        
[Mohammad.Adeel78@C1001Lab16 lab4]$ ./lab4e
Enter a radius for the circle: 
-1
Enter a radius for the circle: 
0
Enter a radius for the circle: 
-10
Enter a radius for the circle: 
10
          *          
      *********      
    *************    
   ***************   
  *****************  
  *****************  
 ******************* 
 ******************* 
 ******************* 
 ******************* 
*********************
 ******************* 
 ******************* 
 ******************* 
 ******************* 
  *****************  
  *****************  
   ***************   
    *************    
      *********      
          *          

*****************************************************************************************************/

