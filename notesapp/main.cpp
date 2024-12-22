#include "mainwindow.h"

#include <QApplication>
#include "notesmanager.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps,true);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling,true);

    QApplication a(argc, argv);

    NotesManager manager;

    Mainwindow w{manager};
    w.show();
    return a.exec();
}
