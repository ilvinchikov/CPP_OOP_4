#ifndef MVC_H
#define MVC_H

#include "UsefulFunctions.h"

#include <QStandardItemModel>
#include <string>
#include <vector>
using namespace std;


// МОДЕЛЬ - управление с данными
class Task {
public:
    string m_name;      // название задачи
    string m_desc;      // описание
    string m_category;  // категория
    int m_priority;     // приоритет
    bool m_status;      // статус
    string m_date;       // срок выполнения

    Task (string name, string desc, string category, int priority, bool status, string date): m_name(name), m_desc(desc), m_category(category), m_priority(priority), m_status(status), m_date(date) {}
};

class ToDoModel {
private:
    vector<Task> m_tasks; // список задач
public:
    // возврат имени
    string getName(size_t index) { return m_tasks[index].m_name; }
    // изменить имя
    void setName(size_t index, string name) { m_tasks[index].m_name = name; }
    // возврат описания
    string getDesc(size_t index) { return m_tasks[index].m_desc; }
    // изменить описание
    void setDesc(size_t index, string desc) { m_tasks[index].m_desc = desc; }
    // возврат категории
    string getCategory(size_t index) { return m_tasks[index].m_category; }
    // изменить категорию
    void setCategory(size_t index, string category) { m_tasks[index].m_category = category; }
    // возврат приоритета
    int getPriority(size_t index) { return m_tasks[index].m_priority; }
    // изменить приоритет
    void setPriority(size_t index, int priority) { m_tasks[index].m_priority = priority; }
    // возврат статуса задачи
    bool getStatus(size_t index) { return m_tasks[index].m_status; }
    // изменить статус задачи
    void setStatus(size_t index, bool status) { m_tasks[index].m_status = status; }
    // возврат срока выполнения
    string getDate(size_t index) { return m_tasks[index].m_date; }
    // изменить срок выполнения
    void setDate(size_t index, string date) { m_tasks[index].m_date = date; }

    // добавление задачи (готовой)
    void addTask(const Task& task) {
        m_tasks.emplace_back(task);
    }

    // удаление задачи
    void deleteTask(size_t index) {
        if (index >= 0 && index < m_tasks.size()) {
            m_tasks.erase(m_tasks.begin() + index);
        }
    }

    // возврат списка задач
    vector<Task> getTasks() {
        return m_tasks;
    }

    // возврат значений для таблицы
    string getColumnStringValuesForTable(long row, long column) {
        UsefulFunctions us;
        switch (column) {
        case 0:
            return getName(row);
        case 1:
            return getDesc(row);
        case 2:
            return getCategory(row);
        case 3:
            return us.toString(getPriority(row));
        case 4:
            if (getStatus(row)) return "Выполнено";
            else return "Не выполнено";
        case 5:
            return getDate(row);
            break;
        default:
            return " ";
            break;
        }
    }



};

// ВИД - отображение пользователю (можно было обойтись и без него, но по заданию
class View {
public:
    // возврат строки (с оформленным списком задач), который присваивается строке, отображающаяся пользователю
    string getDisplayTasks(const vector<Task>& tasks) {
        string display = "";
        for (auto i=0; i<tasks.size(); i++) {
            display += ": tasks[i]";
        }
        return display;
    }

    // возврат числа колонок
    int getColumns() {
        return 6;
    }

    // возврат (стандартной) табличной модели данных
    QStandardItemModel* getQItemModel(ToDoModel& model) {
        // cоздание модели
        QStandardItemModel *tableModel = new QStandardItemModel();
        // установка заголовков столбцов
        tableModel->setHorizontalHeaderLabels(QStringList() << "Название" << "Описание" << "Категория" << "Приоритет" << "Статус" << "Срок выполнения");
        // заполнение модели данными
        for (auto row = 0; row < model.getTasks().size(); row++) {
            for (auto column = 0; column < getColumns(); column++) {
                QStandardItem *item = new QStandardItem(QString::fromStdString(model.getColumnStringValuesForTable(row, column))); // model.getColumnStringValuesForTable(row, column)
                tableModel->setItem(row, column, item); // заполняем ячейку
            }
        }
        return tableModel;
    }

    bool containsInFullRow(ToDoModel& model, int& row,  string& filter){
        UsefulFunctions us;
        for (auto i=0; i<getColumns(); i++) {
            if (us.trim(us.toLowerCase(model.getColumnStringValuesForTable(row, i))).find(us.trim(us.toLowerCase(filter))) != string::npos) {
                return true;
            }
        }
        return false;
    }

    // возврат (фильтрованной) табличной модели данных
    QStandardItemModel* getQItemModelFiltered(ToDoModel& model, int typefilter, string filter) {
        UsefulFunctions us;
        // cоздание модели
        QStandardItemModel *tableModel = new QStandardItemModel();
        // установка заголовков столбцов
        tableModel->setHorizontalHeaderLabels(QStringList() << "Название" << "Описание" << "Категория" << "Приоритет" << "Статус" << "Срок выполнения");
        // заполнение модели данными
        for (auto row = 0; row < model.getTasks().size(); row++) {
            switch (typefilter) {
            case 1: // по категориям
                if (us.trim(us.toLowerCase(model.getColumnStringValuesForTable(row, 2))).find(us.trim(us.toLowerCase(filter))) != string::npos) {
                    for (auto column = 0; column < getColumns(); column++) {
                        QStandardItem *item = new QStandardItem(QString::fromStdString(model.getColumnStringValuesForTable(row, column))); // model.getColumnStringValuesForTable(row, column)
                        tableModel->setItem(row, column, item); // заполняем ячейку
                    }
                }
                break;
            case 2: // по приоритету
                if (us.trim(us.toLowerCase(model.getColumnStringValuesForTable(row, 3))).find(us.trim(us.toLowerCase(filter))) != string::npos) {
                    for (auto column = 0; column < getColumns(); column++) {
                        QStandardItem *item = new QStandardItem(QString::fromStdString(model.getColumnStringValuesForTable(row, column))); // model.getColumnStringValuesForTable(row, column)
                        tableModel->setItem(row, column, item); // заполняем ячейку
                    }
                }
                break;
            case 3: // по статусу
                if (us.trim(us.toLowerCase(model.getColumnStringValuesForTable(row, 4))).find(us.trim(us.toLowerCase(filter))) != string::npos) {
                    for (auto column = 0; column < getColumns(); column++) {
                        QStandardItem *item = new QStandardItem(QString::fromStdString(model.getColumnStringValuesForTable(row, column))); // model.getColumnStringValuesForTable(row, column)
                        tableModel->setItem(row, column, item); // заполняем ячейку
                    }
                }
                break;
            default:
                if (containsInFullRow(model, row, filter)) {
                    for (auto column = 0; column < getColumns(); column++) {
                        QStandardItem *item = new QStandardItem(QString::fromStdString(model.getColumnStringValuesForTable(row, column))); // model.getColumnStringValuesForTable(row, column)
                        tableModel->setItem(row, column, item); // заполняем ячейку
                    }
                }
                break;
            }






        }
        return tableModel;
    }
};

// КОНТРОЛЛЕР - обработка пользовательского ввода
class Controller {
private:
    ToDoModel& m_model;     // Модель (адрес)
    View& m_view;           // Вид (адрес)

public:
    // конструктор
    Controller(ToDoModel& model, View& view): m_model(model), m_view(view) {}

    // добавление задачи (новой)
    void addNewTask(string name, string desc, string category, int priority, bool status, string date) {
        m_model.addTask(Task(name, desc, category, priority, status, date));
    }

    // изменение задачи
    void changeTask(long index, string name, string desc, string category, int priority, bool status, string date) {
        m_model.setName(index, name);
        m_model.setDesc(index, desc);
        m_model.setCategory(index, category);
        m_model.setPriority(index, priority);
        m_model.setStatus(index, status);
        m_model.setDate(index, date);
    }

    // удаление задачи
    void deleteTask(size_t index) {
        m_model.deleteTask(index);
    }

    // возврат модели
    ToDoModel& getModel() {
        return m_model;
    }

    // возврат вида
    View& getView() {
        return m_view;
    }

};

#endif // MVC_H
