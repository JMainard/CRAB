#ifndef PASSERELLE_H
#define PASSERELLE_H
#include <QVector>
#include <QString>
#include <QSqlQuery>
#include "technicien.h"
#include "borne.h"
#include "typeborne.h"
#include "station.h"
///
/// \brief The Passerelle class
/// Permet d'effectuer toutes les requêtes sql.
class Passerelle
{
public:
    Passerelle();
    static QVector <Technicien*> chargerLesTechniciens();
    static QVector <Borne> chargerLesBornes(int unIdStation);
    static QVector <Station> chargerLesStations();
    static void enregistrerVisite(visite uneVisite, int matLeTechnicien, qint64 compteurVisiteId);


};

#endif // PASSERELLE_H
