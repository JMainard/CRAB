#include "technicien.h"

Technicien::Technicien()
{

}
///
/// \brief Technicien::Technicien
/// \param unNom le nom du technicien
/// \param unPrenom le prenom du technicien
/// Constructeur permettant affecter des vistes au technicien pour le vecteur lesVisites
Technicien::Technicien(int unMatricule,QString unNom, QString unPrenom)
{
    matricule=unMatricule;
    nom=unNom;
    prenom=unPrenom;
}

///
/// \brief Technicien::getTempsOccupe
/// \return Retourne la durée totale en minutes des visites affectées au technicien
///
int Technicien::getTempsOccupe()
{

    int temps=0;
    //On recupère le vector visite pour ensuite additionner le temp total
    for (int noVisite=0; noVisite<lesVisites.size(); noVisite++)
    {
        //On doit recupérer les temps de chaque intervention
        temps+= lesVisites[noVisite]->getDureeTotale();
    }
    return(temps);
}
///
/// \brief Technicien::affecterVisite
/// \param uneVisite pointeur de visite afin de determiner de quelle visite on parle
/// ajoute la visite uneVisite dans les visites affectées au technicien
void Technicien::affecterVisite(visite *uneVisite)
{
    lesVisites.push_back(uneVisite);
}
///
/// \brief Technicien::getLesVisites
/// \return retourne l'ensemble des visites affectées au technicien
/// Permet de savoir quel technicien a quel visites de programmé
QVector<visite*> Technicien::getLesVisites()
{
    return(lesVisites);
}

QString Technicien::getInfo()
{
    QString info = "Matricule : "+QString::number(matricule)+" \n"
            +"Nom : "+nom+"\n"
            +"Prenom : "+prenom+"\n"
            +"Temps occupé : "+QString::number(getTempsOccupe())
            +"PROCHAINE VISITES : ";

    for(int i = 0 ; i<lesVisites.size() ; i++)
    {
        info+= lesVisites[i]->getInfoVisite()+"\n";
    }
    return info;
}

int Technicien::getMatricule()
{
    return(matricule);
}
