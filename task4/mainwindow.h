#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MVC.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void updateTableModel(bool ForceUpdate);


    void on_plainTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
    // MVC Старт 1
    ToDoModel m_model;
    View m_view;
    Controller* m_controller;
    size_t sizeTasks;
};
#endif // MAINWINDOW_H
