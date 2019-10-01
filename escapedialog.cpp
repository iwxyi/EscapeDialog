#include "escapedialog.h"

EscapeDialog::EscapeDialog(QString title, QString msg, QString esc, QString nor, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(title);
    setMinimumSize(100, 50);

    QVBoxLayout* main_vlayout = new QVBoxLayout;
    msg_lab = new QLabel(msg, this);
    esc_btn = new HoverButton(esc, this);
    nor_btn = new HoverButton(nor, this);
    main_vlayout->addWidget(msg_lab);
    main_vlayout->addSpacing(esc_btn->height());
    setLayout(main_vlayout);

    resetBtnPos();
}

void EscapeDialog::resizeEvent(QResizeEvent *event)
{
    resetBtnPos();
    return QDialog::resizeEvent(event);
}

void EscapeDialog::resetBtnPos()
{
    static int margin = 20;

    int w = width(), h = height();
    nor_btn->move(w-margin-nor_btn->width(), h-margin-nor_btn->height());
    esc_btn->move(nor_btn->geometry().left()-margin-esc_btn->width(), nor_btn->geometry().top());
}

void EscapeDialog::slotPosEntered(QPoint point)
{

}
