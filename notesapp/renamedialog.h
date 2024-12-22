#ifndef RENAMEDIALOG_H
#define RENAMEDIALOG_H

#include <QDialog>

namespace Ui {
class renameDialog;
}

class renameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit renameDialog(const QString& oldName,QWidget *parent = nullptr);
    ~renameDialog();

    QString newName();

private:
    void onNewNameLeEdited(const QString& text);

private:
    Ui::renameDialog *ui;
};

#endif // RENAMEDIALOG_H
