#ifndef ESCAPEDIALOG_H
#define ESCAPEDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include "hoverbutton.h"

class EscapeDialog : public QDialog
{
#define MARGIN 20
public:
    EscapeDialog(QString title, QString msg, QString esc, QString nor, QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void resetBtnPos();

public slots:
    void slotPosEntered(QPoint point);
    void slotEscapeButton(QPoint p);
    void slotExchangeButton();

private:
    QLabel* msg_lab;
    HoverButton* esc_btn, *nor_btn;

    bool exchanged; // 两个按钮是否交换了位置
    int escape_count; // 跑动的次数（包括交换）
};

#endif // ESCAPEDIALOG_H
