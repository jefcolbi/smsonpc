#ifndef EMOJIDIALOG_H
#define EMOJIDIALOG_H

#include <QDialog>

namespace Ui {
class EmojiDialog;
}

class EmojiDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmojiDialog(QWidget *parent = 0);
    ~EmojiDialog();

private:
    Ui::EmojiDialog *ui;
};

#endif // EMOJIDIALOG_H
