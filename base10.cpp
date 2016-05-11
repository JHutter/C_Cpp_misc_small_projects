// Author: J Hutter
// Date: 2015-06-29
// Sources: Textbook
//
// Program: This program converts base 10 numbers into base 2 (binary) numbers.
//
// Algorithm:
// This program uses an algorithm from Module 1, namely:
// While decimalRemainder > 0
// {
//      Find largest power of two that fits into the decimalRemainder
//      Place a 1 in that bit position
//      Place 0’s in any unfilled positions larger
//      Subtract it from the decimalRemainder to get a new decimalRemainder
// }

#include <iostream>
using namespace std;

int powIntBase2(int exponent);
void findHighestPowerOfTwo(int decimalRemainder, int &binaryDigit, int highestDigit, int &powerOfTwo); // Find the highest power of two that fits into decimalRemainder
void addCurrentToArray(bool binaryArray[], int arrayPosition);
void isHighest(int binaryDigit, bool &highestFound, int &highestDigit);
void printBinaryNumber(bool binaryArray[], int highestDigit); // does not print leading zeros

int main()
{
    int         decimalRemainder = 0,
                powerOfTwo = 0,
                binaryDigit = 30,
                highestDigit = 30; //This is for isHighest() and printBinaryNumber()
    bool        binaryArray[31] = {0}, //assumes 4 byte signed int, and might as well use a bool since bools are already 1 and 0
                highestFound = false; //This is to avoid printing leading zeroes in binary number

    cout << "CS 162 - Assignment 1 - JoAnne Hutter" << endl;
    cout << "This program converts a 4 byte int into binary without leading zeros." << endl << endl;
    cout << "Please enter the number in decimal: \n";
    cin >> decimalRemainder; //must be 2147483647 or less, per signed int limits
    //decimalRemainder = 2147483647;
    cout << "You entered " << decimalRemainder << endl;

    while (decimalRemainder > 0)
    {
        findHighestPowerOfTwo(decimalRemainder, binaryDigit, highestDigit, powerOfTwo);
        decimalRemainder -= powerOfTwo;
        addCurrentToArray(binaryArray, binaryDigit);
        isHighest(binaryDigit, highestFound, highestDigit);
    }

    cout << "The number in binary is ";
    printBinaryNumber(binaryArray, highestDigit);
    return 0;
}

int powIntBase2(int exponent) //base 2 int version of double pow
{
    int         base = 2;

    if (exponent < 0)
    {
        cout << "\nNo negative numbers, please.\n";
        return -1;
    }
    else if (exponent == 0)
        return 1;

    for (int iter = exponent; iter > 1; iter--)
        base *= 2;
    return base;
}

void findHighestPowerOfTwo(int decimalRemainder, int highestDigit, int &binaryDigit, int &powerOfTwo) // Find the highest power of two that fits into decimalRemainder, change 
{
//**************note to self, why highestDigit? change if necessary
    for (int digitsToCheck = highestDigit; digitsToCheck >= 0; digitsToCheck--)
        {
            int checkNumber = powIntBase2(digitsToCheck);
            if (checkNumber <= decimalRemainder)
            {
                binaryDigit = digitsToCheck;
                powerOfTwo = checkNumber;
                return;
            }
        }
    return;
}

void addCurrentToArray(bool binaryArray[], int arrayPosition)
{
    binaryArray[arrayPosition] = 1;
    return;
}

void isHighest(int binaryDigit, bool &highestFound, int &highestDigit)
{
    if (!highestFound)
    {
        highestDigit = binaryDigit;
        highestFound = true;
        return;
    }
    return;
}

void printBinaryNumber(bool binaryArray[], int highestDigit) // prints the binary number, does not print leading zeros
{
    for (int indexDigit = highestDigit; indexDigit >= 0; indexDigit--)
        cout << binaryArray[indexDigit];
    return;
}
