#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "connection.h"
#include "employes.h"
#include "conges.h"
#include<QDate>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_valider_clicked();

    void on_pushButton_supp_emp_clicked();

   void on_pushButton_2_clicked();
   void on_pushButton_quitter_clicked();



   void on_creer_accepted();

   //void on_tableView_Affichage_Emp_activated(const QModelIndex &index);
   
   void on_pushButton_clicked();

   void on_pushButton_sort_clicked();

private:
    Ui::MainWindow *ui;
    employes Etmp,aux;
   int aux_emp;
   QString T;
   conges temp;
};
#endif // MAINWINDOW_H
