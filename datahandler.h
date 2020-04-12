#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <string>
#include "player.h"
#include "mathclass.h"
#include "matchstartdata.h"
#include "scorerview.h"
#include <QDir>
#include <QDebug>

//This is a back-end class.
//This class controls the transfer of data between classes.
//Some data transfer is handled by slots and signals instead.
//--Most of the front end uses slots/signals. Most of the backend uses dataHandler.

using namespace std;


class DataHandler
{
public:
    //initialization
    DataHandler();

    //deprecated versions of current functions
    /*
    string getData(string request);
    string setData(string request);
    */

    //one function for each class that needs to 'talk'
    string sqlGet(string request); //for sqlHandler
    string mathcGet(string request, mathClass myM); //for mathClass
    string matchstartGet(string request, MatchStartData myS); //for MatchStartData
    string playerGet(string request, player myP); //for player
};

#endif // DATAHANDLER_H
