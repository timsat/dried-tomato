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

#include "Interval.h"
#include "IntervalType.h"

using tmtl::Interval;
using tmtl::IntervalType;

Interval::Interval() :
  _seconds(0),
  _type(IntervalType::POMODORO)
{}

Interval::Interval(int seconds, IntervalType type) :
  _seconds(seconds),
  _type(type)
{}

int Interval::seconds() const
{
  return _seconds;
}

IntervalType Interval::type() const
{
  return _type;
}
