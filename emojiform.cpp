#include "emojiform.h"
#include "ui_emojiform.h"

EmojiForm::EmojiForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmojiForm)
{
    ui->setupUi(this);
}

EmojiForm::~EmojiForm()
{
    delete ui;
}
