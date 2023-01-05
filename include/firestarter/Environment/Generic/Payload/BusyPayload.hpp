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

#include <firestarter/Environment/Generic/Payload/GenericPayload.hpp>

namespace firestarter::environment::generic::payload {
class BusyPayload final : public GenericPayload {
public:
  BusyPayload(std::string name)
      : GenericPayload(name) {}
      
   /* unsigned long long int highLoadFunction(unsigned long long int *addrMem, volatile unsigned long long int *addrHigh,
                                            unsigned long long int iterations) override;
    */
    std::list<std::string> getAvailableInstructions() const override;
  void init(unsigned long long *memoryAddr,
            unsigned long long bufferSize) override;

  firestarter::environment::payload::Payload *clone() const override {
    return new BusyPayload("clonedPayload");
  }

    int compilePayload(const std::vector<std::pair<std::string, unsigned int>> &proportion,
                       unsigned int instructionCacheSize, const std::list<unsigned int> &dataCacheBufferSize,
                       unsigned int ramBufferSize, unsigned int thread, unsigned int numberOfLines, bool dumpRegisters,
                       bool errorDetection) override;;

private:
  const std::map<std::string, unsigned> instructionFlops = {
      {"REG", 2},  {"L1_L", 2},  {"L1_S", 2},  {"L1_LS", 2},  {"L2_L", 2},
      {"L2_S", 2}, {"L2_LS", 2}, {"L3_L", 2},  {"L3_S", 2},   {"L3_LS", 2},
      {"L3_P", 2}, {"RAM_L", 2}, {"RAM_S", 2}, {"RAM_LS", 2}, {"RAM_P", 2}};

  const std::map<std::string, unsigned> instructionMemory = {
      {"RAM_L", 64}, {"RAM_S", 128}, {"RAM_LS", 128}, {"RAM_P", 64}};
};
} // namespace firestarter::environment::x86::payload
