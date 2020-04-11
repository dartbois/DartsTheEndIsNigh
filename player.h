#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;


class player
{
public:
    player(int playerID, int playerID2);
    string playerFirst[2];
    string playerLast[2];
    string playerHometown[2];
    int playerRanking[2];
    float playerAvg180s[2];
    float playerAvg180Season[2];
    int playerLastWin[2];
    float playerAvgThrow[2];
    float playerAvgThrowSeason[2];
    int playerTurnScoreHi[2];
    int playerTurnScoreLo[2];
    int playerGamesPlayed[2];
    int playerGamesWon[2];

    float playerWinPercent[2];

    int playerMatch180s[2];
    int playerMatchesWon[2];
    int playerLegsWon[2];

    string dataGet(string request);

};

#endif // PLAYER_H
