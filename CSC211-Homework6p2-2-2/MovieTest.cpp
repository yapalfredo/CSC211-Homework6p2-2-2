#include "MovieStat.h"

int main()
{

	MovieStat mv;
	ofstream outFile;

	try
	{
		outFile.open("Homework6p2-2-2.txt");
		mv.loadScreen(outFile);
		outFile.close();
	}
	catch (const std::exception& e)
	{
		//cout << e.what();
	}

	system("Pause");
	return 0;
}