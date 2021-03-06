#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class MovieStat
{
private:
	int input, sum, max;
public:
	//CONSTRUCTOR
	MovieStat();
	//DESTRUCTOR
	~MovieStat();

	//GETTERS
	int getInput() const;	//GETS INPUT
	double getAverage(int) const;	// CALCULATES ANR RETURNS THE AVERAGE
	double getMedian(const int *, const int) const;	//CALCULATES MEDIAN
	int getSum() const;		//GETS SUM OF THE ARRAY
	int getMax() const;		//GETS LARGEST VALUE IN THE ARRAY

	//SETTERS
	void setInput(int);		//SETS INPUT FROM USER
	void setSum(int);		//SETS SUM VALUE OF ARRAY
	void setMax(const int *, const int);	//SETS LARGEST VALUE IN THE ARRAY
	void setMax(int);			//SETMAX OVERLOADING


	//ASK THE USER HOW MANY STUDENTS WERE SURVEYED.
	//AN ARRAY OF INTEGERS WITH THIS MANY ELEMENTS
	//SHOULD THEN BE DYNAMICALLY ALLOCATED.
	void questionA(ofstream&);


	//ALLOW THE USER TO ENTER THE NUMBER OF MOVIES
	//EACH STUDENT SAW INTO THE ARRAY.
	//CALCULATE AND DISPLAY THE AVERAGE, MEDIAN, AND
	//MODE OF THE VALUES ENTERED.
	void questionBandC(const int, ofstream&);

	//INPUT VALIDATION
	void inputValidation(char, int&, ofstream&);

	//DOES NOTHING ALMOST
	//ONLY TO LOAD THE FIRST QUESTION
	void loadScreen(ofstream&);

	//DISPLAYS ALL THE ELEMENTS IN THE ARRAY
	void displayArray(const int *, const int, ofstream&);

	//DISPLAYS THE MODE IN THE ARRAY
	void displayMode(const int *, const int, ofstream&);

	//A FUNCTION FOR CHECKING THE TEMP ARRAY IF A VALUE
	//HAS ALREADY BEEN COUNTED
	bool ifExists(const vector<int>, int);

	//THIS FUNCTION WILL BE USED FOR COMPARING THE INDEX OF AN ELEMENT
	//TO THE REST OF THE ELEMENT IF IT'S GREATER OR EQUAL.
	//IF TRUE, WILL TAKE THE CURRENT BOOL VARIABLE VALUE AND MULTIPLY TO TRUE
	//ELSE, TAKE CURRENT BOOL VARIABLE VALUE AND MULTIPLY TO FALSE
	bool ifGreaterOrEqual(const int, const int, bool&);
};