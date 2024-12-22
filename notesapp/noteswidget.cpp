#include "noteswidget.h"
#include "note.h"
#include <Qlabel>
#include <QVBoxLayout>
#include <QContextMenuEvent>
#include <QMenu>
#include <renamedialog.h>

Noteswidget::Noteswidget(const Note& note,QWidget *parent)
    : QWidget(parent)
{
    setupGui();

    id = note.id;
    title = note.title;
    lastModified = note.lastModified.toString(dateTimeFormat);

    updatelabels();
    setToolTip(QString("%0\n%1").arg(title).arg(lastModified));
}

int Noteswidget::noteId() const{
    return id;
}

void Noteswidget::updateContent(const Note& note)
{
    title = note.title;
    lastModified = note.lastModified.toString(dateTimeFormat);
}

void Noteswidget::resizeEvent(QResizeEvent* event)
{
    updatelabels();
    QWidget::resizeEvent(event);
}

void Noteswidget::contextMenuEvent(QContextMenuEvent* event)
{
    showContextMenu(event->globalPos());
}

void Noteswidget::setupGui()
{
    titleLbl = new QLabel();
    lastModifiedLbl = new QLabel();

    auto layout = new QVBoxLayout(this);
    layout->addWidget(titleLbl);
    layout->addWidget(lastModifiedLbl);
}

void Noteswidget::updatelabels(){
    setElidedText(titleLbl,title);
    setElidedText(lastModifiedLbl,lastModified);
}

void Noteswidget::setElidedText(QLabel* label,const QString& text)
{
    auto parentObj = parent();
    if(parentObj)
    {
        auto parentWidget = qobject_cast<QWidget*>(parentObj);
        if(parentWidget)
        {
            QFontMetrics fm(label->font());
            QString elidedText = fm.elidedText(text,Qt::ElideRight,parentWidget->width() - 20);
            label->setText(elidedText);
        }
    }
}

void Noteswidget::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(this);
    QAction* renameAction = contextMenu.addAction("Rename Note");
    QAction* removeAction = contextMenu.addAction("Remove Note");
    renameAction->setIcon(QIcon(":/icons/rename.svg.svg"));
    removeAction->setIcon(QIcon(":/icons/delete.svg.svg"));
    connect(renameAction, &QAction::triggered,this,&Noteswidget::onRenameActionTriggered);
    connect(removeAction, &QAction::triggered,this,&Noteswidget::onRemoveActionTriggered);

    contextMenu.exec(pos);
}

void Noteswidget::onRemoveActionTriggered(){
    emit removeNote(id);
}
void Noteswidget::onRenameActionTriggered(){
    renameDialog renameDlg(title,this);
    if(renameDlg.exec()== QDialog::Accepted)
    {
        emit renameNote(id,renameDlg.newName());
    }
}
