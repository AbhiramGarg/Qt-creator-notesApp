#include "notesmanager.h"
#include "note.h"

#include <QTextDocument>
#include <QSignalMapper>
#include <xmlstorage.h>
int nextNoteId();

NotesManager::NotesManager(QObject *parent)
    : QObject{parent}
{
    mapChangedSignalToNoteId = new QSignalMapper(this);
    connect(mapChangedSignalToNoteId, &QSignalMapper::mappedInt,this,&NotesManager::onNotecontentChanged);
    
    readNotes();
    
    if(notes.size() == 0)
        createNewNote();    
    
}


NotesManager::~NotesManager(){
    writeNotes();        
}


void NotesManager::createNewNote()
{
    int id = nextNoteId();
    auto& [note,textDocument] = notes[id];
    note.id = id;
    note.title = "New Note";
    note.lastModified = QDateTime::currentDateTime();
    textDocument = createNewTextDocument(note);
    
    emit newNoteCreated(id);
}

void NotesManager::removeNote(int id)
{
    notes.erase(id);
    
    if(notes.empty())
        createNewNote();
}

void NotesManager::renameNote(int id, const QString &newTitle)
{
    auto found = notes.find(id);
    if(found != notes.end())
    {
        auto&[note,textDocument] = found->second;
        note.title = newTitle;
        note.lastModified = QDateTime::currentDateTime();
    }
}

const Note &NotesManager::note(int id) const
{
    return notes.at(id).first;

}

QTextDocument *NotesManager::noteDocument(int id) const
{
    auto found = notes.find(id);
    if(found != notes.end())
    {
        return found->second.second.get();
    }
    return nullptr;
}

vector<reference_wrapper<Note>> NotesManager::noteCollection()
{
    vector<reference_wrapper<Note>> out;
    for(auto& i: notes)
    {
        auto& [note,textDocument] = i.second;
        note.content = textDocument->toPlainText();
        out.push_back(note);
    }
    return out;
}


size_t NotesManager::count() const
{
    return notes.size();

}

void NotesManager::onNotecontentChanged(int id)
{
    notes.at(id).first.lastModified = QDateTime::currentDateTime();

    emit noteContentChanged(id);
}


void NotesManager::readNotes(){
    XmlStorage storage;
    auto savedNotes = storage.read();

    for(auto n: savedNotes)
    {
        n.id = nextNoteId();
        auto&[note,textDocument] = notes[n.id];
        note = n;
        textDocument = createNewTextDocument(note);
    }
}

void NotesManager::writeNotes(){
    XmlStorage storage;
    storage.write(noteCollection());
}

unique_ptr<QTextDocument> NotesManager::createNewTextDocument(const Note &note)
{
    auto textDocument = make_unique<QTextDocument>(note.content);
    connect(textDocument.get(),&QTextDocument::contentsChanged,
            mapChangedSignalToNoteId,qOverload<>(&QSignalMapper::map));
    mapChangedSignalToNoteId->setMapping(textDocument.get(),note.id);
    return textDocument;
}

int nextNoteId(){
    static int id = 0;
    return ++id;
}

