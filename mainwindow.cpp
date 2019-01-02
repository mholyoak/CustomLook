#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QResizeEvent>
#include <cmath>
#include <array>
#include <QMessageBox>
#include <algorithm>

#include "settingsdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->centralWidget->layout()->setContentsMargins(0,0,0,0);
    ui->settingsBtn->setGraphicsEffect(&_dropShadowEffect);

    _autoServices[0] = CAutoService(CAutoService::Type::securityService, ui->securityBtn, true);
    _autoServices[1] = CAutoService(CAutoService::Type::shadesService, ui->shadesBtn, true);
    _autoServices[2] = CAutoService(CAutoService::Type::watchService, ui->watchBtn, true);
    _autoServices[3] = CAutoService(CAutoService::Type::listenService, ui->listenBtn, true);
    _autoServices[4] = CAutoService(CAutoService::Type::lightingService, ui->lightingBtn, true);
    _autoServices[5] = CAutoService(CAutoService::Type::comfortService, ui->comfortBtn, true);
    _autoServices[6] = CAutoService(CAutoService::Type::appsService, ui->appsBtn, true);
    _autoServices[7] = CAutoService(CAutoService::Type::settingsService, ui->settingsBtn, true);

    // Should verify that this connection worked as SIGNAL and SLOT doesn't check for typos
    QObject::connect(ui->settingsBtn, SIGNAL(clicked()), this, SLOT(onSettingsButtonclicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QSize customGeo = event->size();

    int minSize = std::min(customGeo.width(), customGeo.height());

    bool circleMenu = false;
    int radius = (minSize - ui->control4Lbl->width()) / 4 + ui->control4Lbl->width() / 2;
    int ellipseWidth = (customGeo.width() - ui->control4Lbl->width()) / 4 + ui->control4Lbl->width() / 2;
    int ellipseHeight = (customGeo.height() - ui->control4Lbl->height()) / 4 + ui->control4Lbl->height() / 2;
    QPoint center(customGeo.width() / 2, customGeo.height() / 2);

    centerWidget(ui->control4Lbl, center);

    int serviceCount = 0;
    std::for_each(_autoServices.begin(), _autoServices.end(), [&serviceCount](const CAutoService& autoService){
        if (autoService.GetEnabled())
        {
            serviceCount++;
        }
    });

    for (std::size_t i = 0; i < _autoServices.size(); i++)
    {
        if (_autoServices[i].GetEnabled())
        {
            _autoServices[i].GetWidgetButton()->show();

            double serviceOrder = double(i);
            double serviceRadians = serviceOrder * 6.28 / double(serviceCount) + 3.14;
            int xPos = 0;
            int yPos = 0;

            if (circleMenu)
            {
                // Circle
                xPos = int(double(radius) * std::cos(serviceRadians) + center.x());
                yPos = int(double(radius) * std::sin(serviceRadians) + center.y());
            }
            else
            {
                // ellipse
                xPos = center.x() + int(ellipseWidth  * std::cos(serviceRadians));
                yPos = center.y() + int(ellipseHeight * std::sin(serviceRadians));
            }

            QPoint servicePos(xPos, yPos);

            centerWidget(_autoServices[i].GetWidgetButton(), servicePos);
        }
        else
        {
            _autoServices[i].GetWidgetButton()->hide();
        }
    }
}

void MainWindow::centerWidget(QWidget* widget, QPoint centerPoint)
{
    int widgetWidth = widget->width();
    int widgetHeight = widget->height();

    widget->setGeometry(centerPoint.x() - widgetWidth / 2, centerPoint.y() - widgetHeight / 2, widgetWidth, widgetHeight);
    //widget->setGeometry(centerPoint.x(), centerPoint.y(), widgetWidth, widgetHeight);
}

void MainWindow::onSettingsButtonclicked()
{
    CSettingsDialog settingDlg(this, _autoServices);
    settingDlg.exec();
}
