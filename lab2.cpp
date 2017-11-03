/*
  Author: Mohammad Adeel
  Course: {136}
  Section: Tuesday 7:00PM - 8:40PM
  Instructor: G.P
  Assignment: "Lab 2"

This program take input from the user for the initial population, growth rate, minimum rate loss, the carrying capacity, and number of years the user wants data for. It then inserted these values into the Verhulst formula to calculate the population size for a given year.
*/


/****************************
PSEUDOCODE

p(k) represents the population for a given year k

declare the year starting with year = 0;
declare a final year for user specification;
declare a rate of growth (g);
declare a rate of loss (h);
declare a carrying capacity (M);
declare a population size starting with 10 (populationSize = 10);

Prompt the user for input: Specify the growth rate;
cin: save the input as growthRate;

Prompt the user for input: Specify the loss rate;
cin: save the input as lossRate;

Prompt the user for input: the carrying capacity;
cin: save the input as carryingCapacity;

Prompt the user for input: how many years is the user interested in?
cin: save the input as year;


Use the inputs to calculate p(k) for the first year, when k = 1

check if (year <= finalYear)
as long as (year <= finalYear), then compute p(k+1) = (1+g-h) * p(k) - g*p(k)^2 / M;

output the text "Year" << "     " << "Population";
after running the formula, output the result and increment k by 1.


The Verhulst Formula: p(k+1) = (1+g-h) * p(k) - g*p(k)^2 / M
****************************/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{

     int year = 0;
     int finalYear;
     double growthRate;
     double minimumLossRate;
     double carryingCapacity;
     double population;



     //Ask for the user for the initial population and error check for negative values
     cout << "Specify the initial population: \n";
     cin >> population;
     
     if (population < 0)
        {
         do 
           { 
            cout << "Invalid entry! Enter a positive value for the initial population! \n";
            cin >> population;
           }
         while (population < 0);
        }



     //Ask for the user for the growth rate and error check for negative values
     cout << "Specify a growth rate (as a percent): \n";
     cin >> growthRate;
     
     if (growthRate < 0)
        {
         do 
           { 
            cout << "Invalid entry! Enter a positive percent value for the growth rate! \n";
            cin >> growthRate;
           }
         while (growthRate < 0);
        }

     growthRate /= 100.0; //convert the percent growth rate to a decimal
     


     //Ask for the user for the minimum loss rate and error check for negative values
     cout << "Specify a minimum loss rate (as a percent): \n";
     cin >> minimumLossRate;     
     
     if (minimumLossRate < 0)
        {
         do 
           { 
            cout << "Invalid entry! Enter a positive percent value for the minimum loss rate! \n";
            cin >> minimumLossRate;
           }
         while (minimumLossRate < 0);
        }

     minimumLossRate /= 100.0; //convert the percent minimum loss rate to a decimal



     //Ask for the user for the carrying capacity and error check for negative values
     cout << "Specify a carrying capacity: \n";
     cin >> carryingCapacity;

     if (carryingCapacity < 0)
        {
         do
           {
            cout << "Invalid entry! Enter a positive value for the carrying capacity! \n";
            cin >> carryingCapacity;
            }
         while (carryingCapacity < 0);
        }



     //Ask for the number of years the user wants data for and error check for negative values
     cout << "How many years would you like to do the calculation "
          << "for? \n";
     cin >> finalYear;

     if (finalYear < 0)
        {
         do
           {
            cout << "Invalid entry! Enter a positive value for the number of years! \n";
            cin >> finalYear;
           }
         while (finalYear < 0);
        }



    //output the table column names "year" and "population"

     cout << "Year" << "  " << "Population \n";
     cout << year << "       " << population << endl; //display initial year and population
       

     while (++year <= finalYear)
       {
         
        population = ((1.0 + growthRate - minimumLossRate) * (population)) - ((growthRate * (population*population))/carryingCapacity);
         
        cout << year << "       " << static_cast<int>(population)
             << endl;
        
         
       }
    
    
    return 0;

}


    
/*********************************************************************
---- PART 2 of LAB: ----

CRITICAL VALUES of g leading to oscillating and chaotic behavior:

Oscillating Critical Value: g = 200 . If I set number of years to 20, I saw oscillation at g=199. However, if I set the number of years to 200, I noticed that the population eventually stopped oscillating and stabilized. At g=200, however the population continued to oscillate. 

Possible Chaotic Critical Values:  g = 265 is when it begins oscillating between 3 values instead of 2. It creates a pattern, but it I still consider it chaotic because it oscillates between more than 2 values. When g = 277 the chaotic behavior appears to stop exhibiting all pattern and becomes fully chaotic. Also, I used number of years as 200 instead of 20 because it provided me with a better picture of what was happening with the population.

////////////////////////////////////////////////////////////////////////////////////////
//
//The test cases I tried were 125, 200, and 300. I received similar output valuesfor each of
//these as in the charts on instructions and examples you provided.
//The test values I tried to determine oscillation were 175, 185, 195-200.
//The test values I tried to determin chaotic behavior were 215, 225, 250-260, 270-280.
//Also, when I tested these values, I output data for 200 years instead of 20 because it
//provided me with more complete information over a longer period of time.
//I used 200 years because the seeming oscillations sometimes stabilized after a while
//or the chaotic nature began exhibiting patterns.
//
////////////////////////////////////////////////////////////////////////////////////////

*********************************************************************/

/****************
I tried the following cose first, but realized I needed a loop:

 if (growthRate < 0)
        {
        cout << "Invalid entry! Enter a positive percent value for the growth rate! \n";
        cin >> growthRate;
        }

     else
        {
         growthRate /= 100.0;       
     
         cout << "Specify a minimum loss rate (as a percent). \n";
         cin >> minimumLossRate;
        }

     if (minimumLossRate < 0)
        {
         cout << "Invalid entry! Enter a positive percent value for the minimum loss rate! \n";
         cin >> minimumLossRate;
        }

     else
        {
         minimumLossRate /= 100.0;
     
         cout << "Specify a carrying capacity. \n";
         cin >> carryingCapacity;
        }

     if (carryingCapacity < 0)
        {
        cout << "Invalid entry! Enter a positive value for the carrying capacity! \n";
        cin >> carryingCapacity;
        }

     else
       {
        cout << "How many years would you like to do the calculation "
             << "for? \n";
        cin >> finalYear;
       }
    

     if (finalYear < 0)
       {
        cout << "Invalid entry! Enter a positive value for the carrying capacity! \n";
        cin >> finalYear;
       }
     else
        cout << "Year" << "  " << "Population \n";
        cout << year << "       " << population << endl;
********************/



