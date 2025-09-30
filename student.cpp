// This program will input an undetermined number of student names
// and a number of grades for each student. The number of grades is
// given by the user. The grades are stored in an array.
// Two functions are called for each student.
// One function will give the numeric average of their grades.
// The other function will give a letter grade to that average.
// Grades are assigned on a 10 point spread.
// 90-100 A	80-89 B	70-79 C	60-69 D	Below 60 F

// SAMUEL TORRES

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAXGRADE = 25; // maximum number of grades per student
const int MAXCHAR = 30;	 // maximum characters used in a name

typedef char StringType30[MAXCHAR + 1]; // character array data type for names
										// having 30 characters or less.

typedef float GradeType[MAXGRADE]; // one dimensional integer array data type

float findGradeAvg(GradeType, int); // finds grade average by taking array of
									// grades and number of grades as parameters

char findLetterGrade(float); // finds letter grade from average given
							 // to it as a parameter
int main()
{
	StringType30 firstname, lastname; // two arrays of characters defined
	int numOfGrades = 3;			  // holds the number of grades
	GradeType grades;				  // grades defined as a one dimensional array
	float average;					  // holds the average of a student's grade

	ifstream inFile("grades.txt");
	if (!inFile)
	{
		cout << "Error: could not open grades.txt" << endl;
		return 1;
	}

	cout << setprecision(2) << fixed << showpoint;

	// Input names and grades for each student
	while (inFile >> firstname >> lastname)
	{
		for (int count = 0; count < numOfGrades; count++)
		{
			inFile >> grades[count]; // Fill in the input statement to place grade in the array
		}

		cout << firstname << " " << lastname << " has an average of ";

		// Fill in code to get and print average of student to screen
		average = findGradeAvg(grades, numOfGrades);
		cout << average;

		// Fill in call to get and print letter grade of student to screen
		cout << " which gives the letter grade of "
			 << findLetterGrade(average) << endl
			 << endl;
	}

	inFile.close();
	return 0;
}

float findGradeAvg(GradeType array, int numGrades)
{
	// Fill in the code for this function
	float sum = 0;
	for (int i = 0; i < numGrades; i++)
		sum += array[i];
	return sum / numGrades;
}

char findLetterGrade(float numGrade)
{
	// Fill in the code for this function
	if (numGrade >= 90)
		return 'A';
	else if (numGrade >= 80)
		return 'B';
	else if (numGrade >= 70)
		return 'C';
	else if (numGrade >= 60)
		return 'D';
	else
		return 'F';
}
