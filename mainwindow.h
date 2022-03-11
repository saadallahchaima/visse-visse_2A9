#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "paiement.h"
#include <QMainWindow>
#include "fournisseur.h"
#include "facture.h"
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

 void on_comboBox_TVA_activated( QString Tv);


 void on_pushButton_mdF_2_clicked();

 void on_pushButton_mdFA_clicked();

 void on_pushButton_supp_clicked();

 void on_pushButton_recherche_clicked();



 void on_comboBoxPrecherche_currentIndexChanged(int index);

 void on_pushButton_recherche_ID_clicked();

 void on_comboBoxFa_supprimer_currentTextChanged(QString emaill);



 void on_pushButton_Sup_pressed();

 void on_comboBoxFa_supprimer_currentIndexChanged(QString emaill);

 void on_comboBoxFa_supprimer_currentIndexChanged(int index);

 void on_pushButton_Sup_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseur fo;
    Paiement Pa ;
    FACTURE Fa;
};
#endif // MAINWINDOW_H
