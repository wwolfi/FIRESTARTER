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

#include <chrono>
#include <thread>
#include <type_traits>

#include <firestarter/Environment/Generic/Payload/GenericPayload.hpp>
#include <firestarter/Environment/Payload/Payload.hpp>

using namespace firestarter::environment::generic::payload;

void GenericPayload::lowLoadFunction(volatile unsigned long long *addrHigh,
                                 unsigned long long period) {
  int nap;
  nap = period / 100;
  // while signal low load
  while (*addrHigh == LOAD_LOW) {
    std::this_thread::sleep_for(std::chrono::microseconds(nap));
  }
}

void GenericPayload::init(unsigned long long *memoryAddr,
                      unsigned long long bufferSize, double firstValue,
                      double lastValue) {
}

unsigned long long GenericPayload::highLoadFunction(unsigned long long *addrMem,
                             volatile unsigned long long *addrHigh,
                             unsigned long long iterations) {
  return this->loadFunction(addrMem, addrHigh, iterations);
}
