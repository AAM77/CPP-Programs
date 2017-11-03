/*
  Author: Mohammad Adeek
  Course: {136}, Tuesday 6:50PM - 8:50PM
  Instructor: G.P.
  Assignment: <lab6, DDD Debugger>
*/

#include <iostream> 
using namespace std;

void f1(int k)
{
  int i;
  int s=1;

  cout << "This function outputs powers of 2 from 1 to " << k << endl; // going step by step, I noticed that that output here was showing only 1-9, when k was set to 10. Changed the for loop condition to ' <= ' instead of <.

  for (i=1; i<=k; i++) //I placed a stop at all the cout locations and found that this was not incrementing. The for loop had a semicolon
// 
  {
    cout << "2^" << i << " = ";
    s *= 2;
    cout << s << endl;
  }
}

void f2(int k)
{
  int i;

  cout << "This function outputs even and odd numbers from 1 to " << k << endl;
  
  for (i=1; i<=k; i++) // changed condition to <=
  {
    cout << i << " is an ";
    if (i/2 == (i+1)/2) 
      cout << "even"; // I put a stop here and at the next cout. This should have said even, but was saying odd.
    else
      cout << "odd"; // was even, and I changed it to odd
    cout << " number." << endl;
  }
}

void f3(int num)
{
  int i=0; //i needed to be initialized and assigned to 0. 
  int s=num;

  cout << "This function keeps dividing a large number by 2:" << endl;

  while (num>0)
  {
    cout << num << endl;
    num /= 2;
    i++;
  }

  cout << s << " is 2^" << i-1 << endl;
}

int main()
{
  int num=1073741824;
  int k=10;

  f1(k);
  f2(k);
  f3(num);

  return 0;
}
