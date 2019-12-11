#ifndef DATE_H
#define DATE_H
#include <QDate>
///
/// \brief The Date class
/// Permet de savoir la date afin de vérifier si il y aura besoin de maintenance ou non
class Date : public QDate
{
private:

    int annee;
    int mois;
    int jour;

public:
    Date();
    Date(int uneAnne, int unMois, int unJour);
    static Date aujourdhui();

    int getAnnee();
    int getMois();
    int getJour();
    int difference(Date uneDate);

};

#endif // DATE_H
