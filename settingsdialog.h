#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

#include "autoservice.h"

namespace Ui {
class CSettingsDialog;
}

class CSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CSettingsDialog(QWidget *parent, CAutoService::ServiceArray autoServices);
    ~CSettingsDialog();

private:
    Ui::CSettingsDialog *ui;

    CAutoService::ServiceArray  _autoServices;
};

#endif // SETTINGSDIALOG_H
