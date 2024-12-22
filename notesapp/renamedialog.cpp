#include "renamedialog.h"
#include "ui_renamedialog.h"
#include <QPushButton>

renameDialog::renameDialog(const QString& oldName,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::renameDialog)
{
    ui->setupUi(this);

    connect(ui->newNameLe,&QLineEdit::textChanged,this,&renameDialog::onNewNameLeEdited);

    ui->newNameLe->setText(oldName);
    ui->newNameLe->setSelection(0,ui->newNameLe->text().size());
}

renameDialog::~renameDialog()
{
    delete ui;
}

QString renameDialog::newName(){
    return ui->newNameLe->text();
}
void renameDialog::onNewNameLeEdited(const QString &text)
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(text.size()!=0);
}
