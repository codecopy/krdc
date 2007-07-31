/****************************************************************************
**
** Copyright (C) 2007 Urs Wolfer <uwolfer @ kde.org>
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "remoteview.h"

#include <KXmlGuiWindow>

class KToggleAction;
class KTabWidget;
class KUrlNavigator;

class BookmarkManager;
class FloatingToolBar;
class RemoteView;
class QScrollArea;

class MainWindow : public KXmlGuiWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QList<RemoteView *> remoteViewList() const;
    int currentRemoteView() const;

public slots:
    void slotNewConnection(const KUrl &newUrl = KUrl(), bool switchFullscreenWhenConnected = false);

protected:
    virtual void closeEvent(QCloseEvent *event);

private slots:
    void slotQuit();
    void slotPreferences();
    void slotConfigureNotifications();
    void slotConfigureKeys();
    void slotConfigureToolbars();
    void slotShowMenubar();
    void resizeTabWidget(int w, int h);
    void statusChanged(RemoteView::RemoteStatus status);
    void showRemoteViewToolbar();
    void slotTakeScreenshot();
    void slotSwitchFullscreen();
    void slotLogout();
    void slotViewOnly(bool viewOnly);
    void slotShowLocalCursor(bool showLocalCursor);
    void updateActionStatus();
    void updateConfiguration();
    void tabChanged(int index);
    void createStartPage();
    void newVncConnection();
    void newRdpConnection();

private:
    void setupActions();
    QScrollArea *createScrollArea(QWidget *parent, RemoteView *remoteView);

    QWidget *m_fullscreenWindow;
    QByteArray m_mainWindowGeometry;

    KToggleAction *m_menubarAction;
    KTabWidget *m_tabWidget;
    KUrlNavigator *m_addressNavigator;

    FloatingToolBar *m_toolBar;

    BookmarkManager *m_bookmarkManager;

    QList<RemoteView *> m_remoteViewList;

    int m_topBottomBorder; // tabwidget borders
    int m_leftRightBorder;

    int m_currentRemoteView;
    bool m_showStartPage;
    bool m_switchFullscreenWhenConnected;
};

#endif
