#include "hoverbutton.h"

HoverButton::HoverButton(QWidget *parent) : QPushButton(parent)
{

}

HoverButton::HoverButton(QString text, QWidget *parent) : QPushButton(text, parent)
{

}

void HoverButton::enterEvent(QEvent *event)
{
    emit signalEntered(mapFromGlobal(QCursor::pos()));
    return QPushButton::enterEvent(event);
}
