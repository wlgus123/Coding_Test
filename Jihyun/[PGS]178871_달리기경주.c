#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer;
	map<string, int> playerRank;
	map<int, string> rankPlayer;

	// 초기화
	for (int i = 0; i < players.size(); i++)
	{
		playerRank.insert({ players[i], i });
		rankPlayer.insert({ i, players[i] });
	}

	// 순위 비교 및 변동
	for (int i = 0; i < callings.size(); i++)
	{
		int curRank = playerRank[callings[i]];			// 현재 플레이어 순위
		string curPlayer = rankPlayer[curRank];			// 현재 플레이어 이름
		string frontPlayer = rankPlayer[curRank - 1];	// 바로 앞 플레이어 이름

		// 순위 변동 (플레이어 이름)
		string tempPlayer = rankPlayer[curRank];
		rankPlayer[curRank] = rankPlayer[curRank - 1];
		rankPlayer[curRank - 1] = tempPlayer;

		// 순위 변동 (플레이어 순위)
		--playerRank[curPlayer];
		++playerRank[frontPlayer];
	}

	for (int i = 0; i < players.size(); i++)
	{
		answer.push_back(rankPlayer[i]);
	}

	return answer;
}

int main()
{
	vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
	vector<string> callings = { "kai", "kai", "mine", "mine" };
	vector<string> temp;
	// 테스트용 임시 데이터 삽입
	temp = solution(players, callings);

	// 확인용 출력 코드
	cout << "========before========" << endl;
	for (string player : players)
	{
		cout << player << " ";
	}
	cout << endl << "======================" << endl << endl;

	cout << "=========after========" << endl;
	for (string res : temp)
	{
		cout << res << " ";
	}
	cout << endl << "======================" << endl;

	return 0;
}