#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class dataBase;
class QSqlTableModel;


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    // this lines are added because we are clicking the opening existing database/project
    enum Opening {
        OPENING,
        SAVING,
    };
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_actionClose_triggered();
    void on_actionNew_New_Database_triggered();
    void on_actionOpen_Database_triggered();

    // The following command are added to open an existing Database
    void on_actionAdd_Item_triggered();

    void on_actionRemove_Item_triggered();

    void on_tableView_clicked(const QModelIndex &index);

private:
    void openDataBase(Opening opening);

private:
    Ui::MainWindow *ui;
    dataBase *mDataBase;
    QSqlTableModel *mModel;
};

#endif // MAINWINDOW_H
