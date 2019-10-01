#include "escapedialog.h"

EscapeDialog::EscapeDialog(QString title, QString msg, QString esc, QString nor, QWidget *parent)
    : QDialog(parent), exchanged(false), escape_count(0)
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
        if (!exchanged)
            this->accept();
        else
            this->reject();
    });
    connect(esc_btn, &HoverButton::clicked, [=]{ // 拒绝（点不到的操作）
        if (!exchanged)
            this->reject();
        else
            this->accept();
    });

    connect(esc_btn, SIGNAL(signalEntered(QPoint)), this, SLOT(slotPosEntered(QPoint))); // 进入按钮（移动按钮或者交换位置）

    connect(esc_btn, &HoverButton::signalLeaved, [=](QPoint p){ // 离开按钮（如果两个按钮互换了，换回来）
        if (exchanged)
            slotExchangeButton();
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

/**
 * 按钮触发鼠标进入事件
 * 移动该按钮，或者和另一个按钮进行交换文字
 */
void EscapeDialog::slotPosEntered(QPoint point)
{
    // 判断移动按钮还是交换按钮
    bool is_exchanged = false;


    // 移动按钮
    if (!is_exchanged)
    {
        slotEscapeButton(point);
    }
    // 交换按钮
    else
    {
        slotExchangeButton();
    }

    escape_count++;
}

/**
 * 移动某个按钮的位置
 */
void EscapeDialog::slotEscapeButton(QPoint p)
{

}

void EscapeDialog::slotExchangeButton()
{
    QString text1 = esc_btn->text();
    QString text2 = nor_btn->text();
    esc_btn->setText(text2);
    nor_btn->setText(text1);
    exchanged = !exchanged;
}
