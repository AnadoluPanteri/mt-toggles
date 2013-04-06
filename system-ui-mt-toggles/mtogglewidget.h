#ifndef MTOGGLEWIDGET_H
#define MTOGGLEWIDGET_H

#include <MWidget>
#include <MImageWidget>
#include <QGraphicsWidget>
#include <QSizeF>
#include <QTimer>
#include <QDebug>
#include <QMap>
#include <MButton>
#include <MLabel>
#include <QGraphicsLinearLayout>
#include <QGraphicsSceneMouseEvent>
#include <MProgressIndicator>
#include <MFeedback>

#define ON_SWITCH "/usr/share/mt-toggles/on_switch.png"
#define OFF_SWITCH "/usr/share/mt-toggles/off_switch.png"
#define FEEDBACK_PATTERN "priority2_static_press"
#define LONG_PRESS_FEEDBACK_PATTERN "priority2_callbutton_press"

class MToggleWidget : public MWidget
{
    Q_OBJECT
public:
    explicit MToggleWidget(QGraphicsItem *parent = 0, QImage icon = QImage(), QString iconId = QString(), bool isToggle = true);
    
signals:
    void pressed();
    void released();
    void clicked();
    void longPressed();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *ev);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *ev);
    bool event(QEvent *event);
    
public slots:
    void onIconChanged(QImage icon);
    void onStateChanged(bool state);
    void setIcon(QString iconId);

private:
    MImageWidget *m_iconWidget;
    MImageWidget *m_stateImage;

    bool m_pressed;
    bool m_weWereHeld;

    QTimer *m_longPressTimer;

private slots:
    void onLongPressTimerTimeout();
};

#endif // MTOGGLEWIDGET_H
