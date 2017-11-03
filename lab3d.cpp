/*
  Author: Mohammad Adeel
  Course: {136}
  Section: Tuesday 7:00PM - 8:50PM
  Instructor: G.P.
  Assignment: "Lab 3, Task 4"

This program computes C(n,k) with the formula (n-k+1)/k! using property2: C(n,k) = C(n,n-k)
It uses the type 'long int' for all of the values to do the calculations. It can handle more values than the previous task.
*/

//TASK 4//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long int inputN; //user inputs a value for n
    long int inputK; //user inputs a value for k
    long int factorialN = 1; //this starts factorial at 1 for input of n
    long int factorialK =1; //this starts factorial at 1 for input of k
    long int countN; //a value that increases until n reaches inputN
    long int countK; //a value that increase until k reaches inputK
    
    // calculate task3: (n-k+1)/k! using property2: C(n,k) = C(n,n-k)
    
    //This part starts the count for N at the value the user inputs for it.
    //It compares the countN value to the value provided by the calculation (inputN-inputK+1)
    //If the criteria is met, it calculates the necessary calculation by multiplying countN with factorialN.
    //It then updates the value of factorialN with the new value and decreases countN by 1.
    //The program stops running once countN is less than the value of (inputN-inputK+1)
    
    cout << "This program will take input from you and calculate the factorial.";
    cout << "\nPlease enter the value for n and k you want a factorial for (n>k). \n";
    cin >> inputN;
    cin >> inputK;
    
    
    //defines 'k' as 'n-k'
    if ((inputN - inputK) < inputK)
	   {
		inputK = (inputN - inputK);
	   }   

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

    int property2 = factorialN/factorialK; //divides the final stored value of factorialN by the final stored value of factorialK
    
    cout << "C(" << inputN << "," << inputK << ")" << " = " << property2 << endl;
    
    return 0;
}


/*


TEST CASES

/-CASE 1-/
inputN = 13
inputK = 11
output = 78
expected output = 78


/-CASE 2-/
inputN = 20
inputK = 15
output = 5504
expected output = 5504


/-CASE 3-/
inputN = 20
inputK = 18
output = 190
expected output = 190

/-CASE 4-/
inputN = 21
inputK = 18
output = 1330
expected output = 1330

/-CASE 5-/
inputN = 21
inputK = 19
output = 210
expected output = 210

/-CASE 6-/
inputN = 21
inputK = 20
output = 21
expected output = 21

/-CASE 7-/
inputN = 22
inputK = 20
output = 231
expected output = 231


/-CASE 8-/
inputN = 30
inputK = 20
output = 30045015
expected output = 30045015

/-CASE 9-/
inputN = 30
inputK = 9
output = 14307150
expected output = 14307150

/-CASE 10-/
inputN = 45
inputK = 15
output = 5154512
expected output = 344867425584

/-CASE 11-/
inputN = 31
inputK = 19
output = 141120525
expected output = 141120525

/-CASE 12-/
inputN = 33
inputK = 19
output = -27582433
expected output = 818809200

/-CASE 3-/
inputN = 33
inputK = 20
output = 573166440
expected output = 573166440


ANSWER: One set of values that n & k need to be to result in an error are n=33 and k=19. I found that when the calculation of k=n-k yields 14, the program returns an incorrect result. This may have to do with it not being double. This program is more efficient than in task 3 becasue it can handle more values.


*/