/*
  Author: Mohammad Adeel
  Course: {136}
  Section: Tuesday 7:00PM - 8:50PM
  Instructor: G.P.
  Assignment: "Lab 3, Task 5"

This program computes C(n,k) with the formula (1+((n-k)/k)) using property1: C(n,n-1) = C(n,k)
It uses the type 'double' for all of the values to do the calculations and then uses static_cast to
convert the final result to an int.
*/

//TASK 5//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double inputN; //user inputs a value for n
    double inputK; //user inputs a value for k
    double productK = 1; //this starts product at 1 for input of k
    double productNK = 1; //this starts product at 1 for (1+((n-k)/k))
    double countK; //a value that increase until k reaches inputK
    double countN;

    
    //defines 'k' as 'n-k'
    if ((inputN - inputK) < inputK)
	   {
		inputK = (inputN - inputK);
	   }   
    
    //  calculate the product of (1+((n-k)/k))
    
    //This part starts the count for N at the value the user inputs for it.
    //It compares the countN value to the value provided by the calculation (1+((n-k)/k))
    //If the criteria is met, it calculates the necessary calculation by multiplying countN with productNK.
    //It then updates the value of productNK with the new value and decreases countN by 1.
    //The program stops running once countN is less than the value of (inputN-inputK+1)
    
    cout << "This program will take input from you and calculate the factorial.";
    cout << "\nPlease enter the value for n and k you want a factorial for. \n";
    cin >> inputN;
    cin >> inputK;

    
    for (countN=inputN; countN >= (1+(inputN-inputK)); countN--)
       {
        productNK = productNK * countN;
       }
    
    //This is not a nested loop. It is a second loop that occurs separately, after the previous for loop ends.
    //It does a similar calculation with countK, but compares the value to the input value of K (inputK)
    //It increases by one after each successful iteration, stopping once countK > inputK
    
    for (countK=1; countK<=inputK; countK++)
       {
        productK = productK * countK;
       }

    int property2 = productNK/productK; //divides the final stored value of factorialN by the final stored value of factorialK
    
    cout << "C(" << inputN << "," << inputK << ")" << " = " << static_cast<int>(property2) << endl;
    
    return 0;

}


/*


TEST CASES

/-CASE 1-/
inputN = 34
inputK = 20
output = 1391975640
expected output = 1391975640


/-CASE 2-/
inputN = 33
inputK = 19
output = 818809200
expected output = 818809200


/-CASE 3-/
inputN = 45
inputK = 42
output = 14190
expected output = 14190

/-CASE 4-/
inputN = 45
inputK = 30
output = -2147483648
expected output = 344867425584



ANSWER: One set of values that n & k need to be to result in an error are n=45 and k=30. So, although we can perform higher values with this, this program is still not good for other values.


*/