/**
 ******************************************************************************
 *
 * @file       configgadgetwidget.h
 * @author     The LibrePilot Project, http://www.librepilot.org Copyright (C) 2016.
 *             The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup ConfigPlugin Config Plugin
 * @{
 * @brief The Configuration Gadget used to update settings in the firmware
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#ifndef CONFIGGADGETWIDGET_H
#define CONFIGGADGETWIDGET_H

#include <QWidget>

class QTextBrowser;
class QSettings;
class MyTabbedStackWidget;

class ConfigGadgetWidget : public QWidget {
    Q_OBJECT

public:
    enum WidgetTabs { Hardware = 0, Aircraft, Input, Output, Sensors, Stabilization, CameraStabilization, TxPid, OPLink };

    ConfigGadgetWidget(QWidget *parent = 0);
    ~ConfigGadgetWidget();

    void startInputWizard();

    void saveState(QSettings *settings);
    void restoreState(QSettings *settings);

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void onAutopilotConnect();
    void onAutopilotDisconnect();
    void onOPLinkConnect();
    void onOPLinkDisconnect();
    void tabAboutToChange(int index, bool *proceed);

private:
    MyTabbedStackWidget *stackWidget;
    QTextBrowser *help;
};

#endif // CONFIGGADGETWIDGET_H
