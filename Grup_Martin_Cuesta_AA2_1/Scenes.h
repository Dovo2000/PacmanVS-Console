#pragma once
#include <iostream>
#include <queue>

void Colour(int colour) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}


struct Usuario
{

	std::string name;
	int score;
	friend bool operator <(Usuario u, Usuario u1) {	
			return u.score < u1.score;
	}
};



void OrderRank(std::priority_queue <Usuario> &ordenedMap, std::map<std::string, int> rank) {

	std::map<std::string, int>::iterator it = rank.begin();
	Usuario tmp;

	while (it != rank.end())
	{
		tmp.name = it->first;
		tmp.score = it->second;
		ordenedMap.push(tmp);
		it++;
	}
	

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
	
	if (_rank[name] < _score){
		_rank[name] = _score;
	}
	else
		_rank.insert(std::pair<std::string, int>(name, _score));

	std::ofstream ranking("Ranking.txt");


	if (ranking.is_open()) {
		for (std::map<std::string, int>::iterator it = _rank.begin(); it != _rank.end(); it++)
		{
			ranking << it->first << std::endl;
			ranking << it->second << std::endl;
		}
	}
	ranking.close();
}

void PrintRanking(std::priority_queue <Usuario> ordenedMap, std::map<std::string, int> rank) {
	rank = LoadRanking();
	OrderRank(ordenedMap, rank);
	if (!ordenedMap.empty()) {
		for (int i = 0; i < 5 && !ordenedMap.empty(); i++) {
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
			std::cout << ordenedMap.top().name << "         " << ordenedMap.top().score << std::endl;
			ordenedMap.pop();
		}
	}
}

