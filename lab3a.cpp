/*
  Author: Mohammad Adeel
  Course: {136}
  Section: Tuesday 7:00PM - 8:50PM
  Instructor: G.P.
  Assignment: "Lab 3, Task 1"

This program computes the factorials n!, k!, and (n-k)! after receiving input from the user for value of n & k.
It use the type 'int' for all of the values to do the calculations.
*/


// TASK 1 //

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int inputN; //user inputs a value for N
    int inputK; //user inputs a value for K
    int factorialN = 1; //this starts the factorial at 1 for input of N
    int factorialK =1; //this starts the factorial at 1 for input of K
    int factorialNK = 1; //this starts the factorial at 1 for inputs N-K
    int countN; //a count value for N that increases until it equals the input N
    int countK; //a count value for K that increases until it equals the input K
    int countNK; //a count for n-k until the count is equal to the difference of inputN-inputK
    
    
    
    //This part starts the count of N at 1 and runs it in a loop until countN equals the input value for N.
    //on each iteration of the loop, the existing value for factorial of N multiplies with the new count of N
    //and updates the value of factorialN to reflect this value and countN increases by one.
    //Once countN is greater than inputN, the loop stops.
    cout << "This program will take input from you for n and calculate its factorial.";
    cout << "\nPlease enter the value n you want a factorial for. \n";
    cin >> inputN;

    for (countN=1; countN<=inputN; countN++)
       {
        factorialN = factorialN * countN;
       }
    cout << "Factorial of " << inputN << " = " << factorialN << endl;
    
    

    //This part starts the count of K at 1 and runs it in a loop until countN equals the input value for K.
    //on each iteration of the loop, the existing value for factorial of K multiplies with the new count of k
    //and updates the value of factorialK to reflect this value and countK increases by one.
    //Once countK is greater than inputK, the loop stops.
    cout << "\nThis program will take input from you for k and calculate its factorial.";
    cout << "\nPlease enter the value k you want a factorial for. \n";
    cin >> inputK;

    for (countK=1; countK<=inputK; countK++)
       {
        factorialK = factorialK * countK;
       }
    cout << "Factorial of " << inputK << " = " << factorialK << endl;
    

    
    //This part starts the countNK at 1 and runs it in a loop until countNK equals the difference of the input value of N and K.
    //on each iteration of the loop, the existing value for factorialNK multiplies with the new countNK
    //and updates the value of factorialN to reflect this value and countNK increases by one.
    //Once countN is greater than inputN, the loop stops.
    cout << "\nThis program will take input from you for n & k and calculate the factorial for n-k.";
    cout << "\nPlease enter the values for n & k you want a factorial for. \n";
    cin >> inputN;
    cin >> inputK;


    for (countNK=1; countNK<=(inputN-inputK); countNK++) //Evaluates the value of n against the difference of the input values
       {
        factorialNK = factorialNK * countNK;
       }
    cout << "Factorial of n-k" << " = " << factorialNK << endl;
    
    
    return 0;
}

/*

TEST CASES

/-CASE 1-/
inputN = 10, inputK = 10, or (inputN-inputK) = 10
output = 3628800
expected output = 3628800


/-CASE 2-/
inputN = 11, inputK = 11, or (inputN-inputK) = 11
output = 39916800
expected output = 39916800


/-CASE 3-/
inputN = 12, inputK = 12, or (inputN-inputK) = 12
output k = 479001600
expected output = 479001600


/-CASE 4-/
inputN = 13, inputK = 13, or (inputN-inputK) = 13
output = 1932053504
expected output = 6227020800


ANSWERS:
(1) The lowest value to return an error for 'int' is when inputN = 13, inputK = 13, or (inputN-inputK) = 13
(2) These reason an error occurs is because the type is int and can handle only up to 32-bits.

As a result, this program provides a correct result only until 12 without issues.
Anything beyond this results in overflow errors, with the first error occurring when the input value or N-K is 13.

*/
