#pragma once    /*--BETA!!!--*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

// Algorithms and Probleme Solving level 2 Library  from Youtube channel Programming advice    //
// Here you can Found The functions used in Course 5 "algorithms and probleme solving level 2" //
// Created By mdelhajaji2000                                                                   //
// To use this Library You need to include the .h file path                                    //

//namespace :
//--std
//--Random_func : functions generators
//--arr : functions to worck eith arrays
//--input : functions for users inputs



namespace std
{

         bool CheckPrime(int Number)
        {
            int M = round(Number / 2);
            for (int Counter = 2; Counter <= M; Counter++)
            {
               if (Number % Counter == 0)
                return false;
            }

            return true;
        }
    
    //Note: Perfect Number is = Sum(all divisors)
    bool isPerfectNumber(int Number)
    {
        int Sum = 0;
        for (int i = 1; i < Number; i++)
        {
           if (Number % i == 0)
           Sum += i;
        }
        return Number == Sum;
    }

    //This function Reverse the number
    int ReverseNumber(int Number)
    {
        int Remainder = 0, Number2 = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            Number2 = Number2 * 10 + Remainder;
        }
        return Number2;
    }


        // Digit Frequency
        // Input:
        // 1223222
        // 2
        // Output:
        // Digit 2 Frequency is 5 Time(s).
    int CountDigitFrequency(short DigitToCheck, int Number)
    {
        int FreqCount = 0, Remainder = 0;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number = Number / 10;
            if (DigitToCheck == Remainder)
            { 
                FreqCount++;
            }
        }
        return FreqCount;
    }

    void Swapnumbers(int &a, int &b)// you can used for arrays elements
    {
        int Temp;
        Temp = a;
        a = b;
        b = Temp;
    }

    
} // namespace std // standar hedear fil functions // (in your code only you need to use "using namesapce std" to worck with those functions)


namespace Input
{
    int ReadPositifNumber(string Message)
    {
        int number;
        cout << Message;
        cin >> number;
        while (number < 0 || cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << Message;
            cin >> number;
        }
        
        return number;
    }

    void ReadPositifNumber(int& number, string Message)
    {
        cout << Message;
        cin >> number;
        while (number < 0 || cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << Message;
            cin >> number;
        }
        
        
    }

    int readNumber(string Message)
    {
        int number;
        
        cout << Message;
        cin >> number;
        while (cin.fail())
        {
            cin.clear();
		    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << Message;
            cin >> number;
        }
        
        
        return number;
    }

    void readNumber(int &number, string Message)
    {
        cout << Message;
        cin >> number;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << Message;
            cin >> number;
        }
        
    }

    int readNumber( int from, int To, string Message)
    {
        int number;
        cout << Message;
        cin >> number;

        while (number < from || number > To || cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << Message;
            cin >> number;
        }
        
        return number;
    }

        
    string readtext(string Message) // function to read text or string en general
    {
        string text;
        cout << Message;
        cin >> text;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << Message;
            cin >> text;
        }
        return text;
    }

    void readtext(string& text, string Message)
    {
        cout << Message;
        cin >> text;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << Message;
            cin >> text;
        }
        
    }
} // namespace Input // Inputs Function To read data from user

namespace Random_func
{
    int Random(int from, int to)
    {
        // Seed the random number generator using the current time
        std::mt19937 rng(static_cast<unsigned>(time(nullptr)));

        // Generate a random number between 1 and 100
        std::uniform_int_distribution<int> distribution(from, to);
        int random_number = rand() % (to - from + 1) + from;

        return random_number;
    }

    char GetRandomChar() // Basic charcters // include numbers!
    {
        return char(Random_func::Random(33, 122));
    }

    string GeneratWords(char a_or_A, short Length)
{
    string Word = "";
    for (int i = 0; i < Length; i++)
    {
        if (a_or_A >= 'a' && a_or_A <= 'z') // Use <= instead of =<
            Word += char(Random_func::Random('a', 'z')); // Generate lowercase letters
        else
            Word += char(Random_func::Random('A', 'Z')); // Generate uppercase letters
    }

    return Word;
}
} // namespace Random // Functions To generate Random numbers

namespace arr
{
    void readarray(int arr[], int arrlenght)
    {
        for (int i =0; i < arrlenght; i++)
        {
            arr[i] = Input::ReadPositifNumber("enter array elemnt : ");
        }
    }

    void readarray(string arr[], int arrlenght)
    {
        for (int i = 0; i < arrlenght; i++)
        {
            cout << "enter array elemnt : ";
            cin >> arr[i];
        }
    }

    void readarray(char arr[], int arrlenght)
    {
        for (int i = 0; i < arrlenght; i++)
        {
            cout << "enter array elemnts : ";
            cin >> arr[i];
        }
    }

    void Printarr(int arr[], int arrlenght, char position = 'x')// Char position to read the output line position [vertical = y][horizontal = x]
    {
        if (position == 'x')
        {
            for (int i = 0; i < arrlenght; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else {
            for (int i = 0;i < arrlenght; i++)
            {
                cout << arr[i] << endl;
            }
        }
    }
    void Printarr(string arr[], int arrlenght, char position = 'x')// Char position to read the output line position [vertical = y][horizontal = x]
    {
        if (position == 'x')
        {
            for (int i = 0; i < arrlenght; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else {
            for (int i = 0 ;i < arrlenght; i++)
            {
                cout << arr[i] << endl;
            }
        }
    }
    void Printarr(char arr[], int arrlenght, char position = 'x')// Char position to read the output line position [vertical = y][horizontal = x]
    {
        if (position == 'x')
        {
            for (int i = 0; i < arrlenght; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else {
            for (int i = 0;i < arrlenght; i++)
            {
                cout << arr[i] << endl;
            }
        }
    }

    int Sumarr(int arr[], int arrlenght)
    {
        int Sum = 0;
        for (int i = 0; i < arrlenght; i++)
        {
            Sum += arr[i];
        }

        return Sum;
    }

    int Minarr(int arr[], int arrlenght) // MIninmant element of an array
    {
        int index = arr[0];
        for (int i = 0; i < arrlenght; i++)
        {
            if (arr[i] < index) index = arr[i];
        }

        return index;
    }

    int Maxarr(int arr[], int arrlenght) //Maximant element of an array
    {
        int index = arr[0];
        for (int i = 0; i < arrlenght; i++)
        {
            if (arr[i] > index) index = arr[i];
        }

        return index;
    }

    void Fill_array_With_Random_numbers(int arr[], int arrlenght, int Range_from = 1, int Range_to = 100)
    {
        for (int i = 0; i < arrlenght; i++)
        {
            arr[i] = Random_func::Random(Range_from, Range_to);
        }
    }

    float ArrayAverge(int arr[], int arrlenght)
    {
        return (float)arr::Sumarr(arr, arrlenght) / arrlenght;
    }

    void CopyArray(int arrSource[], int arrDestination[], int arrSourcelenght)
    {
        for (int i = 0; i < arrSourcelenght; i++)
        {
            arrDestination[i] = arrSource[i];
        }
    }

    void CopyArray(string arrSource[], string arrDestination[], int arrlenght)
    {
        for (int i = 0; i < arrlenght; i++)
        {
            arrDestination[i] = arrSource[i];
        }
    }

    void CopyArray(char arrSource[], char arrDestination[], int arrlenght)
    {
        for (int i = 0; i < arrlenght; i++)
        {
            arrDestination[i] = arrSource[i];
        }
    }

    bool Check_number_existance(int number, int arr[], int arrlenght)
    {
        for (int i = 0; i < arrlenght; i++)
        {
            if (number == arr[i]) return true;
        }
        return false;
    }

    void AddArrayelements(int number, int arr[], int& arrlenght)
    {
        arrlenght++;
        arr[arrlenght - 1] = number;
    }

    void CopyDistinctNumbersToArray(int arrSource[100], int
    arrDestination[100], int SourceLength, int& DestinationLength)
    {
        for (int i = 0; i < SourceLength; i++)
        {
            if (!arr::Check_number_existance(arrSource[i], arrDestination, DestinationLength))
            {
                arr::AddArrayelements(arrSource[i], arrDestination, DestinationLength);
            }
        };
    }

    short Find_NUmber_Position(int Number, int arr[], int arrlenght)
    {
        /*This function will search for a number in array and return its 
        index,
        or return -1 if it does not exists*/
        for (int i = 0; i < arrlenght; i++)
        {
            if (arr[i] == Number) return i;
        }
        return -1;//if you reached here, this means the number is not found

    }

    void Sum_two_array_in_third_array(int arr1[], int arr2[], int Sum_arr[], int arrlenght)
    {
        for (int i = 0; i < arrlenght; i++)
        {
            Sum_arr[i] = arr1[i] + arr2[i];
        }
    }

    void ShuffleArray(int arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swapnumbers(arr[Random_func::Random(1, arrLength) - 1], arr[Random_func::Random(1, arrLength) - 1]);
        }
    }
} // namespace arr // Functions To worck with arrays
