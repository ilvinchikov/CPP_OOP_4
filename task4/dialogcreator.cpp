#include "dialogcreator.h"
#include "ui_dialogcreator.h"

#include <QMessageBox>

DialogCreator::DialogCreator(QWidget *parent, Controller* controller): QDialog(parent), ui(new Ui::DialogCreator), m_controller(controller)
{
    ui->setupUi(this);
    this->setFixedSize(385, 398); // установка фиксированного размера (через QT Designer установка Fixed не влияет никак...)
}

DialogCreator::~DialogCreator()
{
    delete m_controller;
    delete ui;
}

// кнопка "ОК"
void DialogCreator::on_buttonBox_accepted()
{
    UsefulFunctions us;
    bool status = false;
    if (ui->textEdit->toPlainText().isEmpty() || ui->textEdit_2->toPlainText().isEmpty() || ui->textEdit_3->toPlainText().isEmpty() || ui->textEdit_4->toPlainText().isEmpty() || ui->textEdit_6->toPlainText().isEmpty()) {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: не все поля заполнены!");
        Msgbox.exec();
    }
    else {
        if (ui->comboBox->currentIndex() == 0) status = true;
        m_controller->addNewTask(ui->textEdit->toPlainText().toStdString(),
                                 ui->textEdit_2->toPlainText().toStdString(),
                                 ui->textEdit_3->toPlainText().toStdString(),
                                 us.toInteger(ui->textEdit_4->toPlainText().toStdString()), // можно было бы выводить ошибку, но при выводе форма закрывается и теряются данные, поэтому дефолтное значение (0) ставим
                                 status,
                                 ui->textEdit_6->toPlainText().toStdString());
        this->close();
    }
}

// кнопка "ОТМЕНА"
void DialogCreator::on_buttonBox_rejected()
{
    this->close();
}

