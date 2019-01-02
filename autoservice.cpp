#include "autoservice.h"

CAutoService::CAutoService() :
    _serviceType(Type::undefinedService),
    _widgetButton(nullptr),
    _enabled(false)
{

}

CAutoService::CAutoService(Type autoService, QWidget* widgetButton, bool enabled) :
    _serviceType(autoService),
    _widgetButton(widgetButton),
    _enabled(enabled)
{

}

CAutoService::Type CAutoService::GetServiceType() const
{
    return _serviceType;
}

QWidget* CAutoService::GetWidgetButton() const
{
    return _widgetButton;
}

bool CAutoService::GetEnabled() const
{
    return _enabled;
}

void CAutoService::SetEnabled(bool enabled)
{
    _enabled = enabled;
}
