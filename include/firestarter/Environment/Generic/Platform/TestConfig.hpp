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

#include <firestarter/Environment/Generic/Platform/GenericPlatformConfig.hpp>
#include <firestarter/Environment/Generic/Payload/GenericPayload.hpp>

namespace firestarter::environment::generic::platform {
class TestConfig final : public GenericPlatformConfig {

public:
    std::string name = "Testconfig";
  TestConfig(unsigned threads)
      : GenericPlatformConfig("TestConfig", 6, {60, 61, 69, 70, 71}, {1, 2}, 0,
                          {32768, 262144, 1572864}, 104857600, 1536, threads,
                          new payload::GenericPayload(name, 4)) {}

  std::vector<std::pair<std::string, unsigned>>
  getDefaultPayloadSettings() const override {
    return std::vector<std::pair<std::string, unsigned>>(
        {{"RAM_L", 2}, {"L3_LS", 3}, {"L2_LS", 9}, {"L1_LS", 90}, {"REG", 40}});
  }
};
} // namespace firestarter::environment::generic::platform
