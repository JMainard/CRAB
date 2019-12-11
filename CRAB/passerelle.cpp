#include "passerelle.h"
#include"jeuenregistrement.h"
#include <QDebug>
Passerelle::Passerelle()
{

}
///
/// \brief Passerelle::chargerLesTechniciens
/// \return Charge les techniciens dans un vecteur
///
QVector<Technicien*> Passerelle::chargerLesTechniciens()
{
qDebug() << "ChargerLesTechniciens";
    QVector <Technicien*> lesTechniciens;

    QString requeteSQl = "select techNum,techNom,techPrenom from technicien;";
    jeuEnregistrement rechTechniciens (requeteSQl);

    while(!rechTechniciens.finReq()){
        int matriculeTech = rechTechniciens.getValeur("techNum").toInt();
        QString nomTech = rechTechniciens.getValeur("techNom").toString();
        QString prenomTech = rechTechniciens.getValeur("techPrenom").toString();
        lesTechniciens.push_back(new Technicien(matriculeTech,nomTech,prenomTech));
        rechTechniciens.suivant();

    }
qDebug() << "nb De techniciens " <<lesTechniciens.size();
    return (lesTechniciens);
}
///
/// \brief Passerelle::chargerLesBornes
/// \return  charges les bornes des stations dans un vecteur
///
QVector<Borne> Passerelle::chargerLesBornes( int unIdStation)
{
qDebug() << "Charger LesBornes";

 QVector <Borne> lesBornes;

 QString reqSQLBornes="select borneNum,borneDerniereRevision,borneIndiceCompteurUnite, typeBorne.typeBorneCode,dureeRevision,nbJoursEntreRevision,nbUnitesEntreRevision";
         reqSQLBornes+=" from borne inner join station on borne.statNum=station.statNum inner join typeBorne on typeBorne.typeBorneCode= borne.typeBorneCode";
         reqSQLBornes+=" where station.statNum="+QString::number(unIdStation)+";";
         qDebug()<<reqSQLBornes;


 jeuEnregistrement rechBorne (reqSQLBornes);

 while(!rechBorne.finReq()){
    int numBorne = rechBorne.getValeur("borneNum").toInt();
    QDate derniereRevision = rechBorne.getValeur("borneIndiceCompteurUnite").toDate();
    Date derniereRevisionDate(derniereRevision.year(), derniereRevision.month(), derniereRevision.day());
    int indiceCompteur =  rechBorne.getValeur("borneIndiceCompteurUnite").toInt();
    QString codeTypeBorne = rechBorne.getValeur("typeBorneCode").toString();
    int dureeRevision = rechBorne.getValeur("dureeRevision").toInt();
    int nbJoursEntreRevision = rechBorne.getValeur("nbJoursEntreRevision").toInt();
    int nbUnitesEntreRevision = rechBorne.getValeur("nbUnitesEntreRevision").toInt();
    TypeBorne leType (codeTypeBorne,dureeRevision,nbJoursEntreRevision,nbUnitesEntreRevision);
    Borne borneInfos (numBorne,derniereRevisionDate,indiceCompteur,leType);
    lesBornes.push_back(borneInfos);

    rechBorne.suivant();

 }
    return(lesBornes);
}

///
/// \brief Passerelle::chargerLesStations
/// \return  charge les sations de la bdd
///
QVector<Station> Passerelle::chargerLesStations()
{
    QVector <Station> lesStations;

    QString requeteSQLStation="select statNum,statRue from station;";
qDebug() << "select statNum,statRue from station;";

    jeuEnregistrement rechStation (requeteSQLStation);

    while(!rechStation.finReq()){
        int numStat = rechStation.getValeur("statNum").toInt();
        QString rueStat = rechStation.getValeur("statRue").toString();
        QVector<Borne> lesBornes = chargerLesBornes(numStat);
        Station stationInfos(numStat,rueStat,lesBornes);
        lesStations.push_back(stationInfos);

        rechStation.suivant();
    }
    qDebug () << "nb De Station" << lesStations.size();
    return(lesStations);
}
///
/// \brief Passerelle::enregistrerVisite
/// \param uneVisite : Vecteur des visites du technicien
/// \param matLeTechnicien : Matricule du technicien
/// \param compteurVisiteId : Id Visite
/// Implémente les visites dans la bdd et créer un ID et les relie a techniciens et Bornes.
///
 void Passerelle::enregistrerVisite(visite uneVisite, int matLeTechnicien, qint64 compteurVisiteId)
{

    QString requeteEnregistrerVisite = " insert into visite values ("uneVisite.";

}
