#ifndef AUTOSERVICE_H
#define AUTOSERVICE_H

#include <QWidget>
#include <array>

class CAutoService
{
public:
    static const std::size_t _totalService = 8;
    typedef std::array<CAutoService, _totalService> ServiceArray;

    enum class Type {
        undefinedService,
        securityService,
        shadesService,
        watchService,
        listenService,
        lightingService,
        comfortService,
        appsService,
        settingsService
    };

    CAutoService();
    CAutoService(Type autoService, QWidget* widgetButton, bool enabled);

    Type GetServiceType() const;
    QWidget*        GetWidgetButton() const;
    bool            GetEnabled() const;
    void            SetEnabled(bool enabled);

private:
    Type        _serviceType;
    QWidget*    _widgetButton;
    bool        _enabled;
};

#endif // AUTOSERVICE_H
