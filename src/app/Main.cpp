/*
 * Copyright (c) 2010-2014 Célio Cidral Junior.
 * Modified work Copyright (c) 2021 Timur Sattarov.
 *
 *     Licensed under the Apache License, Version 2.0 (the "License");
 *     you may not use this file except in compliance with the License.
 *     You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#include <QObject>
#include <QApplication>
#include <QCommandLineParser>

#include "impl/Clockwork_p.h"
#include "impl/StandardPomodoroEngine.h"
#include "impl/StandardPreferences.h"
#include "impl/StandardTimer.h"
#include "impl/StandardTray.h"
#include "impl/StandardTrayController.h"
#include "impl/StandardTrayIconFiles.h"
#include "impl/StandardSoundNotifications.h"
#include "SoundNotificationController.h"

using tmtl::Clockwork;
using tmtl::PomodoroEngine;
using tmtl::Preferences;
using tmtl::StandardPomodoroEngine;
using tmtl::StandardPreferences;
using tmtl::StandardTimer;
using tmtl::Timer;

using tmtl::ui::SoundNotifications;
using tmtl::ui::SoundNotificationController;
using tmtl::ui::StandardSoundNotifications;
using tmtl::ui::StandardTray;
using tmtl::ui::StandardTrayController;
using tmtl::ui::StandardTrayIconFiles;
using tmtl::ui::Tray;
using tmtl::ui::TrayController;
using tmtl::ui::TrayIconFiles;

int main(int argc, char *argv[])
{

  QApplication app(argc, argv);
  app.setApplicationName("Tomatl");
  app.setApplicationVersion(VERSION);

  QCommandLineParser parser;
  parser.setApplicationDescription("Simple Pomodoro timer");
  parser.addHelpOption();
  parser.addVersionOption();

  parser.process(app);

  Clockwork *clockwork = new Clockwork();
  Timer *timer = new StandardTimer(*clockwork);
  Preferences *preferences = new StandardPreferences();
  PomodoroEngine *pomodoroEngine = new StandardPomodoroEngine(*timer, *preferences);
  Tray *tray = new StandardTray();
  TrayIconFiles *trayIconFiles = new StandardTrayIconFiles();
  TrayController *trayController = new StandardTrayController(*tray, *trayIconFiles, *pomodoroEngine, *timer);
  SoundNotifications *soundNotifications = new StandardSoundNotifications();
  SoundNotificationController *soundNotificationController = new SoundNotificationController(*soundNotifications, *preferences);

  soundNotificationController->listenTo(*timer);
  trayController->showTrayIcon();

  return app.exec();
}
