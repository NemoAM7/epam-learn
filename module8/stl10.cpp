#include<algorithm>
#include<map>
#include<iostream>
using namespace std;

struct PlayerStats {
	std::string playerId;
	std::string playerName;
	int score;

	PlayerStats(string playerId, string playerName, int score) :
		playerId(playerId), playerName(playerName), score(score) {
	}
};

struct PlayerRankComparator {
	bool operator()(const PlayerStats& p1, const PlayerStats& p2) const {
		if (p1.score < p2.score) return false;
		if (p1.score > p2.score) return true;
		if (p1.playerName < p2.playerName) return true;
		if (p1.playerName > p2.playerName) return false;
		if (p1.playerId < p2.playerId) return true;
		return false;
	}
};

int main() {
	std::map<PlayerStats, bool, PlayerRankComparator> leaderboard = {
		{ {"P001", "Alice", 1500}, true },
		{ {"P003", "Charlie", 1200}, true },
		{ {"P002", "Bob", 1500}, true },
		{ {"P005", "David", 1800}, true },
		{ {"P004", "Alice", 1000}, true },
		{ {"P007", "Emily", 1200}, true },
		{ {"P006", "Bob", 1500}, true },
	};

	int rank = 0;
	for (const auto& [player, status] : leaderboard) {
		cout << "Rank #" << ++rank << endl;
		cout << "ID: " << player.playerId << ", Name: " << player.playerName << ", Score: " << player.score << "\n==================================\n";
	}
}