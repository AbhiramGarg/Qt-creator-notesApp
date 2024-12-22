/********************************************************************************
** Form generated from reading UI file 'noteslist_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTESLIST_WIDGET_H
#define UI_NOTESLIST_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Noteslist_widget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *noteList;

    void setupUi(QWidget *Noteslist_widget)
    {
        if (Noteslist_widget->objectName().isEmpty())
            Noteslist_widget->setObjectName("Noteslist_widget");
        Noteslist_widget->resize(205, 466);
        verticalLayout = new QVBoxLayout(Noteslist_widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        noteList = new QListWidget(Noteslist_widget);
        noteList->setObjectName("noteList");
        noteList->setFrameShape(QFrame::Shape::StyledPanel);

        verticalLayout->addWidget(noteList);


        retranslateUi(Noteslist_widget);

        QMetaObject::connectSlotsByName(Noteslist_widget);
    } // setupUi

    void retranslateUi(QWidget *Noteslist_widget)
    {
        Noteslist_widget->setWindowTitle(QCoreApplication::translate("Noteslist_widget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Noteslist_widget: public Ui_Noteslist_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTESLIST_WIDGET_H
