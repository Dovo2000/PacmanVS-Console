#pragma once
#include <iostream>

void Colour(int colour) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}


struct Usuario
{

	std::string name;
	int score;
	bool operator <(Usuario u1) {	
			return score < u1.score;
	}
};


void OrderRank(std::vector<Usuario> ordenedMap, std::map<std::string, int> rank) {

	ordenedMap.insert(ordenedMap.begin(), rank.begin(), rank.end());
	

}

std::map<std::string, int> LoadRanking() {

	std::map<std::string, int> rank;
	std::string name;
	int score;
	std::ifstream ranking("Ranking.txt");

	if (ranking.is_open()) {
		while (!ranking.eof()) {
			ranking >> name;
			ranking >> score;
			rank.insert(std::pair<std::string, int>(name, score));
		}
	}
	ranking.close();
	return rank;
}

void SaveRanking(std::string name, int _score, std::map<std::string, int> _rank) {

	_rank.insert(std::pair<std::string, int>(name, _score));

	std::ofstream ranking("Ranking.txt");


	if (ranking.is_open()) {
		for (std::map<std::string, int>::iterator it = _rank.begin(); it != _rank.end(); it++)
		{
			ranking << it->first;
			ranking << it->second;
		}
	}
	ranking.close();
}

void PrintRanking(std::map<std::string, int> _rank) {
	std::map<std::string, int>::iterator it;
	it = _rank.begin();
	for (int i = 0; i < 5 && it != _rank.end(); i++) {
		if (i == 0) {
			Colour(10);
		}
		else if (i == 4) {
			Colour(12);
		}
		else {
			Colour(11);
		}
		std::cout << i + 1 << "- ";
		std::cout << it->first << " => " << it->second << std::endl;
		it++;
	}
}

