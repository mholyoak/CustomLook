#include "settingsdialog.h"
#include "ui_settingsdialog.h"

CSettingsDialog::CSettingsDialog(QWidget *parent, CAutoService::ServiceArray autoServices) :
    QDialog(parent),
    ui(new Ui::CSettingsDialog),
    _autoServices(autoServices)
{
    ui->setupUi(this);


}

CSettingsDialog::~CSettingsDialog()
{
    delete ui;
}
