#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <string>
#include "player.h"
#include "mathclass.h"
#include "matchstartdata.h"
#include "scorerview.h"
#include <QDir>
#include <QDebug>

using namespace std;


class DataHandler
{
public:
    DataHandler();
    /*
    string getData(string request);
    string setData(string request);
    */

    string sqlGet(string request);
    string mathcGet(string request, mathClass myM);
    string matchstartGet(string request, MatchStartData myS);
    string playerGet(string request, player myP);
};

#endif // DATAHANDLER_H
