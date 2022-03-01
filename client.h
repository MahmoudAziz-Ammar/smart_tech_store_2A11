#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <qsqlquerymodel.h>
class client
{
public:
    client();
    client(int,QString,QString,int,QString,QString);


    int getid();
    QString getnom();
    QString getprenom();
    int getnb_points();
    QString getclasse();
    QString getcadeau_client();

     void setid(int);
    void setnb_points(int);
    void setnom(QString );
    void setprenom(QString );
    void setclasse(QString );
    void setcadeau_client(QString );
    bool ajouter_client();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool chercher_client(int);

private :
    int id_client;
    QString nom ;
    QString prenom;
    int nb_points;
    QString classe;
    QString cadeau_client;


};

#endif // CLIENT_H
