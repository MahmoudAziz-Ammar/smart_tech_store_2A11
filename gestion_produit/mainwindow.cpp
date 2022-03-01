#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->le_Numero->setValidator(new QIntValidator(0, 9999999, this));
ui->la_Quantite->setValidator(new QIntValidator(0, 9999999, this));
ui->tab_produit->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()

{
int Numero=ui->le_Numero->text().toInt();
QString Titre=ui->le_Titre->text();
float Prix=ui->le_Prix->text().toFloat();
int Quantite=ui->la_Quantite->text().toInt();

 Produit P1(Numero,Titre,Prix,Quantite);
 bool test=P1.ajouter();
 QMessageBox msgBox;
 if(test)
    { msgBox.setText("ajout avec success !");
     ui->tab_produit->setModel(P1.afficher());
 }
 else
 msgBox.setText("ajout echoué !");
 msgBox.exec();
 }



void MainWindow::on_pb_supprimer_clicked()
{
    Produit P1;
    P1.setnumero(ui->le_num_supp->text().toInt());
    bool test=P1.supprimer(P1.getnumero());
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("suppression avec success !");
    ui->tab_produit->setModel(P.afficher());

    }
    else
    msgBox.setText("suppression echouée !");
    msgBox.exec();
    }

