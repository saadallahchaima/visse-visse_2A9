#ifndef MAINWINDOW_STAT_H
#define MAINWINDOW_STAT_H


class MainWindow_stat
{
public:
    MainWindow_stat();
};

#endif // MAINWINDOW_STAT_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QAbstractItemView;
class QItemSelectionModel;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void openFile();
    void saveFile();

private:
    void setupModel();
    void setupViews();
    void loadFile(const QString &path);

    QAbstractItemModel *model;
    QAbstractItemView *pieChart;
    QItemSelectionModel *selectionModel;
};
