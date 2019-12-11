#include "borne.h"

Borne::Borne()
{

}

Borne::Borne(int unIdBorne, Date uneDateDerniereRevision, int unIndiceCompteurUnites, TypeBorne unType)
{
 idBorne=unIdBorne;
 dateDerniereRevision=uneDateDerniereRevision;
 indiceCompteurUnites=unIndiceCompteurUnites;
 leType=unType;
}

///
/// \brief Borne::getDureeRevision
/// \return retourne un int indiquant la durée de revision
/// Procédure retournant la durée en minutes requise pour réaliser la révision sur la borne,
/// cette durée étant fonction du type de la borne
///
int Borne::getDureeRevision()
{
  return(leType.getDureeRevision());
}

///
/// \brief Borne::estAReviser
/// \return retourne si oui ou non la borne est à réviser
/// Procédure permettant de savoir par un bool si la borne doit etre réviser en fonction du nombre de jour ou de ce qu'il y a eu de consommée en WATTS.
///
bool Borne::estAReviser()
{
    // retourne vrai lorsque la borne doit être révisée, soit parce que le temps qui sépare
    // deux révisions pour ce type de borne s'est écoulé depuis la date de la dernière révision,
    // soit parce que le nombre d'unités de recharge délivrées par la borne
    // depuis la dernière révision a atteint le seuil établi pour ce type de borne ;
    // retourne faux sinon
    //On fait Date::puis le nom de la fonction car aujourdhui() est static
    if (Date::aujourdhui().difference(dateDerniereRevision)>leType.getNbJoursEntreRevisions()|| indiceCompteurUnites-leType.getNbUnitesEntreRevisions()<0)
    {
        //Alors il faut effectuer une revision
        return(true);
    }
    else{
        return(false);
    }
}
