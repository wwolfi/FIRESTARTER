/******************************************************************************
 * FIRESTARTER - A Processor Stress Test Utility
 * Copyright (C) 2020 TU Dresden, Center for Information Services and High
 * Performance Computing
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/\>.
 *
 * Contact: daniel.hackenberg@tu-dresden.de
 *****************************************************************************/

#pragma once

#include <firestarter/Environment/Platform/PlatformConfig.hpp>
#include <firestarter/Environment/Generic/Payload/GenericPayload.hpp>

namespace firestarter::environment::generic::platform {

class GenericPlatformConfig : public environment::platform::PlatformConfig {
private:
  unsigned _family;
  std::list<unsigned> _models;
  unsigned _currentFamily;
  unsigned _currentModel;
  unsigned _currentThreads;

public:
  GenericPlatformConfig(std::string name, std::initializer_list<unsigned> threads,
                        unsigned currentThreads, payload::GenericPayload *payload)
      : PlatformConfig(name, threads, 0, {},
                       0, 0, payload), _currentThreads(currentThreads){}

  bool isDefault() const override {
    return _family == _currentFamily &&
           (std::find(_models.begin(), _models.end(), _currentModel) !=
            _models.end()) &&
           isAvailable();
  }
};

} // namespace firestarter::environment::x86::platform
