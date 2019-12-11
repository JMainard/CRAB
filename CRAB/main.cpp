#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include "maintenance.h"
#include <QDebug>
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    ///
    /// \brief maBase
    /// Configuration et ouverture à la base SQL  pour pouvoir récuperer les informations
    QSqlDatabase maBase = QSqlDatabase::addDatabase("QMYSQL");
    maBase.setHostName("localhost");
    maBase.setDatabaseName("CRAB");
    maBase.setUserName("jeremy");
    maBase.setPassword("elini01");
    bool bddOk = maBase.open();
    if (bddOk)
    {
        Maintenance laMaintenance;
qDebug() << "On passe a afficher tout()";
        laMaintenance.afficherTout();
        //return a.exec();  On a pas le besoin d'afficher l'interface graphique
        return 0;
    }
    else{
        return 1 ;
    }
}

