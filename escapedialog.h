#ifndef ESCAPEDIALOG_H
#define ESCAPEDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include "hoverbutton.h"

class EscapeDialog : public QDialog
{
public:
    EscapeDialog(QString title, QString msg, QString esc, QString nor, QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void resetBtnPos();

public slots:
    void slotPosEntered(QPoint point);

private:
    QLabel* msg_lab;
    HoverButton* esc_btn, *nor_btn;
};

#endif // ESCAPEDIALOG_H
