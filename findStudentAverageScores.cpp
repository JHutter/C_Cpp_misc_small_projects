// Author: JHutter
//
// Program: This program reads students' names and test scores
// from a given input file. It then finds the average score and corresponding grade, as well as the class average.
//
// Algorithm:
// 1. set up arrays (studentName[], testScores[][], studentAverageScore[], and studentAverageGrade[])
// 2. set up variables for class average (classAverageScore, classAverageGrade)
// 3. open file
// 4. function: use a loop to grab each of the parallel arrays
// 5. function: use a loop to calc averageScore and averageGrade
// 6. output everything
// 7. close file

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void readStudents(ifstream& inFile, int classSize, int numberOfTests, string studentName[], double testScores[][5]);
double findAverageScore(double inputArray[], int numberOfEntries);
char findAverageGrade(double score);
void printResults(int classSize, string studentName[], double studentAverageScore[], char studentAverageGrade[], double classAverageScore, char classAverageGrade);

int main()
{
    ifstream inFile;
    int classSize = 10
        , numberOFTests = 5;
    string studentName[classSize];
    double testScores[classSize][5];
    double studentAverageScore[classSize]
        , classAverageScore;
    char studentAverageGrade[classSize]
        , classAverageGrade;

    inFile.open("arrays.txt");

    readStudents(inFile, classSize, numberOFTests, studentName, testScores);

    for (int row = 0; row < classSize; row++)
    {
        studentAverageScore[row] = findAverageScore(testScores[row], numberOFTests);
        studentAverageGrade[row] = findAverageGrade(studentAverageScore[row]);
    }
    classAverageScore = findAverageScore(studentAverageScore, classSize);
    classAverageGrade = findAverageGrade(classAverageScore);

    printResults(classSize, studentName, studentAverageScore, studentAverageGrade, classAverageScore, classAverageGrade);

    inFile.close();
    return 0;
}

void readStudents(ifstream& inFile, int classSize, int numberOfTests, string studentName[], double testScores[][5])
{
    for (int row = 0; row < classSize; row++)
    {
        inFile >> studentName[row];
        for (int col = 0; col < 5; col++)
        {
            inFile >> testScores[row][col];
        }
    }
}

double findAverageScore(double inputArray[], int numberOfEntries)
{
    double sum = 0
        , average;

    for (int i = 0; i < numberOfEntries; i++)
        sum += inputArray[i];

    average = sum / numberOfEntries;
    return average;
}

char findAverageGrade(double score)
{
    if (score >= 90)
        return 'A';
    else if (score >= 80)
        return 'B';
    else if (score >= 70)
        return 'C';
    else if (score >= 60)
        return 'D';
    else
        return 'F';
}

void printResults(int classSize, string studentName[], double studentAverageScore[], char studentAverageGrade[], double classAverageScore, char classAverageGrade)
{
    cout << "------------Student Averages------------\n";
    for (int row = 0; row < classSize; row++)
    {
        cout << setw(15) << left << studentName[row] << setw(6) << studentAverageScore[row] << " " << studentAverageGrade[row] << endl;
    }

    cout << "\n------------Class Averages------------\n";
    cout << setw(15) << left << "Class" << setw(6) << classAverageScore << " " << classAverageGrade << endl;
    return;
}
