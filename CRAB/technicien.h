#ifndef TECHNICIEN_H
#define TECHNICIEN_H
#include <QString>
#include <QVector>
#include "visite.h"
///
/// \brief The Technicien class
/// Permet de récupérer les informations des techniciens afin de les affecter à des visites équitablement
class Technicien
{
private:
    int matricule;
    QString nom;
    QString prenom;
    QVector <visite*> lesVisites;
public:
    Technicien();
    Technicien(int unMatricule, QString unNom, QString unPrenom);
    int getTempsOccupe();
    void affecterVisite(visite* uneVisite);
    QVector <visite*> getLesVisites();
    QString getInfo();
    int getMatricule();
};

#endif // TECHNICIEN_H
