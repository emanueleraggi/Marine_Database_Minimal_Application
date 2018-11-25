#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "additemdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mDataBase = new dataBase(this);
    mModel = nullptr;
    mModel = new QSqlTableModel(this);
    ui->tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->tableView->addActions({ ui->actionAdd_Item,
                                ui->actionRemove_Item});
    ui->label->setText("<b>No image uploaded</b>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered() {
    close();
}

void MainWindow::on_actionNew_New_Database_triggered() {
    openDataBase(SAVING);
}

void MainWindow::on_actionOpen_Database_triggered() {
    openDataBase(OPENING);

}
void MainWindow::openDataBase(MainWindow::Opening opening) {
     QString nameDataBase;
    if (opening == OPENING) {
        nameDataBase = QFileDialog::getOpenFileName(this,
                 "Open Database", QDir::rootPath(),
                 "Database (*.db);;Any type (*.*)");
    } else {
        nameDataBase = QFileDialog::getSaveFileName(this,
                 "New Database", QDir::rootPath(),
                 "Database (*.db);;Any type (*.*)");
    }
    if (nameDataBase.isEmpty()) {
        return;
    }
    if (!mDataBase->inizializationDataBase(nameDataBase)) {
        QMessageBox::critical(this, "Error", mDataBase->getError());
        return;
    }
    if (!mDataBase->configureDataBase()) {
        QMessageBox::critical(this, "Error", mDataBase->getError());
        return;
    }
    delete mModel;
    mModel = new QSqlTableModel(this);
    mModel->setTable("Fish_Table");
    mModel->select();
    ui->tableView->setModel(mModel);
}


void MainWindow::on_actionAdd_Item_triggered()
{
    AddItemDialog d(this);
    if (d.exec() == QDialog::Rejected) {
        return;
    }
    if (!mDataBase->addItem(d.item())) {
        QMessageBox::critical(this, "Error", mDataBase->getError());
        return;
    }
    if (mModel) {
        mModel->select();
    }
}

void MainWindow::on_actionRemove_Item_triggered()
{
    if (!mModel) {
        return;
    }
    mModel->removeRow(ui->tableView->currentIndex().row());
    mModel->select();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if (!index.isValid()) {
        return;
    }
    const int id = mModel->index(index.row(), 0).data().toInt();
    QSqlQuery q;
    q.exec(QString("SELECT dataDatabase FROM Fish_Table WHERE id = %1").arg(id));
    q.next();
    QPixmap pixmap;
    if (!pixmap.loadFromData(q.value(0).toByteArray())) {
        ui->label->setText("<b>Error: no image uploaded</b>");
        return;
    }
    pixmap = pixmap.scaled(400, 400);
    ui->label->setPixmap(pixmap);
}










