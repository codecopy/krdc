/****************************************************************************
**
** Copyright (C) 2008 Urs Wolfer <uwolfer @ kde.org>
** Copyright (C) 2009 Tony Murray <murraytony@gmail.com>
**
** This file is part of KDE.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; see the file COPYING. If not, write to
** the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
** Boston, MA 02110-1301, USA.
**
****************************************************************************/

#ifndef REMOTEDESKTOPSMODEL_H
#define REMOTEDESKTOPSMODEL_H

#include <QAbstractItemModel>
#ifdef BUILD_ZEROCONF
#include <dnssd/servicebrowser.h>
#endif

class KBookmarkGroup;
class KBookmarkManager;
class RemoteDesktopsItem;

class KProcess;
class QByteArray;

class RemoteDesktopsModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    RemoteDesktopsModel(QObject *parent);
    ~RemoteDesktopsModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

private:
    void buildModelFromBookmarkGroup(const KBookmarkGroup &group, RemoteDesktopsItem *item);

    KBookmarkManager *m_manager;
    RemoteDesktopsItem *rootItem;
    RemoteDesktopsItem *bookmarkItem;
#ifdef BUILD_ZEROCONF
    RemoteDesktopsItem *zeroconfItem;
    DNSSD::ServiceBrowser *zeroconfBrowser;
    QHash<QString, QString> m_protocols;
#endif
#if 0
    void scanLocalNetwork();
    RemoteDesktopsItem *localNetworkItem;

    KProcess *m_scanProcess;
    QString m_strBt;
    QByteArray m_output;
#endif

private slots:
    void bookmarksChanged();
#ifdef BUILD_ZEROCONF
    void servicesChanged();
#endif
#if 0
    void readInput();
#endif
};

#endif
