#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Mainwindow;
}
QT_END_NAMESPACE

class NotesManager;
struct Note;

class Mainwindow : public QWidget
{
    Q_OBJECT

public:
    Mainwindow(NotesManager& manager, QWidget *parent = nullptr);
    ~Mainwindow();

private slots:
    //handle signal from ui
    void onNewNotesBtnClicked();
    void onRemoveNotesBtnClicked();

    //handle NoteManager Signals
    void onNewNoteCreated(int id);
    void onNoteContentChanged(int id);

    //handle NotesListWidget Signals
    void onSelectedNoteChanged(int id);
    void onRemoveNote(int id);
    void onRenameNote(int id, const QString&  newTitle);

private:
    void addNoteToList(const Note& note);
    void removeNote(int id);

    void init();
    void makeConnctions();
    Ui::Mainwindow *ui;
    NotesManager& notesManager;
};
#endif // MAINWINDOW_H
