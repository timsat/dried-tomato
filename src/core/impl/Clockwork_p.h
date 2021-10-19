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

#ifndef CLOCKWORK_P_H
#define CLOCKWORK_P_H

#include <QTimer>
#include "Clockwork.h"

namespace tmtl
{
  class ClockworkPrivate
  {
    Q_DECLARE_PUBLIC(Clockwork);
    public:
      explicit ClockworkPrivate(Clockwork *parent):q_ptr(parent) {
        _timer = new QTimer(parent);
        _timer->setInterval(1000);
        parent->connect(_timer, SIGNAL(timeout()), parent,  SIGNAL(secondElapsed()));
      }

      void resume() {
        _timer->start();
      }

      void pause() {
        _timer->stop();
      }

    private:
      Clockwork * q_ptr;
      QTimer *_timer;
  };
}

#endif // CLOCKWORK_P_H
