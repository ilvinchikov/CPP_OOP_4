#ifndef DIALOGDELETE_H
#define DIALOGDELETE_H

#include "MVC.h"

#include <QDialog>

namespace Ui {
class DialogDelete;
}

class DialogDelete : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDelete(QWidget *parent = nullptr, Controller* controller = nullptr);
    ~DialogDelete();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogDelete *ui;
    Controller* m_controller;
};

#endif // DIALOGDELETE_H
