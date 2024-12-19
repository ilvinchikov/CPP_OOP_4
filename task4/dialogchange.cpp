#include "dialogchange.h"
#include "ui_dialogchange.h"

#include <QMessageBox>

DialogChange::DialogChange(QWidget *parent, Controller* controller): QDialog(parent), ui(new Ui::DialogChange), m_controller(controller)
{
    ui->setupUi(this);
    this->setFixedSize(400, 444); // установка фиксированного размера (через QT Designer установка Fixed не влияет никак...)
}

DialogChange::~DialogChange()
{
    delete m_controller;
    delete ui;
}

// кнопка "ОК"
void DialogChange::on_buttonBox_accepted()
{
    UsefulFunctions us;
    bool status = false;
    if (ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty() || ui->textEdit_3->toPlainText().isEmpty() || ui->textEdit_4->toPlainText().isEmpty() || ui->textEdit_5->toPlainText().isEmpty() || ui->textEdit_6->toPlainText().isEmpty()) {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: не все поля заполнены!");
        Msgbox.exec();
    }
    else if (us.extractLong(ui->textEdit_5->toPlainText().toStdString()) > 0 && us.extractLong(ui->textEdit_5->toPlainText().toStdString()) <= m_controller->getModel().getTasks().size()) {
        if (ui->comboBox->currentIndex() == 0) status = true;
        m_controller->changeTask(us.toLong(ui->textEdit_5->toPlainText().toStdString())-1,
                                 ui->textEdit->toPlainText().toStdString(),
                                 ui->textEdit_2->toPlainText().toStdString(),
                                 ui->textEdit_3->toPlainText().toStdString(),
                                 us.toInteger(ui->textEdit_4->toPlainText().toStdString()),
                                 status,
                                 ui->textEdit_6->toPlainText().toStdString());
        this->close();
    }
    else if (us.extractLong(ui->textEdit_5->toPlainText().toStdString()) > m_controller->getModel().getTasks().size()) {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: такой порядковый номер не существует.");
        Msgbox.exec();
    }
    else {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: порядковый номер не является целым положительным числом, больше нуля.");
        Msgbox.exec();
    }
}

// кнопка "ОТМЕНА"
void DialogChange::on_buttonBox_rejected()
{
    this->close();
}

