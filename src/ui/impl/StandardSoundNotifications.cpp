#include <QString>
#include <QAudioDeviceInfo>
#include <QDebug>

#include "StandardSoundNotifications.h"
#include "ImmutableSoundClip.h"

using tmtl::ui::ImmutableSoundClip;
using tmtl::ui::SoundClip;
using tmtl::ui::StandardSoundNotifications;

StandardSoundNotifications::StandardSoundNotifications() :
  _timerSet(new ImmutableSoundClip(QString(":/sound/timer_set.wav"))),
  _timeElapsing(new ImmutableSoundClip(QString(":/sound/clock_ticking.wav"))),
  _timerExpired(new ImmutableSoundClip(QString(":/sound/timer_expired.wav")))
{
  const auto deviceInfos = QAudioDeviceInfo::availableDevices(QAudio::AudioOutput);
  for (const QAudioDeviceInfo &deviceInfo : deviceInfos)
    qDebug() << "Device name: " << deviceInfo.deviceName();
  qDebug() << "Default device name: " << QAudioDeviceInfo::defaultOutputDevice().deviceName();
}

SoundClip &StandardSoundNotifications::timerSet()
{
  return *_timerSet;
}

SoundClip &StandardSoundNotifications::timeElapsing()
{
  return *_timeElapsing;
}

SoundClip &StandardSoundNotifications::timerExpired()
{
  return *_timerExpired;
}
