#include "escapedialog.h"

EscapeDialog::EscapeDialog(QString title, QString msg, QString esc, QString nor, QWidget *parent)
    : QDialog(parent), exchanged(false)
{
    setWindowTitle(title);

    QVBoxLayout* main_vlayout = new QVBoxLayout;
    msg_lab = new QLabel(msg, this);
    esc_btn = new HoverButton(esc, this);
    nor_btn = new HoverButton(nor, this);
    main_vlayout->addWidget(msg_lab);
    main_vlayout->addSpacing(esc_btn->height() + MARGIN*2);
    main_vlayout->setMargin(MARGIN);
    setLayout(main_vlayout);

    setMinimumSize(qMax(msg_lab->width()+MARGIN*2, esc_btn->width()+nor_btn->width()+MARGIN*4), msg_lab->height()+esc_btn->height()+MARGIN*3);

    resetBtnPos();
    nor_btn->setFocus();

    connect(nor_btn, &HoverButton::clicked, [=]{ // 接受（不进行任何操作）
        this->accept();
    });
    connect(esc_btn, &HoverButton::clicked, [=]{ // 拒绝（点不到的操作）
        this->reject();
    });
    connect(esc_btn, &HoverButton::signalsBlocked, [=](QPoint p){ // 进入按钮（移动动画，或者变换位置）

    });
}

void EscapeDialog::resizeEvent(QResizeEvent *event)
{
    resetBtnPos();
    return QDialog::resizeEvent(event);
}

void EscapeDialog::resetBtnPos()
{
    int w = width(), h = height();
    nor_btn->move(w-MARGIN-nor_btn->width(), h-MARGIN-nor_btn->height());
    esc_btn->move(nor_btn->geometry().left()-MARGIN-esc_btn->width(), nor_btn->geometry().top());
}

void EscapeDialog::slotPosEntered(QPoint point)
{

}
