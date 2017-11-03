/*
  Author: Mohammad Adeel
  Course: {136}
  Section: Tuesday 7:00PM - 8:50PM
  Instructor: G.P.
  Assignment: "Lab 3, Task 3"

This program computes C(n,k) with the formula (n-k+1)/k! using property1: C(n,n-1) = C(n,k)
It uses the type 'int' for all of the values to do the calculations.
*/

//TASK 3//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int inputN; //user inputs a value for n
    int inputK; //user inputs a value for k
    int factorialN = 1; //this starts factorial at 1 for input of n
    int factorialK =1; //this starts factorial at 1 for input of k
    int countN; //a value that increases until n reaches inputN
    int countK; //a value that increase until k reaches inputK
    
    // calculate (n-k+1)/k! with property1: C(n,n-1) = C(n,k)
    
    //This part starts the count for N at the value the user inputs for it.
    //It compares the countN value to the value provided by the calculation (inputN-inputK+1)
    //If the criteria is met, it calculates the necessary calculation by multiplying countN with factorialN.
    //It then updates the value of factorialN with the new value and decreases countN by 1.
    //The program stops running once countN is less than the value of (inputN-inputK+1)
    
    cout << "This program will take input from you and calculate the factorial.";
    cout << "\nPlease enter the value for n and k you want a factorial for (n>k). \n";
    cin >> inputN;
    cin >> inputK;
    

    for (countN=inputN; countN >= (inputN-inputK+1); countN--)
       {
        factorialN = factorialN * countN;
       }
   
    
    //This is not a nested loop. It is a second loop that occurs separately, after the previous for loop ends.
    //It does a similar calculation with countK, but compares the value to the input value of K (inputK)
    //It increases by one after each successful iteration, stopping once countK > inputK
    for (countK=1; countK<=inputK; countK++)
       {
        factorialK = factorialK * countK;
       }

    int property1 = factorialN/factorialK; //divides the final stored value of factorialN by the final stored value of factorialK
    
    cout << "C(" << inputN << "," << inputK << ")" << " = " << property1 << endl;
    
    return 0;
}


/*


TEST CASES

/-CASE 1-/
inputN = 10
inputK = 2
output = 45
expected output = 45


/-CASE 2-/
inputN = 10
inputK = 5
output = 252
expected output = 252


/-CASE 3-/
inputN = 10
inputK = 8
output = 45
expected output = 45

/-CASE 4-/
inputN = 12
inputK = 10
output = 66
expected output = 66

/-CASE 5-/
inputN = 12
inputK = 11
output = 12
expected output = 12

/-CASE 6-/
inputN = 13
inputK = 10
output = 286
expected output = 286

/-CASE 7-/
inputN = 13
inputK = 11
output = -29
expected output = 78



ANSWER: The lowest values that n & k need to be to result in an error are n=13 and k=11, which leads to an output of -29, when the result should be 78.
This is more efficient than program 1, but also has less multiplies. It needs to do less calculations to get to the same result.


*/