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

void HoverButton::leaveEvent(QEvent *event)
{
    emit signalLeaved(mapFromGlobal(QCursor::pos()));
    return QPushButton::leaveEvent(event);
}

void HoverButton::mousePressEvent(QMouseEvent *event)
{
    emit signalMousePressed(mapFromGlobal(QCursor::pos()));
    return QPushButton::mousePressEvent(event);
}

void HoverButton::mouseReleaseEvent(QMouseEvent *event)
{
    emit signalMouseReleased(mapFromGlobal(QCursor::pos()));
    return QPushButton::mouseReleaseEvent(event);
}

void HoverButton::keyPressEvent(QKeyEvent *event)
{
    emit signalKeyPressed(event);
    return QPushButton::keyPressEvent(event);
}

void HoverButton::keyReleaseEvent(QKeyEvent *event)
{
    emit signalKeyReleased(event);
    return QPushButton::keyPressEvent(event);
}
