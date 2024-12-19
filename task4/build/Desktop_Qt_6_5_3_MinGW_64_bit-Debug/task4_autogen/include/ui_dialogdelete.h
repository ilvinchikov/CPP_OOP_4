/********************************************************************************
** Form generated from reading UI file 'dialogdelete.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDELETE_H
#define UI_DIALOGDELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogDelete
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit_5;
    QLabel *label_7;

    void setupUi(QDialog *DialogDelete)
    {
        if (DialogDelete->objectName().isEmpty())
            DialogDelete->setObjectName("DialogDelete");
        DialogDelete->resize(400, 138);
        buttonBox = new QDialogButtonBox(DialogDelete);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(40, 90, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit_5 = new QTextEdit(DialogDelete);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(20, 40, 361, 21));
        label_7 = new QLabel(DialogDelete);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 20, 161, 16));

        retranslateUi(DialogDelete);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogDelete, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogDelete, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogDelete);
    } // setupUi

    void retranslateUi(QDialog *DialogDelete)
    {
        DialogDelete->setWindowTitle(QCoreApplication::translate("DialogDelete", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("DialogDelete", "\320\237\320\276\321\200\321\217\320\264\320\272\320\276\320\262\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogDelete: public Ui_DialogDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDELETE_H
