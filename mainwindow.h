#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPrinter>
#include <QUrl>
#include <QSystemTrayIcon>
#include<QNetworkReply>
#include<QPropertyAnimation>
#include<QMediaPlayer>
#include<QSound>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>
#include"login.h"
#include "connection.h"
#include "employes.h"
#include "demande_congee.h"
#include "congee.h"
#include<login.h>
#include<QDate>
#include <QSoundEffect>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QSqlTableModel>
#include <qsystemtrayicon.h>
#include "paiement.h"
#include <QMainWindow>
#include "fournisseur.h"
#include "facture.h"
#include "excelexporthelper.h"
#include "arduino.h"


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
    void on_login_button_clicked();
    void on_pushButton_return_connecx_clicked();
    void on_commandLinkButton_theme_2_clicked();
    //chaima
    void on_pushButton_valider_clicked();
    void on_pushButton_supp_emp_clicked();
   void on_pushButton_2_emp_clicked();
   void on_pushButton_quitter_clicked();
   void on_pushButton_recherche_emp_clicked();
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



   void on_pushButton_7_clicked();


   void on_pushButton_15_clicked();


  // void on_traduction_push_clicked();

  // void on_pushButton_16_clicked();





   void on_lab_anim_emp_linkActivated(int choice);

   void on_pushButton_reset_bouton_clicked();

   void on_chaima_8_clicked();

   void on_pushButton_menu_emp_clicked();

   void on_pushButton_2_clicked();
   //Achref
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


void on_pushButton_save_clicked();



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

void Parduino();

void on_Calculator_PA_clicked();

void on_Set_clicked();

void on_Arduinoo_2_linkActivated(int choice);

void on_toolButton_plus_clicked();

void on_toolButton_Moins_clicked();

void on_Moteur_clicked();

void on_Exit_clicked();


void on_Info_F_clicked(int i);

void on_Theme_A_clicked();

void on_Piano_clicked();



private:
    Ui::MainWindow *ui;

    QSound *son;
    QMediaPlayer musicAdd;
    QSystemTrayIcon *mSystemTrayIcon;

    QPropertyAnimation* animation;
    QMediaPlayer *mMediaPlayer;
    QMediaPlayer *med;
    QRegExp cin_regex,chaine_regex,tel_regex,mail_regex,salaire_regex,horaire_regex ;
    login *log;
    QTranslator *translator=new QTranslator;
    QString current_user;
    QString myid="";

    QPixmap *pix;


    QSound *son0;
    QSound *son1;
    QSound *son2;
    QSound *son3;
    QSound *son4;
    QSound *son5;
    QTimer *timerr;


        int counter=0;
        bool test=false;

        int initial_width;
        int initial_height;

        int login_width;
        int login_height;

        int center_main_x=0;
        int center_main_y=0;
        int center_login_x=0;
        int center_login_y=0;
       //chaima
        employes Etmp,aux;
        demande_congee tamp;
        congee tinmp;
       int aux_emp;
       login l;
       //Ashref
       QTimer *timer;
       QString currentFile = "";

           Fournisseur fo;
           Paiement Pa ;
           FACTURE Fa;
           Arduino A ;
           QByteArray data ;
           QByteArray datar ;


       int At,Dot;
       QString T;


};
#endif // MAINWINDOW_H
