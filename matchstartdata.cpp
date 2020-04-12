#include "matchstartdata.h"
#include "datahandler.h"

MatchStartData::MatchStartData(int matchID)
{
    DataHandler myD;
    string id = to_string(matchID);
    string req;
    req = id + ":gameName";
    gameName = myD.sqlGet(req);
    req = id + ":gameDate";
    gameDate = myD.sqlGet(req);
    req = id + ":gameLocation";
    gameLocation = myD.sqlGet(req);
    req = id + ":gameStartScore";
    gameStartScore = stoi(myD.sqlGet(req));
    req = id + ":gameMatches";
    gameMatches = stoi(myD.sqlGet(req));
    req = id + ":gameLegs";
    gameLegs = stoi(myD.sqlGet(req));
    req = id + ":gameP1";
    gamePs[0] = myD.sqlGet(req);
    req = id + ":gameP2";
    gamePs[1] = myD.sqlGet(req);

}

string MatchStartData::dataGet(string request){
    string answer;
    if (request == "gameName"){
        answer = gameName;
    }
    else if (request == "gameDate"){
        answer = gameDate;
    }
    else if (request == "gameLocation"){
        answer = gameLocation;
    }
    if (request == "gameStartScore"){
        answer = to_string(gameStartScore);
    }
    else if (request == "gameLegs"){
        answer = to_string(gameLegs);
    }
    else if (request == "gameMatches"){
        answer = to_string(gameMatches);
    }
    else if (request == "gameP1"){
        answer = gamePs[0];
    }
    else if (request == "gameP2"){
        answer = gamePs[1];
    }
    return answer;
}
