#ifndef TYPEBORNE_H
#define TYPEBORNE_H
#include <QString>
///
/// \brief The TypeBorne class
/// Permet de référence les type de borne stocké dand la bdd
class TypeBorne
{
private:
    QString codeTypeBorne;
    int dureeRevision;
    int nbJoursEntreRevisions;
    int nbUnitesEntreRevisions;
public:
    TypeBorne();
    TypeBorne(QString unCodeTypeBorne, int uneDureeRevision, int unNbJoursEntreRevisions, int unNbUniteEntreRevisions);
    int getDureeRevision();
    int getNbJoursEntreRevisions();
    int getNbUnitesEntreRevisions();
};

#endif // TYPEBORNE_H
