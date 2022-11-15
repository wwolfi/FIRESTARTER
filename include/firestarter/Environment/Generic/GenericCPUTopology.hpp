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

#include <firestarter/Environment/CPUTopology.hpp>

namespace firestarter::environment::generic {

    class GenericCPUTopology final : public CPUTopology {
    public:
        GenericCPUTopology();

        friend std::ostream &operator<<(std::ostream &stream,
                                        GenericCPUTopology const &cpuTopology);

        std::list<std::string> const &features() const override {
            return this->featureList;
        }

        std::string const &vendor() const override { return this->_vendor; }

        std::string const &model() const override { return this->_model; }

        unsigned long long clockrate() const override;

        unsigned long long timestamp() const override;

    private:
        bool hasRdtsc() const { return this->_hasRdtsc; }

        bool hasInvariantRdtsc() const { return this->_hasInvariantRdtsc; }

        void cpuid(unsigned long long *a, unsigned long long *b,
                   unsigned long long *c, unsigned long long *d) const;

        std::list<std::string> featureList;

        bool _hasRdtsc;
        bool _hasInvariantRdtsc;
        std::string _vendor;
        std::string _model;
    };

    inline std::ostream &operator<<(std::ostream &stream,
                                    GenericCPUTopology const &cpuTopology) {
        return cpuTopology.print(stream);
    }

} // namespace firestarter::environment::generic
