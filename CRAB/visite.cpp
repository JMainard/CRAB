#include "visite.h"

visite::visite()
{

}
///
/// \brief visite::visite
/// \param lesBornesAVisiter vecteur recensant les bornes à visiter
/// \param uneStation station sur lesquelle le vetuer ce base pour savoir quelle borne est à visiter
/// ce constructeur valorise tous les attributs privés de la classe Visite, y compris l'état et la
/// durée totale de la visite
///
visite::visite(QVector<Borne> lesBornesAVisiter, Station *uneStation)
{
    // ce constructeur valorise tous les attributs privés de la classe Visite, y compris l'état et la
    // durée totale de la visite
    lesBornes=lesBornesAVisiter;
    laStation=uneStation;
    dureeTotale=0;
    for (int i=0;i<lesBornesAVisiter.size();i++){
        dureeTotale+=lesBornesAVisiter[i].getDureeRevision();
    }

}
///
/// \brief visite::getDureeTotale
/// \return
///  Fonction retournant la durée totale en minutes requise pour réaliser l'ensemble
/// des révisions prévues sur les bornes de la station
int visite::getDureeTotale()
{
    return(dureeTotale);
}
///
/// \brief visite::getEtat
/// \return retourne l'état de la visite
///  Soit il retourne si oui ou non la visite à était fait
char visite::getEtat()
{
    return(etat);
}
///
/// \brief visite::changerEtat
/// Procédure modifiant l'état de la visite, de 'p' programmée à 'a' affectée, ou de 'a' affectée à 'r' réalisé
void visite::changerEtat()
{
    // modifie l'état de la visite, de 'p' programmée à 'a' affectée, ou de 'a' affectée à 'r' réalisée

    if (etat=='a')
    {
        etat='r';
    }

    if(etat=='p')
    {
        etat='a';
    }
}

/**
 * @brief Visite::getInfo Fonction qui renvoie les informations d'une visite
 * @return Chaine(QString) : information au format texte de la visite (Etat,Durée,Station)
 */
QString visite::getInfoVisite()
{
    QString info = "Etat : \n Durée : "+QString::number(dureeTotale)+"\n Station : " +laStation->getLibelleEmplacement();

    return info;
}
