#
#      Copyright (c) 2017 Programmer Woogwei (woogwei@outlook.com)
#              ALL RIGHTS RESERVED
#
#    This source code is free software; you can redistribute it
#    and/or modify it in source code form under the terms of the GNU
#    General Public License as published by the Free Software
#    Foundation; either version 2 of the License, or (at your option)
#    any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
#

include common.mk

CC                     ?= gcc
CXX                    ?= g++
CONFIG_FLAGS           ?=
OS                      = $(shell uname -o)
CMODELGEN_GIT_FRONTEND  = $(shell pwd)
CMODELGEN_BUILD_DIR     = $(CMODELGEN_GIT_FRONTEND)/build
ifeq ($(OS),Msys)
  DEBUG_CFLAGS          = -g -DCMODELGEN_DEBUG
  ICA_PATCH_CFLAGS      = -DCMODELGEN -static-libgcc
  ICA_PATCH_CXXFLAGS    = -DCMODELGEN -static-libstdc++ -static-libgcc
else
  DEBUG_CFLAGS          = -g -DCMODELGEN_DEBUG -rdynamic
  ICA_PATCH_CFLAGS      = -D__inline= -DCMODELGEN
  ICA_PATCH_CXXFLAGS    = -D__inline= -DCMODELGEN
endif
RELEASE_CFLAGS          =

IVL_SRC_DIR             = $(CMODELGEN_GIT_FRONTEND)/$(IVL_DIR)
IVL_BUILD_DEBUG_DIR     = $(CMODELGEN_BUILD_DIR)/frontend/ivl-build-debug/$(IVL_DIR)
IVL_BUILD_RELEASE_DIR   = $(CMODELGEN_BUILD_DIR)/frontend/ivl-build-release/$(IVL_DIR)
IVL_INSTALL_DEBUG_DIR   = $(CMODELGEN_BUILD_DIR)/frontend/ivl-install-debug/$(IVL_DIR)
IVL_INSTALL_RELEASE_DIR = $(CMODELGEN_BUILD_DIR)/frontend/ivl-install-release/$(IVL_DIR)

.PHONY: all help clean check
.PHONY: debug release checkdebug checkrelease

all: debug release

help:
	@echo "Available options: help, build, clean"

$(IVL_SRC_DIR)/configure:
	cd $(IVL_SRC_DIR); autoconf; cd -

##### Debug

$(IVL_BUILD_DEBUG_DIR)/Makefile: $(IVL_SRC_DIR)/configure
	@if !( [ -d ${IVL_BUILD_DEBUG_DIR} ] ); then mkdir -p ${IVL_BUILD_DEBUG_DIR}; fi
	cd $(IVL_BUILD_DEBUG_DIR); CC="$(CC)" CXX="$(CXX)" CFLAGS="$(DEBUG_CFLAGS) $(ICA_PATCH_CFLAGS)" CXXFLAGS="$(DEBUG_CFLAGS) $(ICA_PATCH_CXXFLAGS)" LDFLAGS="$(DEBUG_FLAGS)" $(IVL_SRC_DIR)/configure --prefix=$(IVL_INSTALL_DEBUG_DIR) --enable-suffix=-$(APP_NAME) $(CONFIG_FLAGS); cd -

debug: $(IVL_BUILD_DEBUG_DIR)/Makefile
	$(MAKE) -C $(IVL_BUILD_DEBUG_DIR)
	@if !( [ -d ${IVL_INSTALL_DEBUG_DIR} ] ); then mkdir -p ${IVL_INSTALL_DEBUG_DIR}; fi
	$(MAKE) -C $(IVL_BUILD_DEBUG_DIR) install

checkdebug: debug
	$(MAKE) -C $(IVL_BUILD_DEBUG_DIR) check

##### Release

$(IVL_BUILD_RELEASE_DIR)/Makefile: $(IVL_SRC_DIR)/configure
	@if !( [ -d ${IVL_BUILD_RELEASE_DIR} ] ); then mkdir -p ${IVL_BUILD_RELEASE_DIR}; fi
	cd $(IVL_BUILD_RELEASE_DIR); CC="$(CC)" CXX="$(CXX)" CFLAGS="$(RELEASE_CFLAGS) $(ICA_PATCH_CFLAGS)" CXXFLAGS="$(RELEASE_CFLAGS) $(ICA_PATCH_CXXFLAGS)" LDFLAGS="$(RELEASE_FLAGS)" $(IVL_SRC_DIR)/configure --prefix=$(IVL_INSTALL_RELEASE_DIR) --enable-suffix=-$(APP_NAME) $(CONFIG_FLAGS); cd -

release: $(IVL_BUILD_RELEASE_DIR)/Makefile
	$(MAKE) -C $(IVL_BUILD_RELEASE_DIR)
	@if !( [ -d ${IVL_INSTALL_RELEASE_DIR} ] ); then mkdir -p ${IVL_INSTALL_RELEASE_DIR}; fi
	$(MAKE) -C $(IVL_BUILD_RELEASE_DIR) install

checkrelease: release
	$(MAKE) -C $(IVL_BUILD_RELEASE_DIR) check

check: checkdebug checkrelease

clean:
	rm -rf $(CMODELGEN_BUILD_DIR)/frontend
	rm -rf $(IVL_SRC_DIR)/configure $(IVL_SRC_DIR)/autom4te.cache
