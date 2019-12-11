#ifndef JEUENREGISTREMENT_H
#define JEUENREGISTREMENT_H
#include <QSqlQuery>
#include <QDebug>
#include <QVariant>
#include <QString>

class jeuEnregistrement : public QSqlQuery
{
private:
    bool fin;
public:
    jeuEnregistrement(QString laRequete);
    void suivant();
    bool finReq();
    QVariant getValeur(QString nomChamp);
    void fermer();
};

#endif // JEUENREGISTREMENT_H
