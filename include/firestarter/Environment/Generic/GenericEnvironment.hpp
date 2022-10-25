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


#include <asmjit/asmjit.h>

#include <functional>

#define REGISTER(NAME)                                                         \
  [](asmjit::x86::Features const &supportedFeatures, unsigned family,          \
     unsigned model, unsigned threads) -> platform::X86PlatformConfig * {      \
    return new platform::NAME(supportedFeatures, family, model, threads);      \
  }

namespace firestarter::environment::generic {

class GenericEnvironment final : public Environment {
public:
  GenericEnvironment() : Environment(new GenericCPUTopology()) {}

  ~GenericEnvironment() {

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



#undef REGISTER
};

} // namespace firestarter::environment::x86