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

#include <firestarter/Environment/Payload/Payload.hpp>
#include <firestarter/Logging/Log.hpp>

#include <firestarter/DumpRegisterWorkerData.hpp>
#include <firestarter/LoadWorkerData.hpp>



namespace firestarter::environment::generic::payload {

class GenericPayload : public environment::payload::Payload {
protected:
    // typedef int (*LoadFunction)(firestarter::ThreadData *);
    typedef unsigned long long (*LoadFunction)(unsigned long long *,
                                               volatile unsigned long long *,
                                               unsigned long long);
    LoadFunction loadFunction = nullptr;

    public:
        GenericPayload(std::string name)
                : Payload(name, 2, 16) {}

        // A generic implemenation for all payloads
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Woverloaded-virtual"
#endif
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverloaded-virtual"
        void init(unsigned long long *memoryAddr, unsigned long long bufferSize,
                  double firstValue, double lastValue);
#pragma GCC diagnostic pop
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
        // use cpuid and usleep as low load
        void lowLoadFunction(volatile unsigned long long *addrHigh,
                             unsigned long long period) override;

        unsigned long long highLoadFunction(unsigned long long *addrMem,
                                            volatile unsigned long long *addrHigh,
                                            unsigned long long iterations) override;

/*        virtual ~GenericPayload() {

        }*/

        bool isAvailable() const override {
            return true;
        }
    };

} // namespace firestarter::environment::generic::payload

