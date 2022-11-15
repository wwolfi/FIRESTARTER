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

#include <firestarter/Environment/Generic/Payload/BusyPayload.hpp>
#include <firestarter/Logging/Log.hpp>

#include <iterator>
#include <utility>

using namespace firestarter::environment::generic::payload;

int BusyPayload::compilePayload(unsigned thread) {
  // Compute the sequence of instruction groups and the number of its repetitions
  // to reach the desired size

  // compute count of flops and memory access for performance report
  long long unsigned a = 1;
  while(a>0){
      a++;
  }
  return EXIT_SUCCESS;
}

std::list<std::string> BusyPayload::getAvailableInstructions() const {
  std::list<std::string> instructions;

  transform(this->instructionFlops.begin(), this->instructionFlops.end(),
            back_inserter(instructions),
            [](const auto &item) { return item.first; });

  return instructions;
}

void BusyPayload::init(unsigned long long *memoryAddr,
                       unsigned long long bufferSize) {
  GenericPayload::init(memoryAddr, bufferSize, 1.654738925401e-10,
                   1.654738925401e-15);
}
