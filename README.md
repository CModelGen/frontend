[![Travis Build Status](https://travis-ci.org/CModelGen/frontend.svg?branch=master)](https://travis-ci.org/CModelGen/frontend/)

# CModelGen Frontend

This project implements a frontend program for [CModelGen](https://github.com/CModelGen/CModelGen).
The program is extended from the [Icarus Verilog](http://iverilog.icarus.com/).

The source code is open under the [GNU General Public License Version 2](https://www.gnu.org/licenses/old-licenses/gpl-2.0.txt).

## Structure of the Source Code

The CModelGen frontend is implemented as a plugin of Icarus Verilog 0.10.0.

The _slightly modified_ source code of Icarus Verilog 0.10.0 resides under the directory `iverilog-0.10.0`.

The source code of the CModelGen frontend locates under `tgt-cmodelgen`.

## Building the Program

This GIT repository is a submodule of [CModelGen](https://github.com/CModelGen/CModelGen).
When building CModelGen, commands to build this program are automatically invoked.

Alternatively, this program can be built manually.

Before building the program, please ensure the following programs are already installed.

- GNU Make
- autoconf
- gperf
- flex
- bison
- readline
- gcc
- g++

The following command can be used to build the program.

    make

The command builds a debug version and a release version of the program, and puts these versions under the following directories.

    build/frontend/ivl-install-debug
    build/frontend/ivl-install-release

## Using the Program

This program can be invoked by CModelGen automatically. To see how it is invoked, add the `--verbose` flag to any CModelGen-invoking command.
