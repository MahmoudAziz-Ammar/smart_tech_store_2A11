#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->id->setValidator( new QIntValidator(0, 9999999, this));
    ui->tab_client->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pb_ajouter_clicked()
{
    int id_client=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int nb_points=ui->nbpts->text().toInt();
    QString cadeau_client=ui->cadeau_client->text();
    QString classe=ui->classe->text();

    client c(id_client,nom,prenom,nb_points,classe,cadeau_client);



bool test=c.ajouter_client();
QMessageBox msgBox;
if(test)
   { msgBox.setText("ajout avec success !");
ui->tab_client->setModel(c.afficher());

}
else
msgBox.setText("ajout échoué !");
msgBox.exec();


}





void MainWindow::on_pb_supprimer_clicked()
{

client c1;
c1.setid(ui->id_supp->text().toInt());

bool test=c1.supprimer(c1.getid());

QMessageBox msgBox;
if(test)
   { msgBox.setText("suppression avec success !");
ui->tab_client->setModel(c1.afficher());

}
else
msgBox.setText("suppression echouée !");
msgBox.exec();
}

