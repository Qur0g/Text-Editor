#include "usersettings.h"

#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>

QList<QString> UserSettings::loadQuickAccess()
{
    QFile file(userSettingsPath);
    QList<QString> buttons = {"AutoSave", "Save", "Undo", "Redo"};

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //QMessageBox::warning(nullptr, "File Error", "Failed to load user settings.");
        return buttons;
    }

    QXmlStreamReader xmlReader(&file);

    if(xmlReader.hasError())
    {
        //QMessageBox::warning(nullptr, "File Error", "Failed to load user settings");
        file.close();
        return buttons;
    }

    buttons.clear();

    while(!xmlReader.atEnd() && !xmlReader.hasError())
    {
        xmlReader.readNext();

        if(xmlReader.isStartElement() && xmlReader.name().toString() == "button")
        {
            xmlReader.readNext();

            if(xmlReader.isCharacters())
            {
                QString button = xmlReader.text().toString().trimmed();

                if(!button.isEmpty())
                {
                    buttons.append(button);
                }
            }
        }
    }    

    file.close();
    return buttons;
}
