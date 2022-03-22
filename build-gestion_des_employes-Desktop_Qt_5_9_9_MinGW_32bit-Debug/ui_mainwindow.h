/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionnew;
    QAction *actionedit;
    QAction *actionimprimer;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *compte;
    QFrame *frame_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_email_login;
    QLineEdit *lineEdit_mdp_login;
    QDialogButtonBox *buttonBox_login;
    QComboBox *comboBox_login;
    QFrame *frame_7;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_17;
    QLineEdit *lineEdit_email_inscri;
    QLineEdit *lineEdit_mdp_inscri;
    QComboBox *comboBox_inscri;
    QDialogButtonBox *buttonBox_inscri;
    QWidget *ajouter;
    QLabel *cin;
    QLabel *nomprenom;
    QLabel *Nationnalite;
    QLabel *adresse;
    QLabel *profession;
    QLabel *Naissance;
    QLabel *cnss;
    QLabel *assurance;
    QLabel *date_entree;
    QLabel *nombre_enfants;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QLabel *salaire;
    QLabel *label_15;
    QComboBox *comboBox_salaire;
    QFrame *frame;
    QLabel *label_8;
    QLineEdit *lineEdit_num_tele;
    QDateEdit *dateEdit_naissance;
    QLineEdit *lineEdit_cin;
    QLineEdit *lineEdit_2_nom_et_prenom;
    QLineEdit *lineEdit_3_adresse;
    QLineEdit *lineEdit_profession;
    QLineEdit *lineEdit_cnss;
    QLineEdit *lineEdit_assurance;
    QSpinBox *spinBox_enfants;
    QComboBox *comboBox_2_nationnalite;
    QFrame *line;
    QLabel *label_img_image;
    QLabel *label;
    QPushButton *pushButton_quitter;
    QPushButton *pushButton_valider;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QFrame *frame_4;
    QDateEdit *dateEdit_entree;
    QPushButton *pushButton_2;
    QPushButton *pushButton_print_2;
    QWidget *affichage_emp;
    QTableView *tableView_Affichage_Emp;
    QLabel *label_5;
    QPushButton *pushButton_supp_emp;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QFrame *frame_5;
    QLineEdit *lineEdit_recherche;
    QPushButton *pushButton_sort;
    QLabel *label_sort;
    QLineEdit *lineEdit_supp;
    QLabel *label_4;
    QTableView *tableView;
    QPushButton *pushButton;
    QWidget *demande;
    QLabel *label_2;
    QLabel *label_nom_emp;
    QLabel *label_debut;
    QLabel *label_fin;
    QLabel *label_fonctio;
    QComboBox *comboBox_type_c;
    QLineEdit *Le_nom_emp;
    QDateTimeEdit *dateTimeEdit_C;
    QDateTimeEdit *dateTimeEdit_D_C;
    QLabel *label_tele_2;
    QLineEdit *Le_tele;
    QPushButton *pushButton_print;
    QFrame *frame_6;
    QLabel *label_liste_demande;
    QLabel *label_cin_emp;
    QLineEdit *le_cin_emp;
    QLineEdit *le_fonction;
    QLabel *label_natureC;
    QPushButton *pushButton_update_demande;
    QPushButton *pushButton_valider_Demande;
    QPushButton *pushButton_supp_emp_supp_demande;
    QLabel *label_supp_demande;
    QLineEdit *lineEdit_supp_demande;
    QTableView *tableView_2_C;
    QLabel *label_date_demande;
    QDateTimeEdit *dateTimeEdit_date_demande;
    QLabel *label_6;
    QLineEdit *le_reponse;
    QLabel *label_8_cause;
    QLineEdit *lineEdit_cause;
    QPushButton *pushButton_sort_2_D;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *affichage_demande;
    QLabel *label_3;
    QFrame *frame_8;
    QTableView *tableView_2_C_2;
    QTableView *tableView_2_C_3;
    QTableView *tableView_2_C_4;
    QLabel *label_12;
    QLabel *label_16;
    QLabel *label_autoriser;
    QLineEdit *lineEdit_autoriser;
    QLabel *label_7;
    QComboBox *comboBox_D;
    QPushButton *pushButton_valider_demande;
    QPushButton *pushButton_sort_C;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_sort_C_en_attente;
    QPushButton *pushButton_Stat_conge;
    QWidget *tab;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QWidget *widget;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QMenuBar *menubar;
    QMenu *menufichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(946, 705);
        MainWindow->setStyleSheet(QLatin1String("QToolTip\n"
"{\n"
"     border: 1px solid black;\n"
"	background-color: rgb(255, 255, 255);\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #ca0619);\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:item:selected\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    background: transparent;\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"    background: #444;\n"
"    border: 1px solid #000;\n"
"    background-color: QLinearGradient(\n"
"        x1:0, y1:0,\n"
"        x2:0, y2:1,\n"
"        stop:1 #212121,\n"
"        stop:0.4 #343434/*,\n"
"        stop"
                        ":0.2 #343434,\n"
"        stop:0.1 #ffaa00*/\n"
"    );\n"
"    margin-bottom:-1px;\n"
"    padding-bottom:1px;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"    border: 1px solid #000;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"    padding: 2px 20px 2px 20px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:disabled\n"
"{\n"
"    color: #404040;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QAbstractItemView\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d);\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"    /*border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0 #646464, stop: 1 #5d5d5d);\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    color:"
                        " #b1b1b1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-width: 1px;\n"
"    border-color: #1e1e1e;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"    selection-background-color: #ffaa00;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0,"
                        " y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"    selection-background-color: #ffaa00;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    border: 2px solid darkgray;\n"
"    selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     border-left-width: 0px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"     image: url(:/down_ar"
                        "row.png);\n"
"}\n"
"\n"
"QGroupBox:focus\n"
"{\n"
"border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"     border: 1px solid #222222;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"     height: 7px;\n"
"     margin: 0px 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"     "
                        " subcontrol-position: right;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"      width: 7px;\n"
"      margin: 16px 0 16px 0;\n"
"      border: 1px solid #222222;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"      background: QLine"
                        "arGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      height: 14px;\n"
"      subcontrol-position: bottom;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #d7801a, stop: 1 #ffa02f);\n"
"      height: 14px;\n"
"      subcontrol-position: top;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:ve"
                        "rtical, QScrollBar::sub-page:vertical\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"}\n"
"\n"
"QCheckBox:disabled\n"
"{\n"
"color: #414141;\n"
"}\n"
"\n"
"QDockWidget::title\n"
"{\n"
"    text-align: center;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button, QDockWidget::float-button\n"
"{\n"
"    text-align: center;\n"
"    spacing: 1px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 "
                        "#323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover\n"
"{\n"
"    background: #242424;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed\n"
"{\n"
"    padding: 1px -1px -1px 1px;\n"
"}\n"
"\n"
"QMainWindow::separator\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #4c4c4c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QMainWindow::separator:hover\n"
"{\n"
"\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d7801a, stop:0.5 #b56c17 stop:1 #ffa02f);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"     spacing: 3px; /* spacing between items i"
                        "n the tool bar */\n"
"     background: url(:/images/handle.png);\n"
"}\n"
"\n"
"QMenu::separator\n"
"{\n"
"    height: 2px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"    background-color: #d7801a;\n"
"    width: 2.15px;\n"
"    margin: 0.5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: #b1b1b1;\n"
"    border: 1px solid #444;\n"
"    border-bottom-style: none;\n"
"    background-color: #323232;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px;\n"
"    padding-bottom: 2px;\n"
"    margin-right: -1px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #444;\n"
"    top: 1px;\n"
"	background-color: rgb(255, 255, "
                        "255);\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
"{\n"
" margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"\n"
"    border-top-left-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"    color: #b1b1b1;\n"
"    border-bottom-style: solid;\n"
"    margin-top: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:.4 #343434);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    margin-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2px solid #ffaa00;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:"
                        "0.4 #343434, stop:0.2 #343434, stop:0.1 #ffaa00);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"    background-color: qradialgradient(\n"
"        cx: 0.5, cy: 0.5,\n"
"        fx: 0.5, fy: 0.5,\n"
"        radius: 1.0,\n"
"        stop: 0.25 #ffaa00,\n"
"        stop: 0.3 #323232\n"
"    );\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    width: 9px;\n"
"    height: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::indicator:hover\n"
"{\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/images/checkbox.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indic"
                        "ator:disabled\n"
"{\n"
"    border: 1px solid #444;\n"
"}"));
        actionnew = new QAction(MainWindow);
        actionnew->setObjectName(QStringLiteral("actionnew"));
        QIcon icon;
        icon.addFile(QStringLiteral("img/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionnew->setIcon(icon);
        actionedit = new QAction(MainWindow);
        actionedit->setObjectName(QStringLiteral("actionedit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("img/modifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionedit->setIcon(icon1);
        actionimprimer = new QAction(MainWindow);
        actionimprimer->setObjectName(QStringLiteral("actionimprimer"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 931, 641));
        tabWidget->setMouseTracking(false);
        tabWidget->setTabletTracking(false);
        tabWidget->setAcceptDrops(false);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 12pt \"MS Shell Dlg 2\";"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);
        compte = new QWidget();
        compte->setObjectName(QStringLiteral("compte"));
        frame_3 = new QFrame(compte);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(40, 30, 411, 521));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(100, 20, 181, 41));
        label_9->setStyleSheet(QLatin1String("color: rgb(170, 170, 255);\n"
"color: rgb(255, 170, 0);"));
        label_9->setMargin(50);
        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 140, 121, 20));
        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 280, 151, 20));
        lineEdit_email_login = new QLineEdit(frame_3);
        lineEdit_email_login->setObjectName(QStringLiteral("lineEdit_email_login"));
        lineEdit_email_login->setGeometry(QRect(190, 140, 211, 25));
        lineEdit_mdp_login = new QLineEdit(frame_3);
        lineEdit_mdp_login->setObjectName(QStringLiteral("lineEdit_mdp_login"));
        lineEdit_mdp_login->setGeometry(QRect(190, 280, 211, 25));
        buttonBox_login = new QDialogButtonBox(frame_3);
        buttonBox_login->setObjectName(QStringLiteral("buttonBox_login"));
        buttonBox_login->setGeometry(QRect(170, 480, 230, 34));
        buttonBox_login->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox_login = new QComboBox(frame_3);
        comboBox_login->setObjectName(QStringLiteral("comboBox_login"));
        comboBox_login->setGeometry(QRect(11, 420, 171, 31));
        frame_7 = new QFrame(compte);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setGeometry(QRect(540, 30, 341, 521));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(frame_7);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(80, 20, 191, 31));
        label_13->setStyleSheet(QLatin1String("color: rgb(255, 170, 127);\n"
"color: rgb(255, 170, 0);"));
        label_14 = new QLabel(frame_7);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 130, 69, 20));
        label_17 = new QLabel(frame_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(0, 290, 151, 21));
        lineEdit_email_inscri = new QLineEdit(frame_7);
        lineEdit_email_inscri->setObjectName(QStringLiteral("lineEdit_email_inscri"));
        lineEdit_email_inscri->setGeometry(QRect(130, 130, 211, 25));
        lineEdit_mdp_inscri = new QLineEdit(frame_7);
        lineEdit_mdp_inscri->setObjectName(QStringLiteral("lineEdit_mdp_inscri"));
        lineEdit_mdp_inscri->setGeometry(QRect(160, 290, 181, 25));
        comboBox_inscri = new QComboBox(frame_7);
        comboBox_inscri->setObjectName(QStringLiteral("comboBox_inscri"));
        comboBox_inscri->setGeometry(QRect(20, 420, 141, 26));
        buttonBox_inscri = new QDialogButtonBox(frame_7);
        buttonBox_inscri->setObjectName(QStringLiteral("buttonBox_inscri"));
        buttonBox_inscri->setGeometry(QRect(110, 480, 230, 34));
        buttonBox_inscri->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget->addTab(compte, QString());
        ajouter = new QWidget();
        ajouter->setObjectName(QStringLiteral("ajouter"));
        cin = new QLabel(ajouter);
        cin->setObjectName(QStringLiteral("cin"));
        cin->setGeometry(QRect(0, 30, 69, 20));
        cin->setStyleSheet(QStringLiteral("font: 75 10pt \"MS Shell Dlg 2\";"));
        nomprenom = new QLabel(ajouter);
        nomprenom->setObjectName(QStringLiteral("nomprenom"));
        nomprenom->setGeometry(QRect(0, 70, 151, 20));
        nomprenom->setStyleSheet(QLatin1String("\n"
"font: 75 10pt \"MS Shell Dlg 2\";"));
        Nationnalite = new QLabel(ajouter);
        Nationnalite->setObjectName(QStringLiteral("Nationnalite"));
        Nationnalite->setGeometry(QRect(0, 110, 121, 20));
        Nationnalite->setStyleSheet(QStringLiteral("font: 75 10pt \"MS Shell Dlg 2\";"));
        adresse = new QLabel(ajouter);
        adresse->setObjectName(QStringLiteral("adresse"));
        adresse->setGeometry(QRect(0, 160, 191, 20));
        adresse->setStyleSheet(QStringLiteral("font: 75 10pt \"MS Shell Dlg 2\";"));
        profession = new QLabel(ajouter);
        profession->setObjectName(QStringLiteral("profession"));
        profession->setGeometry(QRect(0, 200, 101, 20));
        profession->setStyleSheet(QStringLiteral("font: 75 10pt \"MS Shell Dlg 2\";"));
        Naissance = new QLabel(ajouter);
        Naissance->setObjectName(QStringLiteral("Naissance"));
        Naissance->setGeometry(QRect(0, 240, 81, 20));
        Naissance->setStyleSheet(QLatin1String("\n"
"font: 75 10pt \"MS Shell Dlg 2\";"));
        cnss = new QLabel(ajouter);
        cnss->setObjectName(QStringLiteral("cnss"));
        cnss->setGeometry(QRect(0, 290, 361, 20));
        cnss->setStyleSheet(QStringLiteral("font: 75 9pt \"MS Shell Dlg 2\";"));
        assurance = new QLabel(ajouter);
        assurance->setObjectName(QStringLiteral("assurance"));
        assurance->setGeometry(QRect(0, 370, 291, 20));
        assurance->setStyleSheet(QStringLiteral("font: 75 9pt \"MS Shell Dlg 2\";"));
        date_entree = new QLabel(ajouter);
        date_entree->setObjectName(QStringLiteral("date_entree"));
        date_entree->setGeometry(QRect(0, 420, 69, 20));
        date_entree->setStyleSheet(QStringLiteral("font: 75 9pt \"MS Shell Dlg 2\";"));
        nombre_enfants = new QLabel(ajouter);
        nombre_enfants->setObjectName(QStringLiteral("nombre_enfants"));
        nombre_enfants->setGeometry(QRect(0, 470, 231, 20));
        nombre_enfants->setStyleSheet(QStringLiteral("font: 75 9pt \"MS Shell Dlg 2\";"));
        verticalFrame = new QFrame(ajouter);
        verticalFrame->setObjectName(QStringLiteral("verticalFrame"));
        verticalFrame->setGeometry(QRect(430, 200, 351, 151));
        verticalLayout = new QVBoxLayout(verticalFrame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_2 = new QFrame(verticalFrame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        salaire = new QLabel(frame_2);
        salaire->setObjectName(QStringLiteral("salaire"));
        salaire->setGeometry(QRect(10, 0, 333, 51));
        salaire->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 9pt \"MS Shell Dlg 2\";"));
        salaire->setMargin(50);

        verticalLayout->addWidget(frame_2);

        label_15 = new QLabel(verticalFrame);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout->addWidget(label_15);

        comboBox_salaire = new QComboBox(verticalFrame);
        comboBox_salaire->setObjectName(QStringLiteral("comboBox_salaire"));

        verticalLayout->addWidget(comboBox_salaire);

        frame = new QFrame(ajouter);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(440, 350, 349, 149));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setMidLineWidth(0);
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 20, 69, 20));
        label_8->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        lineEdit_num_tele = new QLineEdit(frame);
        lineEdit_num_tele->setObjectName(QStringLiteral("lineEdit_num_tele"));
        lineEdit_num_tele->setGeometry(QRect(110, 20, 191, 25));
        dateEdit_naissance = new QDateEdit(ajouter);
        dateEdit_naissance->setObjectName(QStringLiteral("dateEdit_naissance"));
        dateEdit_naissance->setGeometry(QRect(90, 240, 171, 25));
        lineEdit_cin = new QLineEdit(ajouter);
        lineEdit_cin->setObjectName(QStringLiteral("lineEdit_cin"));
        lineEdit_cin->setGeometry(QRect(60, 30, 211, 25));
        lineEdit_2_nom_et_prenom = new QLineEdit(ajouter);
        lineEdit_2_nom_et_prenom->setObjectName(QStringLiteral("lineEdit_2_nom_et_prenom"));
        lineEdit_2_nom_et_prenom->setGeometry(QRect(160, 70, 251, 25));
        lineEdit_3_adresse = new QLineEdit(ajouter);
        lineEdit_3_adresse->setObjectName(QStringLiteral("lineEdit_3_adresse"));
        lineEdit_3_adresse->setGeometry(QRect(200, 160, 181, 25));
        lineEdit_profession = new QLineEdit(ajouter);
        lineEdit_profession->setObjectName(QStringLiteral("lineEdit_profession"));
        lineEdit_profession->setGeometry(QRect(110, 200, 251, 25));
        lineEdit_cnss = new QLineEdit(ajouter);
        lineEdit_cnss->setObjectName(QStringLiteral("lineEdit_cnss"));
        lineEdit_cnss->setGeometry(QRect(0, 330, 111, 25));
        lineEdit_assurance = new QLineEdit(ajouter);
        lineEdit_assurance->setObjectName(QStringLiteral("lineEdit_assurance"));
        lineEdit_assurance->setGeometry(QRect(252, 370, 161, 25));
        spinBox_enfants = new QSpinBox(ajouter);
        spinBox_enfants->setObjectName(QStringLiteral("spinBox_enfants"));
        spinBox_enfants->setGeometry(QRect(240, 470, 42, 25));
        comboBox_2_nationnalite = new QComboBox(ajouter);
        comboBox_2_nationnalite->setObjectName(QStringLiteral("comboBox_2_nationnalite"));
        comboBox_2_nationnalite->setGeometry(QRect(150, 110, 161, 31));
        line = new QFrame(ajouter);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(420, 50, 20, 411));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_img_image = new QLabel(ajouter);
        label_img_image->setObjectName(QStringLiteral("label_img_image"));
        label_img_image->setGeometry(QRect(740, 60, 151, 131));
        label_img_image->setStyleSheet(QLatin1String("font: 8pt \"MS Shell Dlg 2\";\n"
"image: url(:/img/employe.png);"));
        label_img_image->setFrameShape(QFrame::WinPanel);
        label_img_image->setFrameShadow(QFrame::Sunken);
        label_img_image->setMargin(40);
        label = new QLabel(ajouter);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 10, 391, 31));
        label->setStyleSheet(QLatin1String("font: 75 9pt \"MS Shell Dlg 2\";\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"color: rgb(255, 255, 255);"));
        label->setMargin(50);
        pushButton_quitter = new QPushButton(ajouter);
        pushButton_quitter->setObjectName(QStringLiteral("pushButton_quitter"));
        pushButton_quitter->setGeometry(QRect(780, 530, 112, 34));
        pushButton_quitter->setStyleSheet(QStringLiteral("image: url(:/img/croi.png);"));
        pushButton_valider = new QPushButton(ajouter);
        pushButton_valider->setObjectName(QStringLiteral("pushButton_valider"));
        pushButton_valider->setGeometry(QRect(660, 530, 112, 34));
        pushButton_valider->setStyleSheet(QStringLiteral("image: url(:/img/valider.png);"));
        pushButton_valider->setCheckable(false);
        pushButton_valider->setChecked(false);
        pushButton_valider->setAutoRepeat(false);
        pushButton_valider->setAutoExclusive(false);
        pushButton_valider->setAutoDefault(false);
        pushButton_valider->setFlat(false);
        label_email = new QLabel(ajouter);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setGeometry(QRect(0, 520, 81, 20));
        label_email->setStyleSheet(QLatin1String("font: 9pt \"MS Shell Dlg 2\";\n"
"font: 11pt \"MS Shell Dlg 2\";"));
        lineEdit_email = new QLineEdit(ajouter);
        lineEdit_email->setObjectName(QStringLiteral("lineEdit_email"));
        lineEdit_email->setGeometry(QRect(90, 520, 351, 25));
        frame_4 = new QFrame(ajouter);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(799, 0, 91, 51));
        frame_4->setStyleSheet(QStringLiteral("image: url(:/img/273748291_4587502171372904_7310387823936526442_n.png);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        dateEdit_entree = new QDateEdit(ajouter);
        dateEdit_entree->setObjectName(QStringLiteral("dateEdit_entree"));
        dateEdit_entree->setGeometry(QRect(90, 420, 151, 25));
        pushButton_2 = new QPushButton(ajouter);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(530, 530, 101, 34));
        pushButton_2->setStyleSheet(QStringLiteral("image: url(:/img/modifier.png);"));
        pushButton_print_2 = new QPushButton(ajouter);
        pushButton_print_2->setObjectName(QStringLiteral("pushButton_print_2"));
        pushButton_print_2->setGeometry(QRect(710, 10, 81, 34));
        pushButton_print_2->setStyleSheet(QStringLiteral("image: url(:/img/print.png);"));
        tabWidget->addTab(ajouter, QString());
        affichage_emp = new QWidget();
        affichage_emp->setObjectName(QStringLiteral("affichage_emp"));
        tableView_Affichage_Emp = new QTableView(affichage_emp);
        tableView_Affichage_Emp->setObjectName(QStringLiteral("tableView_Affichage_Emp"));
        tableView_Affichage_Emp->setGeometry(QRect(-20, 90, 481, 511));
        label_5 = new QLabel(affichage_emp);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(280, 10, 381, 41));
        label_5->setStyleSheet(QStringLiteral("font: 75 16pt \"MS Shell Dlg 2\";"));
        label_5->setMargin(50);
        pushButton_supp_emp = new QPushButton(affichage_emp);
        pushButton_supp_emp->setObjectName(QStringLiteral("pushButton_supp_emp"));
        pushButton_supp_emp->setGeometry(QRect(690, 120, 61, 34));
        pushButton_supp_emp->setStyleSheet(QStringLiteral("image: url(:/img/trash.png);"));
        pushButton_4 = new QPushButton(affichage_emp);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(820, 50, 81, 34));
        pushButton_4->setStyleSheet(QStringLiteral("image: url(:/img/fleche.png);"));
        pushButton_5 = new QPushButton(affichage_emp);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(740, 50, 71, 34));
        pushButton_5->setStyleSheet(QStringLiteral("image: url(:/img/precedent.png);"));
        frame_5 = new QFrame(affichage_emp);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(820, -10, 81, 61));
        frame_5->setStyleSheet(QStringLiteral("image: url(:/img/273748291_4587502171372904_7310387823936526442_n.png);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        lineEdit_recherche = new QLineEdit(affichage_emp);
        lineEdit_recherche->setObjectName(QStringLiteral("lineEdit_recherche"));
        lineEdit_recherche->setGeometry(QRect(490, 170, 251, 31));
        lineEdit_recherche->setTabletTracking(false);
        lineEdit_recherche->setToolTipDuration(-1);
        lineEdit_recherche->setAutoFillBackground(false);
        lineEdit_recherche->setStyleSheet(QLatin1String("\n"
"color: rgb(0, 0, 0);\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 255, 255);"));
        lineEdit_recherche->setFrame(true);
        lineEdit_recherche->setDragEnabled(false);
        lineEdit_recherche->setReadOnly(false);
        lineEdit_recherche->setClearButtonEnabled(false);
        pushButton_sort = new QPushButton(affichage_emp);
        pushButton_sort->setObjectName(QStringLiteral("pushButton_sort"));
        pushButton_sort->setGeometry(QRect(170, 40, 51, 34));
        pushButton_sort->setStyleSheet(QStringLiteral("image: url(:/img/sort.png);"));
        label_sort = new QLabel(affichage_emp);
        label_sort->setObjectName(QStringLiteral("label_sort"));
        label_sort->setGeometry(QRect(0, 40, 161, 31));
        label_sort->setMouseTracking(false);
        label_sort->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_sort->setFrameShape(QFrame::NoFrame);
        label_sort->setFrameShadow(QFrame::Raised);
        label_sort->setScaledContents(false);
        label_sort->setWordWrap(false);
        label_sort->setMargin(50);
        lineEdit_supp = new QLineEdit(affichage_emp);
        lineEdit_supp->setObjectName(QStringLiteral("lineEdit_supp"));
        lineEdit_supp->setGeometry(QRect(520, 120, 151, 21));
        label_4 = new QLabel(affichage_emp);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(480, 120, 41, 20));
        label_4->setStyleSheet(QStringLiteral("font: 8pt \"MS Shell Dlg 2\";"));
        tableView = new QTableView(affichage_emp);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(480, 220, 441, 381));
        tableView->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(80, 80, 80);"));
        pushButton = new QPushButton(affichage_emp);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(760, 173, 71, 31));
        pushButton->setStyleSheet(QStringLiteral("image: url(:/img/search.png);"));
        tabWidget->addTab(affichage_emp, QString());
        demande = new QWidget();
        demande->setObjectName(QStringLiteral("demande"));
        label_2 = new QLabel(demande);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 0, 341, 41));
        label_2->setStyleSheet(QStringLiteral("font: 75 16pt \"MS Shell Dlg 2\";"));
        label_2->setMargin(50);
        label_nom_emp = new QLabel(demande);
        label_nom_emp->setObjectName(QStringLiteral("label_nom_emp"));
        label_nom_emp->setGeometry(QRect(0, 100, 111, 20));
        label_nom_emp->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        label_debut = new QLabel(demande);
        label_debut->setObjectName(QStringLiteral("label_debut"));
        label_debut->setGeometry(QRect(10, 190, 69, 20));
        label_debut->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        label_fin = new QLabel(demande);
        label_fin->setObjectName(QStringLiteral("label_fin"));
        label_fin->setGeometry(QRect(10, 240, 69, 20));
        label_fin->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        label_fonctio = new QLabel(demande);
        label_fonctio->setObjectName(QStringLiteral("label_fonctio"));
        label_fonctio->setGeometry(QRect(10, 340, 71, 20));
        label_fonctio->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        comboBox_type_c = new QComboBox(demande);
        comboBox_type_c->setObjectName(QStringLiteral("comboBox_type_c"));
        comboBox_type_c->setGeometry(QRect(110, 390, 201, 31));
        Le_nom_emp = new QLineEdit(demande);
        Le_nom_emp->setObjectName(QStringLiteral("Le_nom_emp"));
        Le_nom_emp->setGeometry(QRect(110, 100, 211, 25));
        dateTimeEdit_C = new QDateTimeEdit(demande);
        dateTimeEdit_C->setObjectName(QStringLiteral("dateTimeEdit_C"));
        dateTimeEdit_C->setGeometry(QRect(100, 190, 221, 25));
        dateTimeEdit_D_C = new QDateTimeEdit(demande);
        dateTimeEdit_D_C->setObjectName(QStringLiteral("dateTimeEdit_D_C"));
        dateTimeEdit_D_C->setGeometry(QRect(100, 240, 221, 25));
        label_tele_2 = new QLabel(demande);
        label_tele_2->setObjectName(QStringLiteral("label_tele_2"));
        label_tele_2->setGeometry(QRect(10, 140, 69, 20));
        label_tele_2->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        Le_tele = new QLineEdit(demande);
        Le_tele->setObjectName(QStringLiteral("Le_tele"));
        Le_tele->setGeometry(QRect(110, 140, 211, 25));
        pushButton_print = new QPushButton(demande);
        pushButton_print->setObjectName(QStringLiteral("pushButton_print"));
        pushButton_print->setGeometry(QRect(840, 150, 81, 34));
        pushButton_print->setStyleSheet(QStringLiteral("image: url(:/img/print.png);"));
        frame_6 = new QFrame(demande);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setGeometry(QRect(839, 0, 81, 51));
        frame_6->setStyleSheet(QStringLiteral("image: url(:/img/273748291_4587502171372904_7310387823936526442_n.png);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_liste_demande = new QLabel(demande);
        label_liste_demande->setObjectName(QStringLiteral("label_liste_demande"));
        label_liste_demande->setGeometry(QRect(510, 160, 251, 31));
        label_cin_emp = new QLabel(demande);
        label_cin_emp->setObjectName(QStringLiteral("label_cin_emp"));
        label_cin_emp->setGeometry(QRect(10, 290, 81, 20));
        label_cin_emp->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        le_cin_emp = new QLineEdit(demande);
        le_cin_emp->setObjectName(QStringLiteral("le_cin_emp"));
        le_cin_emp->setGeometry(QRect(110, 290, 211, 25));
        le_fonction = new QLineEdit(demande);
        le_fonction->setObjectName(QStringLiteral("le_fonction"));
        le_fonction->setGeometry(QRect(110, 340, 211, 25));
        label_natureC = new QLabel(demande);
        label_natureC->setObjectName(QStringLiteral("label_natureC"));
        label_natureC->setGeometry(QRect(10, 400, 91, 20));
        label_natureC->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        pushButton_update_demande = new QPushButton(demande);
        pushButton_update_demande->setObjectName(QStringLiteral("pushButton_update_demande"));
        pushButton_update_demande->setGeometry(QRect(10, 560, 101, 34));
        pushButton_update_demande->setStyleSheet(QStringLiteral("image: url(:/img/modifier.png);"));
        pushButton_valider_Demande = new QPushButton(demande);
        pushButton_valider_Demande->setObjectName(QStringLiteral("pushButton_valider_Demande"));
        pushButton_valider_Demande->setGeometry(QRect(140, 560, 112, 34));
        pushButton_valider_Demande->setStyleSheet(QStringLiteral("image: url(:/img/valider.png);"));
        pushButton_valider_Demande->setCheckable(false);
        pushButton_valider_Demande->setChecked(false);
        pushButton_valider_Demande->setAutoRepeat(false);
        pushButton_valider_Demande->setAutoExclusive(false);
        pushButton_valider_Demande->setAutoDefault(false);
        pushButton_valider_Demande->setFlat(false);
        pushButton_supp_emp_supp_demande = new QPushButton(demande);
        pushButton_supp_emp_supp_demande->setObjectName(QStringLiteral("pushButton_supp_emp_supp_demande"));
        pushButton_supp_emp_supp_demande->setGeometry(QRect(740, 80, 61, 34));
        pushButton_supp_emp_supp_demande->setStyleSheet(QStringLiteral("image: url(:/img/trash.png);"));
        label_supp_demande = new QLabel(demande);
        label_supp_demande->setObjectName(QStringLiteral("label_supp_demande"));
        label_supp_demande->setGeometry(QRect(400, 90, 121, 20));
        label_supp_demande->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        lineEdit_supp_demande = new QLineEdit(demande);
        lineEdit_supp_demande->setObjectName(QStringLiteral("lineEdit_supp_demande"));
        lineEdit_supp_demande->setGeometry(QRect(520, 90, 201, 25));
        tableView_2_C = new QTableView(demande);
        tableView_2_C->setObjectName(QStringLiteral("tableView_2_C"));
        tableView_2_C->setGeometry(QRect(420, 230, 471, 351));
        label_date_demande = new QLabel(demande);
        label_date_demande->setObjectName(QStringLiteral("label_date_demande"));
        label_date_demande->setGeometry(QRect(10, 10, 101, 20));
        label_date_demande->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        dateTimeEdit_date_demande = new QDateTimeEdit(demande);
        dateTimeEdit_date_demande->setObjectName(QStringLiteral("dateTimeEdit_date_demande"));
        dateTimeEdit_date_demande->setGeometry(QRect(110, 10, 211, 25));
        label_6 = new QLabel(demande);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 50, 71, 20));
        label_6->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        le_reponse = new QLineEdit(demande);
        le_reponse->setObjectName(QStringLiteral("le_reponse"));
        le_reponse->setGeometry(QRect(100, 50, 211, 31));
        le_reponse->setReadOnly(true);
        label_8_cause = new QLabel(demande);
        label_8_cause->setObjectName(QStringLiteral("label_8_cause"));
        label_8_cause->setGeometry(QRect(10, 450, 141, 20));
        label_8_cause->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        lineEdit_cause = new QLineEdit(demande);
        lineEdit_cause->setObjectName(QStringLiteral("lineEdit_cause"));
        lineEdit_cause->setGeometry(QRect(150, 440, 251, 101));
        pushButton_sort_2_D = new QPushButton(demande);
        pushButton_sort_2_D->setObjectName(QStringLiteral("pushButton_sort_2_D"));
        pushButton_sort_2_D->setGeometry(QRect(780, 150, 51, 34));
        pushButton_sort_2_D->setStyleSheet(QStringLiteral("image: url(:/img/sort.png);"));
        pushButton_6 = new QPushButton(demande);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(660, 10, 71, 34));
        pushButton_6->setStyleSheet(QStringLiteral("image: url(:/img/precedent.png);"));
        pushButton_7 = new QPushButton(demande);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(740, 10, 81, 34));
        pushButton_7->setStyleSheet(QStringLiteral("image: url(:/img/fleche.png);"));
        tabWidget->addTab(demande, QString());
        affichage_demande = new QWidget();
        affichage_demande->setObjectName(QStringLiteral("affichage_demande"));
        label_3 = new QLabel(affichage_demande);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 20, 191, 31));
        label_3->setStyleSheet(QLatin1String("font: 16pt \"MS Shell Dlg 2\";\n"
"font: 8pt \"MS Shell Dlg 2\";"));
        label_3->setMargin(50);
        frame_8 = new QFrame(affichage_demande);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setGeometry(QRect(789, 10, 101, 61));
        frame_8->setStyleSheet(QStringLiteral("image: url(:/img/273748291_4587502171372904_7310387823936526442_n.png);"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        tableView_2_C_2 = new QTableView(affichage_demande);
        tableView_2_C_2->setObjectName(QStringLiteral("tableView_2_C_2"));
        tableView_2_C_2->setGeometry(QRect(-10, 60, 551, 241));
        tableView_2_C_3 = new QTableView(affichage_demande);
        tableView_2_C_3->setObjectName(QStringLiteral("tableView_2_C_3"));
        tableView_2_C_3->setGeometry(QRect(0, 350, 461, 241));
        tableView_2_C_4 = new QTableView(affichage_demande);
        tableView_2_C_4->setObjectName(QStringLiteral("tableView_2_C_4"));
        tableView_2_C_4->setGeometry(QRect(480, 350, 451, 241));
        label_12 = new QLabel(affichage_demande);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(50, 310, 231, 31));
        label_16 = new QLabel(affichage_demande);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(580, 310, 221, 21));
        label_autoriser = new QLabel(affichage_demande);
        label_autoriser->setObjectName(QStringLiteral("label_autoriser"));
        label_autoriser->setGeometry(QRect(560, 80, 91, 20));
        label_autoriser->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        lineEdit_autoriser = new QLineEdit(affichage_demande);
        lineEdit_autoriser->setObjectName(QStringLiteral("lineEdit_autoriser"));
        lineEdit_autoriser->setGeometry(QRect(650, 80, 201, 25));
        label_7 = new QLabel(affichage_demande);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(560, 140, 71, 21));
        label_7->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        comboBox_D = new QComboBox(affichage_demande);
        comboBox_D->setObjectName(QStringLiteral("comboBox_D"));
        comboBox_D->setGeometry(QRect(660, 140, 171, 31));
        pushButton_valider_demande = new QPushButton(affichage_demande);
        pushButton_valider_demande->setObjectName(QStringLiteral("pushButton_valider_demande"));
        pushButton_valider_demande->setGeometry(QRect(670, 210, 121, 34));
        pushButton_valider_demande->setStyleSheet(QStringLiteral("font: 7pt \"MS Shell Dlg 2\";"));
        pushButton_sort_C = new QPushButton(affichage_demande);
        pushButton_sort_C->setObjectName(QStringLiteral("pushButton_sort_C"));
        pushButton_sort_C->setGeometry(QRect(300, 310, 51, 34));
        pushButton_sort_C->setStyleSheet(QStringLiteral("image: url(:/img/sort.png);"));
        pushButton_8 = new QPushButton(affichage_demande);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(680, 20, 81, 34));
        pushButton_8->setStyleSheet(QStringLiteral("image: url(:/img/fleche.png);"));
        pushButton_9 = new QPushButton(affichage_demande);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(600, 20, 71, 34));
        pushButton_9->setStyleSheet(QStringLiteral("image: url(:/img/precedent.png);"));
        pushButton_sort_C_en_attente = new QPushButton(affichage_demande);
        pushButton_sort_C_en_attente->setObjectName(QStringLiteral("pushButton_sort_C_en_attente"));
        pushButton_sort_C_en_attente->setGeometry(QRect(830, 300, 51, 34));
        pushButton_sort_C_en_attente->setStyleSheet(QStringLiteral("image: url(:/img/sort.png);"));
        pushButton_Stat_conge = new QPushButton(affichage_demande);
        pushButton_Stat_conge->setObjectName(QStringLiteral("pushButton_Stat_conge"));
        pushButton_Stat_conge->setGeometry(QRect(880, 210, 41, 41));
        pushButton_Stat_conge->setStyleSheet(QLatin1String("#pushButton_StatService{\n"
"background-color: transparent;\n"
"border-image: url(:stats.png);\n"
"background: none;\n"
"border: none;\n"
"background-repeat: none;\n"
"}"));
        tabWidget->addTab(affichage_demande, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_18 = new QLabel(tab);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(30, 60, 69, 20));
        label_19 = new QLabel(tab);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(30, 140, 69, 20));
        label_20 = new QLabel(tab);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(30, 220, 69, 20));
        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(180, 60, 321, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(tab);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(180, 140, 331, 22));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(tab);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(190, 220, 321, 22));
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(560, 50, 141, 181));
        spinBox = new QSpinBox(tab);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(510, 50, 42, 25));
        spinBox_2 = new QSpinBox(tab);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(510, 130, 42, 25));
        spinBox_3 = new QSpinBox(tab);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(510, 210, 42, 25));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 946, 30));
        menufichier = new QMenu(menubar);
        menufichier->setObjectName(QStringLiteral("menufichier"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menufichier->menuAction());
        menufichier->addAction(actionimprimer);

        retranslateUi(MainWindow);
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), tabWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), tabWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), horizontalSlider_2, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), horizontalSlider_3, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(spinBox_3, SIGNAL(valueChanged(int)), spinBox_3, SLOT(setValue(int)));

        tabWidget->setCurrentIndex(1);
        pushButton_valider->setDefault(false);
        pushButton_valider_Demande->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionnew->setText(QApplication::translate("MainWindow", "new", Q_NULLPTR));
        actionedit->setText(QApplication::translate("MainWindow", "edit", Q_NULLPTR));
        actionimprimer->setText(QApplication::translate("MainWindow", "imprimer", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Mot de passe", Q_NULLPTR));
        comboBox_login->clear();
        comboBox_login->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Admin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Employe", Q_NULLPTR)
        );
        label_13->setText(QApplication::translate("MainWindow", "Inscription", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Mot de passe", Q_NULLPTR));
        comboBox_inscri->clear();
        comboBox_inscri->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Admin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Employe", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(compte), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        cin->setText(QApplication::translate("MainWindow", "CIN:", Q_NULLPTR));
        nomprenom->setText(QApplication::translate("MainWindow", "Nom et Prenom:", Q_NULLPTR));
        Nationnalite->setText(QApplication::translate("MainWindow", "Nationnalit\303\251:", Q_NULLPTR));
        adresse->setText(QApplication::translate("MainWindow", "Adresse du domicile:", Q_NULLPTR));
        profession->setText(QApplication::translate("MainWindow", "Profession:", Q_NULLPTR));
        Naissance->setText(QApplication::translate("MainWindow", "N\303\251(e)le:", Q_NULLPTR));
        cnss->setText(QApplication::translate("MainWindow", "N\302\260 de la carte d'immatriculation de C.N.S.S:", Q_NULLPTR));
        assurance->setText(QApplication::translate("MainWindow", "Affiliation \303\240 l'assurance groupe(             ):", Q_NULLPTR));
        date_entree->setText(QApplication::translate("MainWindow", "Entr\303\251 le :", Q_NULLPTR));
        nombre_enfants->setText(QApplication::translate("MainWindow", "Nombre d'enfants \303\240 charge:", Q_NULLPTR));
        salaire->setText(QApplication::translate("MainWindow", "Salaire:", Q_NULLPTR));
        label_15->setText(QString());
        comboBox_salaire->clear();
        comboBox_salaire->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "50", Q_NULLPTR)
         << QApplication::translate("MainWindow", "70", Q_NULLPTR)
         << QApplication::translate("MainWindow", "120", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1200", Q_NULLPTR)
         << QApplication::translate("MainWindow", "150", Q_NULLPTR)
         << QApplication::translate("MainWindow", "80", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("MainWindow", "Num_tele", Q_NULLPTR));
        comboBox_2_nationnalite->clear();
        comboBox_2_nationnalite->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Tunisienne", Q_NULLPTR)
         << QApplication::translate("MainWindow", "francaise", Q_NULLPTR)
        );
        label_img_image->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Ajouter un Employ\303\251", Q_NULLPTR));
        pushButton_quitter->setText(QString());
        pushButton_valider->setText(QString());
        label_email->setText(QApplication::translate("MainWindow", "Email:", Q_NULLPTR));
        pushButton_2->setText(QString());
        pushButton_print_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(ajouter), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Liste des employ\303\251s", Q_NULLPTR));
        pushButton_supp_emp->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
#ifndef QT_NO_TOOLTIP
        lineEdit_recherche->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_sort->setText(QString());
        label_sort->setText(QApplication::translate("MainWindow", "Sort", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "cin", Q_NULLPTR));
        pushButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(affichage_emp), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "demande cong\303\251", Q_NULLPTR));
        label_nom_emp->setText(QApplication::translate("MainWindow", "Nom et prenom:", Q_NULLPTR));
        label_debut->setText(QApplication::translate("MainWindow", "d\303\251but:", Q_NULLPTR));
        label_fin->setText(QApplication::translate("MainWindow", "fin:", Q_NULLPTR));
        label_fonctio->setText(QApplication::translate("MainWindow", "fonction", Q_NULLPTR));
        comboBox_type_c->clear();
        comboBox_type_c->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Maternite", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Maladie", Q_NULLPTR)
         << QApplication::translate("MainWindow", "paid leave", Q_NULLPTR)
        );
        label_tele_2->setText(QApplication::translate("MainWindow", "telephone", Q_NULLPTR));
        pushButton_print->setText(QString());
        label_liste_demande->setText(QApplication::translate("MainWindow", "Liste des demandes", Q_NULLPTR));
        label_cin_emp->setText(QApplication::translate("MainWindow", "Cin employe", Q_NULLPTR));
        label_natureC->setText(QApplication::translate("MainWindow", "Nature cong\303\251", Q_NULLPTR));
        pushButton_update_demande->setText(QString());
        pushButton_valider_Demande->setText(QString());
        pushButton_supp_emp_supp_demande->setText(QString());
        label_supp_demande->setText(QApplication::translate("MainWindow", "cin de demendeur:", Q_NULLPTR));
        label_date_demande->setText(QApplication::translate("MainWindow", "date_demande", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "REPONSE", Q_NULLPTR));
        le_reponse->setText(QApplication::translate("MainWindow", "en attente", Q_NULLPTR));
        label_8_cause->setText(QApplication::translate("MainWindow", "justification de cong\303\251", Q_NULLPTR));
        pushButton_sort_2_D->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(demande), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Demandes ", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Demandes acc\303\251pt\303\251es", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Demande refus\303\251s", Q_NULLPTR));
        label_autoriser->setText(QApplication::translate("MainWindow", "cin_employe", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "reponse", Q_NULLPTR));
        comboBox_D->clear();
        comboBox_D->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "accepter", Q_NULLPTR)
         << QApplication::translate("MainWindow", "refuser", Q_NULLPTR)
        );
        pushButton_valider_demande->setText(QApplication::translate("MainWindow", "r\303\251pondre", Q_NULLPTR));
        pushButton_sort_C->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        pushButton_sort_C_en_attente->setText(QString());
        pushButton_Stat_conge->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(affichage_demande), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "R", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "G", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "B", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        menufichier->setTitle(QApplication::translate("MainWindow", "fichier", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
