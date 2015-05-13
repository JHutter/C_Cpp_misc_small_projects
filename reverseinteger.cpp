// Author: JHutter
// Program: This program takes an integer and reverses its digits.
//
// Algorithm:
//  1. Get integer from user
//  2. Find digit length
//      2a. If number is between -9 and 9, length is 1
//      2b. Otherwise, divide by 10 and add 1 to length, stop when the absolute value of the divided number is less than one
//  3. Reverse the digits
//      3a. If the number is one digit, return the number
//      3b. For loop:
//              using the digit length, grab the leftmost digit and add it * a multipliercounter to the reversed digit
//              take that digit off of the number using %
//              increase the multipliercounter
//      3c. return the newly reversed number

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

int findDigitLength(int forwardDigit);
int reverseDigit(int forwardDigit, int digitLength);

int main()
{
    int forwardDigit;
    int digitLength = 0;
    cout << "Enter an integer, and I will reverse its digits:\n";
    cin >> forwardDigit;

    digitLength = findDigitLength(forwardDigit);
    cout << "The length of the integer is " << digitLength;

    cout << "\nYour number is " << forwardDigit
        << "\nYour number reversed is " << reverseDigit(forwardDigit, digitLength);

    return 0;
}

int findDigitLength(int forwardDigit)
{
    int digitLength;
    int tempDigit = forwardDigit;
    if (forwardDigit < 10 && forwardDigit > -10)
        return 1;
    else
    {
        do
        {
            tempDigit /= 10;
            digitLength++;
        }
        while (abs(tempDigit) > 0);
        return digitLength;
    }

}

int reverseDigit(int forwardDigit, int digitLength)
{
    int multiplier = static_cast<int>(pow(10, digitLength-1));
    int multCount = 1;
    int reversedDigit = 0;

    if (digitLength == 1)
    {
        return forwardDigit;
    }
    else
    {
        for (int i = digitLength; i > 0; i--)
        {
            reversedDigit += forwardDigit / multiplier * multCount;
            forwardDigit = forwardDigit % multiplier;
            multiplier /= 10;
            multCount *= 10;
        }
        return reversedDigit;
    }
}
