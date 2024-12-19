#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "MVC.h"
#include "dialogcreator.h"
#include "dialogdelete.h"
#include "dialogchange.h"

#include <QStandardItemModel>




// запуск формы
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    sizeTasks = 0;
    this->setFixedSize(800, 400); // установка фиксированного размера (через QT Designer установка Fixed не влияет никак...)
    // MVC Старт 2
    m_controller = new Controller(m_model, m_view);
}

MainWindow::~MainWindow()
{
    delete m_controller;
    delete ui; 
}

// кнопка "Добавить"
void MainWindow::on_pushButton_clicked()
{
    // создание диалога и передача в него данных
    DialogCreator* dialog = new DialogCreator(this, m_controller);
    // отображение
    dialog->exec();
    updateTableModel(false);
}

// кнопка "Удалить"
void MainWindow::on_pushButton_2_clicked()
{
    if (m_model.getTasks().size() > 0) {
        // проверка на != nullptr (чтоб не вылетало)
        if (ui->tableView->selectionModel()) {
            // проверка на != nullptr   (чтоб не вылетало)
            if (!ui->tableView->selectionModel()->selectedRows().isEmpty()) {
                for (auto i=0; i<ui->tableView->selectionModel()->selectedRows().size(); i++) {
                    qDebug() << "Цикл: " << i << "; Выделенная строка: " << ui->tableView->selectionModel()->selectedRows().at(i).row();
                    m_controller->deleteTask(ui->tableView->selectionModel()->selectedRows().at(i).row());
                }
                updateTableModel(true);
                return;
            }
        }
        // создание диалога и передача в него данных (если в итоге нет выделенных элементов)
        DialogDelete* dialog = new DialogDelete(this, m_controller);
        // отображение
        dialog->exec();
        updateTableModel(false);
    }
}

// кнопка "Изменить"
void MainWindow::on_pushButton_3_clicked()
{
    // создание диалога и передача в него данных
    DialogChange* dialog = new DialogChange(this, m_controller);
    // отображение
    dialog->exec();
    updateTableModel(true);
}

// обновление таблицы
void MainWindow::updateTableModel(bool ForceUpdate) {
    // установка модели в QTableView
    if (sizeTasks != m_model.getTasks().size() || ForceUpdate) {
        // это чтобы если второстепенные диалоговые формы (создание,удаление,изменение) закрывались и данные бы не менялись,
        // то она не меняла бы таблицу | или силовое обновление, если меняем только статус
        ui->tableView->setModel(m_view.getQItemModel(m_model));
    }
    sizeTasks = m_model.getTasks().size();
    // автоматически выровнять размер колонок
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

// кнопка "выполнил"
void MainWindow::on_pushButton_4_clicked()
{
    if (m_model.getTasks().size() > 0) {
        // проверка на != nullptr (чтоб не вылетало)
        if (ui->tableView->selectionModel()) {
            // проверка на != nullptr   (чтоб не вылетало)
            if (!ui->tableView->selectionModel()->selectedRows().isEmpty()) {
                for (auto i=0; i<ui->tableView->selectionModel()->selectedRows().size(); i++) {
                    qDebug() << "Цикл: " << i << "; Выделенная строка: " << ui->tableView->selectionModel()->selectedRows().at(i).row();
                    m_model.setStatus(ui->tableView->selectionModel()->selectedRows().at(i).row(), true);
                }
                updateTableModel(true);
            }
        }
    }
}

// кнопка "не выполнил"
void MainWindow::on_pushButton_5_clicked()
{
    if (m_model.getTasks().size() > 0) {
        // проверка на != nullptr (чтоб не вылетало)
        if (ui->tableView->selectionModel()) {
            // проверка на != nullptr   (чтоб не вылетало)
            if (!ui->tableView->selectionModel()->selectedRows().isEmpty()) {
                for (auto i=0; i<ui->tableView->selectionModel()->selectedRows().size(); i++) {
                    qDebug() << "Цикл: " << i << "; Выделенная строка: " << ui->tableView->selectionModel()->selectedRows().at(i).row();
                    m_model.setStatus(ui->tableView->selectionModel()->selectedRows().at(i).row(), false);
                }
                updateTableModel(true);
            }
        }
    }

}

// изменение текста в фильтре
void MainWindow::on_plainTextEdit_textChanged()
{
    UsefulFunctions us;
    if (ui->plainTextEdit->toPlainText().isEmpty() || us.trim(ui->plainTextEdit->toPlainText().toStdString()) == "") {
        // отключение фильтра
        ui->tableView->setModel(m_view.getQItemModel(m_model));
    }
    else {
        // работа фильтра
        ui->tableView->setModel(m_view.getQItemModelFiltered(m_model, ui->comboBox->currentIndex(), ui->plainTextEdit->toPlainText().toStdString()));
    }
}

