/********************************************************************************
** Form generated from reading UI file 'renamedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMEDIALOG_H
#define UI_RENAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_renameDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *newNameLe;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *renameDialog)
    {
        if (renameDialog->objectName().isEmpty())
            renameDialog->setObjectName("renameDialog");
        renameDialog->resize(320, 90);
        verticalLayout = new QVBoxLayout(renameDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(renameDialog);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        newNameLe = new QLineEdit(renameDialog);
        newNameLe->setObjectName("newNameLe");

        horizontalLayout->addWidget(newNameLe);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(renameDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(renameDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, renameDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, renameDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(renameDialog);
    } // setupUi

    void retranslateUi(QDialog *renameDialog)
    {
        renameDialog->setWindowTitle(QCoreApplication::translate("renameDialog", "Rename", nullptr));
        label->setText(QCoreApplication::translate("renameDialog", "New Name", nullptr));
        newNameLe->setPlaceholderText(QCoreApplication::translate("renameDialog", "Please enter a new name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class renameDialog: public Ui_renameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMEDIALOG_H
