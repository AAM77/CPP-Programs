/* *************************************************************************************************************
Author: Mohammad Adeel
Course: {136}
Section: Tuesday 7:00PM - 8:50PM
CS136 Instructor: G.P.
Assignment: "Lab 6, task 1"
Date: October, 27, 2017

This program:
[1] takes in a number from the user.
[2] determines how many digits the number has
[3] if the number has more than one (1) digit, it finds the sum of of the digits
[4] it then checks to see if the sum has more than one digit.
[5] if it does, it repeats the process until the sum results in a value that is a single digit.
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


int main()
{
    int num,
        numberDigits,
        sum;
        
    cout << "Please enter a number: " << endl;
    cin >> num;
    
    sum = sumDigits(num);
    
    //cout << "The number of digits before transformation is: " << numberDigits << endl;
    cout << "The sum of the number with a single result is: " << num << " is " << sum << endl;
    
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
int getDigit(int& num, int index)
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
    
    while (number_of_Digits != 1)
    {
        for (int index = 0; index < number_of_Digits; index++)
        {
            digit = getDigit(num, index);
            sum = sum + digit;
        }
        
        num = sum;
        finalSum = sum;
        number_of_Digits = numDigits(sum);
        sum = 0;
    }
    
    return (finalSum);
}


/* ************************************************
TEST CASES / TESTING

* TESTING shown in lab6c *



************************************************* */