#include "produit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
Produit::Produit()
{
     Numero=0;Quantite=0;
    Titre="";
    Prix=0;
}

Produit::Produit(int Numero ,QString Titre,float Prix,int Quantite)
{this->Numero=Numero;this->Titre=Titre;this->Prix=Prix;this->Quantite=Quantite;

}
int Produit::getnumero(){return Numero;}
QString Produit::gettitre(){return Titre;}
float Produit::getprix(){return Prix;}
int Produit::getquantite(){return Quantite;}
void Produit::setnumero(int Numero){this->Numero=Numero;}
void Produit::settitre(QString Titre){this->Titre=Titre;}
void Produit::setprix(float Prix){this->Prix=Prix;}
void Produit::setquantite(int Quantite){this->Quantite=Quantite;}

bool Produit::ajouter(){
    QSqlQuery query;
    QString Numero_string= QString::number(Numero);
    QString Prix_string= QString::number(Prix);
    QString Quantite_string= QString::number(Quantite);
          query.prepare("INSERT INTO Produit (Numero,Titre,Prix,Quantite) "
                        "VALUES (:Numero,:Titre,:Prix,:Quantite)");
          query.bindValue(0, Numero_string);
          query.bindValue(1, Titre);
          query.bindValue(2, Prix_string);
          query.bindValue(3, Quantite_string);
    return query.exec();
}

bool Produit::supprimer(int Numero){
    QSqlQuery query;
    QString Numero_string= QString::number(Numero);
    QString Prix_string= QString::number(Prix);
    QString Quantite_string= QString::number(Quantite);
          query.prepare("Delete from Produit where Numero=:Numero");
          query.bindValue(0, Numero);

    return query.exec();


}
QSqlQueryModel* Produit::afficher()
{
   QSqlQueryModel* model=new  QSqlQueryModel();

         model->setQuery("SELECT * FROM Produit");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Titre"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));

   return model;
}
