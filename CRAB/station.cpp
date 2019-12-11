#include "station.h"
#include <QDebug>
Station::Station()
{

}

Station::Station(int unIdStation, QString unLibelleEmplacement, QVector<Borne> unVecteurBorne)
{
    idStation=unIdStation;
    libelleEmplacement=unLibelleEmplacement;
    lesBornes=unVecteurBorne; //Doit appeler la fonction de passerelle avec les info de borne et de type Bornes en fonction  de l'id de la station
}

///
/// \brief Station::getId
/// \return retourne l'identifiant de la station
/// Fonctions retournant l'identifiant de la Station en int
int Station::getId()
{
    return(idStation);
}
///
/// \brief Station::getLibelleEmplacement
/// \return retourne le libellé de l'emplacement
/// Fonctions retournant les informations des Emplacements des Stations
QString Station::getLibelleEmplacement()
{
    return(libelleEmplacement);
}
///
/// \brief Station::getVisiteAFaire
/// \return retourne une instance de classe Visite
/// retourne une instance de classe Visite recensant toutes les bornes de la station
/// qui nécessitent d'être révisées, ou null s'il n'y a aucune borne à réviser
///
visite* Station::getVisiteAFaire()
{
qDebug() << "Je passe  getVisiteAFaire";
    QVector <Borne> lesBornesAReviser;
    for(int numBorne=0; numBorne<lesBornes.size(); numBorne++) {
        if(lesBornes[numBorne].estAReviser()==true){
            lesBornesAReviser.push_back(lesBornes[numBorne]);
        }
    }
    if(lesBornesAReviser.size() !=0) {
    //Doit donc renvoyer un vecteur et une variable de Station
    return(new visite(lesBornesAReviser, this));
    }
    else {
    return(NULL);
    }

}
