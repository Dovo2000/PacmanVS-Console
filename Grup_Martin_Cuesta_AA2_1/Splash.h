#pragma once


void ShowSplash() {

	std::ifstream splash("Splash.txt");
	char tmp;
	Colour(14);
	if (splash.is_open())
	{
		while (!splash.eof())
		{
			splash >> std::noskipws >> tmp;

			std::cout << tmp;
		}

	}

}