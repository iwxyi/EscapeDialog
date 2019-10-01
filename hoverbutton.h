#ifndef HOVERBUTTON_H
#define HOVERBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class HoverButton : public QPushButton
{
    Q_OBJECT
public:
    HoverButton(QWidget* parent = nullptr);
    HoverButton(QString text, QWidget* parent = nullptr);

protected:
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);

signals:
    void signalEntered(QPoint point);
    void signalLeaved(QPoint point);
};

#endif // HOVERBUTTON_H
