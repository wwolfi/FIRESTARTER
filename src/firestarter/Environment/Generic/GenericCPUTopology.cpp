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

#include <firestarter/Environment/Generic/GenericCPUTopology.hpp>
#include <firestarter/Logging/Log.hpp>

#include <ctime>

using namespace firestarter::environment::generic;

GenericCPUTopology::GenericCPUTopology()
    : CPUTopology("generic"){
  std::stringstream ss;
  ss << "Generic Model";
  this->_model = ss.str();

  ss.clear();
  ss << "Generic Vendor, ";
 this->_vendor =ss.str();
}

// TODO: Probably read clockrate from hw lib?
unsigned long long GenericCPUTopology::clockrate() const {
  return -1;
}

// TODO: use nanosec?
unsigned long long GenericCPUTopology::timestamp() const {
  return -1;
}
