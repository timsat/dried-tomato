/*
 * Copyright (c) 2010-2014 Célio Cidral Junior.
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

#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QObject>

namespace tmtl
{
  enum class IntervalType;

  class Preferences : public QObject
  {
      Q_OBJECT

    public:
      explicit Preferences(QObject *parent = 0);

      virtual int intervalLengthInMinutes(IntervalType intervalType) const = 0;
      virtual void setIntervalLengthInMinutes(IntervalType intervalType, int minutes) = 0;

      virtual bool shouldPlaySoundNotificationWhenTimerIsSet() = 0;
      virtual void setShouldPlaySoundNotificationWhenTimerIsSet(bool shouldPlay) = 0;

      virtual bool shouldPlaySoundNotificationDuringPomodoros() = 0;
      virtual void setShouldPlaySoundNotificationDuringPomodoros(bool shouldPlay) = 0;

      virtual bool shouldPlaySoundNotificationDuringBreaks() = 0;
      virtual void setShouldPlaySoundNotificationDuringBreaks(bool shouldPlay) = 0;

      virtual bool shouldPlaySoundNotificationWhenTimerExpires() = 0;
      virtual void setShouldPlaySoundNotificationWhenTimerExpires(bool shouldPlay) = 0;
  };
}

#endif // PREFERENCES_H
