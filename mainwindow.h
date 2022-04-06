#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "connection.h"
#include "employes.h"
#include "demande_congee.h"
#include "congee.h"
#include<QDate>
#include <QSoundEffect>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QSqlTableModel>
#include <qsystemtrayicon.h>
#include <QSound>
#include <QMediaPlayer>

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
   void on_pushButton_clicked();
   void on_pushButton_sort_clicked();

   void on_pushButton_valider_Demande_clicked();

   void on_pushButton_supp_emp_supp_demande_clicked();

   void on_pushButton_update_demande_clicked();


   void on_pushButton_valider_demande_clicked();

   void on_tableView_Affichage_Emp_activated(const QModelIndex &index);

   void on_tableView_2_C_activated(const QModelIndex &index);

   void on_tableView_2_C_2_activated(const QModelIndex &index);

   void on_pushButton_print_3_clicked();

   void on_pushButton_printPDF_demande_clicked();

   void on_pushButton_sort_demande_acceptes_clicked();

   void on_pushButton_sort_demande_refusees_clicked();
   void statistiques();
   void on_pushButton_stat_clicked();

   void on_pushButton_5_clicked();

   void on_pushButton_4_clicked();

   void on_pushButton_6_clicked();

   void on_pushButton_preced_D_clicked();

   void on_pushButton_apres_D_clicked();

   void on_pushButton_9_clicked();

   void on_pushButton_8_clicked();

   void on_pushButton_10_clicked();

   void on_pushButton_3_clicked();

   void on_pushButton_7_clicked();

   void on_pushButton_11_clicked();

   void on_pushButton_12_clicked();


   void on_pushButton_13_clicked();

   void on_pushButton_14_clicked();

   void on_pushButton_15_clicked();


  // void on_traduction_push_clicked();

  // void on_pushButton_16_clicked();


   void on_commandLinkButton_theme_clicked();

private:
    Ui::MainWindow *ui;
         QSound *son;
    employes Etmp,aux;
    demande_congee tamp;
    congee tinmp;
   int aux_emp;

   int At,Dot;
   QString T;

};
#endif // MAINWINDOW_H
