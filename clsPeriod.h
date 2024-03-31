#pragma once
#include "clsDate.h"        // This Library contain Errors Fix theme before use it ! 

class clsPeriod : public clsDate
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate DateTo)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    // static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    // {

    //     if (
    //         clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
    //         ||
    //         clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
    //         )
    //         return false;
    //     else
    //         return true;

    // }


    // bool IsOverLapWith(clsPeriod Period2)
    // {
    //     return IsOverlapPeriods(*this, Period2);
    // }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.print();


        cout << "Period End: ";
        EndDate.print();


    }

};
