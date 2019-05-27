#pragma once

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

	return rank;
}

void SaveRanking(std::string name, int _score, std::vector<std::pair<std::string, int>> _rank) {

	std::ofstream ranking("Ranking.txt");

	if (ranking.is_open()) {
		for (int i = 0; i < 5; i++)
		{
			ranking << _rank[i].first << " " << _rank[i].second;
		}
	}

}

void PrintRanking(std::vector<std::pair<std::string, int>> _rank) {
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			Colour(10);
		}
		else if (i == 4) {
			Colour(12);
		}
		else {
			Colour(11);
		}
		std::cout << i + 1 << "- " << _rank[i].first << " => " << _rank[i].second << std::endl;
	}
}

void Colour(int colour) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}