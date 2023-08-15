#ifndef USERSETTINGS_H
#define USERSETTINGS_H

#include <QList>
#include <QDir>

namespace UserSettings
{
    QList<QString> loadQuickAccess();
    bool saveQuickAccess();

    const QString userSettingsPath = "xml/UserSettings.xml";
}

#endif // USERSETTINGS_H
