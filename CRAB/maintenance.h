#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include <QVector>
#include "passerelle.h"
#include <QDebug>
///
/// \brief The Maintenance class
/// Permet d'affecter chaque maintenance à faire à des techniciens
class Maintenance
{
private:
QVector <Station> lesStations;
QVector <Technicien*> lesTechniciens;
QVector <visite*> lesVisites;


public:
    Maintenance();
    void reviser();
    void affecterVisites();
    void afficherTout();

};

#endif // MAINTENANCE_H
