#include "date.h"

Date::Date()
{

}
///
/// \brief Date::Date
/// \param uneAnne
/// \param unMois
/// \param unJour
/// Constructeur permettant de récuperer la Date du jour
///
Date::Date(int uneAnne, int unMois, int unJour)
    : QDate(uneAnne,unMois,unJour)
{
    annee=uneAnne;
    mois=unMois;
    jour=unJour;

}
///
/// \brief Date::aujourdhui
/// \return Retourne la date du jour
/// Retourne la date du jour grace à la fonction QDate sous forme YY-MM-DDDD
Date Date::aujourdhui()
{

    return(Date(QDate::currentDate().year(),QDate::currentDate().month(),QDate::currentDate().day()));
}

///
/// \brief Date::getAnnee
/// \return Retourne une variable int qui représente une année
///
int Date::getAnnee()
{
    return(annee);
}

///
/// \brief Date::getMois
/// \return Retourne une variable int qui représente un Mois
///
int Date::getMois()
{
    return(mois);
}

///
/// \brief Date::getJour
/// \return Retourne une variable int qui représente un Jour
///
int Date::getJour()
{
    return(jour);
}
///
/// \brief Date::difference
/// \param uneDate représente la date de la dernière revision de la borne
/// \return  retourne  un int pour avoir une différence entre 2 jour
/// Fonction permettant de savoir combien de jour /mois /année il y a de différence entre 2 date date à rentrer et  uneDate (Date de révision ici)
///
int Date::difference(Date uneDate)
{
    return(-daysTo(uneDate));
}
