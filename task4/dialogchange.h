#ifndef DIALOGCHANGE_H
#define DIALOGCHANGE_H

#include "MVC.h"

#include <QDialog>

namespace Ui {
class DialogChange;
}

class DialogChange : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChange(QWidget *parent = nullptr, Controller* controller = nullptr);
    ~DialogChange();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogChange *ui;
    Controller* m_controller;
};

#endif // DIALOGCHANGE_H
