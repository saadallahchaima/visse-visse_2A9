#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "paiement.h"
#include <QMainWindow>
#include "fournisseur.h"
#include "facture.h"
#include "excelexporthelper.h"

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
    void on_pushButton_ajF_clicked();

    void on_pushButton_numF_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_mdF_clicked();

    void on_pushButton_ajF_2_clicked();

    void on_comboBoxP_3_currentIndexChanged(int index);

    void on_pushButton_numF_2_clicked();

 void on_comboBox_2_currentIndexChanged(int index);
 void on_pushButton_ajFA_clicked();




 void on_pushButton_mdFA_clicked();


 void on_pushButton_recherche_clicked();



 void on_comboBoxPrecherche_currentIndexChanged(int index);

 void on_pushButton_recherche_ID_clicked();










 void on_commandLinkButton_TRI_F_clicked();

 void on_commandLinkButton_TRI_Pa_clicked();

 void on_commandLinkButton_TRI_FA_clicked();


 void on_pushButton_Supp_clicked();

 void on_pushButton_rech_FA_clicked();

 void on_commandLinkButton_PDF_clicked();



 void on_commandLinkButton_Statt_clicked();

 void on_pushButton_Verif_clicked();


 void on_label_pic_linkActivated(int  choice);


 void on_commandLinkButton_Clear_clicked();

 void on_commandLinkButtonClear_Fa_clicked();

 void on_commandLinkButtonClear_Pa_clicked();


 void on_label_pic_PA_linkActivated(int choice);

 void on_Traduction_Pa_clicked();

 void on_Traduction_Fo_clicked();

 void on_label_pic_FA_linkActivated(int choice);
void on_label_pic_File_linkActivated(int choice);
void  on_label_Animation(int choice) ;
void  Shattered_Time(int choice) ;
 void on_Traduction_FA_clicked();


void on_pushButton_clicked();



void on_pushButton_New_clicked();


void on_pushButton_Exit_clicked();

void on_pushButton_Copy_clicked();

void on_pushButton_Coupper_clicked();

void on_pushButton_Cut_clicked();


void on_pushButton_Open_clicked();

void on_pushButton_Imprimer_clicked();

void on_pushButton_Exit_2_clicked();

void on_pushButton_Exit_3_clicked();

void on_pushButton_Exit_4_clicked();

void on_Traduction_File_clicked();

void on_tabWidget_currentChanged(int index);

int Blockage(int NUMFA);

void on_commandLinkButton_Ge_clicked();


void on_Historique_Pa__clicked(QString His , int  ID);

void on_Historique_clicked();


void on_Return_clicked();

void on_Excel_clicked();
int  Remise_PA(int a);
void myfunction();
void Click();

void on_Stat_FA_clicked();


void on_tableView_fournis_clicked(const QModelIndex &index);


void on_tableView_facture_clicked(const QModelIndex &index);

void on_commandLinkButton_T1_clicked();


void on_Calculator_PA_clicked();

private:
QTimer *timer;
QString currentFile = "";
    Ui::MainWindow *ui;
    Fournisseur fo;
    Paiement Pa ;
    FACTURE Fa;

};
#endif // MAINWINDOW_H
