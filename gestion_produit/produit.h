#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <QSqlQueryModel>
class Produit
{
public:
    Produit();
    Produit(int,QString,float,int);
    int getnumero();
    QString gettitre();
     float getprix();
     int getquantite();

     void setnumero(int);
      void settitre(QString);
       void setprix(float);
        void setquantite(int);
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
private:
 int Numero,Quantite;
 QString Titre;
 float Prix;
};

#endif // PRODUIT_H
