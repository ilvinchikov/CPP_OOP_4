/********************************************************************************
** Form generated from reading UI file 'dialogcreator.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCREATOR_H
#define UI_DIALOGCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogCreator
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_4;
    QTextEdit *textEdit_6;
    QLabel *label_5;
    QComboBox *comboBox;
    QLabel *label_2;
    QTextEdit *textEdit_4;
    QLabel *label_6;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;

    void setupUi(QDialog *DialogCreator)
    {
        if (DialogCreator->objectName().isEmpty())
            DialogCreator->setObjectName("DialogCreator");
        DialogCreator->resize(385, 398);
        buttonBox = new QDialogButtonBox(DialogCreator);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 350, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_3 = new QLabel(DialogCreator);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 120, 131, 16));
        textEdit = new QTextEdit(DialogCreator);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 40, 351, 21));
        label = new QLabel(DialogCreator);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 131, 16));
        label_4 = new QLabel(DialogCreator);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 170, 151, 16));
        textEdit_6 = new QTextEdit(DialogCreator);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(20, 290, 351, 21));
        label_5 = new QLabel(DialogCreator);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 220, 131, 16));
        comboBox = new QComboBox(DialogCreator);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 240, 351, 24));
        comboBox->setModelColumn(0);
        label_2 = new QLabel(DialogCreator);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 131, 16));
        textEdit_4 = new QTextEdit(DialogCreator);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(20, 190, 351, 21));
        label_6 = new QLabel(DialogCreator);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 270, 131, 16));
        textEdit_2 = new QTextEdit(DialogCreator);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(20, 90, 351, 21));
        textEdit_3 = new QTextEdit(DialogCreator);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(20, 140, 351, 21));

        retranslateUi(DialogCreator);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogCreator, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogCreator, qOverload<>(&QDialog::reject));

        comboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DialogCreator);
    } // setupUi

    void retranslateUi(QDialog *DialogCreator)
    {
        DialogCreator->setWindowTitle(QCoreApplication::translate("DialogCreator", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        label_3->setText(QCoreApplication::translate("DialogCreator", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("DialogCreator", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("DialogCreator", "\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202 (\321\206\320\265\320\273\320\276\320\265 \321\207\320\270\321\201\320\273\320\276)", nullptr));
        label_5->setText(QCoreApplication::translate("DialogCreator", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("DialogCreator", "\320\222\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\276", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("DialogCreator", "\320\235\320\265 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\276", nullptr));

        label_2->setText(QCoreApplication::translate("DialogCreator", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        label_6->setText(QCoreApplication::translate("DialogCreator", "\320\241\321\200\320\276\320\272 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogCreator: public Ui_DialogCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCREATOR_H
