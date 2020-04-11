#include "sqlhandler.h"
#include "datahandler.h"
#include "player.h"
#include <stdio.h>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>


sqlHandler::sqlHandler(const QString& path) {
    bool failFlag = false;

    //Opening the db
    const QString DRIVER("QSQLITE");
    QSqlDatabase dartdb = QSqlDatabase::addDatabase(DRIVER);
    dartdb.setDatabaseName(path);

    //Check if opened
    if (!dartdb.open())
    {
       failFlag = true;
       printf("dartdb failed to open");
    }

}

void sqlHandler::sqlCloseConnection(){
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
    return;
}


//Getters: used to get individual player values from SQLite db
string sqlHandler::sqlGetFirstName(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [First Name] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

string sqlHandler::sqlGetLastName(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Last Name] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

string sqlHandler::sqlGetHometown(int playerID){
    QSqlQuery query;

    query.prepare("SELECT Hometown FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

int sqlHandler::sqlGetRanking(int playerID){
    QSqlQuery query;

    query.prepare("SELECT Ranking FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

float sqlHandler::sqlGetAvg180s(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Avg 180s] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toFloat();
}

float sqlHandler::sqlGetAvg180sSeason(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Avg 180s (Season)] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toFloat();
}

int sqlHandler::sqlGetLastGameWin(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Last Game Win] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

float sqlHandler::sqlGetAvgThrowScore(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Avg Throw Score] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toFloat();
}

float sqlHandler::sqlGetAvgThrowScoreSeason(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Avg Throw Score (Season)] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toFloat();
}

int sqlHandler::sqlGetTurnScoreHi(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Turn Score High] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetTurnScoreLo(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Turn Score Low] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGamesPlayed(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Num Games Played] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGamesWon(int playerID){
    QSqlQuery query;

    query.prepare("SELECT [Num Games Won] FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

//Getters: used to get individual game information from db
string sqlHandler::sqlGetGameName(int gameID){
    QSqlQuery query;

    query.prepare("SELECT [Game Name] FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

string sqlHandler::sqlGetGameDate(int gameID){
    QSqlQuery query;

    query.prepare("SELECT Date FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

string sqlHandler::sqlGetGameLocation(int gameID){
    QSqlQuery query;

    query.prepare("SELECT Location FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toString().toStdString();
}

int sqlHandler::sqlGetGameStartScore(int gameID){
    QSqlQuery query;

    query.prepare("SELECT [Start Score] FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGameMatches(int gameID){
    QSqlQuery query;

    query.prepare("SELECT [Max # Matches] FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGameLegs(int gameID){
    QSqlQuery query;

    query.prepare("SELECT [Max # Legs] FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGameP1(int gameID){
    QSqlQuery query;

    query.prepare("SELECT Player1 FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

int sqlHandler::sqlGetGameP2(int gameID){
    QSqlQuery query;

    query.prepare("SELECT Player2 FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();

    return query.value(0).toInt();
}

//Getter: needs to get all player information from SQLite (for populating lists)
string sqlHandler::sqlGetPlayerList() {
    QSqlQuery query;
    string temp;
    string playerInfoLine = "";

    query.prepare("SELECT [Player ID], [First Name], [Last Name], Hometown, Ranking, [Num Games Played] FROM players ORDER BY [Player ID]");
    query.exec();

    while (query.next()){
        for (int i=0; i<6; i++){
            temp = query.value(i).toString().toStdString();
            playerInfoLine.append(temp);
            playerInfoLine.append("\t");
        }

        playerInfoLine.append("\n");
    }

    return playerInfoLine;
}

string sqlHandler::sqlGetGameList() {
    QSqlQuery query;
    string temp;
    string gameInfoLine = "";

    query.prepare("SELECT [Game ID], [Game Name], Date, Location, Player1, Player2 FROM games ORDER BY [Game ID]");
    query.exec();

    while (query.next()){
        for (int i=0; i<6; i++){
            temp = query.value(i).toString().toStdString();
            gameInfoLine.append(temp);
            gameInfoLine.append("\t");
        }

        gameInfoLine.append("\n");
    }

    return gameInfoLine;
}

//Setter: needs to set final player info into SQLite
void sqlHandler::sqlSetPlayerFinal(int playerID, player Player) {


}

//Setter: needs to update game db stats after game is complete
void sqlHandler::sqlSetGameFinal(int gameID){

}

//Setter: needs to add a new player to the SQLite db
void sqlHandler::sqlAddNewPlayer(int playerID, player Player){
    QSqlQuery query;

    string playerFirst, playerLast, playerHome;
    int playerRank, playerLastWin, playerTSHi, playerTSLo, playerPlayed, playerWon;
    float playerAvg180, playerAvg180S, playerATS, playerATSS;
    QString QplayerFirst, QplayerLast, QplayerHome;

    playerFirst = Player.playerFirst[0];
    playerLast = Player.playerLast[0];
    playerHome = Player.playerHometown[0];
    playerRank = Player.playerRanking[0];
    playerAvg180 = Player.playerAvg180s[0];
    playerAvg180S = Player.playerAvg180Season[0];
    playerLastWin = Player.playerLastWin[0];
    playerATS = Player.playerAvgThrow[0];
    playerATSS = Player.playerAvgThrowSeason[0];
    playerTSHi = Player.playerTurnScoreHi[0];
    playerTSLo = Player.playerTurnScoreLo[0];
    playerPlayed = Player.playerGamesPlayed[0];
    playerWon = Player.playerGamesWon[0];

    QplayerFirst = QString::fromStdString(playerFirst);
    QplayerLast = QString::fromStdString(playerLast);
    QplayerHome = QString::fromStdString(playerHome);


    query.prepare("INSERT INTO players ([Player ID], [First Name], [Last Name], Hometown, Ranking, [Avg 180s], [Avg 180s (Season)], [Last Game Win], [Avg Throw Score], [Avg Throw Score (Season)], [Turn Score High], [Turn Score Low], [Num Games Played], [Num Games Won]) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, playerID);
    query.bindValue(1, QplayerFirst);
    query.bindValue(2, QplayerLast);
    query.bindValue(3, QplayerHome);
    query.bindValue(4, playerRank);
    query.bindValue(5, playerAvg180);
    query.bindValue(6, playerAvg180S);
    query.bindValue(7, playerLastWin);
    query.bindValue(8, playerATS);
    query.bindValue(9, playerATSS);
    query.bindValue(10, playerTSHi);
    query.bindValue(11, playerTSLo);
    query.bindValue(12, playerPlayed);
    query.bindValue(13, playerWon);

    query.exec();
    qDebug()<<query.exec()<<endl;

}

//Setter: needs to remove a player from the SQLite db
void sqlHandler::sqlRemovePlayer(int playerID){
    QSqlQuery query;

    query.prepare("DELETE FROM players WHERE [Player ID] = ?");
    query.bindValue(0, playerID);

    query.exec();
    query.first();
}

//Setter: needs to add a new game to the SQLite db
void sqlHandler::sqlAddNewGame(int gameID, MatchStartData newGame){
    QSqlQuery query;

    string gName, gLoc, gDate;
    int gStart, gLegs, gMatches, gP1, gP2;
    QString QgName, QgLoc, QgDate;

    gName = newGame.gameName;
    gLoc = newGame.gameLocation;
    gDate = newGame.gameDate;
    gStart = newGame.gameStartScore;
    gLegs = newGame.gameLegs;
    gMatches = newGame.gameMatches;
    gP1 = newGame.gamePs[0];
    gP2 = newGame.gamePs[1];

    QgName = QString::fromStdString(gName);
    QgLoc = QString::fromStdString(gLoc);
    QgDate = QString::fromStdString(gDate);

    query.prepare("INSERT INTO Games ([Game ID], [Game Name], Date, Location, [Start Score], [Max # Matches], [Max # Legs], Player1, Player2) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, gameID);
    query.bindValue(1, QgName);
    query.bindValue(2, QgDate);
    query.bindValue(3, QgLoc);
    query.bindValue(4, gStart);
    query.bindValue(5, gMatches);
    query.bindValue(6, gLegs);
    query.bindValue(7, gP1);
    query.bindValue(8, gP2);

    query.exec();
    qDebug()<<query.exec()<<endl;
}

//Setter: needs to remove a game from the SQLite db
void sqlHandler::sqlRemoveGame(int gameID){
    QSqlQuery query;

    query.prepare("DELETE FROM Games WHERE [Game ID] = ?");
    query.bindValue(0, gameID);

    query.exec();
    query.first();
}
