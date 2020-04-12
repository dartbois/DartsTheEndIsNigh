#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <QString>
using namespace std;

//This is a backend class.
//This class holds all variables for both players in a match.


class player
{
public:
    player(int playerID, int playerID2); //constructor
    player(); //overloaded constructor that leaves variables uninitialized
    void postInit(int playerID, int PlayerID2); //initializes after actual instantiation
    string playerFirst[2]; //player first names
    string playerLast[2]; //player last names
    string playerHometown[2]; //player hometown
    int playerRanking[2]; //rank of player in the league
    float playerAvg180s[2]; //average 180s
    float playerAvg180Season[2]; //average 180s for the season
    int playerMatch180s[2]; //number of 180s in the current match
    int playerLastWin[2]; //when was their last win?
    float playerAvgThrow[2]; //average throw
    float playerAvgThrowSeason[2]; //average throw for the season
    int playerTurnScoreHi[2]; //highest turn score
    int playerTurnScoreLo[2]; //lowest turn score
    int playerGamesPlayed[2]; //game count
    int playerGamesWon[2]; //won games
    float playerWinPercent[2]; //percentage of won games
    int playerMatchesWon[2]; //percentage of matches won
    int playerLegsWon[2]; //percentage of legs won

    bool active; //defines which player is currently active

    QString p1Slings; //record of the slings of player 1
    QString p2Slings; //record of the slings of player 2

    string dataGet(string request); //facilitates data transfer

};

#endif // PLAYER_H
