#include "maintenance.h"
#include <QDebug>

///
/// \brief Maintenance::Maintenance
/// Constructeur permettant de créer des vecteur qui ne sont plus vide afin de les utiliser dans les 2 porchaines procédures
///
Maintenance::Maintenance()
{
    lesStations=Passerelle::chargerLesStations();
    lesTechniciens=Passerelle::chargerLesTechniciens();
    reviser();
    affecterVisites();

}
///
/// \brief Maintenance::reviser
/// Procédure  permettant d'établir l'ensemble des visites à réaliser sur les stations
void Maintenance::reviser()
{
qDebug() << "reviser() je passe";
    for (int noStation=0; noStation<lesStations.size(); noStation++) {
        if (lesStations[noStation].getVisiteAFaire()!=NULL)
        {
        lesVisites.push_back(lesStations[noStation].getVisiteAFaire());
        }
    }
}
///
/// \brief Maintenance::affecterVisites
/// Affecte les visites à réaliser aux techniciens, en répartissant équitablement le travail
/// entre les techniciens. Chaque visite est affectée au technicien le moins occupé en temps
/// total de maintenance préventive. L'état de chaque visite doit alors être mis à jour.
///
void Maintenance::affecterVisites()
{
qDebug() << "affecterVisite  je passe";

 qint64 idVisite = QDateTime::currentDateTime().toTime_t();
 qDebug() << idVisite;
    for ( int noVisite=0; noVisite<lesVisites.size(); noVisite++)
    {
qDebug() << "Crash ?";
qDebug() << "noVisite" << noVisite;
        int tempTech=lesTechniciens[0]->getTempsOccupe();
        qDebug()<< "eho";
        Technicien* TechMoinsOccuper = lesTechniciens[0];
qDebug() << "Toujours pas crash";
        for ( int noTechnicien=1; noTechnicien<lesTechniciens.size(); noTechnicien++) {
                if (lesTechniciens[noTechnicien]->getTempsOccupe()<tempTech)
                {
qDebug() << "no Technicien" << noTechnicien;
                    TechMoinsOccuper = lesTechniciens[noTechnicien];
                    tempTech = lesTechniciens[noTechnicien]->getTempsOccupe();
                }
        }
        TechMoinsOccuper->affecterVisite(lesVisites[noVisite]);
        Passerelle::enregistrerVisite(lesVisites[noVisite],TechMoinsOccuper->getMatricule(),idVisite);
        idVisite++;
    }

}
/**
 * @brief Maintenance::afficherTout
 */
void Maintenance::afficherTout()
{
    for (int i = 0 ; i<lesTechniciens.size() ; i++)
    {
        qDebug()<<lesTechniciens[i]->getInfo();
    }
}


