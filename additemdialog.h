#ifndef ADDITEMDIALOG_H
#define ADDITEMDIALOG_H

#include <QDialog>
#include "item.h"

namespace Ui
{
class AddItemDialog;
}

class AddItemDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddItemDialog(QWidget *parent = nullptr);
    ~AddItemDialog();
    Item item() const { return mItem; }
private slots:
    void on_toolButton_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::AddItemDialog *ui;
    Item mItem;
};

#endif // ADDITEMDIALOG_H
