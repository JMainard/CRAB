#ifndef STATION_H
#define STATION_H
#include <QString>
#include <QVector>
#include "borne.h"
#include "visite.h"
class visite;
///
/// \brief The Station class
///Permet de savoir dans qu'elle sation il faut faire de la maintenance
class Station
{
private:

    int idStation;
    QString libelleEmplacement;
    QVector <Borne> lesBornes;
public:
    Station();
    Station(int unIdStation, QString unLibelleEmplacement, QVector<Borne> unVecteurBorne);
    int getId();
    QString getLibelleEmplacement();
    visite *getVisiteAFaire();
};

#endif // STATION_H
