#include "MovieStat.h"

int main()
{

	MovieStat mv;

	try
	{
		mv.loadScreen();
	}
	catch (const std::exception& e)
	{
		//cout << e.what();
	}

	system("Pause");
	return 0;
}