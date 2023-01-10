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

#define INIT_BLOCKSIZE 1024

using namespace firestarter::environment::generic::payload;

void GenericPayload::lowLoadFunction(volatile unsigned long long *addrHigh,
                                 unsigned long long period) {
  int nap;
  nap = period / 100;
  // while signal low load
  while (*addrHigh == LOAD_LOW) {
    std::this_thread::sleep_for(std::chrono::microseconds(nap));
  }
    std::cout << "Low Load: " << std::this_thread::get_id() << "\n";
    for (int z = 0; z < 100000000000; z++) {
        unsigned long long great_array[1000000][1000000][1000000];
        for (int i = 1; i < 1000000000; i++) {
            for (int j = 0; j < 999984; j++) {
                for (int a = 0; a < 999984; a++) {
                    for (int b = 0; b < 999984; b++) {
                        int z = a * j * b;
                        if (z % 2 == 0) {
                            great_array[j][a][b] = 1;
                            great_array[j + 1][a + 1][b + 1] = 1;
                            great_array[j + 2][a + 2][b + 2] = 1;
                            great_array[j + 3][a + 3][b + 3] = 1;
                            great_array[j + 4][a + 4][b + 4] = 1;
                            great_array[j + 5][a + 5][b + 5] = 1;
                            great_array[j + 6][a + 6][b + 6] = 1;
                            great_array[j + 7][a + 7][b + 7] = 1;
                            great_array[j + 8][a + 8][b + 8] = 1;
                            great_array[j + 9][a + 9][b + 9] = 1;
                            great_array[j + 10][a + 10][b + 10] = 1;
                            great_array[j + 11][a + 11][b + 11] = 1;
                            great_array[j + 12][a + 12][b + 12] = 1;
                            great_array[j + 13][a + 13][b + 13] = 1;
                            great_array[j + 14][a + 14][b + 14] = 1;
                            great_array[j + 15][a + 15][b + 15] = 1;
                        } else {
                            great_array[j][a][b] = 0;
                            great_array[j + 1][a + 1][b + 1] = 0;
                            great_array[j + 2][a + 2][b + 2] = 0;
                            great_array[j + 3][a + 3][b + 3] = 0;
                            great_array[j + 4][a + 4][b + 4] = 0;
                            great_array[j + 5][a + 5][b + 5] = 0;
                            great_array[j + 6][a + 6][b + 6] = 0;
                            great_array[j + 7][a + 7][b + 7] = 0;
                            great_array[j + 8][a + 8][b + 8] = 0;
                            great_array[j + 9][a + 9][b + 9] = 0;
                            great_array[j + 10][a + 10][b + 10] = 0;
                            great_array[j + 11][a + 11][b + 11] = 0;
                            great_array[j + 12][a + 12][b + 12] = 0;
                            great_array[j + 13][a + 13][b + 13] = 0;
                            great_array[j + 14][a + 14][b + 14] = 0;
                            great_array[j + 15][a + 15][b + 15] = 0;
                        }
                    }
                }
            }
        }
    }
}

void GenericPayload::init(unsigned long long *memoryAddr,
                      unsigned long long bufferSize, double firstValue,
                      double lastValue) {
    unsigned long long i = 0;

    for (; i < INIT_BLOCKSIZE; i++)
        *((double *)(memoryAddr + i)) = 0.25 + (double)i * 8.0 * firstValue;
    for (; i <= bufferSize - INIT_BLOCKSIZE; i += INIT_BLOCKSIZE)
        std::memcpy(memoryAddr + i, memoryAddr + i - INIT_BLOCKSIZE,
                    sizeof(unsigned long long) * INIT_BLOCKSIZE);
    for (; i < bufferSize; i++)
        *((double *)(memoryAddr + i)) = 0.25 + (double)i * 8.0 * lastValue;
}

unsigned long long GenericPayload::highLoadFunction(unsigned long long *addrMem,
                             volatile unsigned long long *addrHigh,
                             unsigned long long iterations) {
  return this->loadFunction(addrMem, addrHigh, iterations);
}
