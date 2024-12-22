#pragma once

#include <QWidget>

namespace Ui {
class Noteslist_widget;
}
struct Note;
class QListWidgetItem;
class Noteslist_widget : public QWidget
{
    Q_OBJECT

public:
    explicit Noteslist_widget(QWidget *parent = nullptr);
    ~Noteslist_widget();

    void addNote(const Note& note);
    void removeCurrentNote();
    void updateCurrentNote(const Note& note);

    int currentNoteId();

signals:
    void selectNotechanged(int id);
    void removeNote(int id);
    void renameNote(int id,const QString &newTitle);
private:
    void onItemSelectionChanged();

    void moveCurrentItemToTop(const Note& note);
    void setupNoteItem(const Note& note,QListWidgetItem* item);

private:
    Ui::Noteslist_widget *ui;
};


