#include "typeborne.h"

TypeBorne::TypeBorne()
{

}

TypeBorne::TypeBorne(QString unCodeTypeBorne, int uneDureeRevision, int unNbJoursEntreRevisions, int unNbUniteEntreRevisions)
{
    codeTypeBorne=unCodeTypeBorne;
    dureeRevision=uneDureeRevision;
    nbJoursEntreRevisions=unNbJoursEntreRevisions;
    nbUnitesEntreRevisions=unNbUniteEntreRevisions;
}
///
/// \brief TypeBorne::getDureeRevision
/// \return un int qui correspond à la durée standard de révision d'une borne  de ce type
/// Retourne la durée en minutes requise pour réaliser la révision sur les bornes de ce type
int TypeBorne::getDureeRevision()
{
    return(dureeRevision);
}
///
/// \brief TypeBorne::getNbJoursEntreRevisions
/// \return un int du nb de jour qu'il faut entre 2 révisions
/// retourne le nombre de jours au-delà duquel il faut envisager une révision
/// sur les bornes de ce type
///
int TypeBorne::getNbJoursEntreRevisions()
{
    return(nbJoursEntreRevisions);
}
///
/// \brief TypeBorne::getNbUnitesEntreRevisions
/// \return
/// Retourne le nombre d'unités de recharge au-delà duquel il faut envisager une révision
/// sur les bornes de ce type
///
int TypeBorne::getNbUnitesEntreRevisions()
{
    return(nbUnitesEntreRevisions);
}
