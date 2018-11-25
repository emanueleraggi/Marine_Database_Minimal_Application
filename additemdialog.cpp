#include "additemdialog.h"
#include "ui_additemdialog.h"
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QCompleter>
#include <QFileSystemModel>
#include <QDateTime>
#include <QDate>
#include <QTime>

AddItemDialog::AddItemDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddItemDialog)
{
    ui->setupUi(this);
    auto fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setRootPath(QDir::rootPath());
    ui->imageLineEdit->setCompleter(new QCompleter(fileSystemModel,this));
    QDateTime dateTime;
    dateTime.setDate(QDate::currentDate());
}

AddItemDialog::~AddItemDialog()
{
    delete ui;
}

void AddItemDialog::on_toolButton_clicked()
{
    auto nameDataBase = QFileDialog::getOpenFileName(this, "Open Images", QDir::rootPath(),
                      "Images (*.png *.jpg *jpeg *.tif *.tiff);;Any type (*.*)");
    ui->imageLineEdit->setText(nameDataBase);
}

void AddItemDialog::on_buttonBox_accepted()
{
    QFile dataBase(ui->imageLineEdit->text());
    if (!dataBase.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", dataBase.errorString());
        return;
    }
    mItem = Item(ui->nameLineEdit->text(),
                 ui->ImLineEdit->text(),dataBase.readAll());
    dataBase.close();
    accept();
}

void AddItemDialog::on_buttonBox_rejected()
{
    reject();
}
