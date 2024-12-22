/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "noteslist_widget.h"

QT_BEGIN_NAMESPACE

class Ui_Mainwindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *Newnotes;
    QPushButton *removeNotes;
    QSpacerItem *horizontalSpacer;
    QSplitter *splitter;
    Noteslist_widget *NoteslistWidget;
    QTextEdit *textEdit;

    void setupUi(QWidget *Mainwindow)
    {
        if (Mainwindow->objectName().isEmpty())
            Mainwindow->setObjectName("Mainwindow");
        Mainwindow->resize(800, 600);
        verticalLayout = new QVBoxLayout(Mainwindow);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Newnotes = new QPushButton(Mainwindow);
        Newnotes->setObjectName("Newnotes");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/new.svg.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Newnotes->setIcon(icon);
        Newnotes->setIconSize(QSize(32, 32));
        Newnotes->setFlat(true);

        horizontalLayout->addWidget(Newnotes);

        removeNotes = new QPushButton(Mainwindow);
        removeNotes->setObjectName("removeNotes");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/delete.svg.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        removeNotes->setIcon(icon1);
        removeNotes->setIconSize(QSize(32, 32));
        removeNotes->setFlat(true);

        horizontalLayout->addWidget(removeNotes);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        splitter = new QSplitter(Mainwindow);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        splitter->setChildrenCollapsible(false);
        NoteslistWidget = new Noteslist_widget(splitter);
        NoteslistWidget->setObjectName("NoteslistWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NoteslistWidget->sizePolicy().hasHeightForWidth());
        NoteslistWidget->setSizePolicy(sizePolicy);
        splitter->addWidget(NoteslistWidget);
        textEdit = new QTextEdit(splitter);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMinimumSize(QSize(350, 350));
        textEdit->setFrameShape(QFrame::Shape::StyledPanel);
        splitter->addWidget(textEdit);

        verticalLayout->addWidget(splitter);

        verticalLayout->setStretch(1, 1);

        retranslateUi(Mainwindow);

        QMetaObject::connectSlotsByName(Mainwindow);
    } // setupUi

    void retranslateUi(QWidget *Mainwindow)
    {
        Mainwindow->setWindowTitle(QCoreApplication::translate("Mainwindow", "Notes", nullptr));
        Newnotes->setText(QString());
        removeNotes->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Mainwindow: public Ui_Mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
