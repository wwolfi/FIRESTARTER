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

#include <firestarter/Environment/Environment.hpp>
#include <firestarter/Environment/Generic/GenericCPUTopology.hpp>
#include <firestarter/Environment/Generic/Platform/GenericPlatformConfig.hpp>
#include <firestarter/Environment/Generic/Platform/TestConfig.hpp>

#include <functional>

#define REGISTER(NAME)                                                         \
  [](unsigned threads) -> platform::GenericPlatformConfig * {      \
    return new platform::NAME(threads);      \
  }


namespace firestarter::environment::generic {

class GenericEnvironment final : public Environment {
public:
  GenericEnvironment() : Environment(new GenericCPUTopology()) {}

  ~GenericEnvironment() {
      for (auto const &config : platformConfigs) {
          delete config;
      }
      for (auto const &config : fallbackPlatformConfigs) {
          delete config;
      }
  }

  GenericCPUTopology const &topology() {
    return *reinterpret_cast<GenericCPUTopology *>(this->_topology);
  }

  void evaluateFunctions() override;
  int selectFunction(unsigned functionId,
                     bool allowUnavailablePayload) override;
  int selectInstructionGroups(std::string groups) override;
  void printAvailableInstructionGroups() override;
  void setLineCount(unsigned lineCount) override;
  void printSelectedCodePathSummary() override;
  void printFunctionSummary() override;

private:
  // The available function IDs are generated by iterating through this list of
  // PlatformConfig. Add new PlatformConfig at the bottom to maintain stable
  // IDs.

    const std::list<std::function<platform::GenericPlatformConfig *(unsigned)>>
    platformConfigsCtor = {
            REGISTER(TestConfig)
    };

    std::list<platform::GenericPlatformConfig *> platformConfigs;

    // List of fallback PlatformConfig. Add one for each x86 extension.
    const std::list<std::function<platform::GenericPlatformConfig *(unsigned)>>
    fallbackPlatformConfigsCtor = {
            REGISTER(TestConfig)
    };

    std::list<platform::GenericPlatformConfig *> fallbackPlatformConfigs;

    //platform::GenericPlatformConfig * platformConfigs = REGISTER(GenericConfig);


#undef REGISTER
};

} // namespace firestarter::environment::generic
