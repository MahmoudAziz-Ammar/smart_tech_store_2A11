#include "client.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
client::client()
{
id_client =0;
nom="";
prenom="";
classe="C"; //  aana 3 types : ABC par defaut lclient yabda classe c //
nb_points=0;
cadeau_client="rien";

}







//constructor//
client::client(int id_client,QString nom,QString prenom,int nb_points,QString classe,QString cadeau_client)
{

this->id_client=id_client;
this->nom=nom;
this->prenom=prenom;
this->nb_points=nb_points;
this->classe=classe;
this->cadeau_client=cadeau_client;
}


//getter  w setter //
int client::getid() { return id_client ;}
QString client::getnom() {  return nom; }
QString client::getprenom() {return prenom;}
int client::getnb_points() {return nb_points;}
QString client::getclasse(){return (classe);}
QString client::getcadeau_client(){return (cadeau_client);}

void client::setid(int id_client) { this->id_client=id_client;}
void client::setnb_points(int nb_points) { this->nb_points=nb_points;}
void client::setnom(QString nom){ this->nom=nom;}
void client::setprenom(QString prenom){ this->prenom=prenom;}
void client::setclasse(QString classe){ this->classe=classe;}
void client::setcadeau_client(QString cadeau_client){ this->cadeau_client=cadeau_client;}



bool client::ajouter_client()
{



    QSqlQuery query;

    QString id_string=QString::number(id_client);
    QString nb_points_string=QString::number(nb_points);

    query.prepare("INSERT INTO clients (id_client,nom,prenom,nb_points,classe,cadeau_client) "
                  "VALUES (:id_client, :nom, :prenom, :nb_points, :classe, :cadeau_client)");
    query.bindValue(0, id_string);
    query.bindValue(1, nom);
    query.bindValue(2 ,prenom);
    query.bindValue(3, nb_points_string);
    query.bindValue(4 ,classe);
    query.bindValue(5 ,cadeau_client);


    return  query.exec();

}



QSqlQueryModel* client::afficher()
{

QSqlQueryModel* model=new QSqlQueryModel();

  model->setQuery("SELECT* FROM CLIENTS ");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre des points "));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("classe du client "));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("cadeau client"));
  return  model;


}


bool client:: supprimer(int id)
{
QSqlQuery query;

query.prepare("DELETE  FROM clients where id_client=:id ");

query.bindValue(0, id);

return query.exec();


}

bool chercher_client(int id)
{











}







