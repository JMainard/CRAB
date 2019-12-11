#ifndef BORNE_H
#define BORNE_H
#include "typeborne.h"
#include "date.h"

///
/// \brief The Borne class
/// Permet de connaitre les bornes à réviser et leur durée
class Borne
{
private:
    ///
    /// \brief idBorne
    /// identifiant de la borne
    ///
    int idBorne;

    ///
    /// \brief dateDerniereRevision
    /// date de la dernière révision effectuée sur la borne
    Date dateDerniereRevision;
    ///
    /// \brief indiceCompteurUnites
    /// nombre d'unités de recharge délivrées depuis la dernière révision,
    /// ce compteur étant remis à zéro suite à chaque révision
    int indiceCompteurUnites;
    ///
    /// \brief leType
    /// type de la borne
    TypeBorne leType;

public:
    Borne();
    Borne(int unIdBorne, Date uneDateDerniereRevision, int unIndiceCompteurUnites, TypeBorne unType);
    int getDureeRevision();
    // retourne la durée en minutes requise pour réaliser la révision sur la borne,
    // cette durée étant fonction du type de la borne
    bool estAReviser();

};

#endif // BORNE_H
