#pragma once

#include <QObject>
#include <unordered_map>
#include <utility>
#include <memory>

class QTextDocument;
class QSignalMapper;
using namespace std;
struct Note;

class NotesManager : public QObject
{
    Q_OBJECT
public:
    explicit NotesManager(QObject *parent = nullptr);
    ~NotesManager();

    void createNewNote();
    void removeNote(int id);
    void renameNote(int id, const QString& newTitle);

    const Note& note(int id) const;

    QTextDocument* noteDocument(int id) const;
    vector<reference_wrapper<Note>>noteCollection();
    size_t count() const;


signals:
    void newNoteCreated(int id);
    void noteContentChanged(int id);

private:
    void onNotecontentChanged(int id);

    void readNotes();
    void writeNotes();

    unique_ptr<QTextDocument> createNewTextDocument(const Note& note);


private:
    unordered_map<int,pair<Note,unique_ptr<QTextDocument>>> notes;

    QSignalMapper* mapChangedSignalToNoteId = nullptr;
};


