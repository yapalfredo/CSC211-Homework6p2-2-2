#include "MovieStat.h"

MovieStat::MovieStat()
{
	//CONSTRUCTOR

	setMax(0);
}

MovieStat::~MovieStat()
{
	//DESTRUCTOR
}

void MovieStat::setInput(int input)
{
	//THIS FUNCTION SETS THE INPUT 
	//VARIABLE FROM THE USER
	this->input = input;
}

int MovieStat::getInput() const
{
	//THIS FUNCTION RETURNS THE INPUT
	//TO THE USER
	return input;
}

void MovieStat::setSum(int sum)
{
	//THIS FUNCTION SETS THE SUM
	//VARIABLE FROM THE ARRAY
	this->sum = sum;
}

int MovieStat::getSum() const
{
	//THIS FUNCTION RETURNS THE SUM
	//VARIABLE VALUE FROM THE ARRAY
	return sum;
}

void MovieStat::setMax(int max) {
	//THIS FUNCTIONS SETS THE MAX
	//VARIABLE. THIS COULD BE INITIALIZED
	//OR BE CALLED WHILE LOOKING FOR THE
	//LARGEST VALUE IN THE ARRAY
	this->max = max;
}

void MovieStat::setMax(const int * movieArr, const int SIZE)
{
	//THIS FUNCTION WILL SET THE MAX VARIABLE VALUE
	//DEPENDING ON THE LARGEST VALUE OF THE ELEMENT
	//IN THE ARRAY
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (movieArr[i] > movieArr[j] && movieArr[i] > max)
			{
				setMax(movieArr[i]);
			}
			else if (movieArr[i] < movieArr[j] && movieArr[j] > max)
			{
				setMax(movieArr[j]);
			}
		}
	}
}

int MovieStat::getMax() const
{
	//RETURNS THE MAX VARIABLE VALUE
	return max;
}

void MovieStat::loadScreen()
{
	//CALLS questionA()
	questionA();
}

void MovieStat::questionA()
{
	//FUNCTION CALLS INPUT VALIDATION
	inputValidation('A', input);

	setInput(input);
	const int SIZE = getInput();

	cout << endl;
	questionBandC(SIZE);
}

void MovieStat::questionBandC(const int SIZE)
{
	//FOR DYNAMIC ALLOCATION	
	//vector<int> movieArr;

	int * movieArr = new int[SIZE];

	/*for (size_t i = 0; i < SIZE; i++)
	{
		cout << "For student " << i + 1 << ": ";
		inputValidation('B', input);
		movieArr.push_back(getInput());
	}*/

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "For student " << i + 1 << ": ";
		inputValidation('B', input);
		movieArr[i] = getInput();
	}

	cout << endl;
	displayVector(movieArr, SIZE);
	cout << endl << endl << "The average of the array is: " << getAverage(SIZE) << endl << endl;
	cout << "The median of the array is: " << getMedian(movieArr, SIZE) << endl;
	setMax(movieArr, SIZE);
	displayMode(movieArr, SIZE); cout << endl;

	//movieArr.clear();
	//movieArr.resize(0);
}

void MovieStat::inputValidation(char caseChar, int& input)
{
	//THIS FUNCTION VALIDATIONS THE INPUT
	//IT WILL ONLY ACCEPT INPUTS GREATER THAN OR EQUAL TO ZERO
	do {
		switch (caseChar)
		{
		case 'A':	//QUESTION A
			cout << "How many students were surveyed?: ";
			cin >> input;
			break;
		case 'B':
			cout << "Please enter the number of movies: ";
			cin >> input;
			break;
		default:
			break;
		}

		if (input <= 0)
		{
			cout << "Only positive integers are accepted. Please try again!" << endl;
		}
	} while (input <= 0);
}

//void MovieStat::displayVector(vector<int> movieArr)
void MovieStat::displayVector(const int* movieArr , const int SIZE)
{
	//THIS FUNCTION DISPLAY THE VALUES IN THE ARRAY

	int sum = 0;	//THIS VARIABLE WILL HOLD
					//THE SUM OF THE ARRAY

	cout << "Your array of inputs are: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << movieArr[i] << " ";
		sum += movieArr[i];
	}

	setSum(sum);
}

double MovieStat::getAverage(int SIZE) const
{
	//THIS FUNCTION CALCULATES THE AVERAGE VALUE OF THE ARRAY
	return ((double)getSum() / (double)SIZE);
}

//double MovieStat::getMedian(vector<int> movieArr) const
double MovieStat::getMedian(const int * movieArr, const int SIZE) const
{
	//THIS FUNCTION WILL GET THE MEDIAN IN THE ARRAY
	double result;
	int medianSize = SIZE / 2;

	if (SIZE % 2 == 0)
	{
		//IF THE SIZE OF THE ARRAY IS EVEN. GET THE TWO MIDDLE VALUES
		//AND COMPUTE THE AVERAGE
		result = (double)(movieArr[medianSize] + movieArr[medianSize - 1] / 2);
	}
	else if (SIZE % 2 == 1)
	{
		//ELSE, JUST GET THE MIDDLE ELEMENT
		result = movieArr[medianSize];
	}

	return result;
}

void MovieStat::displayMode(const int* movieArr, const int SIZE)
{
	//THIS FUNCTION WILL LOOK FOR AND DISPLAY THE MODE IN THE ARRAY
	vector<int> tempMovieArr(getMax(), 0);

	int counter = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (movieArr[i] == movieArr[j])
			{
				counter++;
			}
		}
		if (!ifExists(tempMovieArr, movieArr[i] - 1))
		{
			tempMovieArr.at(movieArr[i] - 1) = counter;
		}
		counter = 0;
	}
	cout << endl;
	//////////////////////////////////////////////////////////////
	//DISPLAY THE OCCURENCE OF EACH GENERATED VALUE IN THE ARRAY
	for (int i = 0; i < tempMovieArr.size(); i++)
	{
		if (tempMovieArr.at(i) > 0)
		{
			cout << i + 1 << " occured " << tempMovieArr.at(i);

			if (tempMovieArr.at(i) > 1)
			{
				cout << " times" << endl;
			}
			else
			{
				cout << " time " << endl;
			}
		}
	}
	//////////////////////////////////////////////////////////////
	//SET MODE(S)
	cout << endl << "The mode(s) is/are: " << endl;
	bool greaterOrEqual;
	for (int i = 0; i < tempMovieArr.size(); i++)
	{
		greaterOrEqual = true;

		for (int j = 0; j < tempMovieArr.size(); j++)
		{
			ifGreaterOrEqual(tempMovieArr.at(i), tempMovieArr.at(j), greaterOrEqual);
		}

		if (!greaterOrEqual)
		{
			tempMovieArr.at(i) = 0;	//SET TO ZERO IF IT'S NOT A MODE
		}

		if (tempMovieArr.at(i) > 1) //WILL ONLY DISPLAY OCCURENCE GREATER THAN 1
		{
			cout << i + 1 << "    ";
		}
	}
	////////////////////////////////////////////////////////////////
	cout << endl;
	tempMovieArr.clear();
	tempMovieArr.resize(0);
}

bool MovieStat::ifExists(const vector<int> tempMovieArr, int val)
{
	//THIS FUNCTION WILL RETURN TRUE IF THE NUMBER HAS ALREADY BEEN COUNTED
	//OR FALSE OTHERWISE
	bool result = false;

	if (tempMovieArr.at(val) <= 0)
	{
		result = false;
	}
	else
	{
		result = true;
	}
	return result;
}

bool MovieStat::ifGreaterOrEqual(const int a, const int b, bool &greaterOrEqual)
{
	//THIS FUNCTION WILL BE USED TO DETERMINE THE MODE(S)
	//IT HAS 3 ARGUMENTS, BOTH INTS WILL BE COMPARED, THEN
	//SETS THE BOOL VARIABLE TO 'MULTIPLY EQUALS' DEPENDING
	//RESULT OF THE CONDITION. THEN IT WILL RETURN THAT BOOL
	//VARIABLE
	if (a >= b)
	{
		greaterOrEqual *= true;
	}
	else
	{
		greaterOrEqual *= false;
	}

	return greaterOrEqual;
}