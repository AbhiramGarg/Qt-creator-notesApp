#include "noteslist_widget.h"
#include "ui_noteslist_widget.h"

#include "note.h"
#include "noteswidget.h"

Noteslist_widget::Noteslist_widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Noteslist_widget)
{
    ui->setupUi(this);

    connect(ui -> noteList,&QListWidget::itemSelectionChanged,this,&Noteslist_widget::onItemSelectionChanged);
}

Noteslist_widget::~Noteslist_widget()
{
    delete ui;
}

void Noteslist_widget::addNote(const Note &note){
    auto* item = new QListWidgetItem();
    ui -> noteList -> insertItem(0,item);

    setupNoteItem(note,item);
}

void Noteslist_widget::removeCurrentNote()
{
    auto currentItem = ui->noteList->currentItem();
    if(currentItem!= nullptr)
    {
        delete currentItem;
    }
}

void Noteslist_widget::updateCurrentNote(const Note &note)
{
    if(ui->noteList->currentRow() != 0)
    {
        moveCurrentItemToTop(note);
    }
    else
    {
        auto widget = static_cast<Noteswidget*>(ui->noteList->itemWidget(ui->noteList->currentItem()));
        widget->updateContent(note);
    }

}

int Noteslist_widget::currentNoteId()
{
    auto* currentItem = ui->noteList->currentItem();
    int noteId = static_cast<Noteswidget*>(ui->noteList->itemWidget(currentItem))->noteId();

    return noteId;
}


void Noteslist_widget::onItemSelectionChanged()
{
    auto* currentItem = ui->noteList->currentItem();
    if(currentItem){
        int id = currentNoteId();

        emit selectNotechanged(id);
    }
}

void Noteslist_widget::moveCurrentItemToTop(const Note &note)
{
    blockSignals(true);

    auto* item = ui->noteList->takeItem(ui->noteList->currentRow());
    ui->noteList->insertItem(0,item);
    setupNoteItem(note,item);
    blockSignals(false);
}

void Noteslist_widget::setupNoteItem(const Note &note,QListWidgetItem* item)
{
    Noteswidget* widget = new Noteswidget(note);
    connect(widget, &Noteswidget::removeNote,this,&Noteslist_widget::removeNote);
    connect(widget, &Noteswidget::renameNote,this,&Noteslist_widget::renameNote);
    item->setSizeHint(widget->sizeHint());
    ui->noteList->setItemWidget(item,widget);
    ui->noteList->setCurrentItem(item);

}
