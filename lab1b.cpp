/*
  Author: Mohammad Adeel
  Course: {136}
  Section: Tuesday 7:00PM - 8:40PM
  Instructor: G. P.
  Assignment: "Lab 1"

  This program asks for the hour and minutes when sunset occurs and then outputs 'Good morning," "Good afternoon," or "Good evening" based on the time of day and when sunset is.
  
  The second portion of the program (Task 2) prompts the user to input how many minutes it takes him or her to get home and then calculates and displays the approximate time of arrival.
*/

#include <iostream>
#include <ctime>
using namespace std;

//this program prompts the user for the hour and say good morning, good afternoon, or good evening, depending on the time.



int main()
{
    
    time_t t;
    struct tm *now;
    t = time(0);
    now = localtime(&t);
    int hour = now->tm_hour;
    int min = now->tm_min;
    
    int sunset_hour;
    int sunset_minutes;
    int minutesToHome;
    int minutes_home;
    int total_minutes;
    int hour_home;
        
        
    cout << "What hour is sunset? (4-9): \n";
    cin >> sunset_hour;
    
    cout << "Enter the minutes when sunset occurs (0-59): \n";
    cin >> sunset_minutes;

    
    if ((0 <= hour && hour <= 11) && (0 <= min && min <= 59))
    {
        cout << "Good morning Instructor! \n";
    }
    
    else if ((12 <= hour && hour <= sunset_hour) && (0 <= min && min <= sunset_minutes))
    {
        cout << "Good afternoon Instructor! \n";
    }
    
    else if ((sunset_hour <= hour && hour <= 11) && (sunset_minutes <= min && min <= 59))
    {
        cout << "Good evening Instructor! \n";
    }
    
    cout << "How many minutes from now do you expect to be home? \n";
    cin >> minutesToHome;
    
    total_minutes = min + minutesToHome;
    
    if (total_minutes >= 60)
    {
        hour_home = hour + 1;
        minutes_home = total_minutes % 60;

    }
    else
    {
        hour_home = hour;
        minutes_home = total_minutes;
    }
    
    if (0 <= minutes_home && minutes_home <= 9)
    {
        cout << "You will get home at " << hour_home << ":" << 0 << minutes_home << endl;
    }
    else
    {
        cout << "You will get home at " << hour_home << ":" << minutes_home << endl;
    }
    
    return 0;
    
}