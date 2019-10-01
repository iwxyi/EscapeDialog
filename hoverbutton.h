#ifndef HOVERBUTTON_H
#define HOVERBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class HoverButton : public QPushButton
{
public:
    HoverButton(QWidget* parent = nullptr);
    HoverButton(QString text, QWidget* parent = nullptr);

protected:
    void enterEvent(QEvent* event);

signals:
    void signalEntered(QPoint point);
};

#endif // HOVERBUTTON_H
