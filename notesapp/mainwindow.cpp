#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <algorithm>
#include "notesmanager.h"
#include "note.h"
#include "noteslist_widget.h"

#include <QPushButton>
#include <QMessageBox>
Mainwindow::Mainwindow(NotesManager& manager,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mainwindow)
    , notesManager(manager)
{
    ui->setupUi(this);
    makeConnctions();
    init();
}

Mainwindow::~Mainwindow()
{
    delete ui;
}

void Mainwindow::onNewNotesBtnClicked()
{
    notesManager.createNewNote();
}
void Mainwindow::onRemoveNotesBtnClicked(){
    removeNote(ui->NoteslistWidget->currentNoteId());

}

void Mainwindow::onNewNoteCreated(int id)
{
    addNoteToList(notesManager.note(id));
}

void Mainwindow::onNoteContentChanged(int id)
{
    ui->NoteslistWidget->updateCurrentNote(notesManager.note(id));
}

void Mainwindow::onSelectedNoteChanged(int id){
    auto* document = notesManager.noteDocument(id);
    if(document){
        ui->textEdit->setDocument(document);
        auto cursor = ui->textEdit->textCursor();
        cursor.movePosition(QTextCursor::End);
        ui->textEdit->setTextCursor(cursor);
    }
}

void Mainwindow::onRemoveNote(int id){
    removeNote(id);
}
void Mainwindow::onRenameNote(int id,const QString& newTitle){
    notesManager.renameNote(id,newTitle);
    ui->NoteslistWidget->updateCurrentNote(notesManager.note(id));

}

void Mainwindow::addNoteToList(const Note &note)
{
    ui->NoteslistWidget->addNote(note);
}

void Mainwindow::removeNote(int id)
{
    QString noteTitle = notesManager.note(id).title;

    auto pressedBtn = QMessageBox::information(this,"Remove note?",QString("Are you sure you want to remove %0?").arg(noteTitle),QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if(pressedBtn == QMessageBox::Yes)
    {
        if(notesManager.count()==1)
            ui->textEdit->setDocument(nullptr);

        ui->NoteslistWidget->removeCurrentNote();
        notesManager.removeNote(id);
    }
}

void Mainwindow::init()
{
    auto notesList = notesManager.noteCollection();
    sort(notesList.begin(),notesList.end(),[](const Note& left,const Note& right){
        return left.lastModified<right.lastModified;
    });

    for(auto& note: notesList){
        addNoteToList(note);
    }

}
void Mainwindow::makeConnctions()
{
    connect(ui->Newnotes, &QPushButton::clicked,this,&Mainwindow::onNewNotesBtnClicked);
    connect(ui->removeNotes, &QPushButton::clicked,this,&Mainwindow::onRemoveNotesBtnClicked);

    connect(&notesManager,&NotesManager::newNoteCreated,this,&Mainwindow::onNewNoteCreated);
    connect(&notesManager,&NotesManager::noteContentChanged,this,&Mainwindow::onNoteContentChanged);

    connect(ui->NoteslistWidget,&Noteslist_widget::selectNotechanged,this,&Mainwindow::onSelectedNoteChanged);

    connect(ui->NoteslistWidget,&Noteslist_widget::removeNote,this,&Mainwindow::onRemoveNote);
    connect(ui->NoteslistWidget,&Noteslist_widget::renameNote,this,&Mainwindow::onRenameNote);

}

