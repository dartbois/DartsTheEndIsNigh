#ifndef MATCHSTARTDATA_H
#define MATCHSTARTDATA_H
#include <string>

using namespace std;

class MatchStartData
{
public:
    MatchStartData();
    void postInit(int matchID);
    MatchStartData(int matchID);
    string gameName;
    string gameDate;
    string gameLocation;
    int gameStartScore;
    int gameLegs;
    int gameMatches;
    int gamePs[2];
    string dataGet(string request);

};



#endif // MATCHSTARTDATA_H
