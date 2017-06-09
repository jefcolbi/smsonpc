#ifndef EMOJIFORM_H
#define EMOJIFORM_H

#include <QWidget>

namespace Ui {
class EmojiForm;
}

class EmojiForm : public QWidget
{
    Q_OBJECT

public:
    explicit EmojiForm(QWidget *parent = 0);
    ~EmojiForm();

private:
    Ui::EmojiForm *ui;
};

#endif // EMOJIFORM_H
