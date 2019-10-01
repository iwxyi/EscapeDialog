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
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event)override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent* evnet) override;

signals:
    void signalEntered(QPoint point);
    void signalLeaved(QPoint point);
    void signalMousePressed(QPoint point);
    void signalMouseReleased(QPoint point);
    void signalKeyPressed(QKeyEvent* event);
    void signalKeyReleased(QKeyEvent* event);

};

#endif // HOVERBUTTON_H
