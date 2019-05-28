#pragma once
#include <iostream>

void Colour(int colour) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}

void OrderRank(std::vector<std::pair<std::string, int>> ordenedMap, std::map<std::string, int> rank) {

	ordenedMap.insert(ordenedMap.begin(), rank.begin(), rank.end());
	std::sort(ordenedMap.begin(), ordenedMap.end(),
		[](const std::pair<std::string, int> & l, const std::pair<std::string, int> & r) {
		if (l.second != r.second)
			return l.second < r.second;

		return l.first < r.first;
	});

}

std::map<std::string, int> LoadRanking() {

	std::map<std::string, int> rank;
	std::string name;
	int score;
	std::ifstream ranking("Ranking.txt");

	if (ranking.is_open()) {
		while (!ranking.eof()) {
			ranking >> name >> score;
			rank.insert(std::pair<std::string, int>(name, score));
		}
	}
	ranking.close();
	return rank;
}

void SaveRanking(std::string name, int _score, std::map<std::string, int> _rank, std::vector<std::pair<std::string, int>> _orderedMap) {

	_rank.insert(std::pair<std::string, int>(name, _score));

	OrderRank(_orderedMap, _rank);

	std::ofstream ranking("Ranking.txt");


	if (ranking.is_open()) {
		for (std::vector<std::pair<std::string,int>>::iterator it = _orderedMap.begin(); it != _orderedMap.end(); it++)
		{
			ranking << it->first << " " << it->second;
		}
	}
	ranking.close();
}

void PrintRanking(std::vector<std::pair<std::string, int>> _rank) {
	std::vector<std::pair<std::string, int>>::iterator it;
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
		std::cout << _rank[i].first << " => " << _rank[i].second << std::endl;
		it++;
	}
}

