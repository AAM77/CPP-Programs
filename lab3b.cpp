/*
  Author: Mohammad Adeel
  Course: {136}
  Section: Tuesday 7:00PM - 8:50PM
  Instructor: G.P.
  Assignment: "Lab 3, Task 2"

This program computes the factorials n!, k!, and (n-k)! after receiving input from the user for value of n & k.
It use the type 'long int' for all of the values to do the calculations.

*/

//TASK 1//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long int inputN; //user inputs a value for n
    long int inputK; //user inputs a value for k
    long int factorialN = 1; //this starts factorial at 1 for input of n
    long int factorialK =1; //this starts factorial at 1 for input of k
    long int factorialNK = 1; //this starts factorial at 1 for inputs n-k
    long int countN; //a value that increases until n reaches inputN
    long int countK; //a value that increase until k reaches inputK
    long int countNK;
    
    
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
        factorialNK = factorialNK * countNK; // multiplies itself with
                                       //factorialNK and updates factorialNK to reflect the new value.
       }
    cout << "Factorial of n-k" << " = " << factorialNK << endl;
    
    
    return 0;
}

/*

TEST CASES

/-CASE 1-/
inputN = 20, inputK = 20, or (inputN-inputK) = 20
output = 2432902008176640000
expected output = 2432902008176640000


/-CASE 2-/
inputN = 25, inputK = 25, or (inputN-inputK) = 25
output = 7034535277573963776
expected output = 1.551121e+25


/-CASE 3-/
inputN = 21, inputK = 21, or (inputN-inputK) = 21
output = -4249290049419214848
expected output = 5.1090942e+19


ANSWER: The lowest value to return an error for 'long int' is when inputN = 21, inputK = 21, or (inputN-inputK) = 21
There is still an issue of overflow: the program provides a correct answer until 20, but leads to an
incorrect result after this, with the first incorrect result when the input value or N-K is 21.

*/
