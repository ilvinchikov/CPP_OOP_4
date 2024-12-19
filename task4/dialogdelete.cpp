#include "dialogdelete.h"
#include "ui_dialogdelete.h"

#include <QMessageBox>
//Controller* m_controller;

DialogDelete::DialogDelete(QWidget *parent, Controller* controller): QDialog(parent), ui(new Ui::DialogDelete), m_controller(controller)
{
    ui->setupUi(this);
    this->setFixedSize(400, 138); // установка фиксированного размера (через QT Designer установка Fixed не влияет никак...)
}

DialogDelete::~DialogDelete()
{
    delete m_controller;
    delete ui;
}

// КНОПКА ОК
void DialogDelete::on_buttonBox_accepted()
{
    UsefulFunctions us;
    if (ui->textEdit_5->toPlainText().isEmpty()) {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: не все поля заполнены!");
        Msgbox.exec();
    }
    else if (us.extractLong(ui->textEdit_5->toPlainText().toStdString()) > 0 && us.extractLong(ui->textEdit_5->toPlainText().toStdString()) <= m_controller->getModel().getTasks().size()) {
        m_controller->deleteTask(us.extractLong(ui->textEdit_5->toPlainText().toStdString())-1);
        this->close();
    }
    else if(us.extractLong(ui->textEdit_5->toPlainText().toStdString()) > m_controller->getModel().getTasks().size()) {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: такой порядковый номер не существует.");
        Msgbox.exec();
    }
    else {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: введите положительное целое число, больше нуля!");
        Msgbox.exec();
    }
}

// КНОПКА ОТМЕНА
void DialogDelete::on_buttonBox_rejected()
{
    this->close();
}

