/*
This file is part of LightDM-KDE.

Copyright 2011, 2012 David Edmundson <kde@davidedmundson.co.uk>

LightDM-KDE is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

LightDM-KDE is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with LightDM-KDE.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef THEMESMODEL_H
#define THEMESMODEL_H

#include <QAbstractListModel>

class ThemeItem;
class QDir;

class ThemesModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {IdRole = Qt::UserRole,
               AuthorRole,
               DescriptionRole,
               VersionRole,
               PreviewRole,
               PathRole};

    explicit ThemesModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

signals:

public slots:

private:
    void load();
    void loadTheme(const QDir &themePath);
    QList<ThemeItem*> m_themes;

};

#endif // THEMESMODEL_H
