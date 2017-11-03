/* *************************************************************************************************************
Author: Mohammad Adeel
Course: {136}
Section: Tuesday 7:00PM - 8:50PM
CS136 Instructor: G.P.
Assignment: "Lab 6, task 2"
Date: October, 27, 2017

This program:
[1] takes in a number from the user.
[2] determines how many digits the number has
[3] if the number has more than one (1) digit, it finds the sum of of the digits
[4] it then checks to see if the sum has more than one digit.
[5] if it does, it repeats the process until the sum results in a value that is a single digit.
[6] this rendition of the program (task 2/c) checks to see if the input number is divisible by 9
[7] if the number is not divisible by 9, it adds or subtracts a certian amount to make it a multiple of 9.
************************************************************************************************************* */


#include <iostream>
#include <cmath>
using namespace std;

// Precondition: number > 0
// Postcondition: the return number of digits in num
int numDigits(int num);

// Precondition: number > 0, index > 0
// Postcondition: return the index'th digit of num
int getDigit(int num, int index);

// Precondition: number > 0
// Postcondition: the return value is the iterated sum of digits of num
int sumDigits(int num);

// Precondition: the number is evaluated to determine if it is a multiple of 9 or not
// Postcondition: the number is adjusted (through addition or subtraction) to make it a divisible 9
// and have the sum of its digits equal 9
void transformNum(int& num);


int main()
{
    int num,
        numberDigits,
        sum;
        
    
    
    cout << "Please enter a number: " << endl;
    cin >> num;
    
    sum = sumDigits(num);
    
    //cout << "The number of digits before transformation is: " << numDigits(num) << endl;
    cout << "The sum of the number with a single result is: " << num << " is " << sum << endl;
    
    transformNum(num);
    
    cout << "The number has been transformed to be divisible by 9. The transformed number is " << num << endl;
    //cout << "The number of digits after transformation is: " << numDigits(num) << endl;
    //cout << "The sum of the new transformed number is: " << sum << endl;
    
    return 0;
}


// Precondition: number > 0
// Postcondition: the return number of digits in num
//This function determins the number of digits in a number
int numDigits(int num)
{
    int number_of_Digits = 0;
    
    while (num > 0)
    {
        num = num/10;
        number_of_Digits++;
    }

    return (number_of_Digits);
}

// Precondition: number > 0, index > 0
// Postcondition: return the index'th digit of num
//This function assigns each digit in the number an index
//founded on base 10.
//It then outputs/returns the value at that spot.
int getDigit(int num, int index)
{
    int digit;
    num = num/pow(10, index);
    digit = num % 10;
    
    return (digit);
}

// Precondition: number > 0
// Postcondition: the return value is the iterated sum of digits of num
//This functions calculates the sum of all the digits in the original number
//and outputs the result. If the result is not a single digit, it iterates
//until the result is a single digit.
int sumDigits(int num)
{
    int digit;
    int finalSum;
    int sum = 0;
    
    int number_of_Digits = numDigits(num);
    
    if (number_of_Digits > 1)
    {
    
        while (number_of_Digits != 1)
        {
            for (int index = 0; index < number_of_Digits; index++)
            {
                digit = getDigit(num, index);
                sum = sum + digit;
            }

            num = sum;
            finalSum = sum;
            number_of_Digits = numDigits(num);
            sum = 0;
        }
        
        return (finalSum);
        
    }
    else
    {
        return (num);
    }
}


//precondition: the number is evaluated to determine if it is a multiple of 9 or not
//postcondition: the number is adjusted (through addition or subtraction) to make it a divisible 9
//and have the sum of its digits equal 9
//This function checks to see if the input number is divisible by 9.
//If it is not, it adjusts the value to by either adding or subtracting
//such that it becomes divisible by 9.
void transformNum(int& num)
{
    int sum;
    int num1;
    int digit;
    int remainder;
    int difference;
    int transformed_Number;
    
    remainder = num % 9;
    
    if (remainder != 0)
    {
        sum = sumDigits(num);
        difference = 9 - sum;
        num1 = num;
        digit = getDigit(num1, 0);
        
        if ((digit + difference) > 9)
            num = num - sum;
        
        else
            num = num + difference;
    }
}

/* ************************************************
TEST CASES / TESTING

[1]
Input: 234565
Output:
The sum of the number with a single result is: 234565 is 7
The number has been transformed to be divisible by 9. The transformed number is 234567

* The sum or the original number is 7, so it was increased by 2 to be divisible by 9

[2]
Input: 123456789
Output:
The sum of the number with a single result is: 123456789 is 9
The number has been transformed to be divisible by 9. The transformed number is 123456789

* I chose a larger number to test if it can handle the number. Here, the number is already
* divisible by so no change is necessary.

[3]
Input: 2345675
Output: 
The sum of the number with a single result is: 2345675 is 5
The number has been transformed to be divisible by 9. The transformed number is 2345679

* I chose a number that is 5 greater than 234567, to test if it provides the correct output
* of 4 greater than the input.

[4]
Input: 35
Output:
The sum of the number with a single result is: 35 is 8
The number has been transformed to be divisible by 9. The transformed number is 36

* I chose a smaller number to test if it worked on smaller numbers as well.
* I also chose this number to test for a difference of 1.
* The output was what I expected it to be.

[5]
Input: 8
Output:
The sum of the number with a single result is: 8 is 8
The number has been transformed to be divisible by 9. The transformed number is 9

* I chose this number to make sure it works with a number that has a single digit.
* It also chose a number that was not 9 to see if it would output correctly.

************************************************* */