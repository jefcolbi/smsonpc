#include "emojidialog.h"
#include "ui_emojidialog.h"

EmojiDialog::EmojiDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmojiDialog)
{
    ui->setupUi(this);
}

EmojiDialog::~EmojiDialog()
{
    delete ui;
}
