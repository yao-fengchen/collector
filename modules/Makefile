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

include ../makefile.manifest.inc
include ../makefile.env.inc

MAKE_JOBS ?= 1
BUNDLE_FALCO_LIBS ?= 1

$(info    MUSL is $(MUSL))
ifeq ($(MUSL), 1)
	MUSL_FLAG = -DMUSL_OPTIMIZED_BUILD=ON
endif

.PHONY: all
all: init \
	 modules

.PHONY: init
init:
# 	git submodule update --init --recursive --force
# 	cd falco && git checkout $(FALCO_VERSION)
# ifneq ($(FALCO_LIBS_PR),)
# 	cd falco-libs && git fetch origin pull/$(FALCO_LIBS_PR)/head:pull_$(FALCO_LIBS_PR) && git checkout pull_$(FALCO_LIBS_PR)
# else
# 	cd falco-libs && git checkout $(FALCO_LIBS_VERSION)
# endif
# 	cd falco-driver && git checkout $(FALCO_LIBS_DRIVER_VERSION)
# 	cd avro && git checkout $(AVRO_VERSION)
# 	cd elfutils && git checkout $(ELFUTILS_VERSION)
# 	cd glog && git checkout $(GLOG_VERSION)
# 	cd snappy && git checkout $(SNAPPY_VERSION)
# 	cd dkms && git checkout $(DKMS_VERSION)

# elfutils is a pre-requisite for libs.
.PHONY: modules
modules: elfutils/package \
		elfutils/install \
		falcolibs/package \
		falcodriver/package \
		avro/package \
		glog/package \
		snappy/package

.PHONY: install
install: modules \
	falcolibs/install \
	falcodriver/install \
	avro/install \
	sysflow/install \
	fs/install \
	glog/install \
	snappy/install \
	dkms-rh/install

.PHONY: modules/no-elfutils
modules/no-elfutils: falcolibs/package \
		falcodriver/package \
		avro/package \
		glog/package \
		snappy/package

.PHONY: install/no-elfutils
install/no-elfutils: modules/no-elfutils \
	falcolibs/install \
	falcodriver/install \
	avro/install \
	sysflow/install \
	fs/install \
	glog/install \
	snappy/install \
	dkms-rh/install

.PHONY: falcolibs/package
falcolibs/package:
	cd falco-libs && \
	mkdir -p build && cd build && \
        cmake \
			-DDRIVER_VERSION=${FALCO_LIBS_DRIVER_VERSION} \
			-DDRIVER_PACKAGE_NAME=falco \
			-DSCAP_BPF_PROBE_ENV_VAR_NAME=FALCO_BPF_PROBE \
			-DCAP_HOST_ROOT_ENV_VAR_NAME=HOST_ROOT \
			-DFALCOSECURITY_LIBS_VERSION=${FALCO_LIBS_VERSION} \
			-DFALCOSECURITY_LIBS_CHECKSUM=${FALCO_LIBS_CHECKSUM} \
			-DCMAKE_BUILD_TYPE=Release \
			-DDRIVER_NAME=falco \
			-DBUILD_BPF=OFF \
			-DBUILD_DRIVER=OFF \
			-DUSE_BUNDLED_GTEST=ON \
			-DUSE_BUNDLED_DEPS=ON \
			-DCREATE_TEST_TARGETS=OFF \
			-DCMD_MAKE="make -j${MAKE_JOBS}" \
			${MUSL_FLAG} ../. && make -j${MAKE_JOBS} && \
	mkdir -p include && mkdir -p lib && mkdir -p bin && \
	mkdir -p include/curl && cp curl-prefix/src/curl/include/curl/*.h include/curl && \
	mkdir -p include/driver && cp driver/src/*h include/driver && cp ../driver/*h include/driver && \
	mkdir -p include/json && cp ../userspace/libsinsp/third-party/jsoncpp/jsoncpp.cpp include/json && \
	mkdir -p include/json && cp ../userspace/libsinsp/third-party/jsoncpp/json/*.h include/json && \
	mkdir -p include/userspace/common && cp ../userspace/common/*.h include/userspace/common && \
	mkdir -p include/userspace/libsinsp && cp ../userspace/libsinsp/*.h include/userspace/libsinsp && \
	mkdir -p include/userspace/libsinsp/container_engine && cp ../userspace/libsinsp/container_engine/*.h include/userspace/libsinsp/container_engine/ && \
	mkdir -p include/userspace/libsinsp/filter && cp ../userspace/libsinsp/filter/*.h include/userspace/libsinsp/filter/ && \
	mkdir -p include/userspace/libsinsp/include && cp ../userspace/libsinsp/include/*.h include/userspace/libsinsp/include/ && \
	mkdir -p include/userspace/plugin && cp ../userspace/plugin/*.h include/userspace/plugin/ && \
	mkdir -p include/userspace/libscap && cd .. && find userspace/libscap -name '*.h' -exec cp -r --parents '{}' build/include \; && cd build && \
	mkdir -p include/openssl && cp openssl-prefix/src/openssl/include/openssl/*.h include/openssl && \
	cp -r tbb-prefix/src/tbb/include/serial  include/ && \
	cp -r tbb-prefix/src/tbb/include/tbb include/ && \
	cp -r protobuf-prefix/src/protobuf/target/include/google include/ && \
	cp protobuf-prefix/src/protobuf/target/lib/libprotobuf.a lib && \
	cp protobuf-prefix/src/protobuf/target/lib/libprotoc.a lib && \
	cp tbb-prefix/src/tbb/build/lib_release/libtbb.a lib/ && \
	cp tbb-prefix/src/tbb/build/lib_release/libtbbmalloc.a lib/ && \
	cp -r c-ares-prefix/src/c-ares/target/include/*.h include/ && \
	cp -r b64-prefix/src/b64/include/b64 include/ && \
	cp -r jq-prefix/src/jq/target/include/*.h include/ && \
	cp libsinsp/libsinsp.a lib/ && \
	find libscap -name '*.a' -exec cp '{}' lib \; && \
	cp ../../falco/docker/falco/docker-entrypoint.sh bin/ && \
	cp ../../falco/scripts/falco-driver-loader bin/ && \
	sed -i -E "s/@DRIVER_VERSION@/\"$(FALCO_LIBS_DRIVER_VERSION)\"/" bin/falco-driver-loader && \
	sed -i -E "s/@FALCO_VERSION@/\"$(FALCO_VERSION)\"/" bin/falco-driver-loader && \
	sed -i -E "s#@DRIVERS_REPO@#\"$(DRIVERS_REPO)\"#" bin/falco-driver-loader && \
    cp re2-prefix/build/libre2.a lib/ && \
	cp grpc-prefix/src/grpc/*.a lib/ && \
	find grpc-prefix/src/grpc/third_party/abseil-cpp -name '*.a' -exec cp '{}' lib \; && \
	cp c-ares-prefix/src/c-ares/target/lib/libcares.a lib/ && \
	cp b64-prefix/src/b64/src/libb64.a lib/ && \
	cp curl-prefix/src/curl/lib/.libs/libcurl.a lib/ && \
	cp jq-prefix/src/jq/target/lib/*.a lib/ && \
	cp tbb-prefix/src/tbb/build/lib_release/libtbb.a lib/ && \
	cp openssl-prefix/src/openssl/target/lib/*.a lib/ && \
	cp zlib-prefix/src/zlib/libz.a lib/libz.a
ifeq ($(BUNDLE_FALCO_LIBS), 1)	
	cp -r falco-libs/build/lib falco-libs/build/bundle
	cp falco-libs.mri falco-libs/build/bundle 
	cd falco-libs/build/bundle && \
	mv libgrpc++.a libgrpcpp.a && \
	mv libgrpc++_alts.a libgrpcpp_alts.a && \
	mv libgrpc++_error_details.a libgrpcpp_error_details.a && \
	mv libgrpc++_reflection.a libgrpcpp_reflection.a && \
	mv libgrpc++_unsecure.a libgrpcpp_unsecure.a && \
	ar -M <falco-libs.mri && cp libs.a ../lib/
endif

.PHONY: falcolibs/install
falcolibs/install:
	mkdir -p $(FALCOINCPREFIX) && mkdir -p $(FALCOLIBPREFIX) && mkdir -p $(BINPREFIX) && \
	cd falco-libs/build && cp -r include/* $(FALCOINCPREFIX)/ && cp -a lib/* $(FALCOLIBPREFIX)/ && cp -a bin/* $(BINPREFIX)/

.PHONY: falcodriver/package
falcodriver/package:
	cd falco-driver && \
	mkdir -p build && cd build && \
        cmake \
			-DDRIVER_PACKAGE_NAME=falco \
			-DDRIVER_NAME=falco \
			-DCMAKE_BUILD_TYPE=Release \
			-DUSE_BUNDLED_DEPS=ON \
			-DBUILD_LIBSCAP_GVISOR=Off \
			-DBUILD_BPF=True .. && \
	cp -r ../driver/bpf driver/src/

.PHONY: falcodriver/install
falcodriver/install:
	mkdir -p "$(DRIVERPREFIX)$(FALCO_LIBS_DRIVER_VERSION)" && \
	cd falco-driver/build && cp -a driver/src/* "$(DRIVERPREFIX)$(FALCO_LIBS_DRIVER_VERSION)"

.PHONY: avro/package
avro/package:
	cd avro/lang/c++ && mkdir -p build && cd build && \
	cmake -DCMAKE_INSTALL_PREFIX=$(MODPREFIX) \
	-DCMAKE_CXX_FLAGS_ALL_WARNINGS:STRING="-w" \
	-DCMAKE_BUILD_TYPE=ALL_WARNINGS -G "Unix Makefiles" ../. && make -j${MAKE_JOBS} && \
	cp -a ../api avro

.PHONY: avro/install
avro/install:
	cd avro/lang/c++/build && make install

.PHONY: sysflow/install
sysflow/install:
	mkdir -p $(CONFPREFIX) && cp sysflow/avro/avsc/SysFlow.avsc $(CONFPREFIX)/ && \
	mkdir -p $(SFINCPREFIX)/c++/sysflow && cp -r sysflow/c++/sysflow/* $(SFINCPREFIX)/c++/sysflow/

.PHONY: fs/install
fs/install:
	mkdir -p $(FSINCPREFIX) && cp -r filesystem/include/* $(FSINCPREFIX)/

.PHONY: elfutils/package
elfutils/package:
	cd elfutils && autoreconf -i -f && \
	./configure --prefix=/usr --enable-maintainer-mode --disable-debuginfod && \
	make -j${MAKE_JOBS} && make install

.PHONY: elfutils/install
elfutils/install:
	cd elfutils && make install

.PHONY: glog/package
glog/package:
	cd glog && cmake -S . -B build -G "Unix Makefiles" -DBUILD_SHARED_LIBS=OFF -DBUILD_TESTING=OFF -DWITH_GFLAGS=OFF && \
	cmake --build build -- -j${MAKE_JOBS}

.PHONY: glog/install
glog/install:
	cd glog/build && make install

.PHONY: snappy/package
snappy/package:
	cd snappy && cmake -S . -B build -G "Unix Makefiles" -DSNAPPY_BUILD_BENCHMARKS=OFF -DSNAPPY_BUILD_TESTS=OFF -DBUILD_SHARED_LIBS=OFF && \
	cmake --build build -- -j${MAKE_JOBS}

.PHONY: snappy/install
snappy/install:
	cd snappy/build && make install

.PHONY: dkms-deb/install
dkms-deb/install:
	cd dkms && make install-debian

.PHONY: dkms-rh/install
dkms-rh/install:
	cd dkms && make install-redhat

.PHONY: uninstall
uninstall:
	rm -rf $(LIBPREFIX) $(INCPREFIX) $(CONFPREFIX) && \
	rm -rf $(DRIVERPREFIX)$(FALCO_LIBS_DRIVER_VERSION) && \
	find $(BINPREFIX) ! -name "sysporter" -type f -exec rm -f {} +

.PHONY: clean
clean:
	rm -rf avro/lang/c++/build falco-libs/build falco-driver/build glog/build snappy/build
