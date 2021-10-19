#include <QSoundEffect>
#include <QString>

#include "ImmutableSoundClip.h"

using tmtl::ui::ImmutableSoundClip;

ImmutableSoundClip::ImmutableSoundClip(const QString &filePath) :
  _sound(new QSoundEffect())
{
  _sound->setSource(QUrl::fromLocalFile(filePath));
  _sound->stop();
  _sound->setVolume(0.2f);
  _sound->setCategory(QString("notifications"));
}

void ImmutableSoundClip::play()
{
  _sound->setLoopCount(0);
  _sound->play();
}

void ImmutableSoundClip::loop()
{
  _sound->setLoopCount(QSoundEffect::Infinite);
  _sound->play();
}

void ImmutableSoundClip::stop()
{
  _sound->stop();
}
