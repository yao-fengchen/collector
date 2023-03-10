#
# Copyright (C) 2019 IBM Corporation.
#
# Authors:
# Frederico Araujo <frederico.araujo@ibm.com>
# Teryl Taylor <terylt@ibm.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

INSTALL_PATH?=/usr/local/sysflow
MODPREFIX=$(INSTALL_PATH)/modules
LIBPREFIX=$(MODPREFIX)/lib
BINPREFIX=$(MODPREFIX)/bin
CONFPREFIX=$(MODPREFIX)/conf
DRIVERPREFIX=/usr/src/falco-
FALCOINCPREFIX=$(MODPREFIX)/include/falcosecurity
FALCOLIBPREFIX=$(LIBPREFIX)/falcosecurity
AVRINCPREFIX=$(MODPREFIX)/include/avro
SFINCPREFIX=$(MODPREFIX)/include/sysflow
FSINCPREFIX=$(MODPREFIX)/include/filesystem
