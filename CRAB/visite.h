#ifndef VISITE_H
#define VISITE_H
#include "station.h"
#include <QVector>
class Station;
///
/// \brief The visite class
/// Permet de référencé les visites à réaliser à partir de la base de données.
class visite
{
private:
    char etat;
    int dureeTotale;
    Station* laStation;
    QVector <Borne> lesBornes;

public:
    visite();
    visite(QVector<Borne> lesBornesAVisiter, Station* uneStation);
    int getDureeTotale();
    char getEtat();
    void changerEtat();
    QString getInfoVisite();
};

#endif // VISITE_H
