#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "autoservice.h"

#include <QMainWindow>
#include <array>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onSettingsButtonclicked();

private:
    Ui::MainWindow *ui;

    CAutoService::ServiceArray  _autoServices;
    QGraphicsDropShadowEffect   _dropShadowEffect;

    void resizeEvent(QResizeEvent *event) override;

    void centerWidget(QWidget* widget, QPoint centerPoint);
};

#endif // MAINWINDOW_H
