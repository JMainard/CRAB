#include "jeuenregistrement.h"

jeuEnregistrement::jeuEnregistrement(QString laRequete)
    :QSqlQuery(laRequete)
{
    fin =!first(); //Retourne false ou true
}
/**
 * @brief jeuEnregistrement::suivant
 * Avance le curseur sur l'enregistrement suivant
 */
void jeuEnregistrement::suivant()
{
 fin =! next(); //Vas savoir si il y a d'autre donnée après en  retourant false ou true
}
/**
 * @brief jeuEnregistrement::finReq
 * @return Un bool false or true si la requête est finie ou non
 */
bool jeuEnregistrement::finReq()
{
 return(fin);
}
/**
 * @brief jeuEnregistrement::getValeur
 * @param nomChamp variable de SQL
 * @return la valeur correspondant a nomChamp
 */
QVariant jeuEnregistrement::getValeur(QString nomChamp)
{
 return (value(nomChamp));
}
/**
 * @brief jeuEnregistrement::fermer
 * Ferme le curseur et libère les ressources.
 */
void jeuEnregistrement::fermer()
{
    finish();
}
