#ifndef MATCHSTARTDATA_H
#define MATCHSTARTDATA_H
#include <string>

//This is a backend class.
//This class holds all of the information about the active game.
//It is involved with GameSelectionMenu, ScorerView, and AudienceView.
//It is also connected with Player.

using namespace std;

class MatchStartData
{
public:
    //Initialization
    MatchStartData();
    //Gathers all intitialization info after the class is actually instantiated
    void postInit(int matchID);
    //Initialization overloaded (identical, codewise, to postInit)
    MatchStartData(int matchID);
    //Name identifier of the selected game
    string gameName;
    //Date of the game
    string gameDate;
    //Location of the game
    string gameLocation;
    //Score the game will start at
    int gameStartScore;
    //Legs before the game ends
    int gameLegs;
    //Total number of matches in the game
    int gameMatches;
    //IDs of the players in the game
    int gamePs[2];
    //Facilitates data transmission
    string dataGet(string request);

};



#endif // MATCHSTARTDATA_H
