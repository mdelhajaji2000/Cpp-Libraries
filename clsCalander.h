#pragma once
#include "clsDate.h"

#include <iostream>
#include <iomanip>
#include <String>
#include <ctime>

using namespace std;


class clsCalander :
    public clsDate
{

private:
    int _day;
    int _month;
    int _year;

public:

    clsCalander(int day, int month, int year);
    clsCalander();

        static void PrintCalendar(int month, int year) {
        int numberOfDays = DaysInmonth(month, year);
        int current = DayInWeekOrder(year, month, 1);

        cout << "\n  _______________" << MonthShortName(month) << " " << year << "_______________\n\n";
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        // Print leading spaces
        for (int i = 0; i < current; i++)
            cout << "     ";

     // Print days of the month
        for (int day = 1; day <= numberOfDays; day++) {
            cout << setw(5) << day;
            if (++current == 7) {
                current = 0;
                cout << endl;
            }
        }
        cout << "\n  _________________________________\n";
    }

    void PrintCalendar()
    {
        PrintCalendar(month, year);
    }

    static void PrintYearCalander(int year)
    {
        for (int i = 0; i < 12; i++)
        {
            cout << endl;
            PrintCalendar(i + 1 ,year);
            cout << endl;
        }
    }

    void PrintYearCalander()
    {
        PrintYearCalander(this->_year);
    }
};

clsCalander::clsCalander(int day, int month, int year)
{
    _day = day;
    _month = month;
    _year = year;
}

clsCalander::clsCalander()
{
    time_t now = time(nullptr);
    tm* timeinfo = localtime(&now);

    _day = timeinfo->tm_mday;
    _month = timeinfo->tm_mon + 1;
    _year = timeinfo->tm_year + 1900;
}

